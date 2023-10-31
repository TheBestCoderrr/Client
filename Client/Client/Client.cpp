#include <iostream>
#include "Client.h"
using namespace std;
void Client::setFname(String Fname) { FirstName = Fname; }
String Client::getFname() { return FirstName; }

void Client::setLname(String Lname) { LastName = Lname; }
String Client::getLname(){ return LastName; }

void Client::setHomeAdress(String HomeAdress) { this->HomeAdress = HomeAdress; }
String Client::getHomeAdress() { return HomeAdress; }

void Client::setPhoneNumber(size_t PhoneNumber) { this->PhoneNumber = PhoneNumber; }
size_t Client::getPhoneNumber() { return PhoneNumber; }

void Client::setItem(String item){ this->item = item;}
String Client::getItem(){return item;}


