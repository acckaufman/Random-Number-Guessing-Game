//This program generates a random number from 1 to 100,
//then asks the user to guess the number.
//The user gets a maximum of ten guesses.  Invalid input does not count as a guess.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//Get the system time (seed for random number generator, as demonstrated on p. 127 of textbook)
	unsigned seed = time(0);

	//Seed the random number generator
	srand(seed);

	//Define variables to be used in the program
	const int MIN_NUMBER = 1;		//The minimum for the number range
	const int MAX_NUMBER = 100;		//The maximum for the number range
	int randomNumber = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
	//The random number generated by the computer, set to give a result between the maximum and minimum number allowed
	int userGuess;					//To be used for storing the user's guess
	bool correct = false;			//To be used in the loop determining if the user guessed correctly
	int counter = 1;				//The counter for the number of guesses the user has taken, set to 1 for the first guess

	//Explain to the user what the program does
	cout << "Hello!\n\n"
		<< "Welcome to the random number guessing program.\n"
		<< "The computer has generated a random number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n"
		<< "Now, try to guess what the number is, and then press ENTER. (You will be given a maximum of 10 guesses.)\n\n";

	//Note: DELETE THIS LINE BEFORE SUBMITTING AS HOMEWORK ASSIGNMENT
	//cout << "For testing purposes only, the random number is: " << randomNumber << endl << endl;

	while (counter < 11 && correct == false)
	{
		//Get the user's initial guess.
		cout << "Guess #" << counter << ": ";
		cin >> userGuess;
		cin.ignore(20, '\n');	//Ignore any additional characters the user types

		//Validate the user's guess each time they make one
		//If the user's guess is not valid, the loop returns but does not increase the guess counter
		while (userGuess < 1 || userGuess > 100)
		{
			cout << "I'm sorry, but you must enter a number between 1 and 100.  Please try again.\n\n";
			cout << "Guess #" << counter << ": ";
			cin >> userGuess;
			cin.ignore(20, '\n');
		}

			//Assuming the user has entered a valid guess, continue and determine if their guess is correct.
			if (userGuess == randomNumber)
			{
				cout << "Wow, you guessed correctly!\n\n";
				correct = true;
			}
			else if (userGuess > randomNumber)
			{
				cout << "Too high, try again.\n\n";
				counter++;	//Increment the guess counter
				correct = false;
			}
			else if (userGuess < randomNumber)
			{
				cout << "Too low, try again.\n\n";
				counter++;
				correct = false;
			}

	}
		
		//After the user has either made ten guesses or has guessed correctly, the program will display an appropriate message.
		if (counter < 5)
			cout << "Either you know the secret or you got lucky!\n\n";
		else if (counter >= 5 && counter <= 7)
			cout << "You're pretty good at this!\n\n";
		else if (counter >= 8 && counter <= 10)
			cout << "You'll do better next time.\n\n";
		else if (counter >= 11)
			cout << "Sorry - you have taken too many guesses.\n\n";

		system("PAUSE");
		return 0;
}