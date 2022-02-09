TARGET = bytezero
VERSION = 1.0.0
QMAKE_TARGET_COMPANY = bytezero.inc
QMAKE_TARGET_PRODUCT = bytezero
QMAKE_TARGET_DESCRIPTION = bytezero storages
QMAKE_TARGET_COPYRIGHT = Copyright(C) 2021 bytezero.inc

QT += quick
QT += sql

CONFIG += c++11

#CONFIG += debug_and_release warn_on
CONFIG += thread exceptions rtti stl

macx: LIBS += -framework AppKit
win32:CONFIG(debug, debug|release) {
    #CONFIG += console
      QMAKE_CFLAGS_DEBUG += -MTd
      QMAKE_CXXFLAGS_DEBUG += -MTd
}

CONFIG += lrelease
CONFIG += embed_translations

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CHUNKDB_SOURCES = \
      $$PWD/../../../sdk/cores/chunk_db/chunk_db.cpp \
      $$PWD/../../../sdk/cores/chunk_db/chunk_info.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db_file.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db_index.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db_time_index.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db_utils.cpp \
      $$PWD/../../../sdk/cores/chunk_db/db_wallet.cpp \
      $$PWD/../../../sdk/cores/chunk_db/key_storage.cpp \
      $$PWD/../../../sdk/cores/chunk_db/plot_file.cpp \
      $$PWD/../../../sdk/cores/utils/loguru.cpp \
      $$PWD/../../../sdk/cores/utils/md5.cpp \
      $$PWD/../../../sdk/cores/utils/cpurate.cpp \
      $$PWD/../../../sdk/cores/utils/exception.cpp \
      $$PWD/../../../sdk/cores/crypto/base.cpp \

SOURCES += \
      base/baseinfo.cpp \
      base/baselistmodel.cpp \
      chunkdbs/bytezerodb.cpp \
      chunkdbs/chunkdbsdk.cpp \
      chunkdbs/db/dbcreatelistmodel.cpp \
      chunkdbs/db/dbinfo.cpp \
      main.cpp \
      storages/bytezerosdk.cpp \
      utils/config.cpp \
      utils/utils.cpp \
      $$CHUNKDB_SOURCES \

HEADERS += \
      base/baseinfo.h \
      base/baselistmodel.h \
      chunkdbs/bytezerodb.h \
      chunkdbs/chunkdbsdk.h \
      chunkdbs/db/dbcreatelistmodel.h \
      chunkdbs/db/dbinfo.h \
      storages/bytezero.h \
      storages/bytezerosdk.h \
      utils/config.h \
      utils/utils.h


RESOURCES += qml.qrc

TRANSLATIONS += \
    i18n/bytezero_zh_CN.ts \
    i18n/bytezero_en.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = \
      $$PWD/components \
      $$PWD/components/Bytezero \
      $$PWD/components/Bytezero/Theme \
      $$PWD/components/Bytezero/Utils \
      $$PWD/components/Bytezero/Navigator \
      $$PWD/components/Bytezero/Control \
      $$PWD/components/ChunkDB

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



## bitdisk_chunkdb_so.
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../sdk/build/bin/Release/ -lchunk_db_sdk
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../sdk/build/bin/Release/ -lchunk_db_sdk
#else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../sdk/build_release/bin/ -lchunk_db_sdk
#else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../sdk/build/bin/ -lchunk_db_sdk

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../sdk/build/lib/Release/ -lcryptopp-static
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../sdk/build/lib/Debug/ -lcryptopp-static
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../sdk/build_release/bin/ -lcryptopp-static
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../sdk/build/bin/ -lcryptopp-static

INCLUDEPATH += $$PWD/../../../sdk $$PWD/../../../sdk/libraries
DEPENDPATH += $$PWD/../../../sdk $$PWD/../../../sdk/libraries

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../sdk/build/lib/Release/cryptopp-static.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../sdk/build/lib/Debug/cryptopp-static.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../sdk/build/lib/Release/libcryptopp-static.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../sdk/build/lib/Debug/libcryptopp-static.a



DISTFILES += \
    components/Bytezero/Base/qmldir \
    i18n/bytezero_zh_CN.ts \
    i18n/bytezero_en.ts


