#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <fstream>
#include <iostream>
#include "Automobile.h"

using namespace std;

int max(int, int);
void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();
int SortingMenu();

int main()
{
	char fileName[N] = "Auto.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = Menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Auto);
	Auto car;    
	char ok = 'y';
	while (ok == 'y')   
	{
		car.EnterAuto();
		streamOut.write((char*)&car, bufSize);
		cout << " If you want to continue, press 'y' :";
		cin >> ok;
	}
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Auto);
	Auto car;
	char Ok = 'y';
	while (Ok == 'y')
	{
		car.EnterAuto();
		streamOut.write((char*)&car, bufSize);
		cout << " If you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Auto);
	Auto car;
	long position;
	InitNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	car.EnterAuto();
	streamInOut.write((char*)&car, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);
	long n = streamInOut.tellp();
	int bufSize = sizeof(Auto);
	Auto car;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&car, bufSize))
	{
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&car, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int diskriptorFile = _open(fileName, 2);
	_chsize(diskriptorFile, n - bufSize);
	_close(diskriptorFile);
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Auto carOne, carTwo;
		int bufSize = sizeof(Auto);
		streamInOut.read((char*)&carOne, bufSize);
			enum { Model = 1, Color, SerialNumber, RegistartionNumber, ProductionYear, CheckupYear, Price, Exit };
			int key = SortingMenu();
			if (key == Exit)
			{
				return;
			}
			system("cls");
			switch (key)
			{
			case Model:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					int length = max(strlen(carTwo.GetModel()), strlen(carOne.GetModel()));
					for (int i = 0; i < length; i++)
					{
						if (carTwo.GetModel()[i] < carOne.GetModel()[i])
						{
							streamInOut.seekp(-2 * bufSize, ios::cur);
							streamInOut.write((char*)&carTwo, bufSize);
							streamInOut.write((char*)&carOne, bufSize);
							flag = true;
							break;
						}
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case Color:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					int length = max(strlen(carTwo.GetColor()), strlen(carOne.GetColor()));
					for (int i = 0; i < length; i++)
					{
						if (carTwo.GetColor()[i] < carOne.GetColor()[i])
						{
							streamInOut.seekp(-2 * bufSize, ios::cur);
							streamInOut.write((char*)&carTwo, bufSize);
							streamInOut.write((char*)&carOne, bufSize);
							flag = true;
							break;
						}
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case SerialNumber:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					int length = max(strlen(carTwo.GetSerialNumber()), strlen(carOne.GetSerialNumber()));
					for (int i = 0; i < length; i++)
					{
						if (carTwo.GetSerialNumber()[i] < carOne.GetSerialNumber()[i])
						{
							streamInOut.seekp(-2 * bufSize, ios::cur);
							streamInOut.write((char*)&carTwo, bufSize);
							streamInOut.write((char*)&carOne, bufSize);
							flag = true;
							break;
						}
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case RegistartionNumber:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					int length = max(strlen(carTwo.GetRegistrationNumber()), strlen(carOne.GetRegistrationNumber()));
					for (int i = 0; i < length; i++)
					{
						if (carTwo.GetRegistrationNumber()[i] < carOne.GetRegistrationNumber()[i])
						{
							streamInOut.seekp(-2 * bufSize, ios::cur);
							streamInOut.write((char*)&carTwo, bufSize);
							streamInOut.write((char*)&carOne, bufSize);
							flag = true;
							break;
						}
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case ProductionYear:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					if (carTwo.GetProductionYear() < carOne.GetProductionYear())
					{
						streamInOut.seekp(-2 * bufSize, ios::cur);
						streamInOut.write((char*)&carTwo, bufSize);
						streamInOut.write((char*)&carOne, bufSize);
						flag = true;
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case CheckupYear:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					if (carTwo.GetCheckupYear() < carOne.GetCheckupYear())
					{
						streamInOut.seekp(-2 * bufSize, ios::cur);
						streamInOut.write((char*)&carTwo, bufSize);
						streamInOut.write((char*)&carOne, bufSize);
						flag = true;
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			case Price:
				while (streamInOut.read((char*)&carTwo, bufSize))
				{
					if (carTwo.GetPrice() < carOne.GetPrice())
					{
						streamInOut.seekp(-2 * bufSize, ios::cur);
						streamInOut.write((char*)&carTwo, bufSize);
						streamInOut.write((char*)&carOne, bufSize);
						flag = true;
					}
					streamInOut.seekp(-bufSize, ios::cur);
					streamInOut.read((char*)&carOne, bufSize);
				}
				break;
			default:
				cout << "\nIncorrect input! Try again!";
				SystemFun();
			}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Auto);
	Auto* car = new Auto;
	while (streamIn.read((char*)car, bufSize))
	{
		car->DisplayAuto();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with the file:"
		"\n 1 - INITIALIZE THE NAME OF THE FILE"
		"\n 2 - FORMATE OF THE FILE"
		"\n 3 - VIEW THE CONTENT OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO THE FILE"
		"\n 5 - CHANGE AN ELEMENT IN THE FILE"
		"\n 6 - REMOVE AN ELEMENT IN THE FILE"
		"\n 7 - SORT AN ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}

int SortingMenu()
{
	int k;
	cout << "\n Enter the number of the characteristic:"
		"\n 1 - MODEL"
		"\n 2 - COLOR"
		"\n 3 - SERIAL NUMBER"
		"\n 4 - REGISTRATION NUMBER"
		"\n 5 - YEAR OF PRODUCTION"
		"\n 6 - YEAR OF CHECKUP"
		"\n 7 - PRICE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
