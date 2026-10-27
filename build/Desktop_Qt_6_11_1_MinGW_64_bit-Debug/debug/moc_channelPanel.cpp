/****************************************************************************
** Meta object code from reading C++ file 'channelPanel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../components/channel/channelPanel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'channelPanel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ChannelPanelE_t {};
} // unnamed namespace

template <> constexpr inline auto ChannelPanel::qt_create_metaobjectdata<qt_meta_tag_ZN12ChannelPanelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChannelPanel",
        "channelEnabledChanged",
        "",
        "enabled",
        "frequencyChanged",
        "frequencyHz",
        "amplitudeChanged",
        "amplitudeUa",
        "waveformChanged",
        "index"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'channelEnabledChanged'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Signal 'frequencyChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'amplitudeChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'waveformChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ChannelPanel, qt_meta_tag_ZN12ChannelPanelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ChannelPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ChannelPanelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ChannelPanelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ChannelPanelE_t>.metaTypes,
    nullptr
} };

void ChannelPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ChannelPanel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->channelEnabledChanged((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->frequencyChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->amplitudeChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->waveformChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ChannelPanel::*)(bool )>(_a, &ChannelPanel::channelEnabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChannelPanel::*)(int )>(_a, &ChannelPanel::frequencyChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChannelPanel::*)(int )>(_a, &ChannelPanel::amplitudeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChannelPanel::*)(int )>(_a, &ChannelPanel::waveformChanged, 3))
            return;
    }
}

const QMetaObject *ChannelPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChannelPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ChannelPanelE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChannelPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ChannelPanel::channelEnabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ChannelPanel::frequencyChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ChannelPanel::amplitudeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ChannelPanel::waveformChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
