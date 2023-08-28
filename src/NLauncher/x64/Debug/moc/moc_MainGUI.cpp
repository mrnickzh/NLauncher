/****************************************************************************
** Meta object code from reading C++ file 'MainGUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainGUI.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainGUI_t {
    const uint offsetsAndSize[42];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainGUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainGUI_t qt_meta_stringdata_MainGUI = {
    {
QT_MOC_LITERAL(0, 7), // "MainGUI"
QT_MOC_LITERAL(8, 7), // "initGUI"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 9), // "setMemory"
QT_MOC_LITERAL(27, 9), // "debugMode"
QT_MOC_LITERAL(37, 12), // "changeServer"
QT_MOC_LITERAL(50, 20), // "changeServerFinished"
QT_MOC_LITERAL(71, 14), // "QNetworkReply*"
QT_MOC_LITERAL(86, 9), // "drawImage"
QT_MOC_LITERAL(96, 8), // "flipLeft"
QT_MOC_LITERAL(105, 9), // "flipRight"
QT_MOC_LITERAL(115, 4), // "play"
QT_MOC_LITERAL(120, 12), // "getLibraries"
QT_MOC_LITERAL(133, 17), // "downloadGameFiles"
QT_MOC_LITERAL(151, 20), // "gameDownloadFinished"
QT_MOC_LITERAL(172, 17), // "requestAssetIndex"
QT_MOC_LITERAL(190, 14), // "getVersionInfo"
QT_MOC_LITERAL(205, 13), // "getAssetIndex"
QT_MOC_LITERAL(219, 8), // "clearDir"
QT_MOC_LITERAL(228, 20), // "requestFileWhitelist"
QT_MOC_LITERAL(249, 16) // "getFileWhitelist"

    },
    "MainGUI\0initGUI\0\0setMemory\0debugMode\0"
    "changeServer\0changeServerFinished\0"
    "QNetworkReply*\0drawImage\0flipLeft\0"
    "flipRight\0play\0getLibraries\0"
    "downloadGameFiles\0gameDownloadFinished\0"
    "requestAssetIndex\0getVersionInfo\0"
    "getAssetIndex\0clearDir\0requestFileWhitelist\0"
    "getFileWhitelist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainGUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x0a,    1 /* Public */,
       3,    1,  123,    2, 0x0a,    2 /* Public */,
       4,    0,  126,    2, 0x0a,    4 /* Public */,
       5,    0,  127,    2, 0x0a,    5 /* Public */,
       6,    1,  128,    2, 0x0a,    6 /* Public */,
       8,    0,  131,    2, 0x0a,    8 /* Public */,
       9,    0,  132,    2, 0x0a,    9 /* Public */,
      10,    0,  133,    2, 0x0a,   10 /* Public */,
      11,    0,  134,    2, 0x0a,   11 /* Public */,
      12,    0,  135,    2, 0x0a,   12 /* Public */,
      13,    1,  136,    2, 0x0a,   13 /* Public */,
      14,    0,  139,    2, 0x0a,   15 /* Public */,
      15,    0,  140,    2, 0x0a,   16 /* Public */,
      16,    1,  141,    2, 0x0a,   17 /* Public */,
      17,    1,  144,    2, 0x0a,   19 /* Public */,
      18,    0,  147,    2, 0x0a,   21 /* Public */,
      19,    0,  148,    2, 0x0a,   22 /* Public */,
      20,    1,  149,    2, 0x0a,   23 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void MainGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initGUI(); break;
        case 1: _t->setMemory((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->debugMode(); break;
        case 3: _t->changeServer(); break;
        case 4: _t->changeServerFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 5: _t->drawImage(); break;
        case 6: _t->flipLeft(); break;
        case 7: _t->flipRight(); break;
        case 8: _t->play(); break;
        case 9: _t->getLibraries(); break;
        case 10: _t->downloadGameFiles((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 11: _t->gameDownloadFinished(); break;
        case 12: _t->requestAssetIndex(); break;
        case 13: _t->getVersionInfo((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 14: _t->getAssetIndex((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 15: _t->clearDir(); break;
        case 16: _t->requestFileWhitelist(); break;
        case 17: _t->getFileWhitelist((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MainGUI.offsetsAndSize,
    qt_meta_data_MainGUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainGUI_t
, QtPrivate::TypeAndForceComplete<MainGUI, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainGUI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
