/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetGuess();
void PlayGame();
bool AsktoPlayAgain();

FBullCowGame BCGame;

// The entry point for our application
int32 main(void)
{

	FText Guess = "";
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		//Add a game summary
		bPlayAgain = AsktoPlayAgain();

	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	//Introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);
	return Guess;
}

bool AsktoPlayAgain()
{
	FText Response = "";
	do
	{
		std::cout << "Do you want to play again? (y/n):";
		getline(std::cin, Response);
	} while (Response[0] != 'y' && Response[0] != 'n');
	return (Response[0] == 'y');
}


void PrintBack(FText Guess)
{
	std::cout << "Your guess was: " << Guess << std::endl;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	 //loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();//TODO make loop checking valid 
	
		//Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
	}
	// TODO get a guess from the user
}



