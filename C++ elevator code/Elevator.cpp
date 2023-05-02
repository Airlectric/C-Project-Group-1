#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Elevator.h"


int main() {
    Elevator elevator(5, 10);
    elevator.board_passenger(3, 8);
    elevator.board_passenger(5, 1);
    elevator.board_passenger(7, 6);
    elevator.board_passenger(2, 10);
    elevator.board_passenger(9, 4);

    cout << "Starting at floor " << elevator.get_curr_floor() << endl;

    elevator.move_to_destination();
    cout << "Elevator at floor " << elevator.get_curr_floor() << endl;
    cout << "Passenger destinations: ";
    for (auto dest : elevator.get_passenger_destinations()) {
        cout << dest << " ";
    }
    cout << endl;

    elevator.move_to_destination();
    cout << "Elevator at floor " << elevator.get_curr_floor() << endl;
    cout << "Passenger destinations: ";
    for (auto dest : elevator.get_passenger_destinations()) {
        cout << dest << " ";
    }
    cout << endl;

    elevator.move_to_destination();
    cout << "Elevator at floor " << elevator.get_curr_floor() << endl;
    cout << "Passenger destinations: ";
    for (auto dest : elevator.get_passenger_destinations()) {
        cout << dest << " ";
    }
    cout << endl;

    elevator.move_to_destination();
    cout << "Elevator at floor " << elevator.get_curr_floor() << endl;
    cout << "Passenger destinations: ";
    for (auto dest : elevator.get_passenger_destinations()) {
        cout << dest << " ";
    }
    cout << endl;

    elevator.move_to_destination();
    cout << "Elevator at floor " << elevator.get_curr_floor() << endl;
    cout << "Passenger arrived at destination.";
    for (auto dest : elevator.get_passenger_destinations()) {
        cout << dest << " ";
    }
    cout << endl;



    return 0;
}


