//
//  main.cpp
//  BullCowGame
//
//  Created by Simon Marcoux on 18-12-06.
//  Copyright © 2018 Simon Marcoux. All rights reserved.
//

/*
    This is the console executable, that makes use of the BullCow class
    This acts as the view in a MVC pattern, and is responsible for all user interaction
 */

#include <iostream> // input output stream
#include <string> // Used for cin >>
#include "FBullCowGame.hpp"

// Using namespace std replaces std:: namespace before std::cout and std::, but it is dangerous and may cause a namespace clash.
//using namespace std; // standard
using FText = std::string; // unreal compatible

// Declare functions (prototypes) at the top to use them in main
void PrintIntroduction();
void PlayGame();
FText GetGuess();
void PrintGuess(FText);
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game;

// Application entry point
int main(int argc, const char * argv[]) {
    std::cout << BCGame.GetCurrentTry();
    
    bool bPlayAgain = false;
    do {
        PrintIntroduction();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while(bPlayAgain);
    
    return 0;
}

// Loop for the number of turns asking for guesses
void PlayGame() {
    BCGame.Reset();
    
    int MaxTries = BCGame.GetMaxTries();
//    constexpr int MAX_GUESSES = 5;
    std::cout << MaxTries << std::endl;
    
    // Loop fot the number of turns asking for guesses
    // TODO change fromo FOR to WHILE loop once we are validating tries
    for (int i = 1; i <= MaxTries; i++) {
        FText Guess = GetGuess(); // TODO make loop checking valid
        
        // Submit valid guess to the game
        // Print number of bulls and cows
        
        PrintGuess(Guess);
    }
    
    // TODO summarize game
}

// Introduce the game
void PrintIntroduction() {
    constexpr int WORD_LENGTH = 4;
    std::cout << "Welcome to Bulls and Cows a fun word game\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram i'm thinking of ?\n";
}

// get a guess from the user
FText GetGuess() {
    int CurrentTry = BCGame.GetCurrentTry();
    FText Guess = "";
    std::cout << "Try " << CurrentTry << " - Enter your guess: ";
    getline(std::cin, Guess);
    std::cout << "\n";
    
    return Guess;
}

// repeat the guess back to the user
void PrintGuess(FText Guess) {
    std::cout << "Your guess was: " << Guess << std::endl;
}

bool AskToPlayAgain() {
    FText Answer = "";
    
    std::cout << "Do you want to play again ? (y / n)";
    getline(std::cin, Answer);
    
//    std::cout << "Is it y ?" << (Answer[0] == 'y' || Answer[0] == 'Y');
//    std::cout << endl;
    
    return (Answer[0] == 'y') || (Answer[0] == 'Y');
}
