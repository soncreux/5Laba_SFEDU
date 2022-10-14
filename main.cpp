// Лабораторная работа 5.cpp 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct driver
{
	string Name;
	string SecoundName;
	long long int texPassport;
	long long int phone;
	string carNumber;
	string dateOfBirth;
	string gibdd;
};
int getDriversFromUser(driver*& drivers) { //запись первых элементов структуры
	cout << "How many drivers do you want to write? ";
	int n;
	cin >> n;
	if (n <= 0) {
		cout << "ERROR - Wrong number. Try again." << endl;
		getDriversFromUser(drivers);
	}
	else{
		drivers = new driver[n];
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ".Enter the name of driver: ";
			cin >> drivers[i].Name;
			cout << "Enter the secound name: ";
			cin >> drivers[i].SecoundName;
			cout << "Enter the date of birth: ";
			cin >> drivers[i].dateOfBirth;
			cout << "Enter the phone number: ";
			cin >> drivers[i].phone;
			cout << "Enter the texPassport number: ";
			cin >> drivers[i].texPassport;
			cout << "Enter the car number: ";
			cin >> drivers[i].carNumber;
			cout << "Enter the gibdd: ";
			cin >> drivers[i].gibdd;
			
		cin.ignore();
	}
	return n;
}}
void addDrivers(driver*& drivers, int& driversSize) { // добавление новых элементов структуры
	int add;
	cout << "How many drivers do you want to add? ";
	cin >> add;
	if (add <= 0) {
		cout << "ERROR - Wrong number. Try again." << endl;
		addDrivers(drivers, driversSize);
	}
	else {
		int newDriversSize = driversSize + add;
		driver* newDrivers = new driver[newDriversSize];
		int i = 0;
		for (; i < driversSize; i++)
			newDrivers[i] = drivers[i];
		for (; i < newDriversSize; i++)
		{
			cout << i + 1 << ".Enter the name of driver: ";
			cin >> drivers[i].Name;
			cout << "Enter the secound name: ";
			cin >> drivers[i].SecoundName;
			cout << "Enter the date of birth: ";
			cin >> drivers[i].dateOfBirth;
			cout << "Enter the phone number: ";
			cin >> drivers[i].phone;
			cout << "Enter the texPassport number: ";
			cin >> drivers[i].texPassport;
			cout << "Enter the car number: ";
			cin >> drivers[i].carNumber;
			cout << "Enter the gibdd: ";
			cin >> drivers[i].gibdd;
			
		}
		delete[] drivers;
		drivers = newDrivers;
		driversSize = newDriversSize;
	}
}
void conclusion(const driver* drivers, const int driversSize) // вывод структур на экран
{
	cout << "Here are all your drivers:\n";
	for (int i = 0; i < driversSize; i++) {
		cout << drivers[i].Name << endl
			<< drivers[i].SecoundName << endl
			<< drivers[i].dateOfBirth << endl
			<< drivers[i].phone << endl
			<< drivers[i].texPassport <<  " "
			<< drivers[i].carNumber << endl
			<< drivers[i].gibdd << endl;
		cout << "__________________________" << endl;
	}
}
void sorting(driver* drivers, int driversSize) //сортировка по параметру 
{  
	int choise2;
	driver driver_0;
	bool isExit_2 = false;
	while (true) {
		cout << "By what parameter do you want to sort the items?\n1. By phone number.\n2. By texPassport number.\n3. By surname.\n4. Return in main menu.\n>>> ";
		cin >> choise2;
		switch (choise2)
		{
		case 1: {
			for (int i = 0; i < driversSize - 1; i++) {
				for (int j = 0; j < driversSize - 1; j++) {
					if (drivers[j].phone > drivers[j + 1].phone) {
						driver_0 = drivers[j];
						drivers[j] = drivers[j + 1];
						drivers[j + 1] = driver_0;
					}
				}
			}
			for (int i = 0; i < driversSize; i++) {
				cout << drivers[i].Name << endl
					<< drivers[i].SecoundName << endl
					<< drivers[i].dateOfBirth << endl
					<< drivers[i].phone << endl
					<< drivers[i].texPassport <<  " "
					<< drivers[i].carNumber << endl
					<< drivers[i].gibdd << endl;
				cout << "__________________________" << endl;
			}
			break;
		}
		case 2: {
			for (int i = 0; i < driversSize - 1; i++) {
				for (int j = 0; j < driversSize - 1; j++) {
					if (drivers[j].texPassport > drivers[j + 1].texPassport) {
						driver_0 = drivers[j];
						drivers[j] = drivers[j + 1];
						drivers[j + 1] = driver_0;
					}
				}
			}
			for (int i = 0; i < driversSize; i++) {
				cout << drivers[i].Name << endl
					<< drivers[i].SecoundName << endl
					<< drivers[i].dateOfBirth << endl
					<< drivers[i].phone << endl
					<< drivers[i].texPassport <<  " "
					<< drivers[i].carNumber << endl
					<< drivers[i].gibdd << endl;
				cout << "__________________________" << endl;
			}
			break;
		}
		case 3: {for (int i = 0; i < driversSize - 1; i++) {
			for (int j = 0; j < driversSize - 1; j++) {
				if (drivers[j].SecoundName > drivers[j + 1].SecoundName) {
					driver_0 = drivers[j];
					drivers[j] = drivers[j + 1];
					drivers[j + 1] = driver_0;
				}
			}
		}
			  for (int i = 0; i < driversSize; i++) {
				  cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
				  cout << "__________________________" << endl;
			  }
			  break;
		}
		case 4: {
			isExit_2 = true;
			break;
		}
		default: {
			cout << "ERROR - wrong number. Try again.";
			break; }
		}
		if (isExit_2)
			break;
	}
}
void FindDriver(driver* drivers, int driversSize) { //поиск нужного водителя
	int choise_3;
	int ComparisonNumber;
	bool isExit_3 = false;
	string ComparisonLine;
	while (true)
	{
	cout << "By what parameter do you want to find a driver?";
	cout << "\n1.Name.\n2.Secound name.\n3.Date of brith.\n4.Phone number." <<
		"\n5.texPassport number.\n6.Car number.\n7.Gibdd.\n >>> ";
	cin >> choise_3;
	
		switch (choise_3)
		{
		case 1: {
			cout << "Enter the name of human:\n>>>";
			cin >> ComparisonLine;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].Name == ComparisonLine) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 2: {
			cout << "Enter the secound name of human:\n>>>";
			cin >> ComparisonLine;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].SecoundName == ComparisonLine) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 3: {
			cout << "Enter the date of brith:\n>>>";
			cin >> ComparisonLine;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].dateOfBirth == ComparisonLine) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 4: {
			cout << "Enter the phone number of human:\n>>>";
			cin >> ComparisonNumber;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].phone == ComparisonNumber) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 5: {
			cout << "Enter the texPassport number of human:\n>>>";
			cin >> ComparisonNumber;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].texPassport == ComparisonNumber) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 6: {
			cout << "Enter the car number of human:\n>>>";
			cin >> ComparisonLine;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].carNumber == ComparisonLine) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 7: {
			cout << "Enter the gibdd of human:\n>>>";
			cin >> ComparisonLine;
			for (int i = 0; i < driversSize; i++) {
				if (drivers[i].gibdd == ComparisonLine) {
					cout << "Result of finding:" << endl;
					cout << drivers[i].Name << endl
					  << drivers[i].SecoundName << endl
					  << drivers[i].dateOfBirth << endl
					  << drivers[i].phone << endl
					  << drivers[i].texPassport << " " 
					  << drivers[i].carNumber << endl
					  << drivers[i].gibdd << endl;
					cout << "__________________________" << endl;
				}
			}
			break;
		}
		case 9: {
			isExit_3 = true;
			break;
		}
		default: {
			cout << "ERROR - wrong number. Try again.";
			break; 
		}
		}
		if (isExit_3)
			break;
	}
}
void WriteInFile(driver* drivers, int driversSize) { //запись водителей в файл
	ofstream file("result.txt");
	for (int i = 0; i < driversSize; i++) {
		file << drivers[i].Name << endl
				<< drivers[i].SecoundName << endl
				<< drivers[i].dateOfBirth << endl
				<< drivers[i].phone << endl
				<< drivers[i].texPassport << " " 
				<< drivers[i].carNumber << endl
				<< drivers[i].gibdd << endl;
		file << "__________________________" << endl;
	}
		cout << "Done!\n Return you in main menu\n..." << endl;
		file.close();
}
int main()
{
	int driversSize;
	driver* drivers;
	driversSize = getDriversFromUser(drivers);
	int choise;
	bool isExit = false;
	while (true) {
		cout << "What do ypu want to do?\n1. Add new driver.\n2. Sort by specific parameter.\n3. See all drivers.\n4. Find driver.\n5. Write drivers list in file.\n6. Exit. \n >>>  ";
		cin >> choise;
		switch (choise)
		{
		case 1: {
			addDrivers(drivers, driversSize);
			break;
		}
		case 2: {
			sorting(drivers, driversSize);
			break;
		}
		case 3: {
			conclusion(drivers, driversSize);
			break;
		}
		case 4: {
			FindDriver(drivers, driversSize);
			break;
		}
		case 5: {
			WriteInFile(drivers, driversSize);
			break;
		}
		case 6: { //выход из программы
			isExit = true;
			cout << "Have a nice day!";
			break;
		}
		default:
			cout << "ERROR - wrong number. Try again";
			break;
		}

		if (isExit)
			break;
	}
	delete[] drivers;
	return 0;
}