#include<iostream>
#include <fstream>

using namespace std;

void BlockWriteFile(char*, int, int, int);
void DisplayFile(char*);
void WorkFile(char*, char*, int);
void DisplayMatrix(int*, int, int);
void SimpleMatrix(int*, int, int);
int SumElemMatrix(int*, int, int);
void InitMatrix(int*, int, int);
void SystemFun();
int** convert(int*, int**, int, int);
int** createMatrix(int**, int**, int, int, int&, int&, int);
int* reverseConvert(int**, int, int);
void deleteMatrix(int**, int);
int** allocateMemory(int, int);

int main()
{
	const int N = 40;
	char fileName[N] = "";
	cout << "\nEnter the name of file: " << endl;
	cin >> fileName;
	char newFile[N] = "";
	cout << "\nEnter the name of file: " << endl;
	cin >> newFile;
	int k, n, m, l;
	while (true)
	{
		cout << "\nEnter k number of matrices:" << endl;
		cin >> k;
		cout << "\nEnter n, m dimentions of matrices:" << endl;
		cin >> n >> m;
		cout << "" << endl;
		cout << "Enter the element: " << endl;
		cin >> l;
		if (k > 0 && n > 0 && m > 0)
			break;
		cout << "\nNumber is incorrect! Try again!" << endl;
	}
	system("cls");
	BlockWriteFile(fileName, k, n, m);
	cout << "\nThe contents of file <<" << fileName << ">> :" << endl;
	DisplayFile(fileName);
	WorkFile(fileName, newFile, l);
	cout << "\nThe new contents of file <<" << newFile << ">> : " << endl;
	DisplayFile(newFile);
	system("pause");
	return 0;
}

void InitMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = rand() % 10;
}

void BlockWriteFile(char* fileName, int k, int n, int m)
{
	ofstream streamOut(fileName, ios::out | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write.";
		SystemFun();
		exit(1);
	}

	int* pointer = new int[n * m];
	for (int i = 0; i < k; i++)
	{
		InitMatrix(pointer, n, m);
		int bufSize = sizeof(int) * n * m;
		streamOut.write((char*)&n, sizeof(int));
		streamOut.write((char*)&m, sizeof(int));
		streamOut.write((char*)pointer, bufSize);
	}
	delete[] pointer;
	streamOut.close();
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::in | ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}
	int m, n;
	streamIn.read((char*)&n, sizeof(int));
	streamIn.read((char*)&m, sizeof(int));
	int counter = 0;
	int* pointer = new int[n * m];
	while (streamIn.read((char*)pointer, sizeof(int) * n * m))
	{
		cout << endl << counter + 1 << "'s  matrix " << endl;
		if (m > 0 || n > 0)
		{
			DisplayMatrix(pointer, n, m);
			streamIn.read((char*)&n, sizeof(int));
			streamIn.read((char*)&m, sizeof(int));
			counter++;
		}
		else
		{
			cout << 0;
			counter++;
		}
	}
	//delete[] pointer;
	streamIn.close();
}
void DisplayMatrix(int* pointer, int n, int m)
{
	cout << "n = " << n << " m = " << m << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(4);
			cout << pointer[i * m + j];
		}
		cout << endl;
	}
}
void SimpleMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = 1;
}
int SumElemMatrix(int* pointer, int n, int m)
{
	int summa = 0;
	for (int i = 0; i < n * m; i++)
		summa += pointer[i];
	return summa;
}

void WorkFile(char* fileName, char* newFile, int number)
{
	fstream streamIn(fileName, ios::in | ios::binary);
	fstream streamOut(newFile, ios::out | ios::binary);

	if (!streamIn.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}

	if (!streamOut.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}
	int m, n;
	streamIn.read((char*)&n, sizeof(int));
	streamIn.read((char*)&m, sizeof(int));
	int* pointer = new int[n * m];
	int bufSize = sizeof(int) * n * m;
	int l = 0, k = 0;
	int** matrixSource = allocateMemory(n, m);
	int** matrixResult = allocateMemory(n, m);

	while (streamIn.read((char*)pointer, bufSize))
	{
		convert(pointer, matrixSource, n, m);
		createMatrix(matrixSource, matrixResult, n, m, k, l, number);
		int* result = reverseConvert(matrixResult, k, l);
		streamOut.write((char*)&k, sizeof(int));
		streamOut.write((char*)&l, sizeof(int));
		streamOut.write((char*)result, sizeof(int) * k * l);
		delete[] result;
		streamIn.read((char*)&n, sizeof(int));
		streamIn.read((char*)&m, sizeof(int));
	}
	//delete[] pointer;
	deleteMatrix(matrixResult, n);
	deleteMatrix(matrixSource, n);
	streamOut.close();
}
void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

int** convert(int* source, int** result, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result[i][j] = source[i*m + j];
		}
	}

	return result;
}

int * reverseConvert(int ** source, int n, int m)
{
	int* result = new int[n*m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result[i*m + j] = source[i][j];
		}
	}

	return result;
}

int ** createMatrix(int ** source, int** result, int n, int m, int& k, int& l, int number)
{
	bool* rows = new bool[n] {false};
	bool* columns = new bool[m] {false};
	k = l = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (source[i][j] == number)
			{
				rows[i] = true;
				columns[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (rows[i])
		{
			continue;
		}

		l = 0;

		for (int j = 0; j < m; j++)
		{
			if (columns[j])
			{
				continue;
			}

			result[k][l] = source[i][j];
			l++;
		}

		k++;
	}

	return result;
}

int** allocateMemory(int n, int m)
{
	int** result = new int*[n];

	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
	}

	return result;
}

void deleteMatrix(int** source, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] source[i];
	}

	delete[] source;
}

