#ifndef ANALOGCLOCKWIDGET_H
#define ANALOGCLOCKWIDGET_H

#include <QPen>
#include <QWidget>

class AnalogClockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClockWidget(QWidget *parent = nullptr);
    ~AnalogClockWidget();
    void setHoursHandPen(const QPen& pen);
    void setMinutesHandPen(const QPen& pen);
    void setSecondsHandPen(const QPen& pen);
    QPen getHoursHandPen() const;
    QPen getMinutesHandPen() const;
    QPen getSecondsHandPen() const;
    QBrush getClockFace() const;
    void setClockFace(const QBrush &newClockFace);
    int getRotation() const;
    void setRotation(int newRotation);
    double getHoursHandLengthFactor() const;
    void setHoursHandLengthFactor(double newHoursHandLengthFactor);
    double getMinutesHandLengthFactor() const;
    void setMinutesHandLengthFactor(double newMinutesHandLengthFactor);
    double getSecondsHandLengthFactor() const;
    void setSecondsHandLengthFactor(double newSecondsHandLengthFactor);
    bool getDrawSecondsIndicators() const;
    void setDrawSecondsIndicators(bool newDrawSecondsIndicators);
    bool getDrawHoursIndicators() const;
    void setDrawHoursIndicators(bool newDrawHoursIndicators);
    bool getDrawHoursNumbers() const;
    void setDrawHoursNumbers(bool newDrawHoursNumbers);

    int getW() const;
    int getH() const;

    double getClockScale() const;
    void setClockScale(double newClockScale);

protected:
    void paintBody(QPainter &painter);
    void paintHoursHand(QPainter& painter);
    void paintMinutesHand(QPainter& painter);
    void paintSecondsHand(QPainter& painter);
    void paintSecondsIndicators(QPainter& painter);
    void paintHoursIndicators(QPainter& painter);
    void paintHoursNumbers(QPainter& painter);
    void paintCenterPoint(QPainter& painter);

private:
    int w, h;
    QTimer* timer = nullptr;
    QPen outlinePen;
    QPen hoursHandPen;
    QPen minutesHandPen;
    QPen secondsHandPen;
    QPen secondsIndicatorsPen;
    QPen hoursIndicatorsPen;
    QPen hoursNumbersPen;
    QBrush clockFace;
    int rotation = 11;
    double hoursHandLengthFactor = 0.6;
    double minutesHandLengthFactor = 0.8;
    double secondsHandLengthFactor = 1;
    double clockScale = 0.6;

    bool drawSecondsIndicators = true;
    bool drawHoursIndicators = true;
    bool drawHoursNumbers = false;

private slots:
    void move();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ANALOGCLOCKWIDGET_H
