/****************************************************************************
** Meta object code from reading C++ file 'rampSettingsPanel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../components/protocols/ramp/rampSettingsPanel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rampSettingsPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN17RampSettingsPanelE_t {};
} // unnamed namespace

template <> constexpr inline auto RampSettingsPanel::qt_create_metaobjectdata<qt_meta_tag_ZN17RampSettingsPanelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RampSettingsPanel",
        "stepAmplitudeChanged",
        "",
        "value",
        "stimulationTimeChanged",
        "seconds",
        "restTimeChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'stepAmplitudeChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'stimulationTimeChanged'
        QtMocHelpers::SignalData<void(double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
        // Signal 'restTimeChanged'
        QtMocHelpers::SignalData<void(double)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<RampSettingsPanel, qt_meta_tag_ZN17RampSettingsPanelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject RampSettingsPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17RampSettingsPanelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17RampSettingsPanelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17RampSettingsPanelE_t>.metaTypes,
    nullptr
} };

void RampSettingsPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RampSettingsPanel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->stepAmplitudeChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->stimulationTimeChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->restTimeChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RampSettingsPanel::*)(int )>(_a, &RampSettingsPanel::stepAmplitudeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (RampSettingsPanel::*)(double )>(_a, &RampSettingsPanel::stimulationTimeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (RampSettingsPanel::*)(double )>(_a, &RampSettingsPanel::restTimeChanged, 2))
            return;
    }
}

const QMetaObject *RampSettingsPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RampSettingsPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17RampSettingsPanelE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RampSettingsPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RampSettingsPanel::stepAmplitudeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void RampSettingsPanel::stimulationTimeChanged(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void RampSettingsPanel::restTimeChanged(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
