#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>  
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;

void insertionSort(int[], int, int[]);


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
class die {
protected:
	int maxface;
public:
	die() {}				//constructor
	~die() {}				//descructor
	die(int x)		//overloaded constructor
	{
		maxface = x;
	}
	int roll()					//random face the die
	{

		return rand() % maxface;;
	}
	int display_face(int Die_Face[], int whichdie, int choice[], int col, int row)
	{
		HANDLE                      hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO  csbi;
		SHORT                       screenRows;
		SHORT                       screenColumns;
		SHORT						screenLeft;
		SHORT						screenRight;
		SHORT						screenTop;
		SHORT						screenBottom;

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return 0;
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return 0;

		screenRows = csbi.dwMaximumWindowSize.Y;
		screenColumns = csbi.dwMaximumWindowSize.X;

		screenLeft = csbi.srWindow.Left;
		screenRight = csbi.srWindow.Right;
		screenTop = csbi.srWindow.Top;
		screenBottom = csbi.srWindow.Bottom;

		col = 10 * whichdie;
		row = row;
		if (choice[whichdie] % 2 != 0)
		{
			row = row + 12;
		}
		else
		{
			row = row;
			col = col;
		}

		switch (Die_Face[whichdie])
		{

		case 0:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|       |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|   O   |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|       |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 
				  cout << endl << endl;
				  break;
		}
		case 1:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O     |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|       |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|     O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 
				  cout << endl << endl;
				  break;
		}
		case 2:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O     |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|   O   |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|     O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 

				  cout << endl << endl;
				  break;
		}
		case 3:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|       |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 
				  cout << endl << endl;
				  break;
		}
		case 4:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "|   O   |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 
				  cout << endl << endl;
				  break;
		}
		case 5:
		{
				  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "| O   O |";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "+-------+";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				  cout << "    " << whichdie + 1 << "    "; 
				  cout << endl << endl;
				  break;

		}
		default:
		{
				   break;
		}
		}
		return whichdie;
	}
};
class hand {
protected:
	int maxhand;
public:
	hand() {}				//constructor
	~hand() {}				//descructor
	hand(int x)		//overloaded constructor
	{
		maxhand = x;
	}
	int roll_or_keep(int Die_Face[], int whichdie, int choice[], int counter)
	{
		// Make into an inherited function of the score. make the case statements with if statements in it.
		int x = 0;
		int keep;
		cout << "How many die would you like to move" << endl;
		cin >> x;
		if (x > 0 && x <= 5)
		{
			for (int k = 0; k < x; k++)
			{
				cout << "Which die would you like to move?" << endl;
				cin >> keep;
				choice[keep - 1]++;

			}
		}
		else
		if (x < 0 || x > 5)
		{
			cout << "That is not a valid amount" << endl;
		}

		ClearScreen();

		return whichdie;
	}
	
};

