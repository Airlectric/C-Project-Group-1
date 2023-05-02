#include <QtWidgets>
#include "elevator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Elevator elevator;
    elevator.show();

    return app.exec();
}

#include "main.moc"
