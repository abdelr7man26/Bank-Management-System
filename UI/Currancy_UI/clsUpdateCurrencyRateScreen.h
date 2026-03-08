#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _ReadRate()
    {
        float NewRate = 0;
        NewRate = clsInputValidate::readDouble("\nEnter New Rate: ");
        return NewRate;
    }

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

public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        CurrencyCode = clsInputValidate::readString("\nPlease Enter Currency Code: ");

        while (!clsCurrency::isCurrencyExist(CurrencyCode))
        {

            CurrencyCode = clsInputValidate::readString("\nCurrency is not found, choose another one: ");
        }

        clsCurrency Currency = clsCurrency::findByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer ;
        cin >> Answer;
        cin.ignore();

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.updateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);


        }

    }
};
