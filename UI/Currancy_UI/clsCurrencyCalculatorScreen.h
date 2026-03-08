#pragma once
#include <iostream>
#include "Main_UI/clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static float _ReadAmount()
    {
        float Amount = 0;

        Amount = clsInputValidate::readDouble("\nEnter Amount to Exchange: ");
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;

        CurrencyCode = clsInputValidate::readString(Message);

        while (!clsCurrency::isCurrencyExist(CurrencyCode))
        {
            CurrencyCode = clsInputValidate::readString("\nCurrency is not found, choose another one: ");
        }

        clsCurrency Currency = clsCurrency::findByCode(CurrencyCode);
        return Currency;

    }


    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.country();
        cout << "\nCode          : " << Currency.currencyCode();
        cout << "\nName          : " << Currency.currencyName();
        cout << "\nRate(1$) =    : " << Currency.rate();
        cout << "\n_____________________________\n\n";

    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        _PrintCurrencyCard(Currency2, "Convert To:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << "\nConverting from " << Currency1.currencyCode() << " to " << Currency2.currencyCode() << "\t ";

        

        if (Currency2.currencyCode() == "USD")
        {
            cout << Amount << " " << Currency1.currencyCode()
                << " = " << AmountInUSD << " " << Currency2.currencyCode();
            return;
        }
        else {
            float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
            cout << Amount << " " << Currency1.currencyCode()
                << " = " << AmountInCurrrency2 << " " << Currency2.currencyCode();
        }
  

    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DrawScreenHeader("\tCurrancy Calculator Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency Code to convert from it: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency Code to convert to it: ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;
            cin.ignore();
        }


    }
};
