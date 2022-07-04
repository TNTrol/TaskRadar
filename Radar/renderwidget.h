#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>

class RenderWidget: public QWidget
{
    Q_OBJECT
public:
    RenderWidget();
    void setAngle(float angle);
protected:
    void paintEvent(QPaintEvent *e) override;
protected:
    QImage m_img;
    float m_sin;
    float m_cos;
};

#endif // RENDERWIDGET_H
