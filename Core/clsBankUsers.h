#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsutility.h"

using namespace std;
class clsBankUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteUser = 3 };
    enMode _Mode;

    string _UserName;
    string _Password;
    int _Permissions;

    static clsBankUser _convertLineIntoObject(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');

        return clsBankUser(UpdateMode, attributes[0], attributes[1], attributes[2], attributes[3], attributes[4], clsUtil::DecryptText(attributes[5]), stoi(attributes[6]));
    }

    static string _convertObjectIntoLine(clsBankUser USer, char Seperator = '#')
    {
        string attributesRecord = "";
        attributesRecord += USer.firstName + Seperator;
        attributesRecord += USer.lastName + Seperator;
        attributesRecord += USer.email + Seperator;
        attributesRecord += USer.phoneNumber + Seperator;
        attributesRecord += USer.UserName + Seperator;
        attributesRecord += clsUtil::EncryptText(USer.Password) + Seperator;
        attributesRecord += to_string(USer.Permissions);

        return attributesRecord;
    }

    static vector <clsBankUser> _fillFromFile() {

        vector <clsBankUser> vUsers;

        fstream file;
        file.open("Database/Users.txt", ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }
                clsBankUser USer = _convertLineIntoObject(line);
                vUsers.push_back(USer);
            }
            file.close();
        }
        return vUsers;
    }

    static void _saveToFile( vector <clsBankUser> vUsers) {
        fstream file;
        file.open("Database/Users.txt", ios::out);

        string attributesline;

        if (file.is_open()) {
            for (clsBankUser User : vUsers)
            {
                if (User._Mode != enMode::DeleteUser)
                {
                    attributesline = _convertObjectIntoLine(User);
                    file << attributesline << endl;
                }
            }
            file.close();
        }
    }

    static void _saveOneUserToFile( clsBankUser User) {
        fstream file;
        file.open("Database/Users.txt", ios::out | ios::app);

        string attributesline;

        if (file.is_open()) {

            attributesline = _convertObjectIntoLine(User);
            file << attributesline << endl;

            file.close();
        }
    }

    static clsBankUser _emptyUser(enMode mode = enMode::EmptyMode,string UserNaMe = "") {
        return clsBankUser(mode, "", "", "", "", UserNaMe, "", 0);
    }

    string _convertObjectIntoLogLine( char Seperator = '#')
    {
        string attributesRecord = "";
        attributesRecord += clsDate::accurateDateToString(clsDate::GetSystemDate()) + Seperator ;
        attributesRecord += this->fullName() + Seperator;
        attributesRecord += this->phoneNumber + Seperator;
        attributesRecord += this->UserName + Seperator;
        attributesRecord += to_string(this->Permissions);
     
        return attributesRecord;
    }

    static vector<string> _convertLogLineIntoVector(string line) {
        vector <string> attributes;
        attributes = ClsString::split(line, '#');

        return attributes;
    }

    void _Update()
    {
        vector <clsBankUser> _vUsers;
        _vUsers = _fillFromFile();

        for (clsBankUser& User : _vUsers)
        {
            if (User.UserName == UserName)
            {
                User = *this;
                break;
            }

        }

        _saveToFile(_vUsers);

    }

    void _addNew() {
     
        _saveOneUserToFile(*this);

    }

    void _delete() {

        *this = _emptyUser();

    }

public:
    enum enSaveResult { saveFaild = 0, saveSucceeded = 1 };
    enum enDeleteResult { deleteFaild = 0, deletesucced = 1 };
    enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 , pLogHistory = 128
    };


    clsBankUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Phone, Email)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string GetUserName()
    {
        return _UserName;
    }
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;


    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;


    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


    static clsBankUser Find(string UserName)
    {
        vector <clsBankUser> Users = _fillFromFile();
        for (clsBankUser& User : Users) {
            if (User.UserName == UserName) {
                return User;
            }
        }
        return _emptyUser();
    }

    static clsBankUser Find(string UserName, string Password)
    {

        vector <clsBankUser> USers = _fillFromFile();
        for (clsBankUser& User : USers) {
            if (User.UserName == UserName && User.Password == Password) {
                return User;
            }
        }
        return _emptyUser();
    }

    static bool isUserExist(string UserName) {
        clsBankUser client = Find(UserName);
        return !(client.IsEmpty());
    }

    enSaveResult Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:

            return enSaveResult::saveFaild;
        case enMode::UpdateMode:

            _Update();
            return enSaveResult::saveSucceeded;
            break;
        case enMode::AddNewMode:
            if (clsBankUser::isUserExist(UserName)) {
                return enSaveResult::saveFaild;
            }
            else {
                _addNew();
                this->_Mode = enMode::UpdateMode;
                return enSaveResult::saveSucceeded;
            }
        }

    }

    enDeleteResult Delete() {

        this->_Mode = enMode::DeleteUser;
        _Update();

        switch (_Mode)
        {
        case enMode::DeleteUser:

            _delete();
            return enDeleteResult::deletesucced;
        default:

            return enDeleteResult::deleteFaild;
        }
    }

    static clsBankUser GetAddNewUserObject(string UserName)
    {
        return  _emptyUser(AddNewMode , UserName);
    }

    static vector <clsBankUser> GetUsersList()
    {
        return _fillFromFile();
    }

    static clsBankUser emptyUser() {
        return clsBankUser(EmptyMode, "", "", "", "", "", "", 0);
    }
    
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }
    
    void _saveLogHistoryToFile() {
        fstream file;
        file.open("Database/Log.txt", ios::out | ios::app);

        string attributesline;

        if (file.is_open()) {


            attributesline = _convertObjectIntoLogLine();
            file << attributesline << endl;

            file.close();
        }
    }

    static  vector <vector<string>> LoadLogHistoryFromFile() {
        vector <vector<string>> vUsers;

        fstream file;
        file.open("Database/Log.txt", ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty())
                {
                    continue;
                }

                vUsers.push_back(_convertLogLineIntoVector(line));
            }
            file.close();
        }
        return vUsers;

    }
};
