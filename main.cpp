#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));

    char field[12][12] = {
        {' ','A','B','C','D','E','F','G','H','I','J', ' '},
        {'1','0','0','0','0','0','0','0','0','0','0', ' '},
        {'2','0','0','0','0','0','0','0','0','0','0', ' '},
        {'3','0','0','0','0','0','0','0','0','0','0', ' '},
        {'4','0','0','0','0','0','0','0','0','0','0', ' '},
        {'5','0','0','0','0','0','0','0','0','0','0', ' '},
        {'6','0','0','0','0','0','0','0','0','0','0', ' '},
        {'7','0','0','0','0','0','0','0','0','0','0', ' '},
        {'8','0','0','0','0','0','0','0','0','0','0', ' '},
        {'9','0','0','0','0','0','0','0','0','0','0', ' '},
        {'0','0','0','0','0','0','0','0','0','0','0', ' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' '}
    };



    for(int i=1; i<sizeof(field[i])-1; i++) {
        for(int j=1; j<sizeof(field[i])-1; j++) {
            int random = rand() % 4;
            if(random == 1 && (i>1 && j>1)) {
                field[i][j] = 'X';
            }
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }

    int counter;

    for(int i=1; i<sizeof(field[i])-1; i++) {
        for(int j=1; j<sizeof(field[i])-1; j++) {  
            counter = 0;
            if(field[i][j] != 'X') {
                //yandere dev moment
                if(field[i-1][j-1] == 'X') {
                    counter++;
                }
                if(field[i-1][j] == 'X') {
                    counter++;
                }
                if(field[i-1][j+1] == 'X') {
                    counter++;
                }
                if(field[i][j+1] == 'X') {
                    counter++;
                }
                if(field[i+1][j+1] == 'X') {
                    counter++;
                }
                if(field[i+1][j] == 'X') {
                    counter++;
                }
                if(field[i+1][j-1] == 'X') {
                    counter++;
                }
                if(field[i][j-1] == 'X') {
                    counter++;
                }
                field[i][j] = char(counter + 48);
            }
        }
    }

    string input;

    while(true) {
        cout << "\n";
        for(int i=0; i<sizeof(field[i]); i++) {
            for(int j=0; j<sizeof(field[i]); j++) {
                if(i!=0 && j!=0) {
                    cout << "\e[42m";
                }

                cout << field[i][j] << " ";
            }
            cout << "\e[0m\n";
        }

        cin >> input;
        int row = input[0] - (int)'A'+1;
        int col = input[1] - 48;
        cout << "[" << row << "]";
        cout << "[" << col << "]";
        cout << field[row][col];

        if(field[row][col] == 'X') {
            cout << "\nYou tripped a mine!";
            break;
        }

    }

    return 0;
}
