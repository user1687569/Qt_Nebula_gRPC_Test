QT += core
QT -= gui

CONFIG += c++11

TARGET = Qt_Nebula_gRPC_Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES +=  \
    main.cpp \
    gRPC/im_common_utils.c \
    testing/testing.c \
    testing/testing_utils.c \
    gRPC/dev_monitor_main.c \
    testing/testing_monitor.c \
    testing/testing_protobuf.c \
    gRPC/ipc_send_extern.c      \
    protobuf-c/im.pb-c.c    \
#    grpc-c/im.grpc-c.c  \
#    grpc-c/im.grpc-c.service.c

HEADERS += \
    gRPC/im_utils.h \
    testing/testing.h \
    testing/testing_utils.h \
    gRPC/gRPC.h \
    gRPC/im_common.h \
    gRPC/dev_monitor.h \
    testing/testing_monitor.h \
    testing/testing_protobuf.h \
    gRPC/im_upgrade_data.h \
    gRPC/im_passthrough_data.h  \
    protobuf-c/im.pb-c.h    \
#    grpc/im.grpc-c.h

INCLUDEPATH +=  \
    -I /usrlocal/include/protobuf-c

LIBS += \
    /usr/local/lib/libprotobuf.so.26.0.8    \
    /usr/local/lib/libprotobuf-c.so.1.0.0


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


DISTFILES += \
    im.proto
