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
    QDeclarativeItem(parent), m_color(QColor("#CCCCCC")), m_borderColor(QColor("#CCCCCC"))
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
    pen.setWidthF(10);
    pen.setJoinStyle(Qt::RoundJoin);

    QPainterPath path;
    if(parentItem()->property("direction").toInt() == 1)
    {
        path.moveTo(5, rect.height() - 5);
        path.lineTo(rect.width() / 2, 5);
        path.lineTo(rect.width() - 5, rect.height() - 5);
        path.lineTo(5, rect.height() - 5);
    }
    else
    {
         path.moveTo(5, 5);
         path.lineTo(rect.width() / 2, rect.height() - 5);
         path.lineTo(rect.width() - 5, 5);
         path.lineTo(5, 5);
    }

    painter->fillPath(path, m_color);
    painter->strokePath(path, pen);
}
