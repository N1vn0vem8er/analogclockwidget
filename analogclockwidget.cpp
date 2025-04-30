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

bool AnalogClockWidget::getDrawSecondsLines() const
{
    return drawSecondsLines;
}

void AnalogClockWidget::setDrawSecondsLines(bool newDrawSecondsLines)
{
    drawSecondsLines = newDrawSecondsLines;
}

bool AnalogClockWidget::getDrawHoursLines() const
{
    return drawHoursLines;
}

void AnalogClockWidget::setDrawHoursLines(bool newDrawHoursLines)
{
    drawHoursLines = newDrawHoursLines;
}

bool AnalogClockWidget::getDrawHoursNumbers() const
{
    return drawHoursNumbers;
}

void AnalogClockWidget::setDrawHoursNumbers(bool newDrawHoursNumbers)
{
    drawHoursNumbers = newDrawHoursNumbers;
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
    w = (height() < width() ? height() : width())*0.6;
    h = (height() < width() ? height() : width())*0.6;
    painter.setBrush(clockFace);
    painter.setPen(outlinePen);
    painter.drawEllipse(QRect(width() / 2 - w / 2, height() / 2 - h / 2, w, h));
    painter.setPen(hoursHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*hoursHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("h").toInt())/12 + rotation) + width() / 2,
                     (h*hoursHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("h").toInt())/12 + rotation) + height() / 2);
    painter.setPen(minutesHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*minutesHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("mm").toInt())/60 + rotation) + width() / 2,
                     (h*minutesHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("mm").toInt())/60 + rotation) + height() / 2);
    painter.setPen(secondsHandPen);
    painter.drawLine(width() / 2, height() / 2, (w*secondsHandLengthFactor)/2 * cos((2*M_PI*QDateTime::currentDateTime().toString("ss").toInt())/60 + rotation) + width() / 2,
                     (h*secondsHandLengthFactor)/2 * sin((2*M_PI*QDateTime::currentDateTime().toString("ss").toInt())/60 + rotation) + height() / 2);
    if(drawSecondsLines) for(int i = 0 ; i < 60; i++)
        {
            painter.drawLine(w/2 * cos((2*M_PI*i)/60 + rotation) + width() / 2,  h/2 * sin((2*M_PI*i)/60 + rotation) + height() / 2,
                             (w*0.95)/2 * cos((2*M_PI*i)/60 + rotation) + width() / 2, (h*0.95)/2 * sin((2*M_PI*i)/60 + rotation) + height() / 2);
        }
    if(drawHoursLines) for(int i = 0 ; i < 12; i++)
        {
            painter.setPen(QPen(Qt::black, 4));
            painter.drawLine(w/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2,  h/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2,
                             (w*0.95)/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2, (h*0.95)/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2);
        }
    if(drawHoursNumbers) for(int i = 0 ; i < 12; i++)
        {
            painter.setPen(QPen(Qt::black, 4));
            painter.drawText(QPoint((w-20)/2 * cos((2*M_PI*i)/12 + rotation) + width() / 2,  (h-20)/2 * sin((2*M_PI*i)/12 + rotation) + height() / 2), QString::number(i));
        }
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(width() / 2 - 2, height() / 2 - 2, 4, 4);
}
