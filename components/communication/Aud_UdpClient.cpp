#include "Aud_UdpClient.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <cmath>
#include <cstdint>
#include <cstring>

Aud_UdpClient::Aud_UdpClient() : udp_socket(INVALID_SOCKET), running(false), logLevel(INFO) {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        Log(ERRO, "WSAStartup failed: " + std::to_string(result));
        exit(1);
    }
}

Aud_UdpClient::~Aud_UdpClient() {
    esStop();
    WSACleanup();
}

bool Aud_UdpClient::esConfig() {
    std::string message;

    message = "IP defined (Aud): " + std::string(AUD_IP);
    Log(INFO, message);

    message = "PORT defined (Aud): " + std::to_string(AUD_PORT);
    Log(INFO, message);

    message = "TIMEOUT defined (Aud): " + std::to_string(AUD_TIME_OUT);
    Log(INFO, message);

    std::memset(&hardwareIPAddr, 0, sizeof(hardwareIPAddr));
    hardwareIPAddr.sin_family = AF_INET;
    inet_pton(AF_INET, AUD_IP, &hardwareIPAddr.sin_addr);
    hardwareIPAddr.sin_port = htons(AUD_PORT);

    return true;
}

bool Aud_UdpClient::esStart() {
    if (running) {
        Log(WARN, "Auditivo communication already started");
        return false;
    }

    udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udp_socket == INVALID_SOCKET) {
        Log(ERRO, "Auditivo Socket creation failed: " + std::to_string(WSAGetLastError()));
        return false;
    }

    DWORD timeout = AUD_TIME_OUT;
    if (setsockopt(udp_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        Log(ERRO, "Auditivo Failed to set socket receive timeout: " + std::to_string(WSAGetLastError()));
        return false;
    }

    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = INADDR_ANY;
    localAddr.sin_port = htons(0);

    if (bind(udp_socket, (sockaddr*)&localAddr, sizeof(localAddr)) == SOCKET_ERROR) {
        Log(ERRO, "Auditivo Bind failed: " + std::to_string(WSAGetLastError()));
        return false;
    }

    running = true;
    Log(INFO, "Auditivo Communication started successfully");
    return true;
}

void Aud_UdpClient::esStop() {
    if (running) {
        if (udp_socket != INVALID_SOCKET) {
            closesocket(udp_socket);
            Log(INFO, "Auditivo Socket closed.");
            udp_socket = INVALID_SOCKET;
            running = false;
        }
    }
}

int Aud_UdpClient::esSendData(byte *data, unsigned int size_data) {
    if (!running) {
        Log(WARN, "Auditivo Not started");
        return COMM_NOT_STARTED;
    }

    std::cout << " auditivo - Dados a enviar: {";
    for (int i = 0; i < (int)size_data; i++) {
        if (i == (int)size_data - 1) { std::cout << (int)data[i]; }
        else { std::cout << (int)data[i] << ", "; }
    }
    std::cout << "}" << std::endl;

    if (sendto(udp_socket, (const char*)data, size_data, 0, (sockaddr*)&hardwareIPAddr, sizeof(hardwareIPAddr)) < 0){
        Log(ERRO, "Auditivo Send failed: " + std::to_string(WSAGetLastError()));
        return COMM_SEND_DATA_ERROR;
    }

    return OK;
}

int Aud_UdpClient::esReceiveData(char *data_out) {
    if (!running) {
        Log(WARN, "Auditivo Not started");
        return COMM_NOT_STARTED;
    }

    int serverAddrSize = sizeof(hardwareIPAddr);
    int size_data_out = recvfrom(udp_socket, data_out, AUD_RECEIVE_BUFFER_SIZE, 0, (sockaddr*)&hardwareIPAddr, &serverAddrSize);
    if (size_data_out == SOCKET_ERROR) {
        Log(ERRO, "Auditivo Receive failed: " + std::to_string(WSAGetLastError()));
        return COMM_RECIVE_DATA_ERROR;
    }

    std::cout << " auditivo - Dados recebidos: {";
    for (int i = 0; i < size_data_out; i++) {
        if (i == (int)size_data_out - 1) { std::cout << (int)data_out[i]; }
        else { std::cout << (int)data_out[i] << ", "; }
    }
    std::cout << "}" << std::endl;

    return OK;
}

int Aud_UdpClient::esSendPackage(byte id, byte *data_in_ptr, unsigned int size_data) {
    Log(DEBUG, "Dentro da esSendPackage (Auditivo)");

    byte* datos = new byte[size_data + 5];
    datos[0] = (byte)0x5A;
    datos[1] = (byte)((size_data + 5) & 0xFF);
    datos[2] = (byte)((size_data + 5) >> 8 & 0xFF);
    datos[3] = id;

    if (data_in_ptr != NULL) {
        for (unsigned int i = 0; i < size_data; i++)
            datos[i + 4] = data_in_ptr[i];
    }

    datos[size_data + 4] = (byte)0;
    for (unsigned int i = 1; i < size_data + 4; i++)
        datos[size_data + 4] += datos[i];

    int res = esSendData(datos, size_data + 5);
    delete[] datos;
    return res;
}

