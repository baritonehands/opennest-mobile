// checksum 0x7a92 version 0x90018
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

#ifndef QTQUICK1APPLICATIONVIEWER_H
#define QTQUICK1APPLICATIONVIEWER_H

#include <QDeclarativeView>

class QtQuick1ApplicationViewer : public QDeclarativeView
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit QtQuick1ApplicationViewer(QWidget *parent = 0);
    virtual ~QtQuick1ApplicationViewer();

    static QtQuick1ApplicationViewer *create();

    void setMainQmlFile(const QString &file);
    void addImportPath(const QString &path);

    // Note that this will only have an effect on Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

private:
    class QtQuick1ApplicationViewerPrivate *d;
};

#endif // QTQUICK1APPLICATIONVIEWER_H
