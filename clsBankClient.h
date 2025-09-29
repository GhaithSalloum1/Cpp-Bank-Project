#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>


using namespace std;

class clsBankClient : public clsPerson
{

private:

	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1
	};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#") {

		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));


	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {


		string sClientRecord = "";
		sClientRecord += Client.FirstName + Seperator;
		sClientRecord += Client.LastName + Seperator;
		sClientRecord += Client.Email + Seperator;
		sClientRecord += Client.Phone + Seperator;
		sClientRecord += Client.AccountNumber() + Seperator;
		sClientRecord += Client.PinCode + Seperator;
		sClientRecord += to_string(Client.AccountBalance) + Seperator;

		return sClientRecord;
	}

	static  vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}

		return vClients;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(enMode _Mode, string _FirstName, string _LastName, string _Email,
		string _Phone, string _AccountNumber, string _PinCode, float _AccountBalance) 
		: clsPerson(_FirstName, _LastName, _Email, _Phone) {

		this->_Mode = _Mode;
		this->_AccountNumber = _AccountNumber;
		this->_PinCode = _PinCode;
		this->_AccountBalance = _AccountBalance;

	}


	void setPinCode(string _PinCode) {
		this->_PinCode = _PinCode;
	}

	string getPinCode() {
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float _AccountBalance) {
		this->_AccountBalance = _AccountBalance;
	}

	float getAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) string AccountBalance;

	string AccountNumber()
	{
		return _AccountNumber;
	}

};

