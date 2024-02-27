#include <iostream>
#include <string>

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