# Interface Electrical Stimulator LAPIS-UFRJ

Esta interface foi desenvolvida para facilitar a comunicação e controle de um 
estimulador elétrico (modelo X) no laboratório LAPIS da UFRJ. 
Ela permite a configuração e o envio de estímulos elétricos através 
de uma conexão UDP com o dispositivo.

**OBS 1:** No momento, a interface é destinada para Computadores com Sistema Operacinal **Windows**.  
**OBS 2:** Talvez seja necessário configurar opções de rede para ter acesso a porta ,etc.
Tanto para uso do programa e continuar a implementação, tanto para o usuário final do produto.


## Manual de uso da Interface

1. **Verificação de Conexão**: Ao iniciar o programa, a conexão com o dispositivo estimulador é automaticamente verificada. O estado da conexão é indicado pelo **LED**:
   - **Vermelho**: Falha na conexão. Verifique se o dispositivo está devidamente conectado e tente novamente apertando o **LED**.
   - **Verde**: Conexão estabelecida com sucesso.

2. **Configuração dos Estímulos**: Configure as entradas de estímulos desejadas na interface, ajustando parâmetros como frequência, duração e intensidade para cada canal.

3. **Ativação dos Canais**: Selecione os canais que deseja utilizar através dos botões ON/OFF.

4. **Iniciar Estimulação**: Após configurar e ativar os canais desejados, inicie a estimulação pressionando o botão "Iniciar Estimulação". A estimulação pode ser interrompida a qualquer momento com o botão "Parar Estimulação".


## Estrutura Hierárquica da Interface

A interface é composta por duas partes principais e seus subdiretórios:

1. **Código da Interface Qt**:
   - **main.cpp**: Arquivo principal que inicia a aplicação.
   - **mainwindow.cpp** e **mainwindow.h**: Lógica da interface, incluindo controle dos botões, LEDs e configuração dos estímulos.
   - **mainwindow.ui**: Layout da interface definido com o Qt Designer.

2. **Biblioteca Electrical Stimulator para Comunicação**:
   - **ES_UdpClient.cpp** e **ES_UdpClient.h**: Gerencia a comunicação UDP com o dispositivo.
   - **ES_WiFiClient.cpp** e **ES_WiFiClient.h**: Configurações para comunicação via Wi-Fi, caso aplicável.
   - **ES_Communication.h**: Declaração da Classe Communication para herança e modifucação nas classes secundárias
    

## Ferramentas e Versões
- **Sistema Operacional** : Microsoft Windows [versão 10.0.22631.4460]
- **Qt Framework**: 6.5.3 (compilação com MSVC 2019 64-bit)
- **Qt Creator**: 13.0.2
- **Compilador**:  GCC 11.2.0 (MinGW 64-bit)
- **Padrão C++**: C++17
- **CMake**: 3.29.3 (conforme encontrado nas configurações)
