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
#include "triangle.h"
#include "remotestate.h"
#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <QDeclarativeContext>
#include <QDebug>

class QDeclarativeItem;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QtQuick1ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("dp", 1);
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QtQuick1ApplicationViewer::ScreenOrientationLockLandscape);
    viewer.setMainQmlFile(QLatin1String("qrc:/opennest/qml/nest.qml"));
    viewer.showExpanded();

    QSizeF size = QSizeF(QApplication::desktop()->screenGeometry().size());
    QGraphicsObject *rootObject = viewer.rootObject();

    qDebug() << QApplication::primaryScreen()->devicePixelRatio();
    if(size.width() / 320.0 <= size.height() / 240.0)
    {
        float ratio = size.width() / 320.0;
        viewer.rootContext()->setContextProperty("dp", ratio);
        qDebug() << "Scaling " << ratio;
    }
    else
    {
        float ratio = size.height() / 240.0;
        viewer.rootContext()->setContextProperty("dp", ratio);
        qDebug() << "Scaling " << ratio;
    }

    QDeclarativeItem *upArrow = rootObject->findChild<QDeclarativeItem *>("upArrow");
    Triangle up(upArrow);

    QDeclarativeItem *downArrow = rootObject->findChild<QDeclarativeItem *>("downArrow");
    Triangle down(downArrow);

    QDeclarativeItem *thermostatView = rootObject->findChild<QDeclarativeItem *>("thermostatView");
    RemoteState remote(thermostatView);

    return app.exec();
}
