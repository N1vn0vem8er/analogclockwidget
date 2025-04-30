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
    bool getDrawSecondsLines() const;
    void setDrawSecondsLines(bool newDrawSecondsLines);
    bool getDrawHoursLines() const;
    void setDrawHoursLines(bool newDrawHoursLines);
    bool getDrawHoursNumbers() const;
    void setDrawHoursNumbers(bool newDrawHoursNumbers);

private:
    int w, h;
    QPen outlinePen;
    QTimer* timer = nullptr;
    QPen hoursHandPen;
    QPen minutesHandPen;
    QPen secondsHandPen;
    QBrush clockFace;
    int rotation = 11;
    double hoursHandLengthFactor = 0.6;
    double minutesHandLengthFactor = 0.8;
    double secondsHandLengthFactor = 1;

    bool drawSecondsLines = true;
    bool drawHoursLines = true;
    bool drawHoursNumbers = false;

private slots:
    void move();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ANALOGCLOCKWIDGET_H
