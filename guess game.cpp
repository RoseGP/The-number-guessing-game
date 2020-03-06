
/****SAMPLE PROGRAM HEADER*******************************************************

Description: This is a number guessing game with a random number generator

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
using namespace std; //A namespace is a collection of names

/*********************************************************
//Following is the declaration of a round of the guessing game
**********************************************************/
class guessGame
{
public:
	int upper_range;
	int max_guesses;
	int current_guess;
	int random_number;
	bool guessTooLow; //NOT REQUIRED
	bool guessTooHigh; //NOT REQUIRED
};


//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void SetUpperRange(guessGame&, int);
//Precondition: the user has to aggree to play the game and set the level
//Postcondition:  set the range of the of the game.
//Description:  set the range of the of the game. 

int  GetUpperRange(int);
//Precondition: based on the level the user will set the range of the of the game.
//Postcondition: the user enter the range
//Description:  Describe what the function does.

void SetNumGuesses(guessGame&, int);
//Precondition: base on the the level of the game the 
//Postcondition: set the number of guest for the user based on the level
//Description: set the number of guest

int  GetNumGuesses(int);
//Precondition: set the number of guest for the user based on the level
//Postcondition: set the level of the game
//Description: set the level of the game

void PlayOneRound(const string&, guessGame&);
//Precondition: set the level of the game
//Postcondition: play the one round of the game
//Description: play one round the game.

void GetNextGuess(guessGame&);
//Precondition: play the one round of the game.
//Postcondition: get the next guess from the user.
//Description:  get the next guess from the user.

bool InterpretGuess(guessGame& currentGame);
//Precondition: get the next guess from the user.
//Postcondition: guide the user to guess the number.
//Description:  interpret the  game to the user.

void GenerateRandomNumber(guessGame&);
//Precondition: guide the user to guess the number.
//Postcondition: function to generate the random number
//Description: random number generator.

//HERE IS THE main function, a driver to test your program

int main()
{
	string name;
	string yesOrNo;

	//declare an object variable of type guessGame
	guessGame currentGame;

	//get the users name
	cout << "Enter your first name: " <<endl;
	cin >> name;

	//ask the user if they want to play
	cout << "Hi " << name << " ,do you want to play the guessing game? (y or n):\n";
	cin >> yesOrNo;

	while (yesOrNo == "y" || yesOrNo == "Y")//test the while loop condition
	{
		//call the Play One Round function and pass the currentGame
		PlayOneRound(name, currentGame);
		//play again? 
		cout << "Do you want to play the another round? (y or n): " << "\n";

		cin >> yesOrNo;
	}

	//say goodbye to theuser
	cout << "Thanks for playing, " << name << endl;
	return  0;
}

//Function Implementations will go here

void SetUpperRange(guessGame& currentGame, int upper)
//Description:  sets the upper range for the random number generator. 
{
	//sets the upper range value in the current game
	currentGame.upper_range = upper;

}

int  GetUpperRange(int level)
//Description:  Gets the upper range.
{
	//returns the upper range value based on the level
	if (level == 1)



		return 10;
	

	else if (level == 2)
	
		return 50;
	

	else if (level == 3)
	
		return 100;
	

	else
	
		return 0;
	
		
	
	//return GetUpperRange(level);

}

void SetNumGuesses(guessGame& currentGame, int numGuesses)
//Description:  Sets the number of guesses for the current round.
{
	//set the max guesses in the current game, see the SetUpperRange function
	currentGame.max_guesses = numGuesses;
}

int  GetNumGuesses(int level)
//Description:  set the level of the game.
{
	//returns the number of guesses based on the level
	if (level == 1)
	
		
		return 4;
	

	else if (level == 2)
	
		
		return 5;
	

	else if (level == 3)
	
		return 6;
	
	else
		return 0;
	
	
}


void PlayOneRound(const string& name, guessGame& currentGame)
//Description:  play one round of the game.
{
	int level{};
	int upper{};
	int numGuesses{};

	//reset above and below to 0 for the new round
	currentGame.guessTooLow = 0; //optional feature, not required
	currentGame.guessTooHigh = 0; //optional feature, not required

	//describe the levels to the user
	cout << "what level ? \n";
	cout << "(1) Beginner - 4 guesses, numbers 1 through 10\n";
	cout << "(2) Intermediate - 5 guesses, numbers 1 through 50\n";
	cout << "(3) Advanced - 6 guesses, numbers 1 through 100:\n";
	cin >> level;

	GetNumGuesses( level);
	

	
	
	//get and set the upper range
	upper = GetUpperRange(level);
	SetUpperRange(currentGame, upper);
		//cin>>currentGame.upper_range;
		

		//get and set the number of guesses

	numGuesses = GetNumGuesses(level);
		SetNumGuesses(currentGame, numGuesses);

		//generate the random number to be guessed
		GenerateRandomNumber(currentGame);

		cout << " Enter a guess between 1 and " << currentGame.upper_range << endl;
		cin >> currentGame.current_guess;
		
	//loop header, counting loop for the number of guesses

	for (int i = 1; i < currentGame.max_guesses; i++)
	{
		
		//tell the user what guess number they are on
		cout << "This is guess number:" << i++ <<endl;
		
		//get the next guess
		GetNextGuess(currentGame);
	
		//reset above and below to 0
		currentGame.guessTooLow = 0;
		currentGame.guessTooHigh = 0;

		//check if the guess is correct
		if (InterpretGuess(currentGame))
		{
			cout << "\nYou won that round, " << name << "!\n";
			
			//stop the loop, do not use a break statement to stop the loop
			i = currentGame.max_guesses;
		}
		

		
	}
	//tell the user the solution after the round of the game is done
	cout << "THE SOLUTION WAS  " << currentGame.random_number << endl;
}

void GetNextGuess(guessGame& currentGame)
//Description: get the next guess from the user.
{
	//display the information to the user and get the next guess
	//cout << "
	//optional feature, not required for this assignment
	if (currentGame.guessTooLow) //the guess was below the solution
	{
		cout << "\nEnter a guess above " << currentGame.current_guess << " : ";
		cin >> currentGame.current_guess;
	}
	else if (currentGame.guessTooHigh)
		//add more conditions 
	{
		cout << "\nEnter a guess below " << currentGame.current_guess << " : ";
		cin >> currentGame.current_guess;
	}
	else

		//ask and get the next guess
	cin >> currentGame.current_guess;
}

bool InterpretGuess(guessGame& currentGame)
//Description:  interpret the  game to the user.
{
	//check if the guess is correct and return true 
	//else tell the user if it was too high and return false
	//too low and return true
	//example
	if (currentGame.current_guess < currentGame.random_number)
	{
		cout << "\nYour guess was too low.\n";
		cout << "-----------------------\n";
		currentGame.guessTooLow = true; //guess was too low
		return false;//guess was not correct
	}
	else if (currentGame.current_guess > currentGame.random_number)
	{
		cout << "Your guess was too High.\n";
		cout << "-----------------------\n";
		currentGame.guessTooHigh = true; //guess was too high
		return false;
	}
	else
	{
		currentGame.current_guess = currentGame.random_number;
		return true;

	}
	//add more conditions

}

void GenerateRandomNumber(guessGame& currentGame)
//Description:random number generator.
{

	//generate a random number based on the 
	srand((unsigned)time(0));
	currentGame.random_number = 1 + rand() % currentGame.upper_range;
	//cout << "\nSolution is " << currentGame.random_number << endl;

}
