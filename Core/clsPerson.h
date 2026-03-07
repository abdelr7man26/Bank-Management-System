#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
protected :
	string _firstName;
	string _lastName;
	string _phoneNumber;
	string _email;
public:
	clsPerson(string firstName, string lastName, string phoneNumber, string email)
	: _firstName(firstName), _lastName(lastName), _phoneNumber(phoneNumber), _email(email) {}

	virtual ~clsPerson() = default;

	void setFirstName(string firstName) {
		_firstName = firstName;
	}
	string getFirstName() {
		return _firstName;
	}
	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;


	void setLastName(string lastName) {
		_lastName = lastName;
	}
	string getLastName() {
		return _lastName;
	}
	__declspec(property(get = getLastName, put = setLastName)) string lastName;


	void setPhoneNumber(string phoneNumber) {
		_phoneNumber = phoneNumber;
	}
	string getPhoneNumber() {
		return _phoneNumber;
	}
	__declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string phoneNumber;


	void setEmail(string email) {
		_email = email;
	}
	string getEmail() {
		return _email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string email;


	string fullName() {
		return _firstName + " " + _lastName;
	}

};

