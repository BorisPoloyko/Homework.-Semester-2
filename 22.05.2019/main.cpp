#include <fstream>
#include <iostream>
#include "Student.hpp"

using namespace std;

Student* readFromFile(char*);
void writeIntoBinary(char* binaryFile, Student* students, int number);
void DisplayFile(char*);
void SystemFun();
void InitNameFile(char*);

int main()
{
    char* fileName = "/Users/larisapoloyko/Desktop/students.txt";
    char* binaryFile ="/Users/larisapoloyko/Desktop/students.bin";
    Student* students = new Student [5];
    students = readFromFile(fileName);
    writeIntoBinary(binaryFile, students, 5);
    DisplayFile(binaryFile);
}


Student* readFromFile(char* fileName)
{
    ifstream streamIn;
    streamIn.open(fileName);
    
    if (!streamIn.is_open())
    {
        cout << "Cannot open file to read!" << endl;
        system("pause");
        exit(1);
    }
    
    Student* students = new Student [5];
    char buffName[20];
    char buffSurname[20];
    char buffFaculty[20];
    int buffMarks[5];
    
    for(int i=0; i<5; i++)
    {
        streamIn>> buffName;
        streamIn >> buffSurname;
        streamIn >> buffFaculty;
        for (int j = 0; j < 5; j++)
        {
            streamIn >> buffMarks[j];
            
        }
        
        students[i].SetStudent(buffName, buffSurname, buffFaculty, buffMarks);
    }
    return students;
}


void writeIntoBinary(char* binaryFile, Student* students, int number)
{
    ofstream streamOut;
    streamOut.open(binaryFile, ios::binary);
    if (!streamOut.is_open())
    {
        cout << "\nCan't open file to write!";
        SystemFun();
        return;
    }
    int buffSize = sizeof(Student);
    for (int i = 0; i < number; i++)
    {
        streamOut.write((char*)&students[i], buffSize);
    }
    streamOut.close();
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
    int bufSize = sizeof(Student);
    Student* man = new Student;
    while (streamIn.read((char*)man, bufSize))
    {
        man->DisplayStudent();
    }
    streamIn.close();
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

