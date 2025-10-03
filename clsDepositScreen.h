#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter An Account Number? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:


    static void ShowDepositScreen() {

        _DrawScreenHeader("\t   Deposit Screen");


        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] doesn't exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter the amount you want to deposit: ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'n';

        cout << "\nAre you sure you want to do this transaction y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Succesfully.";
            cout << "\nNew Balance Is: " << Client.AccountBalance;
        }
        else
        {
            cout << "\nOperation was canceled.\n";
        }

    }



};

