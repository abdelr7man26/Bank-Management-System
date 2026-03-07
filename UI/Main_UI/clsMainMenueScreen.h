#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "Clients_UI/clsCLientsListScreen.h"
#include "Clients_UI/clsAddClient.h"
#include "Clients_UI/clsDeleteClientScreen.h"
#include "Clients_UI/clsUpdateClientScreen.h"
#include "Clients_UI/clsFindClientScreen.h"
#include "Transactions_UI/clsTransactionsMenueScreen.h"
#include "Users_UI/clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsLogHistoryScreen.h"
#include "Currancy_UI/clsCurrencyScreen.h"

using namespace std;

class clsMainMenueScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLogHistory = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = short(clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? "));
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsCLientsListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
       clsAddClient::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::deleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::updateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClient();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowLogHistoryScreen()
    {
        clsLogHistoryScreen::showLogHistoryScreen();
    }

    static void _showCurrencyExhangeScreen() {
        clsCurrencyScreen::ShowCurrenciesMenue();
    }

    static void _ShowEndScreen()
    {
        CurrentUser = clsBankUser::emptyUser();

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            
            ShowMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
           
            ShowMainMenue();
            break;
        case enMainMenueOptions::eLogHistory:
            system("cls");
            _ShowLogHistoryScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _showCurrencyExhangeScreen();
            ShowMainMenue();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Log History.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};
