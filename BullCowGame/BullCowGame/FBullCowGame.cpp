#include "FBullCowGame.h"

using int32 = int;





FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}


//Recieves a valid guess, increments the try #, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment the turn number
	MyCurrentTry++;

	//Setup a return variable
	FBullCowCount BullCowCount;

	//Loop through all letters in the guess
	int32 MyHiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < MyHiddenWordLength; MHWChar++)
	{
		//Compare letters against the hidden word
		for (int32 GChar = 0; GChar < MyHiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
