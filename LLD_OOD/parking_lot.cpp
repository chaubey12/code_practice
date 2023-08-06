#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum PaymentStatus{
    COMPLETED,
    FAILED,
    PENDING,
    UNPAID,
    REFUNDED
};

enum AccountStatus{
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

class Person{
    private:
        string name;
        string address;
        string phone;
        string email;
};

class Address{
    private:
        int zipCode;
        string address;
        string city;
        string state;
        string country;
};

class Vehicle{
    private:
        string licenseNo;
    public:
        void virtual assignTicket(ParkingTicket ticet) = 0;
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



class ParkingSpot{
    private:
        int id;
        bool isFree;
        Vehicle vehicle;
    public:
        bool isFree();
        virtual bool assignVehicle(Vehicle vehicle) = 0;
        bool removeVehicle();
};

class Handicapped : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle vehicle){

        }
};

class Compact : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle vehicle){

        }
};

class Large : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle vehicle){

        }
};

class MotorCycle : public ParkingSpot{
    public:
        bool assignVehicle(Vehicle vehicle){

        }
};

class Account {
    private:
        string userName;
        string password;
        Person person;
        AccountStatus status;
    public:
        virtual bool resetPassword() = 0;
};


class Admin : public Account{
    public:
        bool addParkingSpot(ParkingSpot spot);
        bool addDisplayBoard(DisplayBoard displayBoard);
        bool addEntrance(Entrance entrance);
        bool addExit(Exit exit);
        bool resetPassword(){

        }
};

class ParkingAttendant : public Account{
    public:
        bool processTicket(string ticketNumber){

        }

        bool resetPassword(){

        }
};

class DisplayBoard{
    private:
        int id;
        vector<Handicapped> handicappedSpot;
        vector<Compact> compactSpot;
        vector<Large> largeSpot;
        vector<MotorCycle> motorCycleSpot;

    public:
        void showFreeSlot();
};

class ParkingRate{
    private:
        double hours;
        double rate;
    public:
        void calculate();
};

class Entrance{
    private:
        int id;
    public:
        ParkingTicket getTicket();
};

class Exit{
    private:
        int id;
    public:
        void validateTicket(ParkingTicket ticket){

        }
};

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

class Payment{
    private:
        double amount;
        PaymentStatus status;
        time_t timestamp;
    
    public:
        virtual bool initiaiteTransaction() = 0;
};

class Cash : public Payment{
    public: 
        bool initiateTransaction(){

        }
};

class CreditCard : public Payment{
    public:
        bool initiateTransaction(){

        }
};


class ParkingLot{
    private:
        int id;
        string name;
        string address;
        ParkingRate parkingRate;
        map<string, Entrance> entrance;
        map<string, Exit> exit;
        map<string, ParkingTicket> tickets;

        static ParkingLot parkingLot = nullptr;
        ParkingLot(){

        }
    public:
        static ParkingLot getInstance(){
            if(parkingLot == nullptr){
                parkingLot = new ParkingLot();
            }
            return parkingLot;
        }
        bool addEntrance(Entrance entrance) {}
        bool addExit(Exit exit) {}

        ParkingTicket getParkingTicket(Vehicle vehicle) {}

        bool isFull(ParkingSpot type) {}
};