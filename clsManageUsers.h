#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsFindUserScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include<iomanip>

class clsManageUsers : protected clsScreen
{

private:

    enum enManageUsers {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5
        , eMainMenu = 6
    };

    static short _ReadManageUsersOptions() {

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return choice;
    }

    static void _GoBackToManageUsersMenu(){
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";

        system("pause>0");
        ShowManageUsersScreen();
    
    }

    static void _ShowListUsersScreen() {
        clsListUsersScreen::ShowUsersList();

    }

    static void _ShowAddUsersScreen() {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUsersScreen() {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUsersScreen() {
        clsUpdateUserScreen::ShowUpdateUserScreen();

    }

    static void _ShowFindUsersScreen() {
        clsFindUserScreen::ShowFindUserScreen();

    }


    static void _PerformManageUserOption(enManageUsers enChoice) {

        switch (enChoice)
        {
        case clsManageUsers::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsers::eAddNewUser:
            system("cls");
            _ShowAddUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsers::eDeleteUser:
            system("cls");
            _ShowDeleteUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsers::eUpdateUser:
            system("cls");
            _ShowUpdateUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsers::eFindUser:
            system("cls");
            _ShowFindUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsers::eMainMenu:
            system("cls");
            break;
        default:
            break;
        }

    }

public:

	static void ShowManageUsersScreen() {

		clsScreen::_DrawScreenHeader("Manage Users");

        system("cls");

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUserOption((enManageUsers)_ReadManageUsersOptions());
	}



};