class score {
protected:
	int predicted_score = 0;
	bool iskept = false;
	string title;
	int kept_score = 0;
public:
	score() {}				//constructor
	~score() {}				//descructor
	score(string x)//overloaded constructor
	{
		title = x;
	}
	int display_score(int col, int row, int Die_Face[], int maxrolls, int whichscore)
	{
		HANDLE                      hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO  csbi;
		SHORT                       screenRows;
		SHORT                       screenColumns;
		SHORT						screenLeft;
		SHORT						screenRight;
		SHORT						screenTop;
		SHORT						screenBottom;

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return 0;
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return 0;

		screenRows = csbi.dwMaximumWindowSize.Y;
		screenColumns = csbi.dwMaximumWindowSize.X;

		screenLeft = csbi.srWindow.Left;
		screenRight = csbi.srWindow.Right;
		screenTop = csbi.srWindow.Top;
		screenBottom = csbi.srWindow.Bottom;
		if (whichscore < 10)
		{
		
		if (iskept == false)
		{
			if (predicted_score < 10)
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << whichscore << "  |" << title << " |  " << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}
			else
			if (predicted_score >= 10 && predicted_score < 100)
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << whichscore << "  |" << title << " | " << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}
			else
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << whichscore << "  |" << title << " |" << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}
		}
		if (iskept == true)
		{

			if (kept_score < 10)
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "X" << "  |" << title << " |  " << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}
			else
			if (kept_score >= 10 && kept_score < 100)
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "X" << "  |" << title << " | " << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}
			else
			{
				SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "X" << "  |" << title << " |" << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
				cout << "   |--------------------|";
				return row;
			}

		}
		}
		if (whichscore >= 10)
		{
			if (iskept == false)
			{
				if (predicted_score < 10)
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << whichscore << " |" << title << " |  " << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
				else
				if (predicted_score >= 10 && predicted_score < 100)
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << whichscore << " |" << title << " | " << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
				else
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << whichscore << " |" << title << " |" << predicted_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
			}
			if (iskept == true)
			{

				if (kept_score < 10)
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "X" << "  |" << title << " |  " << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
				else
				if (kept_score >= 10 && kept_score < 99)
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "X" << "  |" << title << " | " << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
				else
				{
					SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "X" << " |" << title << " |" << kept_score << "|";  SetConsoleCursorPosition(hStdOut, { col, row++ });
					cout << "   |--------------------|";
					return row;
				}
			

			}
		}
		return row;
	}
	
	void which_keep()
	{
			kept_score = predicted_score;
			iskept = true;
	}
	
	bool is_kept()
	{
		return iskept;
	}

	int functionkeptscore()
	{
		return kept_score;
	}
};

class ones : public score {
protected:
public:
	ones() {}					//constructor
	~ones() {}					//destructor
	ones(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 1)
			{
				predicted_score++;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;
	}
};

class twos : public score {
protected:
public:
	twos() {}					//constructor
	~twos() {}					//destructor
	twos(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 2)
			{
				predicted_score = predicted_score + 2;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;

	}
};

class threes : public score {
protected:
public:
	threes() {}					//constructor
	~threes() {}					//destructor
	threes(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 3)
			{
				predicted_score = predicted_score + 3;

			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;
	}
};
class fours : public score {
protected:
public:
	fours() {}					//constructor
	~fours() {}					//destructor
	fours(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 4)
			{
				predicted_score = predicted_score + 4;

			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;
	}
};

class fives : public score {
protected:
public:
	fives() {}					//constructor
	~fives() {}					//destructor
	fives(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 5)
			{
				predicted_score = predicted_score + 5;

			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;
	}
};

class sixes : public score {
protected:
public:
	sixes() {}					//constructor
	~sixes() {}					//destructor
	sixes(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls, int bonus)
	{
		predicted_score = 0;
		for (int x = 0; x < maxrolls; x++)
		{
			if (Sort_Face[x] == 6)
			{
				predicted_score = predicted_score + 6;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		bonus = bonus + predicted_score;
		return predicted_score, bonus;
	}
};

class bonus_score : public score {
protected:
public:
	bonus_score() {}					//constructor
	~bonus_score() {}					//destructor
	bonus_score(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int bonus)
	{
		predicted_score = 0;
			if (bonus >= 63)
			{
				kept_score = 35;
				iskept = true;
			}
			else
			{
				predicted_score = 0;
			}

		return predicted_score;
	}
};

class three_of_a_kind : public score {
protected:
public:
	three_of_a_kind() {}					//constructor
	~three_of_a_kind() {}					//destructor
	three_of_a_kind(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[0] == Sort_Face[1] && Sort_Face[1] == Sort_Face[2])
		{
			for (int x = 0; x < maxrolls; x++)
			{
				predicted_score = predicted_score + Sort_Face[x];
			}
		}
		else
		if (Sort_Face[1] == Sort_Face[2] && Sort_Face[2] == Sort_Face[3])
		{
			for (int x = 0; x < maxrolls; x++)
			{
				predicted_score = predicted_score + Sort_Face[x];
			}
		}
		else
		if (Sort_Face[2] == Sort_Face[3] && Sort_Face[3] == Sort_Face[4])
		{
			for (int x = 0; x < maxrolls; x++)
			{
				predicted_score = predicted_score + Sort_Face[x];
			}
		}
		else
		{
			predicted_score = predicted_score;
		}
		return predicted_score;
	}
};
class four_of_a_kind : public score {
protected:
public:
	four_of_a_kind() {}					//constructor
	~four_of_a_kind() {}					//destructor
	four_of_a_kind(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[0] == Sort_Face[1] && Sort_Face[1] == Sort_Face[2] && Sort_Face[2] == Sort_Face[3])
		{
			for (int x = 0; x < maxrolls; x++)
			{
				predicted_score = predicted_score + Sort_Face[x];
			}
		}
		else
		if (Sort_Face[1] == Sort_Face[2] && Sort_Face[2] == Sort_Face[3] && Sort_Face[3] == Sort_Face[4])
		{
			for (int x = 0; x < maxrolls; x++)
			{
				predicted_score = predicted_score + Sort_Face[x];
			}
		}
		else
		{
			predicted_score = predicted_score;
		}
		return predicted_score;
	}
};

