#include <iostream>
#include <string.h>

using namespace std;

typedef char*(Encrypt)(char*);

int inputLength();
char toUpper(char);
char* encrypt(char letter);
char* encrypt(char* word);
char* task(char*, Encrypt, int);
char* replaceWord(char* source, char* toBeReplaced, char* replacement);
int countWords(char*, int);

int main()
{
	int n = inputLength();

	char source[] = "Why are we still here? Just to suffer?";
	cout << source << endl;
	cout << task(source, encrypt, n) << endl;

	return 0;
}

int inputLength()
{
	int n;
	cout << "Please enter the length of words:";
	cin >> n;
	if (n <= 0)
	{
		throw invalid_argument("Length cannot be less then 0.");
	}
	return n;
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
	int secondDigit = code % 10;
	code /= 10;
	int firstDigit = code % 10;

	result[0] = '(';
	result[1] = firstDigit + '0';
	result[2] = secondDigit + '0';
	result[3] = ')';
	result[4] = 0;

	delete[] result;
	return result;
}

char* encrypt(char* word)
{
	int resultLength = (strlen(word)) * 4 + 1;
	char* result = new char[resultLength];
	for (int i = 0; i < strlen(word); i++)
	{
		char* currentCode = new char[5];
		strcpy(currentCode, encrypt(word[i]));
		strcat(result, currentCode);
		delete[] currentCode;
	}

	delete[] result;
	return result;
}

int countWords(char* source, int n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	const char* symbols = "    1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";

	int count = 0;

	char* word = strtok(copy, symbols);
	while (word)
	{
		if (strlen(word) == n)
		{
			count++;
			word = strtok(0, symbols);
		}
		else
		{
			word = strtok(0, symbols);
		}
	}
	return count;
}

char* task(char* source, Encrypt cypher, int n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	const char* symbols = "    1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* word = strtok(copy, symbols);

	int count = countWords(source, n);

	strcpy(copy, source);
	word = strtok(copy, symbols);
	char* result = new char[strlen(source) + (n * 4 * count) + 1];
	strcpy(result, source);
	while (word)
	{
		if (strlen(word) == n)
		{
			strcpy(result, replaceWord(result, word, encrypt(word)));
			word = strtok(0, symbols);
		}
		else
		{
			word = strtok(0, symbols);
		}
	}
	delete[] result;
	return result;
}

char* replaceWord(char* source, char* toBeReplaced, char* replacement)
{
	int sourceLength = strlen(source);
	int difference = strlen(replacement) - strlen(toBeReplaced);
	char* result = new char[strlen(source) + difference + 1];

	strncpy(result, source, strlen(source) - strlen(strstr(source, toBeReplaced)));
	strcat(result, replacement);
	strcat(result, strstr(source, toBeReplaced) + strlen(toBeReplaced));

	delete[] result;
	return result;
}
