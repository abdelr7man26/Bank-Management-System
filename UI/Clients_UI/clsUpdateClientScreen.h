#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen

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

    static void _readClientInfo(clsBankClient& Client)
    {
        Client.firstName = clsInputValidate::readString("\nEnter FirstName: ");
        Client.lastName = clsInputValidate::readString("\nEnter LastName: ");
        Client.email = clsInputValidate::readString("\nEnter Email: ");
        Client.phoneNumber = clsInputValidate::readString("\nEnter Phone: ");
        Client.pinCode = clsInputValidate::readString("\nEnter PinCode: ");
        Client.accountBalance = clsInputValidate::readDouble("\nEnter Account Balance: ");
    };

public:

    static void updateClient() {

        if (!checkpermission(clsBankUser::enPermissions::pAddNewClient)) {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string accountNumber = clsInputValidate::readString("enter client account number to update\n");

        while (!clsBankClient::isCLientExist(accountNumber)) {
            accountNumber = clsInputValidate::readString("acount not found. enter a valid account number: \n");
        }
        clsBankClient Client1 = clsBankClient::find(accountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _readClientInfo(Client1);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResult::saveSucceeded:

            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        case clsBankClient::enSaveResult::saveFaild:

            cout << "\nError account was not saved because it's Empty";
            break;
        }
    }

};
