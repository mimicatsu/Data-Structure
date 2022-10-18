#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

using mazeType = vector<vector<int>>;

void find(int row, int col, mazeType& maze, int end_x, int end_y, int maze_row, int maze_col);

int main(){

    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if(!inputFile){
        cout << "file is not open";
        exit(1);
    }

    string line;
    getline(inputFile, line,' ');
    int maze_row = stoi(line);
    getline(inputFile, line,'\n');
    int maze_col = stoi(line);
    getline(inputFile, line,' ');
    int start_x = stoi(line);
    getline(inputFile, line,'\n');
    int start_y = stoi(line);
    getline(inputFile, line,' ');
    int end_x = stoi(line);
    getline(inputFile, line,'\n');
    int end_y = stoi(line);

    mazeType maze(maze_row,vector<int>(maze_col,0));

    for( int i = 0; i < maze_row; i++){
        for ( int j = 0; j < maze_col; j ++){
            inputFile >> maze[i][j];
        }
    }


    inputFile.close();
    find(start_x, start_y, maze, end_x, end_y, maze_row, maze_col);
    

    return 0;
}

void find(int row, int col, mazeType& maze, int end_x, int end_y, int maze_row, int maze_col){
    int i = row;
    int j = col;
    maze[i][j] = 2;
    if(i == end_x && j == end_y){
       
        fstream file;
        file.open("answer.txt",ios::out);
        if(!file){
            cout << "not open.";
            exit(1);
        }
        for( int r = 0; r < maze_row; r++){
            file << "\n";
            for ( int c = 0; c < maze_col; c++){
                file << maze[r][c] << " ";
            }
        }

    }
    if(i-1 >= 0 && maze[i-1][j] == 0  ){
        maze[i-1][j] = 2;
        find(i-1, j, maze, end_x, end_y, maze_row, maze_col);
    }
    if(i+1 <= end_x && maze[i+1][j] == 0){
        maze[i+1][j] = 2;
        find(i+1, j, maze, end_x, end_y, maze_row, maze_col);
    }
    if(j-1 >= 0 && maze[i][j-1] == 0){
        maze[i][j-1] = 2;
        find(i, j-1, maze, end_x, end_y, maze_row, maze_col);
    }
    if(j+1 <= end_y && maze[i][j+1] == 0){
        maze[i][j+1] = 2;
        find(i, j+1, maze, end_x, end_y, maze_row, maze_col);
    }
}