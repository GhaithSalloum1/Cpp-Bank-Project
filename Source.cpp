#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"


void ReadClientInfo(clsBankClient& Client) {

    cout << "\nEnter First Name: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter Last Name: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Balance: ";
    Client.AccountBalance = clsInputValidate::ReadDblNumber();

}

void UpdateClient() {

    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();


    switch (SaveResult)
    {
    case clsBankClient::svSucceeded:
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    case clsBankClient::svFaildEmptyObject:
        cout << "\nError account was not saved because it's Empty";
        break;
    default:
        break;
    }

}

int main() {


    UpdateClient();

    system("pause>0");
    return 0;
}