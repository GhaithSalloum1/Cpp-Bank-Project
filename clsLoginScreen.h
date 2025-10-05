#pragma once
<<<<<<< HEAD
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"

=======
#include <iostream>
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
>>>>>>> 6d8c59c1669a152b1f27dd6e4c033528d77b9a7e


class clsLoginScreen : protected clsScreen
{

<<<<<<< HEAD
private:

	static void _Login() {

		bool LoginFailed = false;

		string Username, Password;
		
		do
		{

			if (LoginFailed)
			{
				cout << "\nInvlaid Username/Password!\n\n";
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();


		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();

	}
=======

private:

    static  void _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
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
>>>>>>> 6d8c59c1669a152b1f27dd6e4c033528d77b9a7e


public:


<<<<<<< HEAD
	static void ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();

	}
=======

    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

>>>>>>> 6d8c59c1669a152b1f27dd6e4c033528d77b9a7e

};

