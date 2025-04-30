#include "analogclockwidget.h"

#include <QPainter>
#include <QTimer>
#include <qdatetime.h>

AnalogClockWidget::AnalogClockWidget(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AnalogClockWidget::move);
    timer->setInterval(1000);
    timer->start();
    w = 300;
    h = 300;
    hoursHandPen = QPen(QColor::fromRgb(134, 134, 134));
    minutesHandPen = QPen(QColor::fromRgb(134, 134, 134));
    secondsHandPen = QPen(QColor::fromRgb(134, 134, 134));
    clockFace = QBrush(Qt::white);
    outlinePen = QPen(QColor::fromRgb(255, 255, 255));
    secondsIndicatorsPen = QPen(Qt::black);
    hoursIndicatorsPen = QPen(Qt::black, 4);
    hoursNumbersPen = QPen(Qt::black);
}

AnalogClockWidget::~AnalogClockWidget()
{

}

void AnalogClockWidget::setHoursHandPen(const QPen &pen)
{
    hoursHandPen = pen;
}

void AnalogClockWidget::setMinutesHandPen(const QPen &pen)
{
    minutesHandPen = pen;
}

void AnalogClockWidget::setSecondsHandPen(const QPen &pen)
{
    secondsHandPen = pen;
}

QPen AnalogClockWidget::getHoursHandPen() const
{
    return hoursHandPen;
}

QPen AnalogClockWidget::getMinutesHandPen() const
{
    return minutesHandPen;
}

QPen AnalogClockWidget::getSecondsHandPen() const
{
    return secondsHandPen;
}

QBrush AnalogClockWidget::getClockFace() const
{
    return clockFace;
}

void AnalogClockWidget::setClockFace(const QBrush &newClockFace)
{
    clockFace = newClockFace;
}

int AnalogClockWidget::getRotation() const
{
    return rotation;
}

void AnalogClockWidget::setRotation(int newRotation)
{
    rotation = newRotation;
}

double AnalogClockWidget::getHoursHandLengthFactor() const
{
    return hoursHandLengthFactor;
}

void AnalogClockWidget::setHoursHandLengthFactor(double newHoursHandLengthFactor)
{
    hoursHandLengthFactor = newHoursHandLengthFactor;
}

double AnalogClockWidget::getMinutesHandLengthFactor() const
{
    return minutesHandLengthFactor;
}

void AnalogClockWidget::setMinutesHandLengthFactor(double newMinutesHandLengthFactor)
{
    minutesHandLengthFactor = newMinutesHandLengthFactor;
}

double AnalogClockWidget::getSecondsHandLengthFactor() const
{
    return secondsHandLengthFactor;
}

void AnalogClockWidget::setSecondsHandLengthFactor(double newSecondsHandLengthFactor)
{
    secondsHandLengthFactor = newSecondsHandLengthFactor;
}

bool AnalogClockWidget::getDrawSecondsIndicators() const
{
    return drawSecondsIndicators;
}

void AnalogClockWidget::setDrawSecondsIndicators(bool newDrawSecondsIndicators)
{
    drawSecondsIndicators = newDrawSecondsIndicators;
}

bool AnalogClockWidget::getDrawHoursIndicators() const
{
    return drawHoursIndicators;
}

void AnalogClockWidget::setDrawHoursIndicators(bool newDrawHoursIndicators)
{
    drawHoursIndicators = newDrawHoursIndicators;
}

bool AnalogClockWidget::getDrawHoursNumbers() const
{
    return drawHoursNumbers;
}

void AnalogClockWidget::setDrawHoursNumbers(bool newDrawHoursNumbers)
{
    drawHoursNumbers = newDrawHoursNumbers;
}

void AnalogClockWidget::paintBody(QPainter& painter)
{
    painter.setBrush(clockFace);
    painter.setPen(outlinePen);
    painter.drawEllipse(QRect(width() / 2 - w / 2, height() / 2 - h / 2, w, h));
}

void AnalogClockWidget::paintHoursHand(QPainter &painter)
{
    painter.setPen(hoursHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*hoursHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("h").toInt())/12 + rotation) + width() / 2,
                     (h*hoursHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("h").toInt())/12 + rotation) + height() / 2);
}

void AnalogClockWidget::paintMinutesHand(QPainter& painter)
{
    painter.setPen(minutesHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*minutesHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("mm").toInt())/60 + rotation) + width() / 2,
                     (h*minutesHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("mm").toInt())/60 + rotation) + height() / 2);
}

void AnalogClockWidget::paintSecondsHand(QPainter &painter)
{
    painter.setPen(secondsHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*secondsHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("ss").toInt())/60 + rotation) + width() / 2,
                     (h*secondsHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("ss").toInt())/60 + rotation) + height() / 2);
}

void AnalogClockWidget::paintSecondsIndicators(QPainter &painter)
{
    painter.setPen(secondsIndicatorsPen);
    for(int i = 0 ; i < 60; i++)
    {
        painter.drawLine(w/2 * cos((2*M_PI*i)/60 + rotation) + width() / 2,  h/2 * sin((2*M_PI*i)/60 + rotation) + height() / 2,
                         (w*secondsIndicatorsScale)/2 * cos((2*M_PI*i)/60 + rotation) + width() / 2, (h*secondsIndicatorsScale)/2 * sin((2*M_PI*i)/60 + rotation) + height() / 2);
    }
}

