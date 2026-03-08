#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsString.h"
#include <fstream>

using namespace std;

class clsCurrency
{
private:
	enum enMode { emptyMode = 0 , updateMode = 1 };

	enMode _mode;
	string _country;
	string _currencyCode;
	string _currencyName;
	float _rate;

	static clsCurrency _convertLineToObject(string line, char seperator = '#') {

		vector <string> attributes;
		attributes = ClsString::split(line, seperator);
		return clsCurrency(updateMode , attributes[0] , attributes[1] , attributes[2] , stof(attributes[3]));
	}
	
	static string _convertObjectTOLine(clsCurrency currency , char seperator = '#') {
		string attributes;

		attributes += currency.country() + seperator;
		attributes += currency.currencyCode() + seperator;
		attributes += currency.currencyName() + seperator;
		attributes += to_string(currency.rate());

		return attributes;
	}

	static void _saveToFile(vector <clsCurrency> currencies ) {

		fstream file;
		file.open("Database/Currencies.txt", ios::out);
		string line;
		if (file.is_open()) {
			for (clsCurrency& currency : currencies)
			{
				line = _convertObjectTOLine(currency);
				file << line << endl;
			}
			file.close();
		}
	}

	static vector<clsCurrency> _loadFromFile() {

		vector <clsCurrency> currencies;

		fstream file;
		file.open("Database/Currencies.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				if (line.empty())
				{
					continue;
				}
				clsCurrency USer = _convertLineToObject(line);
				currencies.push_back(USer);
			}
			file.close();
		}
		return currencies;
	}

	static clsCurrency _emptyCurrency() {
		return clsCurrency(emptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector <clsCurrency> currencies;
		currencies = _loadFromFile();

		for (clsCurrency& cureency : currencies)
		{
			if (cureency.currencyCode() == this->currencyCode())
			{
				cureency = *this;
				break;
			}

		}

		_saveToFile(currencies);

	}

public:

	clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate) : _mode(mode), _country(country), _currencyCode(currencyCode), _currencyName(currencyName), _rate(rate) {};

	string country() {
		return _country;
	}
	string currencyCode() {
		return _currencyCode;
	}
	string currencyName() {
		return _currencyName;
	}
	float rate() {
		return _rate;
	}
	void updateRate(float rate) {
		_rate = rate;
		_Update();
	}

	bool isEmpty() {
		if (this->_mode == emptyMode) {
			return true;
		}
		return false;
	}

	static clsCurrency findByCode(string currencycode) {
		vector <clsCurrency> currencies;
		currencies = _loadFromFile();
		for (clsCurrency& currency : currencies) {
			if (ClsString::upperAll(currency.currencyCode()) == ClsString::upperAll(currencycode)) {
				return currency;
			}
		}

		return _emptyCurrency();
	}

	static clsCurrency findByCountry(string country) {
		vector <clsCurrency> currencies;
		currencies = _loadFromFile();
		for (clsCurrency& currency : currencies) {
			if (ClsString::upperAll(currency.country()) == ClsString::upperAll(country)) {
				return currency;
			}
		}

		return _emptyCurrency();
	}

	static bool isCurrencyExist(string code) {
		clsCurrency currency = findByCode(code);
		return !(currency.isEmpty());
	}

	static vector <clsCurrency> currenciesList() {
		return _loadFromFile();
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return  _loadFromFile();

	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.currencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.rate());

	}
};

