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
    double getCenterPointScale() const;
    void setCenterPointScale(double newCenterPointScale);
    QPen getOutlinePen() const;
    void setOutlinePen(const QPen &newOutlinePen);
    QPen getSecondsIndicatorsPen() const;
    void setSecondsIndicatorsPen(const QPen &newSecondsIndicatorsPen);
    QPen getHoursIndicatorsPen() const;
    void setHoursIndicatorsPen(const QPen &newHoursIndicatorsPen);
    QPen getHoursNumbersPen() const;
    void setHoursNumbersPen(const QPen &newHoursNumbersPen);
    double getSecondsIndicatorsScale() const;
    void setSecondsIndicatorsScale(double newSecondsIndicatorsScale);
    double getHoursIndicatorsScale() const;
    void setHoursIndicatorsScale(double newHoursIndicatorsScale);
    bool getDrawHoursHand() const;
    void setDrawHoursHand(bool newDrawHoursHand);
    bool getDrawMinutesHand() const;
    void setDrawMinutesHand(bool newDrawMinutesHand);
    bool getDrawSecondsHand() const;
    void setDrawSecondsHand(bool newDrawSecondsHand);
    bool getDrawBody() const;
    void setDrawBody(bool newDrawBody);
    bool getDrawCenterPoint() const;
    void setDrawCenterPoint(bool newDrawCenterPoint);

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
    int w, h;
    double hoursHandLengthFactor = 0.6;
    double minutesHandLengthFactor = 0.8;
    double secondsHandLengthFactor = 1;
    double clockScale = 0.6;
    double centerPointScale = 0.01;
    double secondsIndicatorsScale = 0.95;
    double hoursIndicatorsScale = 0.95;
    bool drawSecondsIndicators = true;
    bool drawHoursIndicators = true;
    bool drawHoursNumbers = false;
    bool drawHoursHand = true;
    bool drawMinutesHand = true;
    bool drawSecondsHand = true;
    bool drawBody = true;
    bool drawCenterPoint = true;

private slots:
    void move();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ANALOGCLOCKWIDGET_H