void AnalogClockWidget::paintHoursIndicators(QPainter &painter)
{
    painter.setPen(hoursIndicatorsPen);
    for(int i = 0 ; i < 12; i++)
    {
        painter.drawLine(w/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2,  h/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2,
                         (w*hoursIndicatorsScale)/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2, (h*hoursIndicatorsScale)/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2);
    }
}

void AnalogClockWidget::paintHoursNumbers(QPainter &painter)
{
    painter.setPen(hoursNumbersPen);
    for(int i = 0 ; i < 12; i++)
    {
        painter.drawText(QPoint((w-20)/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2,  (h-20)/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2), QString::number(i));
    }
}

void AnalogClockWidget::paintCenterPoint(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(width() / 2 - w*centerPointScale/2, height() / 2 -  w*centerPointScale/2,  w*centerPointScale,  w*centerPointScale);
}

bool AnalogClockWidget::getDrawHoursHand() const
{
    return drawHoursHand;
}

void AnalogClockWidget::setDrawHoursHand(bool newDrawHoursHand)
{
    drawHoursHand = newDrawHoursHand;
}

bool AnalogClockWidget::getDrawMinutesHand() const
{
    return drawMinutesHand;
}

void AnalogClockWidget::setDrawMinutesHand(bool newDrawMinutesHand)
{
    drawMinutesHand = newDrawMinutesHand;
}

bool AnalogClockWidget::getDrawSecondsHand() const
{
    return drawSecondsHand;
}

void AnalogClockWidget::setDrawSecondsHand(bool newDrawSecondsHand)
{
    drawSecondsHand = newDrawSecondsHand;
}

bool AnalogClockWidget::getDrawBody() const
{
    return drawBody;
}

void AnalogClockWidget::setDrawBody(bool newDrawBody)
{
    drawBody = newDrawBody;
}

bool AnalogClockWidget::getDrawCenterPoint() const
{
    return drawCenterPoint;
}

void AnalogClockWidget::setDrawCenterPoint(bool newDrawCenterPoint)
{
    drawCenterPoint = newDrawCenterPoint;
}

QPen AnalogClockWidget::getOutlinePen() const
{
    return outlinePen;
}

void AnalogClockWidget::setOutlinePen(const QPen &newOutlinePen)
{
    outlinePen = newOutlinePen;
}

QPen AnalogClockWidget::getSecondsIndicatorsPen() const
{
    return secondsIndicatorsPen;
}

void AnalogClockWidget::setSecondsIndicatorsPen(const QPen &newSecondsIndicatorsPen)
{
    secondsIndicatorsPen = newSecondsIndicatorsPen;
}

QPen AnalogClockWidget::getHoursIndicatorsPen() const
{
    return hoursIndicatorsPen;
}

void AnalogClockWidget::setHoursIndicatorsPen(const QPen &newHoursIndicatorsPen)
{
    hoursIndicatorsPen = newHoursIndicatorsPen;
}

QPen AnalogClockWidget::getHoursNumbersPen() const
{
    return hoursNumbersPen;
}

void AnalogClockWidget::setHoursNumbersPen(const QPen &newHoursNumbersPen)
{
    hoursNumbersPen = newHoursNumbersPen;
}

double AnalogClockWidget::getSecondsIndicatorsScale() const
{
    return secondsIndicatorsScale;
}

void AnalogClockWidget::setSecondsIndicatorsScale(double newSecondsIndicatorsScale)
{
    secondsIndicatorsScale = newSecondsIndicatorsScale;
}

double AnalogClockWidget::getHoursIndicatorsScale() const
{
    return hoursIndicatorsScale;
}

void AnalogClockWidget::setHoursIndicatorsScale(double newHoursIndicatorsScale)
{
    hoursIndicatorsScale = newHoursIndicatorsScale;
}

double AnalogClockWidget::getCenterPointScale() const
{
    return centerPointScale;
}

void AnalogClockWidget::setCenterPointScale(double newCenterPointScale)
{
    centerPointScale = newCenterPointScale;
}

double AnalogClockWidget::getClockScale() const
{
    return clockScale;
}

void AnalogClockWidget::setClockScale(double newClockScale)
{
    clockScale = newClockScale;
}

int AnalogClockWidget::getW() const
{
    return w;
}

int AnalogClockWidget::getH() const
{
    return h;
}

void AnalogClockWidget::move()
{
    repaint();
}

void AnalogClockWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    w = (height() < width() ? height() : width())*clockScale;
    h = (height() < width() ? height() : width())*clockScale;
    if(drawBody) paintBody(painter);
    if(drawHoursHand) paintHoursHand(painter);
    if(drawMinutesHand) paintMinutesHand(painter);
    if(drawSecondsHand) paintSecondsHand(painter);
    if(drawSecondsIndicators) paintSecondsIndicators(painter);
    if(drawHoursIndicators) paintHoursIndicators(painter);
    if(drawHoursNumbers) paintHoursNumbers(painter);
    if(drawCenterPoint) paintCenterPoint(painter);
}
