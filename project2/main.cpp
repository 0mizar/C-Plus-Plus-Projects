/*
 * Project Title:
 * - Project 2 Conway's Game of Life
 * Description: (should be a few sentences)
 * This program is a one player game in which a board of cells is made with
 * some cells being "alive" and others being "dead".
 * Depending on the parameters entered by the user, the cells will "die" if
 * too many neighbor cells are alive or not enough are.
 * Also, cells will stay "alive" if they have the ideal number of alive
 * neighboring cells or become "alive" if surrounded by the ideal number of
 * live neighboring cells.
 *
 * Developers:
 * - Omar Ahmouda - ahmoudot@mail.uc.edu
 *
 * Help Received:
 * - Online resources(Stack Overflow, C++ forums, Youtube Videos)
 *
 * Special Instructions:
 * - *CHANGE FILE LOCATION(on line 280) TO WHERERVER THE EXAMPLE FILE IS SAVED BEFORE RUNNING*
 * - When using the default cell use 2 or 3 for the ideal number for best results
 *
 * Developer comments:
 * Developer 1:
 * I programmed the game.  At first I was intimidated by the constantly updating
 * game board, however I found that I could just keep clearing the screen and reprinting the values.
 * This really helped me make the connection between what I was viewing and the code I was writing.
 * I also learned how to convert from string to integer and how to extrapolate data from a text file.
 * Originally I was unsure how I was going to implement classes into my code, as I did not have many
 * variables, but was able to use classes for the Cell rules.  Most of the things I learned was in
 * making the board and updating the values.  I copied the color changing code from
 * the internet because I thought it would be fun.*EPILEPSY WARNING*
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <windows.h>

using namespace std;

class CellRules{
public:
    int ideal;
    int underpop;
    int overpop;
    int repop;
};


const int gridSize=25;
void printGrid(bool gridOne[gridSize+1][gridSize+1]);
void determineState(bool gridOne[gridSize+1][gridSize+1]);
void clearScreen(void);

/* Function Name: clearScreen
 *
 * Function Description:
 * This function clears the screen between iterations.
 *
 * Parameters:
 * N/A
 * return value:
 * N/A
 */

void clearScreen(void) {
system("CLS");
}

/* Function Name: PrintGrid
 *
 * Function Description:
 * This function checks if the cells are alive or dead
 * and prints 0 if alive, and . if dead.
 *
 * Parameters:
 * gridOne is the grid dimensions, which I used for the for loop
 * to operate.
 *
 *
 * return value:
 * N/A
 */

void printGrid(bool gridOne[gridSize+1][gridSize+1]){
    for(int a = 1; a < gridSize; a++)
        {
        for(int b = 1; b < gridSize; b++)
        {
            if(gridOne[a][b] == true)
            {
                cout << " O ";
            }
            else
            {
                cout << " . ";
            }
            if(b == gridSize-1)
            {
                cout << endl;
            }
        }
    }
}
/* Function Name: compareGrid
 *
 * Function Description:
 * This function creates a copy of all of the cells in a grid to a new grid.
 *
 * Parameters:
 * gridOne is the grid being copied
 * gridTwo is the grid recieving the copied values
 *
 * return value:
 * N/A
 */

void compareGrid (bool gridOne[gridSize+1][gridSize+1], bool gridTwo[gridSize+1][gridSize+1]){
    for(int a =0; a < gridSize; a++)
    {
        for(int b = 0; b < gridSize; b++)
        {
                gridTwo[a][b] = gridOne[a][b];
        }
    }
}
/* Function Name: determineState
 *
 * Function Description:
 * This function calls the copy function and then
 * checks if the cells will be alive or dead.
 *
 * Parameters:
 * gridOne is the grid of cells to be checked
 * ideal is the name of the CellRules class which
 * contains the values needed for checking the grid within subclasses.
 *
 * return value:
 * No return value
 */

