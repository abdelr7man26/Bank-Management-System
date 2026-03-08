#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.fullName();
        cout << "\nacc. Number : " << Client.AccountNumber();
        cout << "\nPhone       : " << Client.phoneNumber;
        cout << "\nBalance     : " << Client.accountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient _FindClient(string account) {
       
        while (!clsBankClient::isCLientExist(account))
        {

            account = clsInputValidate::readString("\nCLient is not found, choose another one: ");
        }

        clsBankClient Client1 = clsBankClient::find(account);

        if (!Client1.isEmpty())
        {
            cout << "\nUSer Found :-)\n";
            _PrintClient(Client1);
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        return Client1;
    }

public:
    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        string senderaccountNumber = clsInputValidate::readString("\nPlease Enter account Number to transfer from: ");
        clsBankClient Client1 = _FindClient(senderaccountNumber);

        string recieveraccountNumber = clsInputValidate::readString("\nPlease Enter account Number to transfer to: ");
       
        if (recieveraccountNumber == senderaccountNumber) {
            cout << "You can not transfer to your self\n";
            return;
        }

        clsBankClient Client2 = _FindClient(recieveraccountNumber);

        int amount = 0;
        cout << "Enter transfer amount: ";
        cin >> amount;

        while (true) {
            if (Client1.Checkavailableamount(amount)) {

                Client1.Withdraw(amount);
                Client2.Deposit(amount);
                cout << "Transfer done successfully :-)";
                Client1.SaveTransferLog(amount, Client2);
                return;
            }
            else {

                cout << "Transfer Faild, No availabe amount :-( . Try another amount: ";
                cin >> amount;
            }
        }
    }

};

