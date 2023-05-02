#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class Elevator : public QWidget
{
    Q_OBJECT

public:
    Elevator(QWidget *parent = nullptr);

private:
    QGridLayout *m_layout;
    QSpinBox *m_floorSpinBox;
    QLabel *m_displayLabel;
    QPushButton *m_goButton;

    int m_currentFloor;

private slots:
    void goToFloor();
};