void determineState(bool gridOne[gridSize+1][gridSize+1], CellRules ideal){
    bool gridTwo[gridSize+1][gridSize+1] = {};
    compareGrid(gridOne, gridTwo);

    for(int a = 1; a < gridSize; a++)
    {
        for(int b = 1; b < gridSize; b++)
        {
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(gridTwo[a+c][b+d])
                {
                    ++alive;
                }
                    }
                }
            }
            if(alive < ideal.repop)
            {
                gridOne[a][b] = false;
            }
            else if(alive == ideal.ideal)
            {
                gridOne[a][b] = true;
            }
            else if(alive > ideal.ideal)
            {
                gridOne[a][b] = false;
            }
        }
    }
}
/* Function Name: SetIdealCond
 *
 * Function Description:
 * This function sets the ideal number of alive neighbor cells,
 * allowing the user to change the rules of the game slightly
 * and experiment with different cells/rules.
 *
 * Parameters:
 * None
 * return value:
 * Returns the ideal integer value for the CellRule class.
 */

int SetIdealCond(){
    bool err=1;
    int ideal=0;
    while(err==1){
    cout<<"Enter the ideal amount of live neighbors (2-7): "<<endl;
    cin>>ideal;
    if(ideal<2||ideal>7){
        cout<<"Error, please enter a number between 2 & 7: "<<endl;
        err=1;
    }
    else{
        err=0;
    }
}
return ideal;
}
/* Function Name: Intro
 *
 * Function Description:
 * This function states the rules of the game
 *
 * Parameters:
 * N/A
 * return value:
 * N/A
 */

void Intro(){
    cout << "Conway's Game of Life - Implementation in C++" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Also known simply as life, " << endl;
    cout << "is a cellular automaton devised by the British mathematician John Horton Conway in 1970." << endl;
    cout << endl;
    cout << "Rules" << endl;
    cout << "The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells," << endl;
    cout << "each of which is in one of two possible states, alive or dead. Every" << endl;
    cout << "cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent." << endl;
    cout << "At each step in time, the following transitions occur:" << endl;
    cout << "1. Any live cell with fewer than two less than the ideal amount of live neighbours dies, as if caused by under-population." << endl;
    cout << "2. Any live cell with the ideal amount or one less live neighbours lives on to the next generation." << endl;
    cout << "3. Any live cell with more than the ideal amount of live neighbours dies, as if by over-population." << endl;
    cout << "4. Any dead cell with exactly the ideal amount of live neighbours becomes a live cell, as if by reproduction." << endl;
    cout << endl;
    cout << "O - living cell" << endl;
    cout << ". - dead cell" << endl;
    cout << endl;
}

void ChangeColor(){
    char R[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        srand(time(NULL));
        char color_string[20];


            int Ra = rand() %16;

            sprintf(color_string, "color %c", R[Ra]);
            system(color_string);
}

int main(){
    bool gridOne[gridSize+1][gridSize+1] = {};
    int x,y;
    CellRules X;
    string cells;
    string start;
    string filename;
    Intro();
    X.ideal=SetIdealCond();
    X.underpop=X.ideal-2;
    X.overpop=X.ideal+1;
    X.repop=X.ideal-1;
    cout << "Enter the number of cells, or 'd' to use default cell locations(default cells work best for ideal number of 3): ";
    cin >> cells;
    cout << endl;

    if ( cells == "d" ||cells == "D")
      {
    while (true)
      {

        filename = "C://Users//ahmou//OneDrive//Documents//School Folder//Programming for ECE//Project2//Example.txt";

        ifstream readfile(filename.c_str());
        if ( readfile.is_open() )
          {
        string fileline,xx,yy;

        while (getline(readfile,fileline))
          {
            stringstream ss(fileline);

            getline(ss,xx,' ');
            getline(ss,yy,' ');

            x = stoi(xx);
            y = stoi(yy);

            gridOne[x][y] = true;
          }
        break;
          } else {
          cout << "No such file, try again." << endl;
        }
      }
      }
    else
      {

    for(int i=0;i<stoi(cells);i++)
      {
        cout <<stoi(cells)<< "Enter the coordinates of cell " << i+1 << " : ";
        cin >> x >> y;
        gridOne[x][y] = true;
        printGrid(gridOne);
      }
      }
    cout << "Grid setup is done. Start the game ? (y/n)" << endl;
    printGrid(gridOne);
    cin >> start;
    if( start == "y" || start == "Y" )
      {
        while (true)
      {
            printGrid(gridOne);
            determineState(gridOne,X);
            ChangeColor();
            usleep(200000);
            clearScreen();
      }
      }
    else
      {
        return 0;
      }
}


