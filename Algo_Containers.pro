TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        simple_tests.cpp

LIBS += -lstdc++fs

HEADERS += \
    dynamic_arrays.h \
    iarray.h \
    itask.h \
    priority_queue.h \
    simple_tests.h \
    space_array.h \
    tester.h
