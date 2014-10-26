#include "remotestate.h"
#include <QVariant>

RemoteState::RemoteState(QObject *parent) :
    QObject(parent), m_heat(false), m_cool(false), m_fan(false), m_temp(72), m_setTemp(70)
{
    parent->setProperty("thermostat", QVariant::fromValue(this));
    emit changed(this);
}
