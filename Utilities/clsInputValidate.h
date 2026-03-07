#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    static int readInt(const string& message) {
        int number = 0;
        cout << message;
        while (true) {
            cin >> number;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;

    }

    static int ReadIntNumberBetween(int From, int To, const string& message)
    {
        int Number = readInt(message);

        while (!IsNumberBetween(Number, From, To))
        {
      
            cout << "Number is not within range, Enter again:\n";
            Number = readInt(message);
        }
        return Number;
    }


    static double readDouble(const string& message) {
        double number = 0;
        cout << message;
        while (true) {
            cin >> number;
            if (cin.fail() || number < 0) {
                cout << "Invalid input. Please enter a positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return number;
            }
        }
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static double ReadDblNumberBetween(double From, double To, string Message )
    {
        double Number = readDouble(Message);

        while (!IsNumberBetween(Number, From, To)) {
            cout << "Number is not within range, Enter again:\n";
            Number = readDouble(Message);
        }
        return Number;
    }


    static bool readConfirm(const string& message) {
        char input;
        cout << message << " (Y/N): ";
        while (true) {
            cin >> input;
            char upperInput = toupper(input);
            if (upperInput == 'Y' || upperInput == 'N') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (upperInput == 'Y') {
                    return true;
                }
                else return false;
            }
            cout << "Invalid. Enter Y or N.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    static string readString(const string& message) {
        string input;
        cout << message;
        getline(cin, input);
        return input;
    }

    
    static string getCurrentDate() {
       
        string date = clsDate::DateToString(clsDate::GetSystemDate());
        return date;
    }

    static bool IsValideDate(clsDate Date)
    {
        return	clsDate::IsValidDate(Date);
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
       
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            )
        {
            return true;
        }

        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            )
        {
            return true;
        }

        return false;
    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsBankUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pManageUsers;
        }

        cout << "\nLog History? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsBankUser::enPermissions::pLogHistory;
        }

        return Permissions;

    }
};

