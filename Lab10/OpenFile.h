#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Task2
{
public:
	void ShowResult()
	{
		cout << "¬ведите название файла: "; cin >> fileName;

		OpenFile(fileName);
	}

private:

	typedef struct
	{
		unsigned int Number;
		string Punkt;
		float TimeIn;
		float TimeOut;
	} Trip;

	Trip* NewTrip;

	string text;
	string fileName;

	void OpenFile(string name)
	{
		name += ".txt";
		fstream file;


		ifstream fileinfo(name, ios::binary | ios::ate);
		auto filesize = fileinfo.tellg();
		fileinfo.close();
		size_t records_count = filesize / sizeof(Trip);
		//
		NewTrip = new Trip[records_count];

		file.open(name, fstream::in | fstream::binary);
		file.read((char*)NewTrip, sizeof(Trip)*records_count);
		file.close();

		

		for (int i = 0; i < records_count; i++)
			cout << " " << NewTrip[i].Number << " " << NewTrip[i].Punkt << " " << NewTrip[i].TimeIn << " " << NewTrip[i].TimeOut << endl;
	}

};