# Add more folders to ship with the application, here
folder_01.source = qml2
folder_02.source = ../opennest/icons
fonts.source = fonts
DEPLOYMENTFOLDERS = folder_01 folder_02

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

ios {
    QMAKE_INFO_PLIST = OpenNest.plist
    DEPLOYMENTFOLDERS += fonts
}

OTHER_FILES += copyqml.sh OpenNest.plist

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()
