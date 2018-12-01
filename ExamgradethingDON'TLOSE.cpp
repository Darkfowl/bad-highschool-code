#include <iostream>
using namespace std;
int examgrade(int);

int main()
{
	int grade, counter, examaverage;

	counter = 0; 
	grade = 0;
	examaverage = 0;

	const int number_of_students = 10;   // instead of a "magic number"

	int Exam1_Grades[number_of_students];

	for (int i = 0; i < number_of_students; i++)
	{
		Exam1_Grades[i] = examgrade(grade);
	}
	
	for (counter = 0; counter < number_of_students; counter = counter + 1)
	{
		examaverage = examaverage + Exam1_Grades[counter];
	}

	examaverage = examaverage / number_of_students;

	cout << "The class average is: " << examaverage << endl;
}

int examgrade(int grade)
{
	cout << "Enter the next students grade: " << endl;
	cin >> grade;
	return (grade);
}