int Aud_UdpClient::esSendReceivePackage(byte id, byte *data_in, unsigned int size_data_in, char *data_out) {
    int resultado = esSendPackage(id, data_in, size_data_in);
    if (resultado != OK) {
        return resultado;
    }
    return esReceiveData(data_out);
}

int Aud_UdpClient::esSendCmd(byte cmd, char *data_out) {
    int resultado = esSendReceivePackage(cmd, nullptr, 0, data_out);
    if (resultado != OK) {
        return resultado;
    }

    if ((byte)data_out[0] == 0x5A && (byte)data_out[3] == cmd) {
        return OK;
    } else {
        return COMM_SEND_CMD_ERROR;
    }
}

int Aud_UdpClient::esSendConfig(byte cmd, byte* data_in, unsigned int size_data_in) {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];
    if (this->esSendReceivePackage(cmd, data_in, size_data_in, data_out) != OK) {
        return COMM_SEND_CONFIG_ERROR;
    }

    if ((byte)data_out[0] == 0x5A && (byte)data_out[3] == cmd) {
        return OK;
    } else {
        return COMM_SEND_CMD_ERROR;
    }
}

int Aud_UdpClient::esGetNetworkConfig(byte *ip, byte *mask, byte *getway, unsigned int *port) {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];
    int recebido = esSendReceivePackage(0x1E, nullptr, 0, data_out);
    if (recebido != OK) {
        return recebido;
    }
    ip[0] = data_out[4]; ip[1] = data_out[5]; ip[2] = data_out[6]; ip[3] = data_out[7];
    mask[0] = data_out[8]; mask[1] = data_out[9]; mask[2] = data_out[10]; mask[3] = data_out[11];
    getway[0] = data_out[12]; getway[1] = data_out[13]; getway[2] = data_out[14]; getway[3] = data_out[15];
    *port = (unsigned char)data_out[16] | (unsigned char)data_out[17] << 8;
    return OK;
}

int Aud_UdpClient::iniciaEstimAud() {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];
    return esSendCmd(AUD_CMD_INICIA_ESTIM, data_out);
}

int Aud_UdpClient::finEstimAud() {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];
    return esSendCmd(AUD_CMD_FIN_ESTIM, data_out);
}

int Aud_UdpClient::estabVolume(byte vol_dir, byte vol_esq) {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];
    byte pacote[2] = { vol_dir, vol_esq };

    if (esSendReceivePackage(21, pacote, 2, data_out) != OK) {
        return COMM_SEND_CMD_ERROR;
    }
    return OK;
}

int Aud_UdpClient::enviaPaqueteEstimAud(byte* pacote, unsigned int size_pacote, char *data_out) {
    int resultado;
    int tentativas = 0;

    do {
        resultado = esSendReceivePackage(AUD_CMD_ENVIA_PACOTE, pacote, size_pacote, data_out);
        tentativas++;
        if(tentativas > 5) return COMM_SEND_DATA_ERROR;

    } while (resultado != OK || (byte)data_out[0] != 0x5A || (byte)data_out[3] != AUD_CMD_ENVIA_PACOTE);

    return (int)data_out[4];
}

int Aud_UdpClient::esSendSegmentStimulus(byte *data_in, unsigned int size_data_in, char *data_out) {
    return OK;
}

int Aud_UdpClient::esSendStimulus(byte* signal, unsigned int cycles_repetitions, unsigned int samples_in_one_cycle_signal) {
    return OK;
}

int Aud_UdpClient::esSendStimulus(byte* signal, unsigned int N_packages_16b) {
    return OK;
}

void Aud_UdpClient::esSendFinishTransmission() {
}

void Aud_UdpClient::SetLogLevel(LogType level) {
    logLevel = level;
}

void Aud_UdpClient::Log(LogType level, const std::string& message) {
    if (level <= logLevel) {
        std::string color, stringlog;
        switch (level) {
        case DEBUG:
            color = CYAN;
            stringlog = "AUD_DEBUG: ";
            break;
        case INFO:
            color = GREEN;
            stringlog = "AUD_INFO: ";
            break;
        case WARN:
            color = YELLOW;
            stringlog = "AUD_WARN: ";
            break;
        case ERRO:
            color = RED;
            stringlog = "AUD_ERRO: ";
            break;
        case TESTE:
            color = MAGENTA;
            stringlog = "AUD_TESTE: ";
            break;
        }
        std::cout << color << stringlog << RESET << message << std::endl;
    }
}

int Aud_UdpClient::EstadoPugs(byte &ch_der, byte &ch_izq) {
    char data_out[AUD_RECEIVE_BUFFER_SIZE];

    if (esSendReceivePackage(23, nullptr, 0, data_out) != OK) {
        return COMM_SEND_CMD_ERROR;
    }

    ch_der = data_out[4];
    ch_izq = data_out[5];

    return OK;
}