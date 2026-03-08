#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.country();
        cout << "\nCode       : " << Currency.currencyCode();
        cout << "\nName       : " << Currency.currencyName();
        cout << "\nRate(1$) = : " << Currency.rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.isEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer;

        cin >> Answer;
        cin.ignore();

        if (Answer == 1)
        {
            string CurrencyCode;
            CurrencyCode = clsInputValidate:: readString("\nPlease Enter CurrencyCode: ");
            clsCurrency Currency = clsCurrency::findByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            Country = clsInputValidate::readString("\nPlease Enter Country Name: ");
            clsCurrency Currency = clsCurrency::findByCountry(Country);
            _ShowResults(Currency);
        }

    }
};

