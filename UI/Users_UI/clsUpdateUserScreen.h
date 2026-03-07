#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUsers.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
private:

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

    static void _readUserInfo(clsBankUser& Client)
    {
        Client.firstName = clsInputValidate::readString("\nEnter FirstName: ");
        Client.lastName = clsInputValidate::readString("\nEnter LastName: ");
        Client.email = clsInputValidate::readString("\nEnter Email: ");
        Client.phoneNumber = clsInputValidate::readString("\nEnter Phone: ");
        Client.Password = clsInputValidate::readString("\nEnter Password: ");
        Client.Permissions = clsInputValidate:: _ReadPermissionsToSet();

    }

public:

    static void updateUser() {

        _DrawScreenHeader("\tUpdate Client Screen");

        string UserName = clsInputValidate::readString("enter User name to update\n");

        while (!clsBankUser::isUserExist(UserName)) {
            UserName = clsInputValidate::readString("acount not found. enter a valid account number: \n");
        }
        clsBankUser User1 = clsBankUser::Find(UserName);
        _PrintUser(User1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _readUserInfo(User1);

        clsBankUser::enSaveResult SaveResult;

        SaveResult = User1.Save();

        switch (SaveResult)
        {
        case  clsBankUser::enSaveResult::saveSucceeded:

            cout << "\nAccount Updated Successfully :-)\n";
            _PrintUser(User1);
            break;
        case clsBankUser::enSaveResult::saveFaild:

            cout << "\nError account was not saved because it's Empty";
            break;
        }
    }

};
