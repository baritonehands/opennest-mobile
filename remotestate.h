#ifndef REMOTESTATE_H
#define REMOTESTATE_H

#include <QObject>

class RemoteState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool heat READ heat WRITE setHeat)
    Q_PROPERTY(bool cool READ cool WRITE setCool)
    Q_PROPERTY(bool fan READ fan WRITE setFan)
public:
    explicit RemoteState(QObject *parent = 0);

    bool heat() const
    {
        return m_heat;
    }

    void setHeat(bool heat)
    {
        m_heat = heat;
    }

    bool cool() const
    {
        return m_cool;
    }

    void setCool(bool cool)
    {
        m_cool = cool;
    }

    bool fan() const
    {
        return m_fan;
    }

    void setFan(bool fan)
    {
        m_fan = fan;
    }

signals:

public slots:

private:
    bool m_heat, m_cool, m_fan;

};

#endif // REMOTESTATE_H
