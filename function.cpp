
#include "ATM.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <ctime>

using namespace std;

// ====================== Account Functions ========================================
bool isSpecialChar(char ch)											// Function to check if string has a special char
{
	bool isSpecial = false;											// isSpecial is set to false because we don't know if it has special char yet
	if (!isdigit(ch) && !isalpha(ch))								// If not a number or a alphabetic letter, then it's a special char	(ERROR)
			{
				isSpecial = true;									// isSpecial becomes TRUE when a special char is found
			}
			return isSpecial;										// If there isn't a special char, it proceeds to isDigitChar function
}

bool isDigitChar(char ch)											// Function to check if string has a digit char
{
	bool isDigitChar = false;										// isDigitChar is set to false because we don't know if it has digit char yet
	if (isdigit(ch))												// If there's a number, then error message will pop	
			{
				isDigitChar = true;									// isDigitChar becomes TRUE when a digit char is found
			}
			return isDigitChar; 									// If there isn't a digit char, it proceeds
}

void Account::signUp()
{
    printf("==========================================================\n");
    printf("Welcome! Thank you for choosing MI Bank\n");
	printf("Please fill out the sign-up form.\n");
	bool valid = true;
	
	// firstName_
	do
	{
		cout << "First name: ";
		cin >> firstName_;

		// Check for numbers in firstName_
		for (size_t i = 0; i < firstName_.size(); i++)							// Goes through the string firstName_
		{
			if (isSpecialChar(firstName_[i]) || isDigitChar(firstName_[i]))		// Checking if firstName_[i] is a special/digit char
			{
				valid = false;													// If special/digit char is found, valid becomes false; error message
				cerr << "\t[*] ERROR: FIRST NAME INCORRECT\n\n";				// Error message
				//break;															// Stops and re-runs the loop
			}	
			else
			{
				valid = true;													// firstName_ contains no special/digit char. Goes on to lastName_
			}
		}
	} while (valid == false);													// Will keep on looping if there's a special/digit char in str. Otherwise, it moves on

	// lastName_
	do
	{
		cout << "Last name: ";
		cin >> lastName_;

		// Check for spcial char or digit in lastName_
		for (size_t i = 0; i < lastName_.size(); i++)							// Goes through the string lastName_
		{
			if (isSpecialChar(lastName_[i]) || isDigitChar(lastName_[i]))		// Checking if lastName_[i] is a special/digit char
			{
				valid = false;													// If special/digit char is found, valid becomes false; error message
				cerr << "\t[*] ERROR: LAST NAME INCORRECT\n\n";					// Error message 
				break;															// Stops and re-runs the loop
			}
			else
			{
				valid = true;													// lastName_ contains no special/digit char. Goes on to lastName_
			}
		}
	} while (valid == false);													// Will keep on looping if there's digit in str. Otherwise, it moves on
	
	// emailOne_ & emailTwo_
	do
	{
		cout << "Email: ";
		cin >> emailOne_;
		cout << "Re-enter email: ";
		cin >> emailTwo_;

		if (emailOne_.compare(emailTwo_) != 0)
		{
			valid = false;
			cerr << "\t[*] ERROR: EMAILS DO NOT MATCH\n\n";
		}
		else
		{
			valid = true;
		}

		string myArray [2] = {"@gmail.com", "@yahoo.com"};
		for (int i = 0; i < 2; i++)
		{
			auto found = emailOne_.find(myArray[i]);
			if (found == string::npos)
			{
				valid = false;
				cerr << "\t[*] ERROR: EMAILS MUST HAVE @gmail.com or @yahoo.com\n\n";
				break;
			}
			else
			{
				valid = true;
			}
		}
		
	} while (valid == false);

	// passwordOne_ & passwordTwo_
	do
	{
		cout << "Password: ";
		cin >> passwordOne_;
		cout << "Re-enter password: ";
		cin >> passwordTwo_;

		if (passwordOne_.compare(passwordTwo_) != 0)
		{
			valid = false;
			cerr << "\t[*] ERROR: PASSWORDS DO NOT MATCH\n\n";
		}
		else
		{
			valid = true;
		}
	} while (valid == false);

	cout << "\nThank you for signing up! Your account will be created shortly\n";
	cout << "What would you like to do now?\n\n";
	ATM atm;
	atm.displayMenu();
}

void ATM::displaySignInMenu()
{
	printf("\n");
	printf("\t1. Withdrawal\n");
	printf("\t2. Deposit\n");
	printf("\t3. Exit\n");
	printf("\n");
	printf("\n");
}
void Account::signIn()
{
	ATM atm;
    printf("==========================================================\n");
	printf("\t\tMI Bank");
    printf("Please sign-in to view personl information\n");

	cout << "Email: ";
	cin >> emailOne_;
	cout << "Password: ";
	cin >> passwordOne_;

	cout << "Welcome back " << firstName_ << " " << lastName_ 
			<< ". What would you like to do next";
	
	atm.displaySignInMenu();
}


// ====================== ATM Functions ============================================
void ATM::totalBalance()
{

}


void ATM::moneyWithdrawal()
{

}


void ATM::moneyDeposit()
{

}

// ====================== Main file ============================================
void ATM::displayMenu()
{
    printf("\n");
	printf("\t1. Sign up\n");
	printf("\t2. Sign in\n");
	printf("\t3. Exit\n");
	printf("\n");
	printf("\n");
}

void ATM::processMenuChoices()
{
    Account acc;
    int choice = 0;
    bool ok = false;
    
    do
	{
		ok = false;
		while (std::cout << "Please select an option: " && !(std::cin >> choice))       // Review this while loop
		{
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			std::cout << "\nERROR: Invalid input! Please try again.\n\n";
		}

		switch (choice)
		{
		case 1:
			cout << endl;
			acc.signUp();
			break;

		case 2:
			cout << endl;
			acc.signIn();
			break;
			
		case 3:
			if (choice == 3)
			{
				cout << "\nThank you. Have a nice day!" << endl;
				ok = true;
				break;
			}

		default:
			//cout << "Invalid input! Please try again.\n";
			ok = true;
		}
	} while (!ok);
}