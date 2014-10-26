#include "remotestate.h"

RemoteState::RemoteState(QObject *parent) :
    QObject(parent), m_heat(false), m_cool(false), m_fan(false)
{
}
