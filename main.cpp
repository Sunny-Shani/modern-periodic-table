// Modern Periodic Table
#include <iostream>
#include <string>
#include <process.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <cwchar>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

// Function to randamize color output
inline void color()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned)time(0));

	int result = 1 + (rand() % 15);

	if (result == 1)
	{
		SetConsoleTextAttribute(h, 1);
	}

	else if (result == 2)
	{
		SetConsoleTextAttribute(h, 2);
	}

	else if (result == 3)
	{
		SetConsoleTextAttribute(h, 3);
	}

	else if (result == 4)
	{
		SetConsoleTextAttribute(h, 4);
	}

	else if (result == 5)
	{
		SetConsoleTextAttribute(h, 5);
	}

	else if (result == 6)
	{
		SetConsoleTextAttribute(h, 6);
	}

	else if (result == 7)
	{
		SetConsoleTextAttribute(h, 7);
	}

	else if (result == 8)
	{
		SetConsoleTextAttribute(h, 8);
	}

	else if (result == 9)
	{
		SetConsoleTextAttribute(h, 9);
	}

	else if (result == 10)
	{
		SetConsoleTextAttribute(h, 10);
	}

	else if (result == 11)
	{
		SetConsoleTextAttribute(h, 11);
	}

	else if (result == 12)
	{
		SetConsoleTextAttribute(h, 12);
	}

	else if (result == 13)
	{
		SetConsoleTextAttribute(h, 13);
	}

	else if (result == 14)
	{
		SetConsoleTextAttribute(h, 14);
	}

	else if (result == 15)
	{
		SetConsoleTextAttribute(h, 15);
	}
}

// Function to search for an element
inline void search(const string &userInput)
{
	// Map to store atomic numbers, element names, symbols, and atomic masses
	map<string, string> index;

	// Read the index.txt file
	ifstream indexFile("files/index.txt");
	if (!indexFile.is_open())
	{
		cout << "Error: Unable to open index.txt file." << endl;
		return;
	}

	// Populate the map with data from index.txt
	string line;
	while (getline(indexFile, line))
	{
		string atomicNumber, elementName, elementSymbol, fileName;
		istringstream iss(line);
		if (iss >> atomicNumber >> elementName >> elementSymbol >> fileName)
		{
			index[atomicNumber] = fileName;
			index[elementName] = fileName;
			index[elementSymbol] = fileName;
		}
	}

	indexFile.close();

	// Check if the user input matches any key in the index map
	if (index.find(userInput) != index.end())
	{
		string fileName = index[userInput];
		ifstream infile("files/" + fileName + ".txt");
		if (!infile.is_open())
		{
			cout << "Error: Unable to open file for " << userInput << "." << endl;
			return;
		}

		// Read and print data from the file
		string data;
		color();
		while (getline(infile, data))
		{
			cout << data << endl;
		}
		infile.close();
	}
	else
	{
		cout << "Error: Element not found." << endl;
	}
}

string Command;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int option, i;

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 22.5;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// Blinking Welcome Screen

	for (i = 1; i <= 3; i++)
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\n\n \t\t\t\t\t******************************************************\n";
		cout << " \t\t\t\t\t********** WELCOME TO MODERN PERIODIC TABLE **********\n";
		cout << " \t\t\t\t\t******************************************************";
		Sleep(750);
		system("cls");
		Sleep(750);
	}

	// Main Menu
repeat:
	SetConsoleTextAttribute(h, 3);
	system("cls");

	cout << "\n \t\t\t\t\t\t*****************************************\n";
	cout << " \t\t\t\t\t\t********* MODERN PERIODIC TABLE *********\n";
	cout << " \t\t\t\t\t\t*****************************************\n";
repeat_3:
	SetConsoleTextAttribute(h, 15);
	cout << "\n \t\t\t\t\t\t      *****************************\n";
	cout << "\t\t\t\t\t\t                MAIN MENU\n";
	cout << " \t\t\t\t\t\t      *****************************";
	cout << "\n \t\t\t\t\t\t      * 1. Display Periodic Table *\n";
	cout << " \t\t\t\t\t\t      * 2. Search for an Element  *\n";
	cout << " \t\t\t\t\t\t      * 3. Exit                   *\n";
	cout << " \t\t\t\t\t\t      *****************************";
	cout << "\n\n    \t\t\t\t\t\tEnter your option : ";
	cin >> option;

	switch (option)
	{
	case 1:
		system("periodic_table.jpg");
		goto repeat;
		break;

	case 2:
		system("cls");

		while (1)
		{
		repeat_2:
			SetConsoleTextAttribute(h, 15);
			cout << "\n \t\t\t\t\t\t      *******************************";
			cout << "\n \t\t\t\t\t\t      *  1. Search by Element Name  *\n";
			cout << " \t\t\t\t\t\t      *  2. Search by Symbol        *\n";
			cout << " \t\t\t\t\t\t      *  3. Search by Atomic No.    *\n";
			// cout << " \t\t\t\t\t\t      *  4. Search by Atomic Mass   *\n";
			cout << " \t\t\t\t\t\t      *  4. Main Menu               *\n";
			cout << " \t\t\t\t\t\t      *  5. EXIT                    *\n";
			cout << " \t\t\t\t\t\t      *******************************";
			cout << "\n\n    \t\t\t\t\t\t      Enter your choice : ";
			cin >> option;

			if (option == 1) // element name
			{
				cout << "\n \t\t\t\t\t\t      Enter name of an element (Ex Hydrogen) : ";
				cin >> Command;
				search(Command);
				goto repeat_2;
			}

			else if (option == 2) // symbol
			{
				cout << "\n \t\t\t\t\t\t      Enter Symbol of an element (Ex H for Hydrogen) : ";
				cin >> Command;
				search(Command);
				goto repeat_2;
			}

			else if (option == 3) // number
			{
				cout << "\n \t\t\t\t\t\t      Enter Atomic Number of an element : ";
				cin >> Command;
				search(Command);
				goto repeat_2;
			}

			else if (option == 4)
			{
				goto repeat;
			}

			else if (option == 5)
			{
				system("cls");
				cout << "\n\n\t   THANKS FOR USING OUR PROGRAM :D\n              HOPE TO SEE YOU AGAIN :)";
				exit(0);
			}

			else
			{
				cout << " \t\t\t\t\t\t      Invalid Choice";
				continue;
			}

			break;

		case 3:
			system("cls");
			cout << "\n\n\t   THANKS FOR USING OUR PROGRAM :D\n              HOPE TO SEE YOU AGAIN :)";
			exit(0);

		default:
			cout << " \t\t\t\t\t\t      Invalid Option";
			goto repeat_3;
		}
	} // while loop end
	return 0;
}
