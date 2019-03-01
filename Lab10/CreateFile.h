#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class MyCreateFile
{
public:
	void Task1()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		Create();
		FillFile();
		/*SearchTrip(MyFileName);*/
		
	}

private:


	typedef struct
	{
		unsigned int Number;
		string Punkt;
		float TimeIn;
		float TimeOut;
	} Trip;

	int key = 0, count = 0;
	string MyFileName;
	int time = 0;
	string space = "_________________________________________________________________";

	Trip * NewTrip;

	void Create()
	{
		cout << "������� �������� �����: ";
		cin >> fileName;
		fileName += ".txt";
		newFile.open(fileName, fstream::in | fstream::out | fstream::trunc);
		newFile.close();
	}

	void FillFile()
	{

		cout << "������� ����� ������� -> "; cin >> count;
		NewTrip = new Trip[count];
		for (int i = 0; i < count; i++)
		{
			newFile.open(fileName, fstream::in | fstream::out | fstream::app | fstream::binary);
			cout << "������ �" << i + 1 << endl;
			cout << "������� ����� ����� -> "; cin >> NewTrip[i].Number;
			cout << "������� ����� ���������� -> "; cin >> NewTrip[i].Punkt;
			cout << "������� ����� ����������� -> "; cin >> NewTrip[i].TimeIn;
			cout << "������� ����� �������� -> "; cin >> NewTrip[i].TimeOut;
			cout << space << endl;
			newFile.write((char*)&NewTrip[i], sizeof(Trip));
			newFile.close();
		}
		delete[count] NewTrip;
	}

	fstream newFile;
	string fileName;

	/*void SearchTrip(string FileName)
	{
		system("cls");
		key = 0;
		cout << "������ ������� ����? 1 - ��\\2 - ���" << endl; cin >> key;
		switch (key)
		{
		case 1:
			cout << "������� ����� ��������: "; cin >> time;
			for (int i = 0; i < count; i++)
			{
				if (NewTrip[i].TimeOut > time)
				{
					printf("��� �������� ���� �%i\n", NewTrip[i].Number);
					cout << "���������� � �����: " << FileName << endl;
				}
			}
			getchar();
		}
	}*/
};