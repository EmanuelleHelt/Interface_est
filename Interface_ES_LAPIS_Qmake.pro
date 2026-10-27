# ============================================================
#  Projeto: Interface_ES_LAPIS
#  Sistema de build: qmake (convertido de CMake)
# ============================================================

TEMPLATE = app
TARGET = Interface_ES_LAPIS
CONFIG += qt gui c++17
win32-g++ {
    QMAKE_CXXFLAGS += -Wa,-mbig-obj
}
# ------------------------------------------------------------
#  Módulos Qt necessários
# ------------------------------------------------------------
QT += widgets printsupport

# ------------------------------------------------------------
#  Arquivos fonte, cabeçalhos, forms e recursos
# ------------------------------------------------------------
SOURCES += \
    components/general/durationPanel.cpp \
    components/general/qcustomplot.cpp \
    main.cpp \
    mainwindow.cpp \
    components/channel/channelPanel.cpp \
    components/communication/ES_UdpClient.cpp \
    components/communication/ES_WiFiClient.cpp \
    components/patients/patient.cpp \
    components/patients/patientPanel.cpp \
    components/patients/patientRepository.cpp \
    components/protocols/protocolSelector.cpp \
    components/protocols/ramp/rampSettingsPanel.cpp \
    components/sessions/session.cpp \
    components/sessions/sessionRepository.cpp \
    components/sidebar/sideBar.cpp

HEADERS += \
    components/general/durationPanel.h \
    components/general/qcustomplot.h \
    components/protocols/protocolSelector.h \
    mainwindow.h \
    components/channel/channelPanel.h \
    components/communication/ES_Communication.h \
    components/communication/ES_UdpClient.h \
    components/communication/ES_WiFiClient.h \
    components/patients/patient.h \
    components/patients/patientPanel.h \
    components/patients/patientRepository.h \
    components/protocols/ramp/rampSettingsPanel.h \
    components/sessions/session.h \
    components/sessions/sessionRepository.h \
    components/sidebar/sideBar.h

FORMS += \
    components/channel/channelPanel.ui \
    mainwindow.ui \
    components/patients/patientPanel.ui \
    components/protocols/ramp/rampSettingsPanel.ui \
    components/sidebar/sidebar.ui

RESOURCES += \
    resources.qrc

# ------------------------------------------------------------
#  Diretórios de inclusão
# ------------------------------------------------------------
# Permite localizar os cabeçalhos dos componentes.
INCLUDEPATH += \
    $$PWD \
    $$PWD/components/communication \
    $$PWD/components/channel \
    $$PWD/components/patients \
    $$PWD/components/protocols \
    $$PWD/components/protocols/ramp \
    $$PWD/components/sessions \
    $$PWD/components/sidebar \
    $$PWD/components/general

# ------------------------------------------------------------
#  Bibliotecas externas
# ------------------------------------------------------------
LIBS += -lWs2_32

# ------------------------------------------------------------
#  Configurações adicionais
# ------------------------------------------------------------
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS += -std=c++17

# ------------------------------------------------------------
#  Instalação (manual)
# ------------------------------------------------------------
target.path = $$[QT_INSTALL_BINS]
INSTALLS += target

DISTFILES +=
