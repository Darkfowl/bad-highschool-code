#include <iostream> 
using namespace std;
/* srand example */
#include <stdio.h> /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */

int main()
{
	int random;
	char key_pressed;
	int guess;
	key_pressed = 'k';
	
	srand((unsigned int)time(NULL));

	random = 500 + rand() % 1001;
	do
	{
		printf("Guess a random number from 500 to 1500 \n\n");
		cin >> guess;
		if (guess > random)
		{
			cout << "secret number is lower. \n\n";
		}
		else

		if (guess < random)
		{
			cout << "secret number is higher. \n\n";
		}
		else
		if (guess == random)
		{
			cout << "congrats, that is the secret number!. \n\n";
		}
		
		
		cout << "Enter Q to quit or any key to continue: \n\n";
		cin >> key_pressed;
		cout << "\n";
	} while (key_pressed != 'Q' && key_pressed != 'q');
	
	return 0;
}