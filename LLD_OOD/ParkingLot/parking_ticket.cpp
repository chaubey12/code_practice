#include <iostream>
#include "vehicle.h"

using namespace std;

class ParkingTicket{
private:
    int ticketNo;
    time_t timestamp;
    time_t exit;
    double amount;
    bool status;

    Vehicle vehicle;
    Payment payment;
    Entrance entrance;
    Exit exitIns;
};