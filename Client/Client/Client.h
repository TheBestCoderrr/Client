#pragma once
#include "String.h"
using namespace std;
class Client
{
public:
	void setFname(String Fname);
	String getFname();
	void setLname(String Lname);
	String getLname();
	void setHomeAdress(String HomeAdress);
	String getHomeAdress();
	void setPhoneNumber(size_t PhoneNumber);
	size_t getPhoneNumber();
	void setItem(String item);
	String getItem();
private:
	String FirstName;
	String LastName;
	String HomeAdress;
	size_t PhoneNumber;
	String item;
	friend istream& operator>>(istream& in, Client& client);
};

inline ostream& operator<<(ostream& out, Client& client){
	out << "Firstname: " << client.getFname().GetStr() << endl;
	out << "Lastname: " << client.getLname().GetStr() << endl;
	out << "Home adress: " << client.getHomeAdress() << endl;
	out << "Phone number: " << client.getPhoneNumber() << endl;
	out << "Item: " << client.getItem() << endl << endl;
	return out;
}

inline istream& operator>>(istream& in,Client& client) {
	in.ignore();
	cout << "Enter firstname: ";
	in >> client.FirstName;
	
	cout << "Enter lastname: ";
	in >> client.LastName;
	
	cout << "Enter home adress: ";
	in >> client.HomeAdress;
	
	cout << "Enter phone number: ";
	in >> client.PhoneNumber;
	
	cout << "Enter item: ";
	in.ignore();
	in >> client.item;
	return in;
}

