#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

typedef struct
{
	char name[15]; // имя сотрудника
	char sername[20]; // фамилия сотрудника
	int age; // возраст сотрудника
	int experience; // опыт работы
}
TEmploee;
int n; //глобальная переменная
const int N = 100; //глобальная переменная, которая будет задавать максимальный размер всех массивов программе (ее значение больше, чем количество используемых ячеек)
void output(TEmploee A[]) //процедура вывода в консоль
{
	for (int i = 0; i < n; i++)
	{
		cout << "Сотрудник номер  " << i + 1 << ":" << endl;
		cout << A[i].name << " " << A[i].sername << ", " << A[i].age << ", " << A[i].experience << endl << endl;
	}
}

void outputForSort(TEmploee *A[]) //процедура вывода в консоль при сортировке
{
	for (int i = 0; i < n; i++)
	{
		cout << "Сотрудник номер  " << i + 1 << ":" << endl;
		cout << A[i]->name << " " << A[i]->sername << ", " << A[i]->age << ", " << A[i]->experience << endl << endl;
	}
}

void writeDown(TEmploee A[])//процедура "сохранения" в файл
{
	ofstream fout; // создание объектов
	fout.open("emploees.dat", ios::binary);

	fout.write((char*)&n, sizeof(int));
	fout.write((char*)A, n*sizeof(TEmploee));
	fout.close();
}

void writeDownForDelete(TEmploee *A[]) // процедура сохранения при удалении данных об одном из сотрудников
{
	ofstream fout; // создание объектов
	fout.open("emploees.dat", ios::binary);

	fout.write((char*)&n, sizeof(int));
	fout.write((char*)*A, n*sizeof(TEmploee));
	fout.close();
}

void add(TEmploee A[]) // добавление сотрудников
{

	cout << n << " Введите имя сотрудника:  ";
	cin >> A[n - 1].name;

	cout << endl << "Введите фамилию сотрудника:  ";
	cin >> A[n - 1].sername;

	cout << endl << "Введите возраст сотрудника:  ";
	cin >> A[n - 1].age;

	cout << endl << "Введите стаж сотрудника:  ";
	cin >> A[n - 1].experience;
	writeDown(A);
}

void sort(TEmploee A[]) //процедура  сортировки
{
	TEmploee *P[N];
	TEmploee *ptmp; // переменная для сортировки
	for (int i = 0; i<n; i++)
		P[i] = &A[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (P[j]->age > P[j + 1]->age)
			{
				ptmp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = ptmp;
			}
		}
	}

	outputForSort(P);
}
void del(TEmploee A[])//процедура удаления
{
	ofstream fout;
	int number;
	cout << "Введите номер сотрудника, чьи данные хотите удалить:" << endl;
	cin >> number;
	for (int i = number - 1; i < n; i++)
		A[i] = A[i + 1];
	n--;
	output(A);
	writeDown(A);
}

int main()
{
	TEmploee Emploees[N];
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	ifstream fin; //создание объектов
	fin.open("emploees.dat", ios::binary);

	/**/

	if (fin)
	{
		fin.close();
		int menu = -1;
		while (menu != 0)
		{
			/**/
			//fin.read((char*)Emploees,sizeof(TEmploee));
			//ofstream fout; // создание объектов
			//	fout.open("emploees.dat", ios::binary);

			//	ifstream fin; //создание объектов
			//	fin.open("emploees.dat", ios::binary);

			/**/
			cout << "n=" << n;
			cout << "Выберите действие: " << endl;
			cout << "Введите 1 для чтения данных." << endl;
			cout << "Введите 2 для сохранения данных в файл" << endl;
			cout << "Введите 3, чтобы добавить данные" << endl;
			cout << "Введите 4, чтобы отсортировать данные по возрасту сотрудников" << endl;
			cout << "Введите 5 для удаления данных о сотруднике" << endl;
			cout << "Введитек 0, чтобы завершить работу." << endl;
			cin >> menu;

			if (menu == 1) // вывод данных в консоль
			{

				fin.open("emploees.dat", ios::binary);
				fin.read((char*)&n, sizeof(int));
				fin.read((char*)Emploees, n*sizeof(TEmploee));
				output(Emploees);
				fin.close();
			}

			if (menu == 2) //запись данных в файл 
			{

				writeDown(Emploees);
			}

			if (menu == 3) //Добавление данных
			{
				fin.open("emploees.dat", ios::binary);
				fin.read((char*)&n, sizeof(int));
				fin.read((char*)Emploees, n*sizeof(TEmploee));
				n++;
				add(Emploees); //вызов процедуры добавуления данных
				fin.close();
			}

			if (menu == 4)// сортировка данных
			{
				fin.open("emploees.dat", ios::binary);
				fin.read((char*)&n, sizeof(int));
				fin.read((char*)Emploees, n*sizeof(TEmploee));
				sort(Emploees);
				fin.close();
			}

			if (menu == 5) //удаление элемента
			{
				del(Emploees);
			}
		}
	}
	else
	{
		cin >> n;
		cout << "Заполните данные: " << endl;
		for (int i = 0; i<n; i++) // заполнение данных в структуре
		{
			cout << i + 1 << " Введите имя сотрудника:  ";
			cin >> Emploees[i].name;

			cout << endl << "Введите фамилию сотрудника:  ";
			cin >> Emploees[i].sername;

			cout << endl << "Введите возраст сотрудника:  ";
			cin >> Emploees[i].age;

			cout << endl << "Введите стаж сотрудника:  ";
			cin >> Emploees[i].experience;
		}

		writeDown(Emploees);
	}
	return 0;
}

