#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankUsers.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
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
    static void deleteClient() {
        string UserName = clsInputValidate::readString("enter User Name to delete\n");
        while (!(clsBankUser::isUserExist(UserName))) {
            UserName = clsInputValidate::readString("User doesnt exist already. enter a valid User Name to delete\n");
        }
        clsBankUser targetAccount = clsBankUser::Find(UserName);
        _PrintUser(targetAccount);
        cout << "--------------------------------\n";

        if (!(clsInputValidate::readConfirm("are you sure you want to delete this client?\n"))) {
            cout << "operation cancelled successfully :-)" << endl;
        }
        else {
            clsBankUser::enDeleteResult deleteResult;
            deleteResult = targetAccount.Delete();
            switch (deleteResult) {
            case  clsBankUser::enDeleteResult::deleteFaild:
                cout << "failed to delete :-(\n";
                break;
            case clsBankUser::enDeleteResult::deletesucced:
                cout << "client deleted successfully :-)\n";
                _PrintUser(targetAccount);
            }
        }
    }

};
