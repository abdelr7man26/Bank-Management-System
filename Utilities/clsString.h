#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ClsString
{
private:
	std::string _Value;
public:
	ClsString() {
		_Value = "";
	}
	ClsString(std::string value) {
		_Value = value;
	}

	void setValue(std::string value) {
		_Value = value;
	}
	std::string getValue() {
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) std::string Value;

	static short countWords(const std::string& word) {
		short counter = 0;
		bool inWord = false;

		for (const char& c : word) {

			if (std::isspace(c)) {
				inWord = false;
			}
			else if (!inWord) {
				inWord = true;
				counter++;
			}
		}
		return counter;
	}

	short countWords() {
		return countWords(this->_Value);
	}

	static short length(const std::string& word) {
		short counter = 0;

		for (const char& c : word) {
			counter++;
		}
		return counter;
	}

	short length() {
		return length(_Value);
	}

	static bool isEmpty(const std::string& word) {
		return (length(word) == 0);
	}

	bool isEmpty() {
		return(isEmpty(_Value));
	}

	static char at(const std::string& word, const int& index) {

		int counter = 0;
		bool found = false;
		for (const char& c : word) {

			if (counter == index) {
				found = true;
				return c;
			}
			counter++;
		}
		if (!found) {
			return '\0';
		}
		return '\0';
	}

	char at(const int& index) {
		return at(_Value, index);
	}

	static std::string append(const std::string& extra, std::string& word) {
		word = word + extra;
		return word;
	}

	std::string append(const std::string& extra) {
		return append(extra, _Value);
	}

	static std::string clear(std::string& word) {
		word = "";
		return word;
	}

	void clear() {
		_Value = clear(_Value);
	}

	static std::string pushBack(const char& extra, std::string& word) {
		word = word + extra;
		return word;
	}

	std::string pushBack(const char& extra) {
		return pushBack(extra, _Value);
	}

	static std::string upperAll(std::string word) {
		if (word.empty()) return word;

		char* ptr = &word[0];
		char* endPtr = ptr + length(word);

		for (; ptr < endPtr; ptr++) {
			if (*ptr >= 'a' && *ptr <= 'z') {
				*ptr -= 32;
			}
		}
		return word;
	}

	void upperAll() {
		_Value = upperAll(_Value);
	}

	static std::string upperFirstLetterOfEachWord(std::string& text) {
		bool isFirstLetter = true;

		for (size_t i = 0; i < text.length(); ++i) {
			if (!std::isalpha(text[i])) {
				isFirstLetter = true;
			}
			else if (isFirstLetter) {
				text[i] = std::toupper(text[i]);
				isFirstLetter = false;
			}
		}

		return  text;
	}

	void upperFirstLetterOfEachWord() {
		_Value = upperFirstLetterOfEachWord(_Value);
	}

	static std::string lowerAll(std::string word) {
		char* ptr = &word[0];
		char* endPtr = ptr + length(word);

		for (; ptr < endPtr; ptr++) {
			if (*ptr >= 'A' && *ptr <= 'Z') {
				*ptr += 32;
			}

		}
		return word;
	}

	void lowerAll() {
		_Value = lowerAll(_Value);
	}

	static std::string lowerFirstLetterOfEachWord(std::string& text) {
		bool isFirstLetter = true;

		for (size_t i = 0; i < text.length(); ++i) {
			if (!std::isalpha(text[i])) {
				isFirstLetter = true;
			}
			else if (isFirstLetter) {
				text[i] = std::tolower(text[i]);
				isFirstLetter = false;
			}
		}

		return text;
	}

	void lowerFirstLetterOfEachWord() {
		_Value = lowerFirstLetterOfEachWord(_Value);
	}

	static char invertCharCase(char& c) {
		return (isupper(c) ? tolower(c) : toupper(c));
	}

	static std::string invertAllLettersCases(std::string text) {
		for (char& c : text) {
			invertCharCase(c);
		}
		return text;
	}

	void invertAllLettersCases() {
		_Value = invertAllLettersCases(_Value);
	}

	static std::string reverse(std::string& word) {

		char* startPtr = &word[0];
		short len = length(word);
		char* endPtr = &word[len - 1];

		while (startPtr < endPtr)
		{
			char temp = ' ';
			temp = *startPtr;
			*startPtr = *endPtr;
			*endPtr = temp;
			startPtr++;
			endPtr--;
		}
		return word;
	}

	void reverse() {
		_Value = reverse(_Value);
	}

	enum enwhatToCount { smallcase = 1, uppercase = 2, alphas = 3, allLetters = 4, All = 5 };

	static size_t countLetters(const std::string& text, enwhatToCount whatToCount) {
		if (whatToCount == All) return text.length();

		size_t counter = 0;
		for (unsigned char c : text) {
			switch (whatToCount) {
			case smallcase:         if (std::islower(c)) counter++; break;
			case uppercase:         if (std::isupper(c)) counter++; break;
			case alphas:            if (std::isalpha(c)) counter++; break;
			case allLetters:  if (!std::isalpha(c)) counter++; break;
			default: break;
			}
		}
		return counter;
	}

	size_t countLetters(enwhatToCount whattocount) {
		return countLetters(_Value, whattocount);
	}

	static size_t countSpecificLetter(const std::string& text, char& letter, bool matchCase = false) {
		size_t counter = 0;

		if (matchCase) {
			for (char c : text) {
				if (c == letter) counter++;
			}
		}
		else {
			char lowerLetter = (unsigned char)std::tolower(letter);
			for (char c : text) {
				if ((unsigned char)std::tolower(c) == lowerLetter) {
					counter++;
				}
			}
		}

		return counter;
	}

	size_t countSpecificLetter(char& letter, bool matchCase = 0) {
		return countSpecificLetter(_Value, letter, matchCase);
	}

	static short find(const std::string& target, std::string& word, short startSearchPos = false) {

		short targetLength = length(target);
		short wordLength = length(word);

		if (targetLength == 0 || targetLength > wordLength) return -1;

		const char* ptr = &word[0] + startSearchPos;
		short counter = startSearchPos;

		while ((wordLength - counter) >= targetLength) {

			if (*ptr == target[0]) {
				const char* temp = ptr;
				bool found = true;


				for (size_t i = 1; i < targetLength; ++i)
				{

					if (*(++temp) != target[i])
					{
						found = false;
						break;
					}
				}

				if (found == true) return counter;

			}
			ptr++;
			counter++;
		}
		return -1;
	}

	short find(const std::string& target, short startSearchPos = 0) {
		return find(target, _Value);
	}

	static std::string replace(std::string& text, const std::string& oldWord, const std::string& newWord) {

		size_t index = text.find(oldWord);
		if (index == -1) return text;

		const char* startPtr = &text[0];
		short oldWordLength = length(oldWord);

		std::string prefix = "";
		prefix.std::string::append(startPtr, index);


		std::string postfix = "";
		postfix.std::string::append(startPtr + index + oldWordLength, length(text) - (index + oldWordLength));

		text = prefix + newWord + postfix;


		return  text;
	}

	std::string replace(const std::string& oldWord, const std::string& newWord) {
		return replace(_Value, oldWord, newWord);
	}

	static std::string replaceAll(std::string& text, const std::string& oldWord, const std::string& newWord) {
		if (oldWord.empty()) return text;

		std::string result = "";
		short oldLength = length(oldWord);
		short textLen = length(text);

		short currentPos = 0;
		short foundPos = 0;


		while ((foundPos = find(oldWord, text, currentPos)) != -1) {

			result.append(text.c_str() + currentPos, foundPos - currentPos);


			result += newWord;

			currentPos = foundPos + oldLength;
		}

		if (currentPos < textLen) {
			result.append(text.c_str() + currentPos, textLen - currentPos);
		}

		return result;
	}

	std::string replaceAll(const std::string& oldWord, const std::string& newWord) {
		return replaceAll(_Value, oldWord, newWord);
	}

	static std::vector<std::string> split(const std::string& text, char delimeter) {
		std::vector <std::string> tookens;
		std::string tooken;
		auto startptr = text.begin();
		while (startptr != text.end()) {
			auto pos = std::find(startptr, text.end(), delimeter);
			while (startptr != pos) {
				tooken += *startptr;
				startptr++;
			}
			if (!isEmpty(tooken)) tookens.push_back(tooken);
			tooken.clear();
			if (pos == text.end()) break;
			startptr = pos + 1;
		}
		return tookens;
	}

	std::vector<std::string> split(char Delim)
	{
		return split(_Value, Delim);
	}
};

// replace ---- split ---- find ---- reverse  ----> most important //
// pointers ---- itterators ---- stl functions