//Calculator Project
//
#include <iostream> //allows the program to actually function correctly

//Beginning of program, adding the variables
int main() //like the "main program" the bracket thingys that let you do more than one thing with a program
{

	// variables in which the two numbers are stored as well as the operation
	int number1;
	int number2;
	int number3;
	char operation;
	char quit;

	//------------------------------------------------------------------------------
	//prompting the user to input into the keyboard
	//std::cin allows the keyboard to work in this case
	//------------------------------------------------------------------------------

	std::cout << "Enter Q to quit or enter C to continue: ";
	std::cin >> quit;

	if (quit != 'q' && quit != 'Q')
	{
	std::cout << "enter an integer number: ";
	std::cin >> number1;

	std::cout << "enter second integer number: ";
	std::cin >> number2;

	std::cout << "enter one of the following operations +,-,*,/ or %: ";
	std::cin >> operation;

	

	//------------------------------------------------------------------------------
	//the actual equation now
	//
	//------------------------------------------------------------------------------
	
	number3 = (number1 + number2);

		if (operation == '+')
			std::cout << number1 << "+" << number2 << "= " << number3 << "\n\n";

		//------------------------------------------------------------------------------
		//subtraction
		//
		//------------------------------------------------------------------------------

		number3 = (number1 - number2);

		if (operation == '-')
			std::cout << number1 << "-" << number2 << "=" << number3 << "\n\n";

		//------------------------------------------------------------------------------
		//multiplication
		//
		//------------------------------------------------------------------------------

		number3 = (number1 * number2);

		if (operation == '*')
			std::cout << number1 << "*" << number2 << "=" << number3 << "\n\n";

		//------------------------------------------------------------------------------
		//division
		//
		//------------------------------------------------------------------------------



		if (operation == '/' && number2 != 0)
			std::cout << number1 << "/" << number2 << "=" << number1 / number2 << "\n\n";

		if (operation == '/' && number2 == 0)
			std::cout << "Do not break the rules of math "  "\n\n";


		//------------------------------------------------------------------------------
		//module
		//
		//------------------------------------------------------------------------------

		if (operation == '%' && number2 == 0)
			std::cout << "Do not break the rules of math. "    "\n\n";



		if (operation == '%' && number2 != 0)
		{
			std::cout << number1 << "%" << number2 << "=" << number3 << "\n\n";
			number3 = (number1 % number2);
		}
		
		// Attempt at improper operator

	}
	
	if (operation != '+', '-', '*', '/', '%')
	{
		std::cout << "Invalid Operation."    "\n\n";
	}
	if (quit == 'q' || quit == 'Q')
	{
		return 0; //program ending
	}
} //end function