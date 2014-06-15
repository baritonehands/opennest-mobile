// checksum 0x8000 version 0x90018
/*  OpenNest, an open source thermostat
    Copyright (C) 2014  Brian Gregg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qtquick1applicationviewer.h"

#include <QDir>
#include <QFileInfo>
#include <QApplication>
#include <QDeclarativeComponent>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>

#include <qplatformdefs.h> // MEEGO_EDITION_HARMATTAN

class QtQuick1ApplicationViewerPrivate
{
    QString mainQmlFile;
    friend class QtQuick1ApplicationViewer;
    static QString adjustPath(const QString &path);
};

QString QtQuick1ApplicationViewerPrivate::adjustPath(const QString &path)
{
#if defined(Q_OS_IOS)
    if (!QDir::isAbsolutePath(path))
        return QString::fromLatin1("%1/%2")
                .arg(QCoreApplication::applicationDirPath(), path);
#elif defined(Q_OS_MAC)
    if (!QDir::isAbsolutePath(path))
        return QString::fromLatin1("%1/../Resources/%2")
                .arg(QCoreApplication::applicationDirPath(), path);
#elif defined(Q_OS_BLACKBERRY)
    if (!QDir::isAbsolutePath(path))
        return QString::fromLatin1("app/native/%1").arg(path);
#elif !defined(Q_OS_ANDROID)
    QString pathInInstallDir =
            QString::fromLatin1("%1/../%2").arg(
                QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return pathInInstallDir;
    pathInInstallDir =
            QString::fromLatin1("%1/%2").arg(
                QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return pathInInstallDir;
#endif
    return path;
}

QtQuick1ApplicationViewer::QtQuick1ApplicationViewer(QWidget *parent)
    : QDeclarativeView(parent)
    , d(new QtQuick1ApplicationViewerPrivate())
{
    connect(engine(), SIGNAL(quit()), SLOT(close()));
    setResizeMode(QDeclarativeView::SizeRootObjectToView);
}

QtQuick1ApplicationViewer::~QtQuick1ApplicationViewer()
{
    delete d;
}

QtQuick1ApplicationViewer *QtQuick1ApplicationViewer::create()
{
    return new QtQuick1ApplicationViewer();
}

void QtQuick1ApplicationViewer::setMainQmlFile(const QString &file)
{
    d->mainQmlFile = QtQuick1ApplicationViewerPrivate::adjustPath(file);
#ifdef Q_OS_ANDROID
    setSource(QUrl(QLatin1String("assets:/")+d->mainQmlFile));
#else
    setSource(QUrl::fromLocalFile(d->mainQmlFile));
#endif
}

void QtQuick1ApplicationViewer::addImportPath(const QString &path)
{
    engine()->addImportPath(QtQuick1ApplicationViewerPrivate::adjustPath(path));
}

void QtQuick1ApplicationViewer::setOrientation(ScreenOrientation orientation)
{
#if QT_VERSION < 0x050000
    Qt::WidgetAttribute attribute;
    switch (orientation) {
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
    };
    setAttribute(attribute, true);
#else // QT_VERSION < 0x050000
    Q_UNUSED(orientation)
#endif // QT_VERSION < 0x050000
}

void QtQuick1ApplicationViewer::showExpanded()
{
#if defined(Q_WS_SIMULATOR) || defined(Q_OS_QNX)
    showFullScreen();
#else
    show();
#endif
}
