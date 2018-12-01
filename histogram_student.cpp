#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

int main()
{
	//an array to store random numbers
	const int numbersGenerated = 500;
	int random_number[numbersGenerated] = {};
	
	// an array to use in creating a histogram
	const int maxBuckets = 10;
	int buckets[maxBuckets] = {};


	srand(static_cast <int>( time(NULL) ));  //seed the random number generator
	
	// create and store random numbers between 0 and 100 in the array
	for (int i = 0; i < numbersGenerated; i++)
	{
		random_number[i] = rand() % 101;
		
		
		if (random_number[i] < 10 && random_number[i] > 0)
		{
			buckets [0] +=1;
		}
		else
		if (random_number[i] < 20 && random_number[i] > 9)
		{
			buckets[1] += 1;
		}
		else

		if (random_number[i] < 30 && random_number[i] > 19)
		{
			buckets[2] += 1;
		}
		else

		if (random_number[i] < 40 && random_number[i] > 29)
		{
			buckets[3] += 1;
		}
		else

		if (random_number[i] < 50 && random_number[i] > 39)
		{
			buckets[4] += 1;
		}
		else

		if (random_number[i] < 60 && random_number[i] > 49)
		{
			buckets[5] += 1;
		}
		else

		if (random_number[i] < 70 && random_number[i] > 59)
		{
			buckets[6] += 1;
		}
		else

		if (random_number[i] < 80 && random_number[i] > 69)
		{
			buckets[7] += 1;
		}
		else

		if (random_number[i] < 90 && random_number[i] > 79)
		{
			buckets[8] += 1;
		}
		else

		if (random_number[i] <= 100 && random_number[i] > 89)
		{
			buckets[9] += 1;
		}
	}

	// add your code here 
	cout << "Bucket [0];";
	for (int i = 0; i < buckets[0]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [1];";
	for (int i = 0; i < buckets[1]; i++)
	{
		cout << "x"; 
	}
	cout << endl;
	cout << "Bucket [2];";
	for (int i = 0; i < buckets[2]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [3];";
	for (int i = 0; i < buckets[3]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [4];";
	for (int i = 0; i < buckets[4]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [5];";
	for (int i = 0; i < buckets[5]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [6];";
	for (int i = 0; i < buckets[6]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [7];";
	for (int i = 0; i < buckets[7]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [8];";
	for (int i = 0; i < buckets[8]; i++)
	{
		cout << "x";
	}
	cout << endl;
	cout << "Bucket [9];";
	for (int i = 0; i < buckets[9]; i++)
	{
		cout << "x";
	}
	cout << endl;
	

	// 
	
	return 0;
}
