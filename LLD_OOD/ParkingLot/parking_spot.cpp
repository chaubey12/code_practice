#include <iostream>
#include <vector>
#include <string>
#include "vehicle.h"

using namespace std;

class ParkingSpot{
private:
    int id;
    bool isFree;
    Vehicle vehicle;
public:
    bool isFree();
    virtual bool assignVehicle(Vehicle vehicle) = 0;
    bool removeVehicle(){

    }
};

class Handicapped : public ParkingSpot{

};

class Compact : public  ParkingSpot{

};

class Large : public ParkingSpot{

};

class Motorcycle : public ParkingSpot{

};