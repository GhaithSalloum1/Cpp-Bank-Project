#pragma once
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:


	//constructor
	clsPerson(string _FirstName, string _LastName, string _Email, string _Phone) 
	{
		this->_FirstName = _FirstName;
		this->_LastName = _LastName;
		this->_Email = _Email;
		this->_Phone = _Phone;
	}

	//sets

	void setFirstName(string _FirsName) {
		this->_FirstName = _FirstName;
	}

	void setLastName(string _LastName) {
		this->_LastName = _LastName;
	}

	void setEmail(string _Email) {
		this->_Email = _Email;
	}

	void setPhone(string _Phone) {
		this->_Phone = _Phone;
	}

	//gets

	string getFirstName() {
		return _FirstName;
	}

	string getLastName() {
		return _LastName;
	}

	string getEmail() {
		return _Email;
	}

	string getPhone() {
		return _Phone;
	}

	// __declspec

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
	__declspec(property(get = getLastName, put = setLastName)) string LastName;
	__declspec(property(get = getEmail, put = setEmail)) string Email;
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

};

