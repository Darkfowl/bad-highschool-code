#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int NumStudents = 10;
const int NumGrades = 3;
void insertionSort(string[], int[], int[][NumGrades], int);
void getaverage(double[], int[][NumGrades], int);
int main() 
{

	

	string student_name[NumStudents] =  { "Joe Student",
	                                       "Mary Christmas",
	                                       "Phil Dirt",
	                                       "Jimmy Dean",
	                                       "Phil McKraken",
	                                       "Mike Keester",
	                                       "Warren Peace",
	                                       "Marge Innovera",
	                                       "Haywood Jabuzoff",
	                                       "Pikup Andropov" };

	int student_ID[NumStudents] = {	10124,
	                                    10001,
	                                    11020,
	                                    12251,
										10245,
										10029,
										10178,
										10042,
										10202,
										10054 };

	int student_grades[NumStudents][NumGrades] = {	{ 92, 93, 97 },
	                                                { 85, 81, 75 },
													{ 87, 88, 93 },
													{ 78, 85, 90 },
													{ 81, 85, 89 },
													{ 89, 95, 99 },
													{ 92, 86, 88 },
													{ 68, 73, 65 },
													{ 93, 78, 84 },
													{ 90, 85, 95 } };

	double student_average[NumStudents] = { 0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0, };
	insertionSort(student_name, student_ID, student_grades, NumStudents);
	getaverage(student_average, student_grades, NumGrades);
	cout.flags(ios::left);   //align cout fields to the left
	cout.precision(3);       //output significant figures for real values

	cout << setw(20) << "Name"           << "ID         Exam 1  Exam 2  Exam 3    Average" << endl;
	for (int i = 0; i < NumStudents; i++)
	{
	cout << setw(20) << student_name[i] << student_ID[i] <<"      "<< student_grades[i][0] <<"     "<< student_grades[i][1] <<"         "<< student_grades[i][2] << "      "<< setprecision(1) << fixed << student_average[i] << endl;
	}
	
	return 0;
}
void insertionSort(string student_name[], int student_ID[], int student_grades[][NumGrades], int NumStudents)
{
	int placeholderID, placeholdergrade1, placeholdergrade2, placeholdergrade3;
	string placeholderstudent = "Hello MR.D";
	placeholderID = 0;
	placeholdergrade1 = 0;
	placeholdergrade2 = 0;
	placeholdergrade3 = 0;

	for (int i = 1; i < NumStudents; i++)
	{
		placeholderID = student_ID[i];
		placeholderstudent = student_name[i];
		placeholdergrade1 = student_grades[i][0];
		placeholdergrade2 = student_grades[i][1];
		placeholdergrade3 = student_grades[i][2];
		for (int k = 0; k < i; k++)
		{
			if (student_ID[i] < student_ID[k])
			{
				for (int g = i; g > k; g--)
				{
					student_ID[g] = student_ID[g - 1];
				}
				student_ID[k] = placeholderID;
				
				for (int u = i; u > k; u--)
				{
					student_name[u] = student_name[u - 1];
				}
				student_name[k] = placeholderstudent;
				
				for (int l = i; l > k; l--)
				{
					student_grades[l][0] = student_grades[l - 1][0];
				}
				student_grades[k][0] = placeholdergrade1;
			
				for (int f = i; f > k; f--)
				{
					student_grades[f][1] = student_grades[f - 1][1];
				}
				student_grades[k][1] = placeholdergrade2;

				for (int t = i; t > k; t--)
				{
					student_grades[t][2] = student_grades[t - 1][2];
				}
				student_grades[k][2] = placeholdergrade3;
				break;
			}
			else
			if (student_ID[i] >= student_ID[k])
			{

				student_ID[i] = placeholderID;
			}
		}

	}
}
void getaverage(double student_average[], int student_grades[][NumGrades], int Numgrades)
{
	for (int i = 0; i < NumStudents; i++)
	{
		student_average[i] = student_grades[i][0] + student_grades[i][1] + student_grades[i][2];
		student_average[i] = student_average[i] / NumGrades;
	}



}