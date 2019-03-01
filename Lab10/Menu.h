#include <iostream>

using namespace std;

class Menu
{
public:
	void MyMenu()
	{
		cout << "Выберите действие\n";
		cout << "1. Создать файл\n";
		cout << "2. Открыть файл\n";
		cout << "3. Выбор рейса\n";
		cout << "q. Выход\n" << std::endl;
		cout << ">>> ";
	}
};
