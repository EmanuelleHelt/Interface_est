/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "test_connection",
        "",
        "send_parameters",
        "startStimulations",
        "stopStimulations",
        "enviaEstimEletr",
        "uint8_t*",
        "data_in",
        "size_data_in",
        "on_actionRegistrar_paciente_triggered",
        "on_actionSalvar_sessao_triggered",
        "on_actionSobre_triggered",
        "aud_testar_conexao",
        "aud_iniciar_estimulo",
        "aud_parar_estimulo",
        "verificarPedidoAudio",
        "prepararSinalWAV",
        "caminho",
        "aud_selecionar_audio",
        "aud_alterar_volume",
        "vol_dir",
        "vol_esq",
        "aud_canalEstimuloAlterado",
        "index",
        "aud_tipoEstimuloAlterado",
        "aud_reproducaoCiclicaToggled",
        "checked",
        "aud_tempoReproducaoCiclicaAlterado",
        "tempo",
        "aud_duracaoEstimuloAlterada",
        "aud_freqAudioAlterada",
        "valor",
        "aud_duracaoMsAlterada",
        "aud_amplitudeAlterada",
        "aud_freqPortadoraAlterada",
        "aud_freqModulacaoAlterada",
        "aud_fatorAMAlterado",
        "aud_exponencialModAlterada",
        "aud_faseFMAlterada",
        "aud_fatorFMAlterado"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'test_connection'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'send_parameters'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'startStimulations'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'stopStimulations'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enviaEstimEletr'
        QtMocHelpers::SlotData<int(uint8_t *, int)>(6, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { 0x80000000 | 7, 8 }, { QMetaType::Int, 9 },
        }}),
        // Slot 'on_actionRegistrar_paciente_triggered'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSalvar_sessao_triggered'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSobre_triggered'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'aud_testar_conexao'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'aud_iniciar_estimulo'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'aud_parar_estimulo'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'verificarPedidoAudio'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'prepararSinalWAV'
        QtMocHelpers::SlotData<void(QString)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 18 },
        }}),
        // Slot 'aud_selecionar_audio'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'aud_alterar_volume'
        QtMocHelpers::SlotData<void(int, int)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 21 }, { QMetaType::Int, 22 },
        }}),
        // Slot 'aud_canalEstimuloAlterado'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Slot 'aud_tipoEstimuloAlterado'
        QtMocHelpers::SlotData<void(int)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Slot 'aud_reproducaoCiclicaToggled'
        QtMocHelpers::SlotData<void(bool)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 27 },
        }}),
        // Slot 'aud_tempoReproducaoCiclicaAlterado'
        QtMocHelpers::SlotData<void(const QTime &)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QTime, 29 },
        }}),
        // Slot 'aud_duracaoEstimuloAlterada'
        QtMocHelpers::SlotData<void(const QTime &)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QTime, 29 },
        }}),
        // Slot 'aud_freqAudioAlterada'
        QtMocHelpers::SlotData<void(int)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_duracaoMsAlterada'
        QtMocHelpers::SlotData<void(int)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_amplitudeAlterada'
        QtMocHelpers::SlotData<void(int)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_freqPortadoraAlterada'
        QtMocHelpers::SlotData<void(int)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_freqModulacaoAlterada'
        QtMocHelpers::SlotData<void(int)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_fatorAMAlterado'
        QtMocHelpers::SlotData<void(int)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_exponencialModAlterada'
        QtMocHelpers::SlotData<void(int)>(38, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_faseFMAlterada'
        QtMocHelpers::SlotData<void(int)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'aud_fatorFMAlterado'
        QtMocHelpers::SlotData<void(int)>(40, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->test_connection(); break;
        case 1: _t->send_parameters(); break;
        case 2: _t->startStimulations(); break;
        case 3: _t->stopStimulations(); break;
        case 4: { int _r = _t->enviaEstimEletr((*reinterpret_cast<std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_actionRegistrar_paciente_triggered(); break;
        case 6: _t->on_actionSalvar_sessao_triggered(); break;
        case 7: _t->on_actionSobre_triggered(); break;
        case 8: _t->aud_testar_conexao(); break;
        case 9: _t->aud_iniciar_estimulo(); break;
        case 10: _t->aud_parar_estimulo(); break;
        case 11: _t->verificarPedidoAudio(); break;
        case 12: _t->prepararSinalWAV((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->aud_selecionar_audio(); break;
        case 14: _t->aud_alterar_volume((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->aud_canalEstimuloAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->aud_tipoEstimuloAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->aud_reproducaoCiclicaToggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->aud_tempoReproducaoCiclicaAlterado((*reinterpret_cast<std::add_pointer_t<QTime>>(_a[1]))); break;
        case 19: _t->aud_duracaoEstimuloAlterada((*reinterpret_cast<std::add_pointer_t<QTime>>(_a[1]))); break;
        case 20: _t->aud_freqAudioAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->aud_duracaoMsAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->aud_amplitudeAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->aud_freqPortadoraAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->aud_freqModulacaoAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->aud_fatorAMAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->aud_exponencialModAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->aud_faseFMAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->aud_fatorFMAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}
QT_WARNING_POP
