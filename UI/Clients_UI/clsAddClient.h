#pragma once
#include <iostream>
#include "clsBankClient.h"
#include<iomanip>
#include "Main_UI/clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddClient: protected clsScreen
{
private:

    static void _readClientInfo(clsBankClient& Client)
    {
        Client.firstName = clsInputValidate::readString("\nEnter FirstName: ");
        Client.lastName = clsInputValidate::readString("\nEnter LastName: ");
        Client.email = clsInputValidate::readString("\nEnter Email: ");
        Client.phoneNumber = clsInputValidate::readString("\nEnter Phone: ");
        Client.pinCode = clsInputValidate::readString("\nEnter PinCode: ");
        Client.accountBalance = clsInputValidate::readDouble("\nEnter Account Balance: ");
    };

    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.firstName;
        cout << "\nLastName    : " << client.lastName;
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nEmail       : " << client.email;
        cout << "\nPhone       : " << client.phoneNumber;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.pinCode;
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";

    }

public:
    static void ShowAddNewClientScreen()
    {
        if (!checkpermission(clsBankUser::enPermissions::pAddNewClient)) {
            return;
        }
        
        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValidate::readString("\nPlease Enter Account Number: ");
        while (clsBankClient::isCLientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::readString("\nAccount Number Is Already Used, Choose another one: ");
        }

        clsBankClient NewClient = clsBankClient::createNewObject(AccountNumber);

        _readClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResult::saveSucceeded:
        
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        
        case clsBankClient::enSaveResult::saveFaild:
        
            cout << "\nError account was not saved:-(";
            break;
        }

    }
};

