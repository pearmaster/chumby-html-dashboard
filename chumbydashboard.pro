greaterThan(QT_MAJOR_VERSION, 4):QT += widgets webkitwidgets

# Add more folders to ship with the application, here

# Define TOUCH_OPTIMIZED_NAVIGATION for touch optimization and flicking
#DEFINES += TOUCH_OPTIMIZED_NAVIGATION

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

QT += webkit network

CONFIG += qt warn_on

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    mydebug.cpp \
    mypage.cpp \
    chumbycontrolls.cpp

# Please do not modify the following two lines. Required for deployment.
include(html5applicationviewer/html5applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    mydebug.h \
    mypage.h \
    chumbycontrolls.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../jpeg-6b/release/ -ljpeg
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../jpeg-6b/debug/ -ljpeg
else:unix: LIBS += -L$$PWD/../jpeg-6b/ -ljpeg

INCLUDEPATH += $$PWD/../jpeg-6b
DEPENDPATH += $$PWD/../jpeg-6b

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../jpeg-6b/release/jpeg.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../jpeg-6b/debug/jpeg.lib
else:unix: PRE_TARGETDEPS += $$PWD/../jpeg-6b/libjpeg.a

QTPLUGIN += qjpeg qgif
