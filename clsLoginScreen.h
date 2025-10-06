#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{


private:

    static bool _Login()
    {
        bool LoginFaild = false;
        short counter = 3;

        string Username, Password;
        do
        {


            if (LoginFaild)
            {
                counter--;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << counter << " Trials to login.\n";
            }

            if (counter == 0)
            {
                cout << "\nYou're locked after 3 failed trials!";
                return 0;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

 

        } while (LoginFaild);

        clsMainScreen::ShowMainMenue();

    }


public:



    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }


};

