#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Elevator {
public:

    Elevator(int capacity, int num_floors, int curr_floor = 1);


    bool board_passenger(int floor, int destination);
    void move_to_destination();
    void announce_current_floor() const;


    int get_capacity() const;
    int get_num_floors() const;
    int get_curr_floor() const;
    vector<int> get_passenger_floors() const;
    vector<int> get_passenger_destinations() const;
    void set_capacity(int capacity);
    void set_num_floors(int num_floors);
    void set_curr_floor(int curr_floor);

private:
    int capacity_;
    int num_floors_;
    int curr_floor_;
    vector<int> passenger_floors_;
    vector<int> passenger_destinations_;


    bool is_valid_floor(int floor) const;
    void remove_arrived_passengers();
};


Elevator::Elevator(int capacity, int num_floors, int curr_floor)
    : capacity_(capacity), num_floors_(num_floors), curr_floor_(curr_floor) {}



bool Elevator::board_passenger(int floor, int destination) {
    if (!is_valid_floor(floor) || !is_valid_floor(destination) ||
        floor == destination || passenger_floors_.size() >= capacity_) {
        return false;
    }
    passenger_floors_.push_back(floor);
    passenger_destinations_.push_back(destination);
    return true;
}

void Elevator::move_to_destination() {
    if (passenger_floors_.empty()) {
        return;
    }
    int destination = *min_element(passenger_destinations_.begin(), passenger_destinations_.end());
    int direction = (destination > curr_floor_) ? 1 : -1;
    while (curr_floor_ != destination) {
        curr_floor_ += direction;
        announce_current_floor();
    }
    remove_arrived_passengers();
}

void Elevator::announce_current_floor() const {
    cout << "Elevator at floor " << curr_floor_ << endl;
}



int Elevator::get_capacity() const {
    return capacity_;
}

int Elevator::get_num_floors() const {
    return num_floors_;
}

int Elevator::get_curr_floor() const {
    return curr_floor_;
}

vector<int> Elevator::get_passenger_floors() const {
    return passenger_floors_;
}

vector<int> Elevator::get_passenger_destinations() const {
    return passenger_destinations_;
}

void Elevator::set_capacity(int capacity) {
    capacity_ = capacity;
}

void Elevator::set_num_floors(int num_floors) {
    num_floors_ = num_floors;
}

void Elevator::set_curr_floor(int curr_floor) {
    curr_floor_ = curr_floor;
}



bool Elevator::is_valid_floor(int floor) const {
    return floor >= 1 && floor <= num_floors_;
}

void Elevator::remove_arrived_passengers() {
    auto it = passenger_destinations_.begin();
    while (it != passenger_destinations_.end()) {
        if (*it == curr_floor_) {
            it = passenger_destinations_.erase(it);
            passenger_floors_.erase(passenger_floors_.begin() + (it - passenger_destinations_.begin()));
        } else {
            ++it;
        }
    }
}


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


