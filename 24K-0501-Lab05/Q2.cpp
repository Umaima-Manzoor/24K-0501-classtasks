#include <iostream>
using namespace std;

bool isSafe(int maze[5][5], int x, int y, int solution[5][5]) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1 && solution[x][y] == 0); //solution wala isliye check kia k already visited to nhi hai because it was entering an infinite loop
}

bool LionMaze(int maze[5][5], int x, int y, int solution[5][5]) {
    if (x == 4 && y == 4) {
        solution[x][y] = 1; 
        return true;
    }

    if (isSafe(maze, x, y, solution)) {
        solution[x][y] = 1; 

        if (LionMaze(maze, x + 1, y, solution)){    
            return true; 
        }
        if (LionMaze(maze, x, y + 1, solution)) {   
            return true;
        } 
        if (LionMaze(maze, x - 1, y, solution)) {
            return true;
        } 
        if (LionMaze(maze, x, y - 1, solution)) {
            return true;
        }


        
        solution[x][y] = 0;
        return false; 
    }
    return false; 
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int solution[5][5] = {0};

    if (LionMaze(maze, 0, 0, solution)) {
        cout << "Path to the meat for lion:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found to the meat for the lion" << endl;
    }
    return 0;
}
