#include "renderwidget.h"
#include "qpainter.h"
#include <QString>
#include <QMatrix2x2>
#include <math.h>

RenderWidget::RenderWidget(): m_img("../ptr3.png")
{
}

void RenderWidget::setAngle(float angle)
{
    m_angle = angle;
}

void RenderWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    float x, y, _cos, _sin;
    float r1 = width() / 2.5f;
    float r2 =  height() / 2.5f;
    QFont font;
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(QPen(Qt::black, 3, Qt::DashDotDotLine));
    painter.drawEllipse(QRect(width()/2 - r1, height()/2 - r2, r1*2, r2*2));
    for(int angle = 0; angle < 360; angle += 30)
    {
        _cos = cos((angle-90) * 3.14f / 180);
        _sin =  sin((angle - 90) * 3.14f / 180);
        x = (width()/2  + (width()/2.1f) * _cos);
        y = (height()/2 + (height()/2.1f) * _sin);
        painter.drawLine(width()/2, height()/2, x, y);
        painter.drawText(QPoint(x, y), QString::number(angle));
    }
    QTransform transform_centerOfWindow( 1, 0, 0, 1, width()/2, height()/2 );
    transform_centerOfWindow.scale(0.3 * width() / (height() *1.0f), 0.3);
    transform_centerOfWindow.rotate( m_angle );
    painter.setTransform( transform_centerOfWindow );
    painter.drawImage( -m_img.width()/2, -m_img.height()/2, m_img );

}
