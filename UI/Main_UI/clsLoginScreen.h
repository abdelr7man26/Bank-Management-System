#pragma once

#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsBankUsers.h"
#include <iomanip>
#include "clsMainMenueScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        short tries = 0;

        string Username, Password;
        do
        {  
            if (tries == 3)
            {
                cout << "you are out of tries.";
                return false;
            }

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                
               
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsBankUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            tries++;

        } while (LoginFaild);

        CurrentUser._saveLogHistoryToFile();
           
        clsMainMenueScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
