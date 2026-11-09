/****************************************************************************
** Meta object code from reading C++ file 'sidePanel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../components/side/sidePanel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sidePanel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9sidePanelE_t {};
} // unnamed namespace

template <> constexpr inline auto sidePanel::qt_create_metaobjectdata<qt_meta_tag_ZN9sidePanelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "sidePanel",
        "iniciarAuditivoClicado",
        "",
        "pararAuditivoClicado",
        "selecionarAudioClicado",
        "volumeAlterado",
        "volDir",
        "volEsq",
        "canalEstimuloAlterado",
        "index",
        "tipoEstimuloAlterado",
        "reproducaoCiclicaToggled",
        "checked",
        "tempoReproducaoCiclicaAlterado",
        "tempo",
        "duracaoEstimuloAlterada",
        "freqAudioAlterada",
        "valor",
        "duracaoMsAlterada",
        "amplitudeAlterada",
        "freqPortadoraAlterada",
        "freqModulacaoAlterada",
        "fatorAMAlterado",
        "exponencialModAlterada",
        "faseFMAlterada",
        "fatorFMAlterado",
        "aoMudarVolume"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'iniciarAuditivoClicado'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pararAuditivoClicado'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'selecionarAudioClicado'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumeAlterado'
        QtMocHelpers::SignalData<void(int, int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 7 },
        }}),
        // Signal 'canalEstimuloAlterado'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'tipoEstimuloAlterado'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'reproducaoCiclicaToggled'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Signal 'tempoReproducaoCiclicaAlterado'
        QtMocHelpers::SignalData<void(const QTime &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 14 },
        }}),
        // Signal 'duracaoEstimuloAlterada'
        QtMocHelpers::SignalData<void(const QTime &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 14 },
        }}),
        // Signal 'freqAudioAlterada'
        QtMocHelpers::SignalData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'duracaoMsAlterada'
        QtMocHelpers::SignalData<void(int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'amplitudeAlterada'
        QtMocHelpers::SignalData<void(int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'freqPortadoraAlterada'
        QtMocHelpers::SignalData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'freqModulacaoAlterada'
        QtMocHelpers::SignalData<void(int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'fatorAMAlterado'
        QtMocHelpers::SignalData<void(int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'exponencialModAlterada'
        QtMocHelpers::SignalData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'faseFMAlterada'
        QtMocHelpers::SignalData<void(int)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Signal 'fatorFMAlterado'
        QtMocHelpers::SignalData<void(int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'aoMudarVolume'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<sidePanel, qt_meta_tag_ZN9sidePanelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject sidePanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9sidePanelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9sidePanelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9sidePanelE_t>.metaTypes,
    nullptr
} };

void sidePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<sidePanel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->iniciarAuditivoClicado(); break;
        case 1: _t->pararAuditivoClicado(); break;
        case 2: _t->selecionarAudioClicado(); break;
        case 3: _t->volumeAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->canalEstimuloAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->tipoEstimuloAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->reproducaoCiclicaToggled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->tempoReproducaoCiclicaAlterado((*reinterpret_cast<std::add_pointer_t<QTime>>(_a[1]))); break;
        case 8: _t->duracaoEstimuloAlterada((*reinterpret_cast<std::add_pointer_t<QTime>>(_a[1]))); break;
        case 9: _t->freqAudioAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->duracaoMsAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->amplitudeAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->freqPortadoraAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->freqModulacaoAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->fatorAMAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->exponencialModAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->faseFMAlterada((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->fatorFMAlterado((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->aoMudarVolume(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)()>(_a, &sidePanel::iniciarAuditivoClicado, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)()>(_a, &sidePanel::pararAuditivoClicado, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)()>(_a, &sidePanel::selecionarAudioClicado, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int , int )>(_a, &sidePanel::volumeAlterado, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::canalEstimuloAlterado, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::tipoEstimuloAlterado, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(bool )>(_a, &sidePanel::reproducaoCiclicaToggled, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(const QTime & )>(_a, &sidePanel::tempoReproducaoCiclicaAlterado, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(const QTime & )>(_a, &sidePanel::duracaoEstimuloAlterada, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::freqAudioAlterada, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::duracaoMsAlterada, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::amplitudeAlterada, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::freqPortadoraAlterada, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::freqModulacaoAlterada, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::fatorAMAlterado, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::exponencialModAlterada, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::faseFMAlterada, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (sidePanel::*)(int )>(_a, &sidePanel::fatorFMAlterado, 17))
            return;
    }
}

const QMetaObject *sidePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sidePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9sidePanelE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int sidePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void sidePanel::iniciarAuditivoClicado()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sidePanel::pararAuditivoClicado()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void sidePanel::selecionarAudioClicado()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void sidePanel::volumeAlterado(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void sidePanel::canalEstimuloAlterado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void sidePanel::tipoEstimuloAlterado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void sidePanel::reproducaoCiclicaToggled(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void sidePanel::tempoReproducaoCiclicaAlterado(const QTime & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void sidePanel::duracaoEstimuloAlterada(const QTime & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void sidePanel::freqAudioAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void sidePanel::duracaoMsAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void sidePanel::amplitudeAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void sidePanel::freqPortadoraAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void sidePanel::freqModulacaoAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void sidePanel::fatorAMAlterado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void sidePanel::exponencialModAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void sidePanel::faseFMAlterada(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void sidePanel::fatorFMAlterado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}
QT_WARNING_POP
