#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen :protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.firstName;
        cout << "\nLastName    : " << Client.lastName;
        cout << "\nFull Name   : " << Client.fullName();
        cout << "\nEmail       : " << Client.email;
        cout << "\nPhone       : " << Client.phoneNumber;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.pinCode;
        cout << "\nBalance     : " << Client.accountBalance;
        cout << "\n___________________\n";

    }

public:
    static void deleteClient() {
        if (!checkpermission(clsBankUser::enPermissions::pDeleteClient)) {
            return;
        }
        string accountNumber = clsInputValidate::readString("enter account number to delete\n");
        while (!(clsBankClient::isCLientExist(accountNumber))) {
            accountNumber = clsInputValidate::readString("account doesnt exist already. enter a valid account number to delete\n");
        }
        clsBankClient targetAccount = clsBankClient::find(accountNumber);
        _PrintClient(targetAccount);
        cout << "--------------------------------\n";

        if (!(clsInputValidate::readConfirm("are you sure you want to delete this client?\n"))) {
            cout << "operation cancelled successfully :-)" << endl;
        }
        else {
            clsBankClient::enDeleteResult deleteResult;
            deleteResult = targetAccount.Delete();
            switch (deleteResult) {
            case  clsBankClient::enDeleteResult::deleteFaild:
                cout << "failed to delete :-(\n";
                break;
            case clsBankClient::enDeleteResult::deletesucced:
                cout << "client deleted successfully :-)\n";
                _PrintClient(targetAccount);
            }
        }
    }

};
