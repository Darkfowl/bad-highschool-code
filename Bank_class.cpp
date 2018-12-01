
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include <windows.h>

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}


// class definition
class bank_account{

private:  // declare data and functions only accessible within the class
	double interest_rate;
	double balance;
	string name;
public:  // declare data and functions accessible outside the class
	bank_account(string new_name);
	~bank_account();

	void make_deposit(double amount);
	void make_withdrawal(double amount);
	void get_balance();
};

bank_account::bank_account(string new_name)  //constructor
{
	name = new_name;
	balance = 0.0;
	cout << "The initial balance for "<< name << " Account is $" << balance << endl << endl;
}

bank_account::~bank_account()  //destructor
{
	cout << "The final balance for " << name << " Account is $" << balance << endl << endl;
}

void bank_account::make_deposit(double amount)
{
	balance = balance + amount;
}

void bank_account::make_withdrawal(double amount)
{
	if (amount <= balance)
	{
		balance = balance - amount;
	}
	else
		cout << "You do not have enough money to make that withdrawal" << endl << endl;
}
 
void bank_account::get_balance()
{
	cout << "Your balance is $" << fixed << setprecision(2) << balance << endl << endl;
}


int main()
{
	double scale = .01;

	bank_account my_savings_account("Savings");    //create a savings account object

	bank_account checkings_account("Checkings");		 //create a Checkings account object
	bank_account holiday_club("Holiday club");			 //create a Holiday club object
	bank_account automotive_loan("Auto Loan");		 //create a Automotive Loan object

	double amount = 0;
	string choice;
	string account;
	string transfer;
	cout << "Please Choose which account you would like to open" << endl << "Hit S for savings account" << endl;
	cout << "Hit C for your Checkings account" << endl << "Hit H for Holiday Club account" << endl;
	cout << "Hit A for your Auto Loan account" << endl << endl;
	cin >> account;
	ClearScreen();
	if(account == "S" || account == "s")
	{
		cout << "You have Chosen your Savings Account" << endl << endl;
	}
	else
	if (account == "C" || account == "c")
	{
		cout << "You have Chosen your Checkings Account" << endl << endl;
	}
	else
	if (account == "H" || account == "h")
	{
		cout << "You have Chosen your Holiday Club Account" << endl << endl;
	}
	else
	if (account == "A" || account == "a")
	{
		cout << "You have Chosen your Auto Loan account" << endl << endl;
	}
	else
		cout << "Invalid choice" << endl;


	for (int i = 2; i > 0; i++)
	{
		cout << "Choose the next action you would like to take" << endl;
		cout << "To enter a deposit, hit D" << endl;
		cout << "To withdraw an amount, hit W" << endl;
		cout << "To view account balance, hit B" << endl;
		cout << "To exit the program, hit Q" << endl;
		cout << "To transfer money, hit T" << endl;
		cout << "To switch accounts, hit S" << endl;
		cin >> choice;
		cout << endl;
		ClearScreen();

		if (choice == "D" || choice == "d")
		{
			cout << "Please Enter the amount you would like to deposit" << endl;
			cin >> amount;
			amount = (int)(amount / scale) * scale;
			cout << endl;
			if (account == "S" || account == "s")
			{
			my_savings_account.make_deposit(amount);
			}
			else
			if (account == "C" || account == "c")
			{
				checkings_account.make_deposit(amount);
			}
			else 
			if (account == "H" || account == "h")
			{
				holiday_club.make_deposit(amount);
			}
			else
			if (account == "A" || account == "a")
			{
				automotive_loan.make_deposit(amount);
			}
			else
			{
				cout << "error" << endl;
			}
			
		}
		else

		if (choice == "W" || choice == "w")
		{
			cout << "Please Enter the amount you would like to withdraw" << endl;
			cin >> amount;
			amount = (int)(amount / scale) * scale;
			cout << endl;

			if (account == "S" || account == "s")
			{
				my_savings_account.make_withdrawal(amount);
			}
			else
			if (account == "C" || account == "c")
			{
				checkings_account.make_withdrawal(amount);
			}
			else
			if (account == "H" || account == "h")
			{
				holiday_club.make_withdrawal(amount);
			}
			else
			if (account == "A" || account == "a")
			{
				automotive_loan.make_withdrawal(amount);
			}
			else
			{
				cout << "error" << endl;
			}

		}
		else

		if (choice == "B" || choice == "b")
		{
			if (account == "S" || account == "s")
			{
				my_savings_account.get_balance();
			}
			else

			if (account == "C" || account == "c")
			{
				checkings_account.get_balance();
			}
			else

			if (account == "H" || account == "h")
			{
				holiday_club.get_balance();
			}
			else

			if (account == "A" || account == "a")
			{
				automotive_loan.get_balance();
			}
			else

			{
				cout << "error" << endl;
			}

		}
		else

		if(choice == "T" || choice == "t")
		{
			cout << "Which account would you like to transfer to?" << endl << "Hit S for savings account" << endl;
			cout << "Hit C for your Checkings account" << endl << "Hit H for Holiday Club account" << endl;
			cout << "Hit A for your Auto Loan account" << endl << endl;
			
			cin >> choice;
			cout << "How much would you like to transfer?" << endl;
			cin >> amount;
			amount = (int)(amount / scale) * scale;
			cout << endl;

			if (account == "S" || account == "s")
			{
				if (choice == "S" || choice == "s")
				{
					cout << "You cannot transfer to the same account" << endl << endl;
				}
				if (choice == "C" || choice == "c")
				{
					my_savings_account.make_withdrawal(amount);
					checkings_account.make_deposit(amount);
					cout << "You have transfered " << amount << " from you Savings account to your Checking account" << endl << endl;
				}
				else

				if (choice == "H" || choice == "h")
				{
					my_savings_account.make_withdrawal(amount);
					holiday_club.make_deposit(amount);
					cout << "You have transfered " << amount << " from you Savings account to your Holiday Club account" << endl << endl;
				}
				else

				if (choice == "A" || choice == "a")
				{
					my_savings_account.make_withdrawal(amount);
					automotive_loan.make_deposit(amount);
					cout << "You have transfered " << amount << " from you Savings account to your Auto loan account" << endl << endl;
				}
			}

			else

			if (account == "C" || account == "c")
			{
				if (choice == "S" || choice == "s")
				{
					my_savings_account.make_deposit(amount);
					checkings_account.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Checking account to your Savings account" << endl << endl;
				}
				else
				if (choice == "C" || choice == "c")
				{
					cout << "You cannot transfer to the same account" << endl << endl;
				}
				else
				if (choice == "H" || choice == "h")
				{
					holiday_club.make_deposit(amount);
					checkings_account.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Checking account to your Holiday Club account" << endl << endl;
				}
				else
				if (choice == "A" || choice == "a")
				{
					automotive_loan.make_deposit(amount);
					checkings_account.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Checking account to your Auto loan account" << endl << endl;
				}
				
			}
			else

			if (account == "H" || account == "h")
			{
				if (choice == "S" || choice == "s")
				{
					my_savings_account.make_deposit(amount);
					holiday_club.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Holiday Club account to your Savings account" << endl << endl;
				}
				else
				if (choice == "C" || choice == "c")
				{
					checkings_account.make_deposit(amount);
					holiday_club.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Holiday Club account to your Checking account" << endl << endl;
				}
				else
				if (choice == "H" || choice == "h")
				{
					cout << "You cannot transfer to the same account" << endl << endl;
				}
				else
				if (choice == "A" || choice == "a")
				{
					automotive_loan.make_deposit(amount);
					holiday_club.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Holiday Club account to your Auto loan account" << endl << endl;
				}
				
			}
			else

			if (account == "A" || account == "a")
			{
				if (choice == "S" || choice == "s")
				{
					my_savings_account.make_deposit(amount);
					automotive_loan.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Auto loan account to your Savings account" << endl << endl;
				}
				else
				if (choice == "C" || choice == "c")
				{
					checkings_account.make_deposit(amount);
					automotive_loan.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Auto loan account to your Checking account" << endl << endl;
				}
				else
				if (choice == "H" || choice == "h")
				{
					holiday_club.make_deposit(amount);
					automotive_loan.make_withdrawal(amount);
					cout << "You have transfered " << amount << " from you Auto loan account to your Holiday Club account" << endl << endl;
				}
				else
				if (choice == "A" || choice == "a")
				{
					cout << "You cannot transfer to the same account" << endl << endl;
				}
			
			}
			else

			{
				cout << "error" << endl << endl;
			}
		}
		else
		if (choice == "S" || choice == "s")
		{
			cout << "Please Choose which account you would like to open" << endl << "Hit S for savings account" << endl;
			cout << "Hit C for your Checkings account" << endl << "Hit H for Holiday Club account" << endl;
			cout << "Hit A for your Auto Loan account" << endl << endl;
			cin >> account;
			ClearScreen();
			if (account == "S" || account == "s")
			{
				cout << "You have Chosen your Savings Account" << endl << endl;
			}
			else
			if (account == "C" || account == "c")
			{
				cout << "You have Chosen your Checkings Account" << endl << endl;
			}
			else
			if (account == "H" || account == "h")
			{
				cout << "You have Chosen your Holiday Club Account" << endl << endl;
			}
			else
			if (account == "A" || account == "a")
			{
				cout << "You have Chosen your Auto Loan account" << endl << endl;
			}
			else
				cout << "Invalid choice" << endl;

		}
			else
		if (choice == "Q" || choice == "q")
		{
			break;
		}
		else
		{
			cout << "That is not a valid input" << endl << endl;
		}
	}
	return 0;
}
