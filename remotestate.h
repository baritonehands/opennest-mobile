#ifndef REMOTESTATE_H
#define REMOTESTATE_H

#include <QObject>

class RemoteState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool heat READ heat WRITE setHeat)
    Q_PROPERTY(bool cool READ cool WRITE setCool)
    Q_PROPERTY(bool fan READ fan WRITE setFan)
    Q_PROPERTY(int temp READ temp)
    Q_PROPERTY(int setTemp READ setTemp WRITE setSetTemp)
public:
    explicit RemoteState(QObject *parent = 0);

    bool heat() const
    {
        return m_heat;
    }

    void setHeat(bool heat)
    {
        m_heat = heat;
        emit changed(this);
    }

    bool cool() const
    {
        return m_cool;
    }

    void setCool(bool cool)
    {
        m_cool = cool;
        emit changed(this);
    }

    bool fan() const
    {
        return m_fan;
    }

    void setFan(bool fan)
    {
        m_fan = fan;
        emit changed(this);
    }

    int setTemp() const
    {
        return m_setTemp;
    }

    void setSetTemp(int setTemp)
    {
        m_setTemp = setTemp;
        emit changed(this);
    }

    int temp() const
    {
        return m_temp;
    }

signals:
    void changed(QObject *obj);

public slots:

private:
    bool m_heat, m_cool, m_fan;
    int m_temp, m_setTemp;
};

#endif // REMOTESTATE_H
