#pragma once
#include "Main_UI/clsScreen.h"
#include <iostream>
#include "clsBankUsers.h"
#include <iomanip>
#include <vector>

using namespace std;

class clsLogHistoryScreen : protected clsScreen
{
private:

    static void _printLogHistoryRecordLine(vector <string> Log) {
        if (Log.size() >= 5) {
            cout << setw(8) << left << "" << "| " << setw(25) << left << Log[0];
            cout << "| " << setw(20) << left << Log[1];
            cout << "| " << setw(12) << left << Log[2];
            cout << "| " << setw(20) << left << Log[3];
            cout << "| " << setw(10) << left << Log[4];
        }
    }

public:
	static void showLogHistoryScreen() {
        if (!checkpermission(clsBankUser::enPermissions::pLogHistory)) {
 
            return;
        }

        vector <vector<string>> logs;
        logs = clsBankUser::LoadLogHistoryFromFile();

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date / Time";
        cout << "| " << left << setw(20) << "Full name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(12) << "User NAme";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (logs.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (vector<string>& log : logs)
            {
                _printLogHistoryRecordLine(log);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}

};

