#include "triangle.h"
#include <QRectF>
#include <QColor>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QPen>

class QStyleOptionGraphicsItem;
class QWidget;

Triangle::Triangle(QDeclarativeItem *parent) :
    QDeclarativeItem(parent), m_color(QColor("#CCCCCC")), m_borderColor(QColor("#CCCCCC")), m_dp(1.0)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
    QRectF size = parent->boundingRect();

    setWidth(size.width());
    setHeight(size.height());
}

void Triangle::paint (QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);

    QRectF rect = boundingRect();
    QPen pen = QPen(m_borderColor);
    pen.setWidthF(10 * m_dp);
    pen.setJoinStyle(Qt::RoundJoin);


    QPainterPath path;
    if(parentItem()->property("direction").toInt() == 1)
    {
        path.moveTo(5 * m_dp, rect.height() - 5 * m_dp);
        path.lineTo(rect.width() / 2, 5 * m_dp);
        path.lineTo(rect.width() - 5 * m_dp, rect.height() - 5 * m_dp);
        path.lineTo(5 * m_dp, rect.height() - 5 * m_dp);
    }
    else
    {
         path.moveTo(5 * m_dp, 5 * m_dp);
         path.lineTo(rect.width() / 2, rect.height() - 5 * m_dp);
         path.lineTo(rect.width() - 5 * m_dp, 5 * m_dp);
         path.lineTo(5 * m_dp, 5 * m_dp);
    }

    painter->fillPath(path, m_color);
    painter->strokePath(path, pen);
}
