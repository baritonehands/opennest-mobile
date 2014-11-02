# Add more folders to ship with the application, here
DEPLOYMENTFOLDERS =

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

ios {
    QMAKE_INFO_PLIST = OpenNest.plist
    fontFiles.files = fonts/Bariol_Regular.ttf
    fontFiles.path = fonts
    QMAKE_BUNDLE_DATA += fontFiles
}

OTHER_FILES += copyqml.sh OpenNest.plist \
    android/AndroidManifest.xml

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    triangle.cpp \
    remotestate.cpp

RESOURCES += qml.qrc

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick1applicationviewer/qtquick1applicationviewer.pri)
# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    triangle.h \
    remotestate.h

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