class full_house : public score {
protected:
public:
	full_house() {}					//constructor
	~full_house() {}					//destructor
	full_house(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[0] == Sort_Face[1] && Sort_Face[1] == Sort_Face[2] && Sort_Face[3] == Sort_Face[4])
		{
			predicted_score = 25;
		}
		else
		if (Sort_Face[0] == Sort_Face[1] && Sort_Face[2] == Sort_Face[3] && Sort_Face[3] == Sort_Face[4])
		{
			predicted_score = 25;
		}
		else
		{
			predicted_score = predicted_score;
		}
		return predicted_score;
	}
};

class small_straight : public score {
protected:
public:
	small_straight() {}					//constructor
	~small_straight() {}					//destructor
	small_straight(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[1] != Sort_Face[2] && Sort_Face[2] != Sort_Face[3])
		{
			if (Sort_Face[0] + 1 == Sort_Face[1] && Sort_Face[1] + 1 == Sort_Face[2] && Sort_Face[2] + 1 == Sort_Face[3])
			{
				predicted_score = 30;
			}
			else
			if (Sort_Face[1] + 1 == Sort_Face[2] && Sort_Face[2] + 1 == Sort_Face[3] && Sort_Face[3] + 1 == Sort_Face[4])
			{
				predicted_score = 30;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		if (Sort_Face[1] == Sort_Face[2] && Sort_Face[2] != Sort_Face[3])
		{
			if (Sort_Face[0] + 1 == Sort_Face[2] && Sort_Face[2] + 1 == Sort_Face[3] && Sort_Face[3] + 1 == Sort_Face[4])
			{
				predicted_score = 30;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		if (Sort_Face[1] != Sort_Face[2] && Sort_Face[2] == Sort_Face[3])
		{
			if (Sort_Face[0] + 1 == Sort_Face[1] && Sort_Face[1] + 1 == Sort_Face[3] && Sort_Face[3] + 1 == Sort_Face[4])
			{
				predicted_score = 30;
			}
			else
			{
				predicted_score = predicted_score;
			}
		}
		return predicted_score;
	}
};

class large_straight : public score {
protected:
public:
	large_straight() {}					//constructor
	~large_straight() {}					//destructor
	large_straight(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[0] + 1 == Sort_Face[1] && Sort_Face[1] + 1 == Sort_Face[2] && Sort_Face[2] + 1 == Sort_Face[3] && Sort_Face[3] + 1 == Sort_Face[4])
		{
			predicted_score = 40;
		}
		else
		{
			predicted_score = predicted_score;
		}
		return predicted_score;
	}
};

class chance : public score {
protected:
public:
	chance() {}					//constructor
	~chance() {}					//destructor
	chance(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		for (int l = 0; l < maxrolls; l++)
		{
			predicted_score = Sort_Face[l] + predicted_score;
		}
		return predicted_score;
	}
};

class yahtzee : public score {
protected:

public:
	yahtzee() {}					//constructor
	~yahtzee() {}					//destructor
	yahtzee(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int Sort_Face[], int maxrolls)
	{
		predicted_score = 0;
		if (Sort_Face[0] == Sort_Face[1] && Sort_Face[1] == Sort_Face[2] && Sort_Face[2] == Sort_Face[3] && Sort_Face[3] == Sort_Face[4])
		{
			predicted_score = 50;
		}

		return predicted_score;
	}
};

class total : public score {
protected:

public:
	total() {}					//constructor
	~total() {}					//destructor
	total(string x)	//overloaded constructor
	{
		title = x;
	}

	int potential_score(int totalscore)
	{
		predicted_score = totalscore;
		return predicted_score;
	}
};
int main()
{
	srand(static_cast <int>(time(NULL)));
	const int maxrolls = 5;
	int Die_Face[maxrolls] = {};
	int Sort_Face[maxrolls] = {};
	int whichdie = 0;
	int choice[maxrolls] = {};
	hand myhand(5);
	die mydie(6);
	int placeholder_face[maxrolls] = {};
	int counter = 0;
	const int maxscores = 15;
	bool kept_something = false;
	int bonus = 0;
	int whichscore = 0;
	int predictedscore[maxscores] = {};
	score myscore("placeholder");
	ones myones("ones           ");
	twos mytwos("twos           ");
	threes mythrees("threes         ");
	fours myfours("fours          ");
	fives myfives("fives          ");
	sixes mysixes("sixes          ");
	bonus_score mybonus("bonus          ");
	three_of_a_kind mythree_of_a_kind("Three of a kind");
	four_of_a_kind myfour_of_a_kind("Four of a kind ");
	full_house myfull_house("Full House     ");
	small_straight mysmall_straight("Small Straight ");
	large_straight mylarge_straight("Large Straight ");
	chance mychance("Chance         ");
	yahtzee myyahtzee("Yahtzee        ");
	total mytotal("Total          ");
	int totalscore = 0;






	/*
	---------------------------------------------------------------------------------------------------------
	The console window is basically a 2 dimensional array of characters.
	The size of the array depends on how your computer's console window has been configured.
	Let's say your console is configured to be 132 characters wide and 50 characters tall.

	The top left corner of the screen is at location [0,0].
	The top right corner of the screen is at location [131,0]
	The bottom left corner of the screen is at location [0,49]
	The bottom right corner of the screen is at location [131,49]

	You can position the cursor anywhere in those values and output to the screen
	---------------------------------------------------------------------------------------------------------
	*/
	HANDLE                      hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO  csbi;
	SHORT                       screenRows;
	SHORT                       screenColumns;
	SHORT						screenLeft;
	SHORT						screenRight;
	SHORT						screenTop;
	SHORT						screenBottom;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return 0;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return 0;

	screenRows = csbi.dwMaximumWindowSize.Y;
	screenColumns = csbi.dwMaximumWindowSize.X;

	screenLeft = csbi.srWindow.Left;
	screenRight = csbi.srWindow.Right;
	screenTop = csbi.srWindow.Top;
	screenBottom = csbi.srWindow.Bottom;

	for (int o = 0; o < 13; o++)
	{
		for (int j = 0; j < 5; j++)
		{
			choice[j] = 0;
		}

		for (int l = 0; l < 3; l++)
		{
			bonus = myones.functionkeptscore() + mytwos.functionkeptscore() + mythrees.functionkeptscore() + myfours.functionkeptscore() + myfives.functionkeptscore() + mysixes.functionkeptscore(); // Continue this through sixes
			totalscore = myones.functionkeptscore() + mytwos.functionkeptscore() + mythrees.functionkeptscore() + myfours.functionkeptscore() + myfives.functionkeptscore() + mysixes.functionkeptscore() + mythree_of_a_kind.functionkeptscore() + myfour_of_a_kind.functionkeptscore() + myfull_house.functionkeptscore() + mysmall_straight.functionkeptscore() + mylarge_straight.functionkeptscore() + mychance.functionkeptscore() + myyahtzee.functionkeptscore();
			whichdie = 0;
			int col = screenLeft + 50;
			int row = screenTop;
			for (int k = 0; k < maxrolls; k++)
			{
				placeholder_face[k] = Die_Face[k];
				Die_Face[k] = mydie.roll();
				if (choice[k] % 2 != 0)
				{
					Die_Face[k] = placeholder_face[k];
				}
				mydie.display_face(Die_Face, whichdie, choice, col, row);
				whichdie++;

			}
			insertionSort(Die_Face, maxrolls, Sort_Face);
			/////////////////////////////////////////////////
			predictedscore[0] = myones.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[1] = mytwos.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[2] = mythrees.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[3] = myfours.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[4] = myfives.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[5] = mysixes.potential_score(Sort_Face, maxrolls, bonus);
			predictedscore[6] = mybonus.potential_score(bonus);
			predictedscore[7] = mythree_of_a_kind.potential_score(Sort_Face, maxrolls);
			predictedscore[8] = myfour_of_a_kind.potential_score(Sort_Face, maxrolls);
			predictedscore[9] = myfull_house.potential_score(Sort_Face, maxrolls);
			predictedscore[10] = mysmall_straight.potential_score(Sort_Face, maxrolls);
			predictedscore[11] = mylarge_straight.potential_score(Sort_Face, maxrolls);
			predictedscore[12] = mychance.potential_score(Sort_Face, maxrolls);
			predictedscore[13] = myyahtzee.potential_score(Sort_Face, maxrolls);
			predictedscore[14] = mytotal.potential_score(totalscore);
			/////////////////////////////////////////////////
			col = 50;
			row = 0;
			SetConsoleCursorPosition(hStdOut, { col, row++ });
			cout << "   ______________________" << endl;
			whichscore = 0;
			whichscore++;
			row = myones.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mytwos.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mythrees.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = myfours.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = myfives.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mysixes.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore = 0;
			row = mybonus.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore = 7;
			row = mythree_of_a_kind.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = myfour_of_a_kind.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = myfull_house.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mysmall_straight.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mylarge_straight.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mychance.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = myyahtzee.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore++;
			row = mytotal.display_score(col, row, Die_Face, maxrolls, whichscore);
			whichscore = 0;
			////////////////////////////////////////////////
			col = 1;
			row = 22;
			SetConsoleCursorPosition(hStdOut, { col, row++ });
			myhand.roll_or_keep(Die_Face, whichdie, choice, counter);
		}
		whichdie = 0;
		int col = screenLeft + 50;
		int row = screenTop;
		for (int k = 0; k < maxrolls; k++)
		{
			placeholder_face[k] = Die_Face[k];
			Die_Face[k] = mydie.roll();
			if (choice[k] % 2 != 0)
			{
				Die_Face[k] = placeholder_face[k];
			}
			mydie.display_face(Die_Face, whichdie, choice, col, row);
			whichdie++;
		}
		insertionSort(Die_Face, maxrolls, Sort_Face);
		/////////////////////////////////////////////////
		myones.potential_score(Sort_Face, maxrolls, bonus);
		mytwos.potential_score(Sort_Face, maxrolls, bonus);
		mythrees.potential_score(Sort_Face, maxrolls, bonus);
		myfours.potential_score(Sort_Face, maxrolls, bonus);
		myfives.potential_score(Sort_Face, maxrolls, bonus);
		mysixes.potential_score(Sort_Face, maxrolls, bonus);
		mybonus.potential_score(bonus);
		mythree_of_a_kind.potential_score(Sort_Face, maxrolls);
		myfour_of_a_kind.potential_score(Sort_Face, maxrolls);
		myfull_house.potential_score(Sort_Face, maxrolls);
		mysmall_straight.potential_score(Sort_Face, maxrolls);
		mylarge_straight.potential_score(Sort_Face, maxrolls);
		mychance.potential_score(Sort_Face, maxrolls);
		myyahtzee.potential_score(Sort_Face, maxrolls);
		mytotal.potential_score(totalscore);
		/////////////////////////////////////////////////
		col = 50;
		row = 0;
		SetConsoleCursorPosition(hStdOut, { col, row++ });
		cout << "   ______________________" << endl;
		whichscore++;
		row = myones.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mytwos.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mythrees.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = myfours.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = myfives.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mysixes.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore = 0;
		row = mybonus.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore = 7;
		row = mythree_of_a_kind.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = myfour_of_a_kind.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = myfull_house.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mysmall_straight.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mylarge_straight.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mychance.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = myyahtzee.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore++;
		row = mytotal.display_score(col, row, Die_Face, maxrolls, whichscore);
		whichscore = 0;
		////////////////////////////////////////////////
		cout << endl << endl;
		
		kept_something = false;
		do
		{
			cout << "Which score would you like to keep? (1-13)" << endl;
			cin >> whichscore;
			switch (whichscore)
			{
			case 1:
			{
					  if (myones.is_kept() == false)
					  {
						  myones.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 2:
			{
					  if (mytwos.is_kept() == false)
					  {
						  mytwos.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 3:
			{
					  if (mythrees.is_kept() == false)
					  {
						  mythrees.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 4:
			{
					  if (myfours.is_kept() == false)
					  {
						  myfours.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 5:
			{
					  if (myfives.is_kept() == false)
					  {
						  myfives.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 6:
			{
					  if (mysixes.is_kept() == false)
					  {
						  mysixes.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 7:
			{
					  if (mythree_of_a_kind.is_kept() == false)
					  {
						  mythree_of_a_kind.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 8:
			{
					  if (myfour_of_a_kind.is_kept() == false)
					  {
						  myfour_of_a_kind.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 9:
			{
					  if (myfull_house.is_kept() == false)
					  {
						  myfull_house.which_keep();
						  kept_something = true;
					  }
					  else
					  {
						  cout << "That score has already been kept, please choose another" << endl;
					  }
					  break;
			}
			case 10:
			{
					   if (mysmall_straight.is_kept() == false)
					   {
						   mysmall_straight.which_keep();
						   kept_something = true;
					   }
					   else
					   {
						   cout << "That score has already been kept, please choose another" << endl;
					   }
					   break;
			}
			case 11:
			{
					   if (mylarge_straight.is_kept() == false)
					   {
						   mylarge_straight.which_keep();
						   kept_something = true;
					   }
					   else
					   {
						   cout << "That score has already been kept, please choose another" << endl;
					   }
					   break;
			}
			case 12:
			{
					   if (mychance.is_kept() == false)
					   {
						   mychance.which_keep();
						   kept_something = true;
					   }
					   else
					   {
						   cout << "That score has already been kept, please choose another" << endl;
					   }
					   break;
			}
			case 13:
			{
					   if (myyahtzee.is_kept() == false)
					   {
						   myyahtzee.which_keep();
						   kept_something = true;
					   }
					   else
					   {
						   cout << "That score has already been kept, please choose another" << endl;
					   }

					   break;
			}
			default:
				{
					cout << "That is not a valid score number" << endl;
				}
			}
		} while (kept_something == false);

		ClearScreen();
	}
	cout << "Your final score is " << totalscore << endl;
	
	return 0;
}

void insertionSort(int Die_Face[], int maxrolls, int Sort_Face[])
{
	for (int p = 0; p < maxrolls; p++)
	{
		Sort_Face[p] = Die_Face[p] + 1;
	}

	int placeholder;
	placeholder = 0;
	for (int i = 1; i < maxrolls; i++)
	{
		placeholder = Sort_Face[i];
		for (int k = 0; k < i; k++)
		{
			if (Sort_Face[i] < Sort_Face[k])
			{
				for (int g = i; g > k; g--)
				{
					Sort_Face[g] = Sort_Face[g - 1];
				}
				Sort_Face[k] = placeholder;
				break;
			}
			else
			if (Sort_Face[i] >= Sort_Face[k])
			{

				Sort_Face[i] = placeholder;
			}
		}

	}

}