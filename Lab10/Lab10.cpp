﻿#include "pch.h"
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
			Task2 & Result2 = Task2::OpenFile();
			Result2.ShowRecords();
			break;
		}
		case '3':
		{
			Task2 & Result3 = Task2::OpenFile();
			Task2::FindAndShowTripsByArrivalTime(Result3);
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
