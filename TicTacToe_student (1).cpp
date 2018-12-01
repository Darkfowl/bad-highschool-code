#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int maxRows = 3;
const int maxCols = 3;


void printboard(char[][maxCols], int, int);
bool checkwinner(char array[][maxCols], int, int);
bool checkfull(char array[][maxCols], int, int);

int main()
{

	// declare boolean variables
	bool winner = false;  // used to check if there was a winner
	bool draw = false;    // used to check if there was a draw

	// declare the tictactoe board and initialize it to spaces
	char tictactoe[maxRows][maxCols] = { { ' ', ' ', ' ' }, 
	                                     { ' ', ' ', ' ' }, 
										 { ' ', ' ', ' ' } };

	int thisrow;      //used to decide which row to put in an X or O
	int thiscol;      //used to decide which column to pun in an X or O
	char XorO = 'X';  //used to switch back and forth between X and O,  start with X

	srand(static_cast <int>(time(NULL)));  //seed the random number generator

	do
	{
		thisrow = rand() % maxRows;  //randomly select a row
		thiscol = rand() % maxCols;  //randomly select a column

		if (tictactoe[thisrow][thiscol] == ' ')   //if the element hasn't been used
			tictactoe[thisrow][thiscol] = XorO;   //store the X or O in it

		printboard(tictactoe, maxRows, maxCols);  //print the tictactoe board to the screen

		// check to see if there was a winner.
		// if so, output whether X or O won.
		winner = checkwinner(tictactoe, maxRows, maxCols); 
		if (winner)
		{
			cout << XorO << " wins!" << endl << endl;    
		}

		// check to see if all elements on the board have been used.
		// if the board is full and there was no winner then it was a draw
		draw = checkfull(tictactoe, maxRows, maxCols) && !winner;
		if (draw)
		{
			cout << "It's a draw." << endl << endl;
		}

		// swtich between X and O
		if (XorO == 'X')
			XorO = 'O';
		else
			XorO = 'X';

	} while ( !winner && !draw); //continue 

	return 0;

}

// print the tictactoe board in a nice format
void printboard(char array[][maxCols], int rows, int cols)
{
	cout << "-------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << array[i][j] << setw(4) << "|";
		}
		cout << endl;
		cout << "-------------------------" << endl;
	}
	cout << endl;
}

//
bool checkwinner(char array[][maxCols], int rows, int cols)
{
	// Add your code here to check if there was a winner
	// defined as three of the same letter (X or O) exist in a row, column or diagonally
	// if there was a winner then return true.
	for (int h = 0; h < rows; h++)
	{
		if (array[h][0] == array[h][1] && array[h][0] == array[h][2])
		{
			if (array[h][0] == 'X' || array[h][0] == 'O')
			{
				return true;
			}
		}

	}
	for (int k = 0; k < cols; k++)
	{
		if (array[0][k] == array[1][k] && array[0][k] == array[2][k])
		{
			if (array[0][k] == 'X' || array[0][k] == 'O')
			{
				return true;
			}
		}

	}

	if (array[0][0] == array[1][1] && array[0][0] == array[2][2])
	{
		if (array[0][0] == 'X' || array[0][0] == 'O')
		{
			return true;
		}
	}
	if (array[0][2] == array[1][1] && array[0][2] == array[2][0])
	{
		if (array[0][2] == 'X' || array[0][2] == 'O')
		{
			return true;
		}
	}
	// if there is no winner then return false
	return false;
}

bool checkfull(char array[][maxCols], int rows, int cols)
{
	// Add your code here to check to see if all of the array elements 
	// have been populated with an X or an O  (all the spaces are gone).
	// If all elements have been used then return true.
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] == 'X' || array[i][j] == 'O')
				counter = counter + 1;
			else
				counter = counter - 1;
		
		}
	}
	if (counter >= 9)
		return true;

	else
	     return false;
}