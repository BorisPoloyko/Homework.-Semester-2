#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Automobile.h"

using namespace std;

Auto::Auto(char* model, char* color, char* serialNumber, char* registrationNumber, int productionYear, int checkupYear, double price)
{
	this->SetAuto(model, color, serialNumber, registrationNumber, productionYear, checkupYear, price);
}

void Auto::SetAuto(char* model, char* color, char* serialNumber, char* registrationNumber, int productionYear, int checkupYear, double price)
{
	this->SetModel(model);
	this->SetColor(color);
	this->SetSerialNumber(serialNumber);
	this->SetRegistrationNumber(registrationNumber);
	this->SetProductionYear(productionYear);
	this->SetCheckupYear(checkupYear);
	this->SetPrice(price);
}

void Auto::SetModel(char* model)
{
	strcpy(this->model, model);
}

void Auto::SetColor(char* color)
{
	strcpy(this->color, color);
}

void Auto::SetSerialNumber(char* serialNumber)
{
	strcpy(this->serialNumber, serialNumber);
}

void Auto::SetRegistrationNumber(char* registartionNumber)
{
	strcpy(this->registrationNumber, registartionNumber);
}

void Auto::SetProductionYear(int year)
{
	if (year <= 1900)
	{
		throw invalid_argument("Please enter valid year!");
	}

	this->productionYear = year;
}

void Auto::SetCheckupYear(int year)
{
	if (year <= 1900)
	{
		throw invalid_argument("Please enter valid year!");
	}

	this->checkupYear = year;
}

void Auto::SetPrice(double cprice)
{
	if (cprice < 0)
	{
		throw invalid_argument("Please enter valid price");
	}

	this->price = cprice;
}

char* Auto::GetModel()
{
	return this->model;
}

char* Auto::GetColor()
{
	return this->color;
}

char*  Auto::GetSerialNumber()
{
	return this->serialNumber;
}

char*  Auto::GetRegistrationNumber()
{
	return this->registrationNumber;
}

int  Auto::GetProductionYear() 
{
	return this->productionYear;
}

int  Auto::GetCheckupYear()
{
	return this->checkupYear;
}

double  Auto::GetPrice()
{
	return this->price;
}

void Auto::DisplayAuto()
{
	cout << "Model: " << this->model << endl;
	cout << "Color: " << this->color << endl;
	cout << "Serial number: " << this->serialNumber << endl;
	cout << "Registartion number: " << this->registrationNumber << endl;
	cout << "Production / checkup years: " << this->productionYear << " / " << this->checkupYear << endl;
	cout << "Price: " << this->price << endl;
}

void Auto::EnterAuto()
{
	const int N = 256;
	char model[N] = "", color[N] = "", serialNumber[N] = "", registrationNumber[N] = "";
	cout << "Enter a model of the automobile: ";
	cin.ignore();
	cin.getline(model, N, '\n');
	cout << "Enter a color of the automonile: ";
	cin.getline(color, N, '\n');
	cout << "Enter the serial number: ";
	cin.getline(serialNumber, N, '\n');
	cout << "Enter the registration number: ";
	cin.getline(registrationNumber, N, '\n');
	
	int pyear, cyear;
	cout << "Enter the year of production: ";
	cin >> pyear;
	cout << "\n";

	cout << "Enter the checkup year: ";
	cin >> cyear;
	cout << "\n";

	cout << "Enter the price: ";
	cin >> price;
	cout << "\n";

	this->SetAuto(model, color, serialNumber, registrationNumber, pyear, cyear, price);
}
