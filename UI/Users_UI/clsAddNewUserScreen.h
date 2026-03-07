#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUsers.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _readUserInfo(clsBankUser& Client)
    {
        Client.firstName = clsInputValidate::readString("\nEnter FirstName: ");
        Client.lastName = clsInputValidate::readString("\nEnter LastName: ");
        Client.email = clsInputValidate::readString("\nEnter Email: ");
        Client.phoneNumber = clsInputValidate::readString("\nEnter Phone: ");
        Client.Password = clsInputValidate::readString("\nEnter Password: ");
        Client.Permissions = clsInputValidate::_ReadPermissionsToSet();
 
    };

    static void _PrintUser(clsBankUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.firstName;
        cout << "\nLastName    : " << User.lastName;
        cout << "\nFull Name   : " << User.fullName();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phoneNumber;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        UserName = clsInputValidate::readString("\nPlease Enter UserName: ");
        while (clsBankUser::isUserExist(UserName))
        {
            UserName = clsInputValidate::readString("\nUserName Is Already Used, Choose another one: ");
        }

        clsBankUser NewUser = clsBankUser::GetAddNewUserObject(UserName);

        _readUserInfo(NewUser);

        clsBankUser::enSaveResult SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsBankUser::enSaveResult::saveSucceeded:

            cout << "\USer Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;

        case clsBankUser::enSaveResult::saveFaild:

            cout << "\nError User was not saved:-(";
            break;
        }
    }



};
