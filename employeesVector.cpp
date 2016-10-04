#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct
{
	char name[15];
	char sername[20];
	int age;
	int experience;
}
TEmploee;

ifstream fin;

void output(vector <TEmploee> &A)
{
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		cout << "Employee " << i + 1 << ":" << endl;
		cout << A[i].name << ", " << A[i].sername << ", " << A[i].age << ", " << A[i].experience << endl << endl;
	}
}

void outputForSort(TEmploee** A, int size) //процедура вывода в консоль при сортировке. Передавался указатель
{
	for (int i = 0; i < size; i++)
	{
		cout << "Сотрудник номер " << i + 1 << ":" << endl;
		cout << A[i]->name << " " << A[i]->sername << ", " << A[i]->age << ", " << A[i]->experience << endl << endl;
	}
}

void writeDown(const vector <TEmploee> &A)
{
	int n = A.size();

	ofstream fout;
	fout.open("emploees.dat", ios::binary);
	for (int i = 0; i<n; i++)
	{
		fout.write((char*)&A[i], sizeof(TEmploee));
	}
	fout.close();
}
void add(vector <TEmploee> &A)
{
	int n = A.size();
	TEmploee tmp;
	cout << n << endl;
	cout << "Enter employee's name:  ";
	cin >> tmp.name;
	cout << endl << "Enter employee's name: ";
	cin >> tmp.sername;
	cout << endl << "Enter employee's age: ";
	cin >> tmp.age;
	cout << endl << "Enter employee's experience: ";
	cin >> tmp.experience;
	A.push_back(tmp);
	writeDown(A);
}

void sort(vector <TEmploee> A)
{
	int n = A.size();
	TEmploee **P = new TEmploee*[n];
	for (int i = 0; i<n; ++i)
	{
		P[i] = &A[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (P[j]->age > P[j + 1]->age)
			{
				TEmploee *ptmp = P[j]; //temporary variable for sort
				P[j] = P[j + 1];
				P[j + 1] = ptmp;
			}
		}
	}
	outputForSort(P, n);
	delete[]P;
}

void del(vector <TEmploee> &A)
{
	ofstream fout;
	int number;
	cout << "Enter the employee number whose data will be deleted:" << endl;
	cin >> number;
	vector <TEmploee> ::iterator it = A.begin();
	A.erase(it + number - 1);
	output(A);
	writeDown(A);
}

void read(vector <TEmploee> &A)
{
	A.clear();

	TEmploee tmp;
	ifstream fin;
	fin.open("emploees.dat", ios::binary);
	while (!fin.eof())
	{
		fin.read((char*)&tmp, sizeof(TEmploee));
		A.push_back(tmp);

	}
	A.pop_back();
	fin.close();
}



int main()
{
	vector <TEmploee> Emploees;

	//Emploees.push_back(TEmploee);
	//Emploees[i].name = 1;
	//Emploees.size();

	setlocale(LC_ALL, "rus");
	ifstream fin;
	int menu = -1;
	for (;1;)
	{
		fin.open("emploees.dat", ios::binary);
		if (fin)
		{
			read(Emploees);
			fin.close();

			//fin.read((char*)Emploees,sizeof(TEmploee));
			//ofstream fout; // создание объектов
			// fout.open("emploees.dat", ios::binary);
			// ifstream fin; //создание объектов
			// fin.open("emploees.dat", ios::binary);

			cout << "n=" << Emploees.size();
			cout << "Select the action: " << endl;
			cout << "Select 1 to read the data." << endl;
			cout << "Select 2 to save the data." << endl;
			cout << "Select 3, to add the data." << endl;
			cout << "Select 4, to sort the data" << endl;
			cout << "Select 5 to delete the employee data." << endl;
			cout << "Select 0, to exit the program." << endl;

			cin >> menu;

			if (menu == 1)
				output(Emploees);

			if (menu == 2)
				writeDown(Emploees);

			if (menu == 3)
				add(Emploees);

			if (menu == 4)
				sort(Emploees);

			if (menu == 5)
				del(Emploees);

			if (menu == 0)
				break;
		}
		else
		{
			cout << "Enter the number of employees:" << endl;
			int N;
			cin >> N;
			cout << "Fill in the details: " << endl;
			for (int i = 0; i<N; ++i)
			{
				TEmploee tmp;
				cout << i + 1 << "Enter employee's name: ";
				cin >> tmp.name;
				cout << endl << "Enter employee's name: ";
				cin >> tmp.sername;
				cout << endl << "Enter employee's age: ";
				cin >> tmp.age;
				cout << endl << "Enter employee's experience: ";
				cin >> tmp.experience;
				Emploees.push_back(tmp);
			}
			writeDown(Emploees);

		}
	}

	return 0;
}
