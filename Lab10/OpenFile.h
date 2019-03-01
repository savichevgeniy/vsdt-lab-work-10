#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Task2
{
public:
	Task2(string filename) {
		filename_ = filename + ".txt";
		CountRecords();
		newTrip_ = new Trip[records_count_];
		file_.open(filename_, fstream::in | fstream::binary);
		file_.read((char*)newTrip_, sizeof(Trip)*records_count_);
		file_.close();
	}

	~Task2() {
		delete[records_count_] newTrip_;
	}


	static Task2 & OpenFile() {
		string filename = "";
		cout << "¬ведите название файла: "; cin >> filename;
		Task2 * result = new Task2(filename);
		return (*result);
	}

	void ShowRecords() {
		for (size_t i = 0; i < records_count_; i++)
			cout << " " << newTrip_[i].Number << " " << newTrip_[i].Punkt << " " << newTrip_[i].TimeIn << " " << newTrip_[i].TimeOut << endl;
	}
private:

	typedef struct
	{
		unsigned int Number;
		string Punkt;
		float TimeIn;
		float TimeOut;
	} Trip;


	void CountRecords() {
		ifstream fileInfo(filename_, ios::binary | ios::ate);
		size_t tripSize = sizeof(Trip);
		auto filesize = fileInfo.tellg();
		fileInfo.close();
		records_count_ = filesize / tripSize;
	}

	string filename_ = "";
	size_t records_count_ = 0;
	int time = 0;
	Trip* newTrip_;
	string text;
	fstream file_;

	void Search()
	{
		cin >> time;
	}
};