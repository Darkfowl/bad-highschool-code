#include <iostream> 
using namespace std;

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int toss(int);

int main()
{
	int heads, counter, tails;
		heads = 0;
		tails = 0;
		int random = 0;

		srand((unsigned int)time(NULL));

		for (counter = 0; counter < 150; counter = counter + 1) //calling for coin toss 150 times//
		{ 

		random = toss(random);  //coin toss called//
		
		if (random == 1)
		{
			heads = heads + 1;
			cout << "heads" << endl;
		}
		if (random == 0)
		{
			tails = tails + 1;
			cout << "tails" << endl;

		}
		}
		
		cout << "The coin was heads " << heads <<  " times." << endl;
		cout << "The coin was tails "<< tails << " times." << endl;

		if (heads == tails)
		{
			cout << "Its your lucky day!" << endl;
		}






		return  0;
}

int toss(int random)
{
	
	random = rand() % 2;
	return (random);
}