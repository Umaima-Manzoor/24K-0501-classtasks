#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Guess(int num, int turn) {
    if (turn==1) {
        cout << "Player 1's turn to guess the number: ";
    }
    else {
        cout << "Player 2's turn to guess the number: ";
    }

    int guess;
    cin >> guess;

    if (guess == num) {
        cout << "Player " << turn << " guessed the number " << num << " correctly! Player " << turn << " wins!" << endl;
        return; }
        
    else if (guess < num) {
        cout << "Too low! Next player's turn" << endl;
    }
    else {
        cout << "Too high! Next player's turn" << endl;
    }

    if (turn == 1) {
        Guess(num, 2);
    }
    else {
        Guess(num, 1);
    }
}

int main() {
    srand(time(0));
    int num = rand() % 100 + 1;

    Guess(num, 1);

    return 0;
}
