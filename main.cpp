#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
  //seed number generator
  srand(static_cast<unsigned int>(time(0)));
  //initiating sleep function
  unsigned int sleep(unsigned int seconds);
  
  int health = 10, attack, block, turn = 0, numTurns;  
  
  //intro
  cout << "Welcome to your first adventure.\n";
  cout << "Here, we'll test your defense ability.\n\n";
  
  //difficulty selection
  cout << "Select the battle mode\n";
  cout << "1 - Standard (4 turns)\n";
  cout << "2 - Random (3 - 10 turns)\n";

  int choice;
  cout << "Choice: ";
  cin >> choice;

  switch (choice)
  {
    case 1:
      cout << "You picked standard mode.\n";
      numTurns = 4;
      cout << "The goal: Survive 4 attacks\n\n";
      break;
    case 2:
      cout << "You picked randmon mode.\n";
      numTurns = rand() % 8 + 3;
      cout << "The goal: Survive " << numTurns << " attacks\n\n";
      break;
    default:
      cout << "You made an illegal pick. Standard mode is auto-selected.\n";
      cout << "The goal: Survive 4 attacks\n\n";
      numTurns = 4;
      break;
  }

  
  //start of game
  cout << "Get ready! Here comes the first attack.\n";
  while (turn < numTurns && health > 0)
  {    
    sleep(2); 
    ++turn;
    //generates random numbers for attack and block
    attack = rand() % 5;
    block = rand() % 5;
    
    if(block >= attack)
    {
      cout << "You blocked the attack. Great job!\n";
    }
    else
    {
      health -= attack;
      if(health >7)
      {
        cout << "Ouch! That attack got through but you're still in the fight\n";
      }
      else if(health > 5)
      {
        cout << "Keep your guard up! You're looking a little beat up!\n";
      }
      else if(health > 3)
      {
        cout << "You're taking too much damage! I don't know how much more you can take!\n";
      }
      else
      {
        cout << "You need to go see a doctor!\n";
      }     
    }
    //turn stats
    cout << "Attack: " << attack << "\n";
    cout << "Block: " << block << "\n";
    cout << "Health: " << health << "\n\n";
  }

  //end of game
  if(health > 0)
  {
    cout << "\nYou survived! Good job!\n";
    cout << "Total health: " << health;
  }
  else
  {
    cout << "\nYou're dead. Game Over!\n";
    cout << "Total turns: "<< turn;
  }
}
