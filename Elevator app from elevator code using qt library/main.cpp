#include <QtWidgets>

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

Elevator::Elevator(QWidget *parent)
    : QWidget(parent), m_currentFloor(0)
{
    // Create layout for elevator widget
    m_layout = new QGridLayout(this);

    // Create and add floor selection spinbox to layout
    m_floorSpinBox = new QSpinBox(this);
    m_floorSpinBox->setRange(0, 10); // Set range of floors (0-10)
    m_layout->addWidget(m_floorSpinBox, 0, 0);

    // Create and add display label to layout
    m_displayLabel = new QLabel("Current floor: 0", this);
    m_layout->addWidget(m_displayLabel, 1, 0);

    // Create and add go button to layout
    m_goButton = new QPushButton("Go", this);
    m_layout->addWidget(m_goButton, 2, 0);

    // Connect go button to goToFloor() slot
    connect(m_goButton, &QPushButton::clicked, this, &Elevator::goToFloor);
}

void Elevator::goToFloor()
{
    int destinationFloor = m_floorSpinBox->value();

    // Check if destination floor is different than current floor
    if (destinationFloor != m_currentFloor)
    {
        // Update display label with new floor
        m_displayLabel->setText(QString("Moving to floor %1").arg(destinationFloor));

        // Move elevator to destination floor (delayed for demonstration purposes)
        QTimer::singleShot(3000, this, [=]() {
            m_currentFloor = destinationFloor;
            m_displayLabel->setText(QString("Current floor: %1").arg(m_currentFloor));
        });
    }
    else
    {
        // Destination floor is the same as current floor, update display label
        m_displayLabel->setText(QString("Already on floor %1").arg(m_currentFloor));
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Elevator elevator;
    elevator.show();

    return app.exec();
}

#include "main.moc"
