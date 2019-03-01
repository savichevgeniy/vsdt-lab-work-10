#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Task2
{
public:

	struct Trip
	{
		unsigned int Number;
		string Punkt;
		float TimeIn;
		float TimeOut;

		void Show() {
			cout << "номер рейса: " << Number << "  ";
			cout << "Пункт назначения: " << Punkt << "  ";
			cout << "Время прибытия: " << TimeIn << "  ";
			cout << "Время вылета: " << TimeOut << "  " << endl;
		}

		inline bool IsArrivalTimeBetween(const float & arrivalTimeStart, const float & arrivalTimeEnd) {
			return TimeIn >= arrivalTimeStart && TimeIn <= arrivalTimeEnd;
		}
	};

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
		cout << "Введите название файла: "; cin >> filename;
		Task2 * result = new Task2(filename);
		return (*result);
	}

	vector<Trip> FindTripsInTimeRange(const float & arrivalTimeStart, const float & arrivalTimeEnd) const
	{
		vector<Trip> trips;
		for (size_t i = 0; i < records_count_; i++)
		{
			if (newTrip_[i].IsArrivalTimeBetween(arrivalTimeStart, arrivalTimeEnd))
				trips.push_back(newTrip_[i]);
		}
		return trips;
	}

	static void FindAndShowTripsByArrivalTime(const Task2 & fileForSearch) {
		float timeStart, timeEnd;
		cout << "Введите промежуток времени прибытия" << endl;
		cout << "Начало: ";
		cin >> timeStart;
		cout << "Конец: ";
		cin >> timeEnd;
		vector<Trip> findedTrips = fileForSearch.FindTripsInTimeRange(timeStart, timeEnd);
		for (Trip trip : findedTrips)
			trip.Show();
		cout << endl;

	}

	void ShowRecords() {
		for (size_t i = 0; i < records_count_; i++)
			newTrip_[i].Show();
	}
private:



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

};