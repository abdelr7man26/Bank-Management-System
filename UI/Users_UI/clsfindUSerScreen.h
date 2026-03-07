#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUsers.h"
#include "clsInputValidate.h"

class clsFindUSerScreen :protected clsScreen
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

public:

    static void FindUser()
    {

        _DrawScreenHeader("\tFind USer Screen");

        string UserNAme = clsInputValidate::readString("\nPlease Enter User Name: ");

        while (!clsBankUser::isUserExist(UserNAme))
        {

            UserNAme = clsInputValidate::readString("\nUser is not found, choose another one: ");
        }

        clsBankUser Client1 = clsBankUser::Find(UserNAme);

        if (!Client1.IsEmpty())
        {
            cout << "\nUSer Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(Client1);

    }

};
