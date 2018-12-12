//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Simon Marcoux on 18-12-10.
//  Copyright © 2018 Simon Marcoux. All rights reserved.
//



#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

class FBullCowGame {
public:
    FBullCowGame(); // constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool isGameWon() const;
    
    void Reset(); // TODO update return value
    bool CheckGuessValidity(std::string); // TODO update return value
    
    // TODO provide a method for counting bulls and couws, and increasing try #
    
    
private:
    int MyCurrentTry;
    int MyMaxTries;
    
};

#endif /* FBullCowGame_hpp */
