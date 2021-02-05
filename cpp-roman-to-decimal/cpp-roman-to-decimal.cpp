#include <iostream>
#include <string>

using namespace std;

int romanToDecimal(string romanNumeral)
{
	
	string newRomanNumeral = romanNumeral;
	enum romanNumberValue { M = 1000, D = 500, C = 100, L = 50, X = 10, V=5, I = 1 };
	int decimalValue;
	
	if (newRomanNumeral == "M" || newRomanNumeral == "m")
		decimalValue = M;
	else if (newRomanNumeral == "D" || newRomanNumeral == "d")
		decimalValue = D;
	else if (newRomanNumeral == "C" || newRomanNumeral == "c")
		decimalValue = C;
	else if (newRomanNumeral == "L" || newRomanNumeral == "l")
		decimalValue = L;
	else if (newRomanNumeral == "X" || newRomanNumeral == "x")
		decimalValue = X;
	else if (newRomanNumeral == "V" || newRomanNumeral == "v")
		decimalValue = V;
	else if (newRomanNumeral == "I" || newRomanNumeral == "i")
		decimalValue = I;
	else decimalValue = 0;

	// cout << "The decimal value of " << newRomanNumeral << " is " << decimalValue << "\n";

	return decimalValue;

}

bool isLarger(int num1, int num2)
{
	int newNum1 = num1;
	int newNum2 = num2;
	bool isLarger = false;

	if (newNum1 > newNum2)
	{
		isLarger = true;
	}

	return isLarger;
}

bool isEqual(int num1, int num2)
{
	int newNum1 = num1;
	int newNum2 = num2;
	bool isEqual = false;

	if (newNum1 == newNum2)
	{
		isEqual = true;
	}

	return isEqual;
}

int main()
{
	string romanNumeral = "";
	int romanNumeralLength = 0;
	int i = 0;
	string leftDigit = "";
	string rightDigit = "";
	int runningTotal = 0;
	int decimalVal = 0;
	int bank = 0;
	int decimalValLeft;
	int decimalValRight;
	string romanValLast;
	int sentinalVal = 99;

	//do
	//{
	cout << "Enter a Roman numeral" << "\n";
	getline(cin, romanNumeral);
	//romanNumeral = "MCMLXXIX";

	romanNumeralLength = romanNumeral.length();

	cout << "You entered: " << romanNumeral << " which has a length of: " << romanNumeralLength << "\n";

	for (i = 0; i < romanNumeralLength-1; i++)
	{
		leftDigit = romanNumeral[i];
		rightDigit = romanNumeral[i + 1];
		decimalValLeft = romanToDecimal(leftDigit);
		decimalValRight = romanToDecimal(rightDigit);
		
		if (isLarger(decimalValLeft, decimalValRight) == true)
		{
			bank = bank + decimalValLeft;
		}
		else if (isEqual(decimalValLeft, decimalValRight) == true)
		{
			bank = bank + decimalValLeft;
		}
		else
		{
			bank = bank - decimalValLeft;
		}
		/*
		cout << "The values being compared are  " << decimalValLeft << 
			" and decimal value " << decimalValRight << "\n\n";
		*/
		
		//cout << "The current bank value is: " << bank << "\n\n";
	}
	
	romanValLast = romanNumeral[romanNumeralLength-1];
	//cout << "The last digit in the roman numeral is: " << romanToDecimal(romanValLast);
	
	bank = bank + romanToDecimal(romanValLast);
	
	cout << "Roman numeral " << romanNumeral << " is equal to " << bank 
		<< " decimal." << "\n\n";

	cout << "\n";

	//cout << "Repeat? ";
	//cin >> sentinalVal;
	//system("CLS");
	//} while (sentinalVal != 99);
	
	system("PAUSE");
	
	return 0;

}