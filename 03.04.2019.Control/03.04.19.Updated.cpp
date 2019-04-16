#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

typedef char*(Encrypt)(char*);

char toUpper(char);
char* encrypt(char letter);
char* encrypt(char* word);
char* task(char*, Encrypt, int);
char* replaceWord(char* source, char* toBeReplaced, char* replacement, int count);
int countWords(char*, int);

int main()
{
	int n = 2;

	char source[] = "Why are we still here? Just to suffer?";

	cout << task(source, encrypt, n) << endl;

	system("pause");
	return 0;
}

char toUpper(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
		return letter;
	}
	else
	{
		return letter - 32;
	}
}

char* encrypt(char letter)
{
	letter = toUpper(letter);
	int code = 91 - letter;
	char* result = new char[5];
	result[4] = 0;
	int secondDigit = code % 10;
	code /= 10;
	int firstDigit = code % 10;

	result[0] = '(';
	result[1] = firstDigit + '0';
	result[2] = secondDigit + '0';
	result[3] = ')';

	return result;
}

char* encrypt(char* word)
{
	char* result = new char[1];
	result[0] = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		char* currentCode = new char[5];
		currentCode[4] = 0;
		strcpy(currentCode, encrypt(word[i]));
		strcat(result, currentCode);
		delete[] currentCode;
	}
	return result;
}

int countWords(char* source, int n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	const char* symbols = "    1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* word = strtok(copy, symbols);

	int count = 0;

	while (word)
	{
		if (strlen(word) == n)
		{
			count++;
		}
		word = strtok(0, symbols);
	}
	delete[] copy;
	return count;
}

char* task(char* source, Encrypt cypher, int n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	int count = countWords(copy, n);

	const char* symbols = "    1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* word = strtok(copy, symbols);

	char* result = new char[strlen(source) + (n * 4 * count) + 1];
	strcpy(result, source);

	while (word)
	{
		if (strlen(word) == n)
		{
			strcpy(result, replaceWord(result, word, encrypt(word), count));
		}
		word = strtok(0, symbols);
	}
	delete[]copy;
	return result;
}

char* replaceWord(char* source, char* toBeReplaced, char* replacement, int count)
{
	int difference = strlen(replacement) - strlen(toBeReplaced);
	int sourceLength = strlen(source);
	char* result = new char[sourceLength + difference * count + 1];

	do 
	{
		strncpy(result, source, sourceLength - strlen(strstr(source, toBeReplaced)));
		result[sourceLength - strlen(strstr(source, toBeReplaced))] = 0;
		strcat(result, replacement);
		strcat(result, strstr(source, toBeReplaced) + strlen(toBeReplaced));

	} while (strstr(result, toBeReplaced));

	return result;
}
