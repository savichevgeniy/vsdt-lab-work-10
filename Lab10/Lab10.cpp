#include "pch.h"
#include <iostream>
#include "Menu.h"
#include <Windows.h>
#include "CreateFile.h"
#include "OpenFile.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char key = ' ';
	
	while (key != 'й')
	{
		Menu menu;
		menu.MyMenu();
		cin >> key;

		switch (key)
		{
		case '1':
		{
			MyCreateFile Result1;
			Result1.Task1();
			break;
		}
		case '2':
		{
			Task2 Result2;
			Result2.ShowResult();
			break;
		}
		case 'й':
			cout << "Закрытие программы" << endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			cerr << "Выбран не существующий пункт меню!" << endl ;
			break;
		}
		system("pause");
		system("cls");
	}

}
