#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <regex>

using namespace std;

class tile {
    public:
        bool revealed = false;
        char value = '0';
        
        void revealTile() {
            //if()
            this->revealed = true;
        }
};

tile field[10][10];

int main(int argc, char const *argv[])
{
    srand(time(0));

    for(int i=1; i<sizeof(field[i])-1; i++) {
        for(int j=1; j<sizeof(field[i])-1; j++) {
            int random = rand() % 4;
            if(random == 1 && (i>1 && j>1)) {
                field[i][j].value = 'X';
            }
            cout << field[i][j].value << " ";
        }
        cout << "\n";
    }

    for(int i=1; i<sizeof(field[i])-1; i++) {
        for(int j=1; j<sizeof(field[i])-1; j++) {  
            int counter = 0;
            if(field[i][j].value != 'X') {
                //yandere dev moment
                if(field[i-1][j-1].value == 'X') {
                    counter++;
                }
                if(field[i-1][j].value == 'X') {
                    counter++;
                }
                if(field[i-1][j+1].value == 'X') {
                    counter++;
                }
                if(field[i][j+1].value == 'X') {
                    counter++;
                }
                if(field[i+1][j+1].value == 'X') {
                    counter++;
                }
                if(field[i+1][j].value == 'X') {
                    counter++;
                }
                if(field[i+1][j-1].value == 'X') {
                    counter++;
                }
                if(field[i][j-1].value == 'X') {
                    counter++;
                }
                field[i][j].value = char(counter + 48);
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

                cout << field[i][j].value << " ";
            }
            cout << "\e[0m\n";
        }

        cin >> input;
       int row = input[0] - (int)'A'+1;
       int col = input[1] - 48;
       cout << "[" << row << "]";
       cout << "[" << col << "]";
       cout << field[row][col].value;

        if(field[row][col].value == 'X') {
            cout << "\nYou tripped a mine!";
            break;
        }

    }

    return 0;
}
