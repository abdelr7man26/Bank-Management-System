#pragma once
#include <iostream>
#include "clsBankUsers.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        dateAndUser();
    }
    
    static bool checkpermission(clsBankUser::enPermissions permission ) {
        
        if (!CurrentUser.CheckAccessPermission(permission)) {

            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        return true;
    }

    static void dateAndUser() {
        if (!CurrentUser.IsEmpty()) {
            cout << "\t\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
        }
        cout << "\t\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << endl;
    }
};

