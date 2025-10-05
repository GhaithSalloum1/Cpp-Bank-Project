#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"



class clsLoginScreen : protected clsScreen
{

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


public:


	static void ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();

	}

};

