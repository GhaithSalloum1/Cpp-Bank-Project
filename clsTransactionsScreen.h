#pragma once
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsTransferScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTransferLogScreen.h"
#include"clsTotalBalancesScreen.h"

class clsTransactionsScreen : protected clsScreen
{

private:


    enum enTransactionOptions {
        Deposit = 1, Withrdraw = 2, TotalBalance = 3,Transfer = 4,
        TransferLog = 5, MainMenu = 6,
    };

    static short _ReadTransactionOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transcations Menu...\n";

        system("pause>0");
        ShowTransactionsScreen();
    }

    static void _ShowDepositScreen() {
        clsDepositScreen::ShowDepositScreen();

    }

    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();

    }

    static void _ShowTotalBalanceScreen() {
        clsTotalBalancesScreen::ShowTotalBalances();

    }

    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();

    }

    static void _ShowTransferLogScreen() {
        clsTransferLogScreen::ShowTransferLogScreen();

    }


    static void _PerformTransactionsMenuOptions(enTransactionOptions TransactionsOption) {

        switch (TransactionsOption)
        {
        case clsTransactionsScreen::Deposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::Withrdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::TotalBalance:
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::Transfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionMenu();
            break;
        case clsTransactionsScreen::TransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenu();
        case clsTransactionsScreen::MainMenu:
            system("cls");
            
            break;
        default:
            break;
        }


    }

public:

	static void ShowTransactionsScreen() {

        system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

		_DrawScreenHeader("\t  Transactions Screen");
         
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionsMenuOptions((enTransactionOptions)_ReadTransactionOption());
	}


};

