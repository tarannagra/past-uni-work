// POINT SYSTEMS 4075 PROJECT CODE  

//The various enemy types within the game are listed within the enumeration 
// EnemyType is defined by this code 
// Each opponent type is then given a score on the value on the enemy scores map
// The score values for each type of opponent are added in the main function using a for loop
// The console is then updated with a result giving the overall score for the player ingame 

#include <iostream>
#include <map>

// Enemies within the game = 

enum EnemyType { 
    Soldier, // Represents a enemy soldier 
    Tank, // Represents a enemy tank
    Helicopter, // Represents a enemy helicopter 
    Boss, // represents a enemy boss 
};

// Code for the map to remember each value of each enemy within the game = 
std::map<EnemyType, int> enemeyscores= {{Soldier, 100}, Tank, 500},{Helicopter,1000},{Boss, 5000}};

int main(){
    int score = 0;
}

// 5 enemy soldiers killed to add to their main score and total score shown on the code below =
for (int i = 0; i <5; i++){
    score += enemyscores[Soldier];
}

// 2 enemy tanks destroyed to add to their main score and total score shown on the code below = 
for (int i=0; i < 2; i++){
    score += enemyscores[Tank];
}

// Adds the score for one enemy helicopter destroyed 
score += enemyscores[Helicopter];

// Adds the score for one enemy boss killed 
score += enemeyscores[Boss];

//Outputs or prints the final score to the console = 
std::cout << "Final Score:" << score << std::endl;


return 0;


// Code written by Vince Dayrit 

