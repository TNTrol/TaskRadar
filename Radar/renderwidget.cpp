#include "renderwidget.h"
#include "qpainter.h"
#include <math.h>

RenderWidget::RenderWidget(): m_img("../radian.png")
{
    m_sin = sin(0);
    m_cos = cos(0);
}

void RenderWidget::setAngle(float angle)
{
    m_cos = cos(-angle * 3.14f / 180);
    m_sin = sin(-angle * 3.14f / 180);
}

void RenderWidget::paintEvent(QPaintEvent *e)
{

    float x = (width()/2.0f) * (1 + m_cos);
    float y = (height()/2.0f) * (1 +  m_sin);
    QPainter painter(this);
    painter.drawImage(QRect(0, 0, width(), height()), m_img);
    painter.setPen(QPen(Qt::red, 6));
    painter.drawLine(width()/2, height()/2 + 11, x, y + 11);
}
