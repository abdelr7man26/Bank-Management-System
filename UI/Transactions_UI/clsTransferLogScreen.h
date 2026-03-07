#pragma once
#include <iostream>
#include  <iomanip>
#include "clsBankClient.h"
#include <vector>
#include "clsScreen.h"

using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:

    static void _printTransferHistoryRecordLine(vector <string> Log) {
        if (Log.size() >= 5) {
            cout << setw(8) << left << "" << "| " << setw(18) << left << Log[0];
            cout << "| " << setw(12) << left << Log[1];
            cout << "| " << setw(12) << left << Log[2];
            cout << "| " << setw(12) << left << Log[3];
            cout << "| " << setw(12) << left << Log[4];
            cout << "| " << setw(12) << left << Log[5];
            cout << "| " << setw(12) << left << Log[6];
        }
    }

public:
    static void showLogHistoryScreen() {

        vector <vector<string>> logs;
        logs = clsBankClient::LoadTransferLog();

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(18) << "Date / Time";
        cout << "| " << left << setw(12) << "Sender";
        cout << "| " << left << setw(12) << "Sender Balance";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "Reciever";
        cout << "| " << left << setw(12) << "Reciver Balance";
        cout << "| " << left << setw(12) << "User / Admin";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (logs.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (vector<string>& log : logs)
            {
                _printTransferHistoryRecordLine(log);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

