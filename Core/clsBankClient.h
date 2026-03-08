#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Global.h"
#include "clsutility.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode { emptyMode = 0, updateMode = 1, addNew = 2 , delteaccount = 3};

	enMode _mode;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;

    static clsBankClient _convertLineIntoObject(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');
        
        return clsBankClient(updateMode, attributes[0],clsUtil::DecryptText( attributes[1]), stof(attributes[6]), attributes[2], attributes[3], attributes[5], attributes[4]);
    }

    static string _convertObjectIntoLine(clsBankClient Client, char Seperator = '#')
    {
        string attributesRecord = "";
        attributesRecord += Client.AccountNumber() + Seperator;
        attributesRecord += clsUtil::EncryptText(Client.pinCode) + Seperator;
        attributesRecord += Client.firstName + Seperator;
        attributesRecord += Client.lastName + Seperator;
        attributesRecord += Client.email + Seperator;
        attributesRecord += Client.phoneNumber + Seperator;
        attributesRecord += to_string(Client.accountBalance);

        return attributesRecord;
    }

    static vector <clsBankClient> _fillFromFile(string fileName ) {

        vector <clsBankClient> clients;

        fstream file;
        file.open(fileName, ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }
                clsBankClient client = _convertLineIntoObject(line);
                clients.push_back(client);
            }
            file.close(); 
        }
        return clients;
    }

    static void _saveToFile(string fileName, vector <clsBankClient> vClients) {
        fstream file;
        file.open(fileName, ios::out);

        string attributesline;

        if (file.is_open()) {
            for (clsBankClient client : vClients)
            {
                if (client._mode != enMode::delteaccount)
                {
                    attributesline = _convertObjectIntoLine(client);
                    file << attributesline << endl;
                }
            }
            file.close();
        }
    }
    
    static void _saveOneClientToFile(string fileName, clsBankClient client) {
        fstream file;
        file.open(fileName, ios::out | ios::app);

        string attributesline;

        if (file.is_open()) {

            attributesline = _convertObjectIntoLine(client);
            file << attributesline << endl;
      
            file.close();
        }
    }

    static string _convertTranferHistoryToLine(clsBankClient sender ,int amount, clsBankClient Reciver , char Seperator = '#') {
        string attributesRecord = "";
        attributesRecord += clsDate::accurateDateToString(clsDate::GetSystemDate()) + Seperator;
        attributesRecord += sender.AccountNumber() + Seperator;
        attributesRecord += to_string(sender.accountBalance) + Seperator;
        attributesRecord += to_string(amount) + Seperator;
        attributesRecord += Reciver.AccountNumber() + Seperator;
        attributesRecord += to_string(Reciver.accountBalance) + Seperator;
        attributesRecord += CurrentUser.UserName;
        return attributesRecord;
    }

    static void _saveTransferHistoryToFile(clsBankClient Sender ,int amount , clsBankClient Reciver) {
        fstream file;
        file.open("Database/Transfer Log.txt", ios::out);

        string attributesline;

        if (file.is_open()) {


            attributesline = _convertTranferHistoryToLine(Sender , amount ,Reciver);
            file << attributesline << endl;


            file.close();
        }
    }

    static vector<string> _convertTransferLineIntoVector(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');

        return attributes;
    }

    static  vector <vector<string>> _LoadLogHistoryFromFile() {
        vector <vector<string>> vattributes;

        fstream file;
        file.open("Database/Transfer Log.txt", ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }

                vattributes.push_back(_convertTransferLineIntoVector(line));
            }
            file.close();
        }
        return vattributes;

    }

    static clsBankClient _emptyclient(enMode mode = enMode::emptyMode ,string accountNumber ="") {
        return clsBankClient(mode, accountNumber, "", 0, "", "", "", "");
    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _fillFromFile("Database/clients.txt");

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _saveToFile("Database/clients.txt", _vClients);

    }
    
    void _addNew() {
       /* vector <clsBankClient> _vClients;
        _vClients = _fillFromFile("");
        _vClients.push_back(*this);
        _saveToFile("", _vClients);
        */


        _saveOneClientToFile("Database/clients.txt", *this);
       
    }
    
    void _delete() {

        *this = _emptyclient();
       
    }

public :
    enum enSaveResult { saveFaild = 0, saveSucceeded = 1 };
    enum enDeleteResult { deleteFaild = 0, deletesucced = 1 };

	clsBankClient(enMode mode, string accountNumber, string pinCode, float accountBalance, string firstName, string lastName, string phoneNumber, string email)
		: _mode(mode), _accountNumber(accountNumber), _pinCode(pinCode), _accountBalance(accountBalance), clsPerson(firstName, lastName, phoneNumber, email) {

	}
    
    bool isEmpty() {
        return (_mode == emptyMode);
    }

    string AccountNumber()
    {
        return _accountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _pinCode = PinCode;
    }
    string GetPinCode()
    {
        return _pinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string pinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _accountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _accountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float accountBalance;


    static clsBankClient find(string accountNumber) {
        vector <clsBankClient> clients = _fillFromFile("Database/clients.txt");
        for (clsBankClient& client : clients) {
            if (client.AccountNumber() == accountNumber) {
                return client;
            }
        }
        return _emptyclient();
    }

    static clsBankClient find(string accountNumber , string pinCode) {
        vector <clsBankClient> clients = _fillFromFile("Database/clients.txt");
        for (clsBankClient& client : clients) {
            if (client.AccountNumber() == accountNumber && client.pinCode == pinCode) {
                return client;
            }
        }
        return _emptyclient();
    }

    static bool isCLientExist(string accountNumber) {
        clsBankClient client = find(accountNumber);
        return !(client.isEmpty());
    }

    enSaveResult Save()
    {

        switch (_mode)
        {
        case enMode::emptyMode:

            return enSaveResult::saveFaild;
        case enMode::updateMode:

            _Update();
            return enSaveResult::saveSucceeded;
            break;
        case enMode::addNew:
            if (clsBankClient::isCLientExist(_accountNumber)) {
                return enSaveResult::saveFaild;
            }
            else {
                _addNew();
                this->_mode = enMode::updateMode;
                return enSaveResult::saveSucceeded;
            }
        }

    }

    enDeleteResult Delete () {

       this->_mode = enMode::delteaccount;
       _Update();

        switch (_mode)
        {
        case enMode::delteaccount:
            
            _delete();
            return enDeleteResult::deletesucced;
        default :

            return enDeleteResult::deleteFaild;  
        }
    }

    static clsBankClient createNewObject(string accountNumber) {
        return _emptyclient(addNew, accountNumber);
    }

    static vector <clsBankClient> clientsList()
    {
        return _fillFromFile("Database/clients.txt");
    }

    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::clientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.accountBalance;
        }

        return TotalBalances;

    }

    void Deposit(double amount) {
        _accountBalance += amount;
        Save();
    }
    bool Withdraw(double amount) {
        if (amount > _accountBalance)
        {
            return false;
        }
        else
        {
            _accountBalance -= amount;
            Save();
            return true;
        }
    }
    
    bool Checkavailableamount(int amount) {
        if (amount <= this->accountBalance) {
            return true;
        }
        return false;
    }

    void SaveTransferLog(int amount , clsBankClient Reciver) {
        clsBankClient::_saveTransferHistoryToFile(*this, amount, Reciver);
    }

    static vector <vector<string>> LoadTransferLog() {
        return  _LoadLogHistoryFromFile();
    }
};

