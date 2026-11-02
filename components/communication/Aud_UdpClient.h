#ifndef AUD_UDPCLIENT_H
#define AUD_UDPCLIENT_H

#include "ES_Communication.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>
#include <string>
#include <vector>

// MACROS CÓDIGOS DE ERROS
#define OK                      1
#define COMM_NOT_STARTED        -1
#define COMM_SEND_DATA_ERROR    -2
#define COMM_RECIVE_DATA_ERROR  -3
#define COMM_SEND_CMD_ERROR     -4
#define COMM_SEND_CONFIG_ERROR  -5

// MACROS DE COMUNICAÇÃO DO AUDITIVO
// #define AUD_IP                  "192.168.0.10" // IP do auditivo
#define AUD_IP                  "127.0.0.1" // IP do script
#define AUD_PORT                668           // Porta padrão do auditivo
#define AUD_TIME_OUT            200

// MACROS UDP
#define AUD_RECEIVE_BUFFER_SIZE 4096

// Comandos específicos para o Hardware Auditivo (mera especulação por agora)
#define AUD_CMD_INICIA_ESTIM      20 // IniciaEstimAud()
#define AUD_CMD_ESTAB_VOLUME      21 // EstabVolume()
#define AUD_CMD_FIN_ESTIM         22 // FinEstimAud()
#define AUD_CMD_ESTADO_PUGS       23 // EstadoPugs()
#define AUD_CMD_ENVIA_PACOTE      25 // EnviaPaqueteEstimAud()
#define AUD_CMD_GRABA_ULTIMO      33 // GrabaUltimoPaquete()

class Aud_UdpClient : public ES_Communication {
public:
    Aud_UdpClient();
    ~Aud_UdpClient();

    bool esConfig() override;
    bool esStart() override;
    void esStop() override;

    int esSendData(byte *data, unsigned int size_data) override;
    int esReceiveData(char *data_out) override;
    int esSendPackage(byte id, byte *data_in, unsigned int size_data_in) override;
    int esSendReceivePackage(byte id, byte *data_in, unsigned int size_data_in, char *data_out) override;
    int esSendCmd(byte cmd, char *data_out) override;
    int esSendConfig(byte cmd, byte* data_in, unsigned int size_data_in) override;
    int esGetNetworkConfig(byte *ip, byte *mask, byte *getway, unsigned int *port) override;

    // Sobrecargas para satisfazer ES_Communication
    int esSendSegmentStimulus(byte *data_in, unsigned int size_data_in, char *data_out) override;
    int esSendStimulus(byte* signal, unsigned int cycles_repetitions, unsigned int samples_in_one_cycle_signal) override;
    int esSendStimulus(byte* signal, unsigned int N_packages_16b) ;
    void esSendFinishTransmission() override;

    // Métodos específicos do auditivo
    int iniciaEstimAud();
    int finEstimAud();
    int estabVolume(byte vol_dir, byte vol_esq);
    int enviaPaqueteEstimAud(byte* pacote, unsigned int size_pacote, char *data_out);
    int EstadoPugs(byte &ch_der, byte &ch_izq);

    void SetLogLevel(LogType level = INFO) override;
    void Log(LogType level, const std::string& message) override;

private:
    SOCKET udp_socket;
    sockaddr_in hardwareIPAddr;
    bool running;
    LogType logLevel;

    void PrintLog(const std::string& message,
                  const std::string& color,
                  const std::string& stringlog);
};

#endif // AUD_UDPCLIENT_H