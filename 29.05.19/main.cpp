#include <iostream>
#include <fstream>

using namespace std;

void InitMatrix(int*, int);
int** convert(int*, int**, int);
int* reverseConvert(int**, int);
int** allocateMemory(int);
int** allocateMemoryArray(int, int);
void DisplayFile(char*);
void DisplayMatrix(int*, int, int);
void BlockWriteFile(char*,char*, int, int);
int diagonalSum(int*, int);
void transpose(int*, int);
bool ifOdd(int*, int);


int main()
{
    char* fileNameF ="/Users/larisapoloyko/Desktop/first.bin";
    char* fileNameS ="/Users/larisapoloyko/Desktop/second.bin";
    int k, n;
    while (true)
    {
        cout << "\nEnter k number of matrices:" << endl;
        cin >> k;
        cout << "\nEnter n dimensions of matrices:" << endl;
        cin >> n;
        if (k > 0 && n > 0)
        {
            break;
        }
        cout << "\nNumber is incorrect! Try again!" << endl;
    }
    system("cls");
    
    BlockWriteFile(fileNameF,fileNameS, k, n);
    cout << "\nThe contents of file <<" << fileNameF << ">> :" << endl;
    DisplayFile(fileNameF);
    cout << "\nThe contents of file <<" << fileNameS << ">> :" << endl;
    DisplayFile(fileNameS);
    
    return 0;
}

int** convert(int* source, int** result, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = source[i*n + j];
        }
    }
    
    return result;
}

int * reverseConvert(int ** source, int n)
{
    int* result = new int[n * n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i * n + j] = source[i][j];
        }
    }
    
    return result;
}



void InitMatrix(int* pointer, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        pointer[i] = rand() % 10;
    }
}

void BlockWriteFile(char* fileNameF,char* fileNameS, int k, int n)
{
    ofstream streamOutF(fileNameF, ios::out | ios::binary);
    ofstream streamOutS(fileNameS, ios::out | ios::binary);
    if (!streamOutF.is_open())
    {
        cout << "\nCan't open file to write.";
        exit(1);
    }
    if (!streamOutS.is_open())
    {
        cout << "\nCan't open file to write.";
        exit(1);
    }
    int* pointer = new int[n * n];
    for (int i = 0; i < k; i++)
    {
        InitMatrix(pointer, n);
        int bufSize = sizeof(int) * n * n;
        if (ifOdd(pointer, n))
        {
            streamOutS.write((char*)&n, sizeof(int));
            streamOutS.write((char*)&n, sizeof(int));
            streamOutS.write((char*)pointer, bufSize);
            
            transpose(pointer, n);
            
            streamOutF.write((char*)&n, sizeof(int));
            streamOutF.write((char*)&n, sizeof(int));
            streamOutF.write((char*)pointer, bufSize);
            
            continue;
        }
        streamOutF.write((char*)&n, sizeof(int));
        streamOutF.write((char*)&n, sizeof(int));
        streamOutF.write((char*)pointer, bufSize);
    }
    delete[] pointer;
    streamOutF.close();
    streamOutS.close();
}

void DisplayFile(char* fileName)
{
    ifstream streamIn(fileName, ios::in | ios::binary);
    if (!streamIn.is_open())
    {
        cout << "Can't open file to read.";
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(4);
            cout << pointer[i * n + j];
        }
        cout << endl;
    }
}

int diagonalSum(int* matrix, int n)
{
    int result = 0;
    
    for (int i = 0; i <= n * n; i+=n+1)
    {
        result += matrix[i];
    }
    return result;
}

void transpose(int* matrix, int n)
{
    int buff;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            buff = matrix[n*i+j];
            matrix[n*i+j] = matrix[n*j+i];
            matrix[n*j+i] = buff;
        }
    }
}

bool ifOdd(int* matrix, int n)
{
    return abs(diagonalSum(matrix, n)) % 2 ? true : false;
}


int** allocateMemory(int n)
{
    
    int** result = new int*[n];
    
    for (int i = 0; i < n; i++)
    {
        result[i] = new int[n];
    }
    
    return result;
}

