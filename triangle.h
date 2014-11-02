#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QDeclarativeItem>
class QColor;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class Triangle : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
    Q_PROPERTY(double dp READ dp WRITE setDp)

public:
    explicit Triangle(QDeclarativeItem *parent = 0);

    QColor color() const
    {
        return m_color;
    }

    void setColor(const QColor& color)
    {
        m_color = color;
        update();
    }

    QColor borderColor() const
    {
        return m_borderColor;
    }

    void setBorderColor(const QColor& borderColor)
    {
        m_borderColor = borderColor;
        update();
    }

    double dp() const
    {
        return m_dp;
    }

    void setDp(double dp)
    {
        m_dp = dp;
    }

    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

signals:

public slots:

private:
    QColor m_color, m_borderColor;
    double m_dp;
};

#endif // TRIANGLE_H
