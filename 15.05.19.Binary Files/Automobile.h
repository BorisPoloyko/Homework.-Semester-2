#ifndef automobile_h
#define automobile_h

const int N = 25;

class Auto
{
public:
	Auto() {}
	Auto(char*, char*, char*, char*, int, int, double);
	~Auto() {}
	void SetModel(char*);
	void SetColor(char*);
	void SetSerialNumber(char*);
	void SetRegistrationNumber(char*);
	void SetProductionYear(int);
	void SetCheckupYear(int);
	void SetPrice(double);
	void SetAuto(char*, char*, char*, char*, int, int, double);

	char* GetModel();
	char* GetColor();
	char* GetSerialNumber();
	char* GetRegistrationNumber();
	int GetProductionYear();
	int GetCheckupYear();
	double GetPrice();

	void EnterAuto();
	void DisplayAuto();
private:
	char model[N]{}, color[N]{}, serialNumber[N]{}, registrationNumber[N]{};
	int productionYear, checkupYear;
	double price;

};

#endif