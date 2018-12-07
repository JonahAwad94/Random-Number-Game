#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getUserInput(int lowerBound, int upperBound);

int main()
{
	cout << "Enter a number to play up to. (Up to 1,000) ";
	int limit = getUserInput(10, 1000);

	cout << "A random number between 0 and " << limit << " has been selected. Try to guess what it is. ";

	//generate random number
	srand(time(0));
	int randNum = (rand() % limit + 1);
	int num = getUserInput(0, limit);

	for (int lives = 4; lives > 0; lives--)
	{
		if (num != randNum)
		{
			cout << "Nope. ";
			// print if randNum is bigger or smaller
			if (num < randNum)
				cout << "It's BIGGER than " << num <<". Guess again. ";
			else if (num > randNum)
				cout << "It's smaller than " << num <<". Guess again. ";

			//print remaining lives
			if (lives > 1)
				cout << lives << " lives left. ";
			else if (lives == 1)
				cout << "Last guess! ";


			num = getUserInput(0, limit);
		}
		else if (num == randNum)
			break;
	}

	// print results
	if (num == randNum)
		cout << "Congratulations! You got it! " << endl;
	else if (num != randNum)
		cout << "You're all out of lives. The number was " << randNum << ". Try again. " << endl;

	// Play again or exit
	cout << "\n1. Play again\n2. Exit ";

	int userInput = getUserInput(1, 2);

	if (userInput == 1)
	{
		system("CLS");
		return main();
	}
	else
		return 0;
}

// Get user input, check if its valid
int getUserInput(int lowerBound, int upperBound)
{
	int num;
	cin >> num;


	if (num < lowerBound || num > upperBound)
	{
		do
		{
			cout << "That is not a valid input, enter a number between " << lowerBound << " and " << upperBound;
			cin >> num;
		} while (num < lowerBound || num > upperBound);
	}

	return num;
}
