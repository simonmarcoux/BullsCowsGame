//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Simon Marcoux on 18-12-10.
//  Copyright © 2018 Simon Marcoux. All rights reserved.
//

#include "FBullCowGame.hpp"

using FText = std::string;

// Constructor
FBullCowGame::FBullCowGame() {
    Reset();
}

bool FBullCowGame::CheckGuessValidity(FText) {
    return false;
}


bool FBullCowGame::isGameWon() const {
    return false;
}


int FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}


int FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}


void FBullCowGame::Reset() {
    constexpr int MAX_TRIES = 8;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    
    return;
}


