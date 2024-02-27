#include <iostream>
#include <vector>
#include <string>
#include "parking_ticket.h"

using namespace std;

class Vehicle{
private:
    string licenseNo;
public:
    virtual void assignTicket(ParkingTicket ticket) = 0;
};

class Car : public Vehicle{
public:
    void assignTicket(ParkingTicket ticket){

    }
};

class Van : public Vehicle{
public:
    void assignTicket(ParkingTicket ticket){
        
    }
};

class Truck : public Vehicle{
public:
    void assignTicket(ParkingTicket ticket){
        
    }
};

class Motorcycle : public Vehicle{
public:
    void assignTicket(ParkingTicket ticket){
        
    }
};