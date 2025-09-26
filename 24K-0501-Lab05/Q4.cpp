#include <iostream>
#include <cmath>
using namespace std;

int solutionCount = 0;
bool printed = false;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}


int solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        solutionCount++;
        
        if (printed == false) {
            cout << "One of the possible solutions is:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i] == j) cout << " Q ";
                    else cout << " . ";
                }
                cout << endl;
            }
            cout << endl;
            printed = true;
        }
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            count += solveNQueens(board, n, row + 1);
            board[row] = -1; 
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    

    int board[n] = {-1};
    
    int total = solveNQueens(board, n);

    if (total > 0) {
        cout << "Total number of distinct solutions: " << total << endl;
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
