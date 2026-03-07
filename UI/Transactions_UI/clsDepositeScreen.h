#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = clsInputValidate::readString("\nenter an account number: ");


        while (!clsBankClient::isCLientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::readString("\nenter a valid client: ");
        }

        clsBankClient Client1 = clsBankClient::find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        Amount = clsInputValidate::readDouble("\nPlease enter deposit amount ? ");

        

        if (clsInputValidate::readConfirm("\nare you sure you want to deposite this amount? "))
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.accountBalance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};
