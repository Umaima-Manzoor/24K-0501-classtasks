#include <iostream>
using namespace std;

bool isSafe(int maze[7][7], int x, int y, int solution[7][7]) {
    return (x >= 0 && x < 7 && y >= 0 && y < 7 && maze[x][y] == 1 && solution[x][y] == 0); 
}

bool ChildMaze(int maze[7][7], int x, int y, int solution[7][7]) {
    if (x == 6 && y == 6) {
        solution[x][y] = 1; 
        return true;
    }

    if (isSafe(maze, x, y, solution)) {
        solution[x][y] = 1; 

        if (ChildMaze(maze, x + 1, y, solution)){    
            return true; 
        }
        if (ChildMaze(maze, x, y + 1, solution)) {   
            return true;
        } 
        if (ChildMaze(maze, x - 1, y, solution)) {
            return true;
        } 
        if (ChildMaze(maze, x, y - 1, solution)) {
            return true;
        }


        
        solution[x][y] = 0;
        return false; 
    }
    return false; 
}

int main() {
    int maze[7][7] = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1}
    };

    int solution[7][7] = {0};

    if (ChildMaze(maze, 0, 0, solution)) {
        cout << "Path for the child to the ice cream shop:" << endl;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found for the child to the ice cream shiop" << endl;
    }
    return 0;
}
