#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
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

    static void FindClient()
    {
        if (!checkpermission(clsBankUser::enPermissions::pFindClient)) {
            return;
        }
        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber = clsInputValidate::readString("\nPlease Enter Account Number: ");
        
        while (!clsBankClient::isCLientExist(AccountNumber))
        {
     
            AccountNumber = clsInputValidate::readString("\nAccount number is not found, choose another one: ");
        }

        clsBankClient Client1 = clsBankClient::find(AccountNumber);

        if (!Client1.isEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};
