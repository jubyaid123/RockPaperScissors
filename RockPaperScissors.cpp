#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int userScore = 0;
  int computerScore = 0;

  while (true) {
    cout << "Enter 'exit' to quit, or your move (rock, paper, or scissors): ";

    string userMove;
    cin >> userMove;

    if (userMove == "exit") {
      break;
    }

    srand(time(0));  // Seed the random number generator

    // Generate the computer's move
    int computerMove = rand() % 3;
    string computerMoveStr;
    if (computerMove == 0) {
      computerMoveStr = "rock";
    } else if (computerMove == 1) {
      computerMoveStr = "paper";
    } else {
      computerMoveStr = "scissors";
    }

    // Determine the winner
    if (userMove == computerMoveStr) {
      cout << "It's a tie!" << endl;
    } else if (userMove == "rock" && computerMoveStr == "scissors") {
      cout << "You win! Rock beats scissors." << endl;
      userScore++;
    } else if (userMove == "paper" && computerMoveStr == "rock") {
      cout << "You win! Paper beats rock." << endl;
      userScore++;
    } else if (userMove == "scissors" && computerMoveStr == "paper") {
      cout << "You win! Scissors beats paper." << endl;
      userScore++;
    } else {
      cout << "The computer wins! " << computerMoveStr << " beats " << userMove << "." << endl;
      computerScore++;
    }

    cout << "Current score: You " << userScore << " - Computer " << computerScore << endl;

    if (userScore == 3 || computerScore == 3) {
      break;
    }
  }

  if (userScore > computerScore) {
    cout << "You win the game!" << endl;
  } else if (computerScore > userScore) {
    cout << "The computer wins the game!" << endl;
  } else {
    cout << "The game is a tie!" << endl;
  }

  return 0;
}
