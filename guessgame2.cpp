
/****SAMPLE PROGRAM HEADER*******************************************************

Description: This is a number guessing game with a random number generator

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
#include <fstream>//output file
using namespace std;

const int NUM_GAMES = 50;
//maximum number of games for the array declaration
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
	bool guessTooLow;//NOT REQUIRED
	bool guessTooHigh;//NOT REQUIRED
	string name; //name of current player
	bool wonOrLost; //true or false for the current round of the game
	int level;//level of the current round of the game
};


//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void SetUpperRange(guessGame&, int);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does. 

int  GetUpperRange(int);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

void SetNumGuesses(guessGame&, int);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

int  GetNumGuesses(int);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

void PlayOneRound(guessGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

void GetNextGuess(guessGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

bool InterpretGuess(guessGame& currentGame);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

void GenerateRandomNumber(guessGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

void PrintGameResults(guessGame gameList[], int gameCount);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.

//HERE IS THE main function, a driver to test your program

int main()
{
	string yesOrNo = "y";

	guessGame gameList[NUM_GAMES];//declare an arry of guessGames
	int gameCount = 0;//count the number of games t


	cout << "Do you want to play the guessing game? (y or n):  \n";
	cin >> yesOrNo;

	while (yesOrNo == "y" || yesOrNo == "Y")
	{
		//ask for the name here, it may be a different player
		//into the member variable name
		cout << "Enter your first name: " << endl;

		cin >> gameList[gameCount].name;
		//call Ply one round function

		PlayOneRound(gameList[gameCount]);

		//Play again (Y or n)?
		cout << "Do you want to play the another round? (y or n): " << "\n";

		cin >> yesOrNo;
		//add one to the gameCount
		gameCount++;
			

	}
	//Print the game results
	PrintGameResults(gameList, gameCount);


	return  0;
}

//Function Implementations will go here

void PlayOneRound(guessGame& currentGame)
//Description:  Play one round of the guess game
{
	//int level{};

	int upper{};

	int numGuesses{};

	//reset above and below to 0 for the new round
	currentGame.wonOrLost = 0; //REQUIRED, keeps track if the user won or lost the round
	currentGame.guessTooLow = 0; //optional feature, not required

	currentGame.guessTooHigh = 0; //optional feature, not required

	//describe the levels to the user

	cout << "what level do you want to play? \n" << "(1) Beginner - 4 guesses, numbers 1 through 10\n(2) Intermediate - 5 guesses, numbers 1 through 50\n(3) Advanced - 6 guesses, numbers 1 through 100:\n";

	cin >> currentGame.level;

	//GetNumGuesses(currentGame.level);


	//get and set the upper range

	upper = GetUpperRange(currentGame.level);

	SetUpperRange(currentGame, upper);

	//cin>>currentGame.upper_range;



	//get and set the number of guesses

	numGuesses = GetNumGuesses(currentGame.level);

	SetNumGuesses(currentGame, numGuesses);

	//generate the random number to be guessed

	GenerateRandomNumber(currentGame);


	//loop header, counting loop for the number of guesses

	for (int i = 0; i < currentGame.max_guesses; i++)

	{

		//tell the user what guess number they are on
		//let the user know the guess number
		//Get the current guess

		cout << "This is guess number: (" << i+1<< ") \n" <<endl;

		cout << "Enter a guess between 1 and " << currentGame.upper_range << endl;


		
		//get the next guess

		GetNextGuess(currentGame);



		//reset above and below to 0

		currentGame.guessTooLow = 0;

		currentGame.guessTooHigh = 0;

		//check if the guess is correct

		if (InterpretGuess(currentGame))

		{

			cout << "\nYou won that round, " << currentGame.name << "!\n";



			//stop the loop, do not use a break statement to stop the loop

			currentGame.wonOrLost = true;
			i = currentGame.max_guesses;

		}


	}

	//tell the user the solution after the round of the game is done

	cout << "THE SOLUTION WAS  \n" << currentGame.random_number << endl;
}

//prints the information in the array on the screen and into an output file
//the name, level, and whether or not they won or lost that round
void PrintGameResults(guessGame gameList[], int gameCount)
{
	ofstream out;
	//open the output file
	
out.open("gameresult.txt");
	cout << "Name\t" << "Level\t" << "won or lost\n";
	//use a loop to output the results onto the screen

	out << "\n***********************************\n";
	out << "Name\t" << "Level\t" << "won or lost\n";
	//use a loop to output the results into the file


	
	for (int i = 0; i < gameCount; i++)
	{

		cout << gameList[i].name << "\t";

		cout << gameList[i].level << " \t";

		cout << gameList[i].wonOrLost << endl;

		out << gameList[i].name << "\t";

		out << gameList[i].level << "\t";

		out << gameList[i].wonOrLost << endl;
		//gameCount++;
	}
	

	out.close();
}

void SetUpperRange(guessGame& currentGame, int upper) 
//Description:  sets the upper range for the random number generator. 
{
	currentGame.upper_range = upper;
}

int  GetUpperRange(int level)
//Description:  Gets the upper range.
{
	

	if (level == 1)

		return 10;

	else if (level == 2)

		return 50;

	else if (level == 3)

		return 100;

	else

		return 0;
}

void SetNumGuesses(guessGame& currentGame, int numGuesses)
//Description:  Sets the number of guesses for the current round.
{
	//set maximum number of guesses
	currentGame.max_guesses = numGuesses;

}

int  GetNumGuesses(int level)
//Description:  Gets the number of guesses for the current round
{
	if (level == 1)


		return 4;


	else if (level == 2)


		return 5;


	else if (level == 3)

		return 6;

	else
		return 0;
}



void GetNextGuess(guessGame& currentGame)
//Description:  get the next guess from the user
{
	//if (currentGame.guessTooLow)//NOT REQUIRED
	//{
	//	cout << "\nEnter a guess above " << currentGame.current_guess << " : ";
	//}
	//ask for the next guess
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
//Description:  Describe what the function does.
{
	
	//add other conditions 
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

}

void GenerateRandomNumber(guessGame& currentGame)
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does.
{

	srand((unsigned)time(0));
	currentGame.random_number = 1 + rand() % currentGame.upper_range;
	//cout << "\nSolution is " << currentGame.random_number << endl;

}
