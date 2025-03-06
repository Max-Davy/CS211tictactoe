#include <iostream>
#include <string>
using namespace std;

void out(string output="",bool cr = false);
void out(int output=0,bool cr = false);
void out(float output=0,bool cr = false);
void drawBoard(int board[9],string player1="X",string player2="O");
int in(int type, string prompt);
char in(char type, string prompt);
string in(string type, string prompt);
int winner(int board[9]);

int main() {
    out("Welcome to Tic Tac Toe", 1);
    int board[] = {0,0,0,0,0,0,0,0,0};
    char player1;
    char player2;
    int win = 0;
    int move;
    player1 = in(' ',"Enter player 1 symbol:");
    player2 = in(' ',"Enter player 2 symbol:");
    drawBoard(board);
    while (win==0) {
        move = in(0,"Choose player 1 move (square 1 through 9):");
        board[move-1] = 1;
        drawBoard(board);
        win = winner(board);
    }
    out("Winner is player ",0);out(win);
    return 0;
}

/* 
    get if game has been won
    input "board" same as drawBoard function
    outputs 0 if no win, 1 if player 1 win, 2 if player 2 win
*/
int winner(int board[9]){
    if ((board[0]==1&&board[3]==1&&board[6]==1)||
        (board[1]==1&&board[4]==1&&board[7]==1)||
        (board[2]==1&&board[5]==1&&board[8]==1)||
        (board[0]==1&&board[1]==1&&board[2]==1)||
        (board[3]==1&&board[4]==1&&board[5]==1)||
        (board[6]==1&&board[7]==1&&board[8]==1)||
        (board[2]==1&&board[4]==1&&board[6]==1)||
        (board[0]==1&&board[4]==1&&board[8]==1)) {
        return 1;
    } else if((board[0]==2&&board[3]==2&&board[6]==2)||
        (board[1]==2&&board[4]==2&&board[7]==2)||
        (board[2]==2&&board[5]==2&&board[8]==2)||
        (board[0]==2&&board[1]==2&&board[2]==2)||
        (board[3]==2&&board[4]==2&&board[5]==2)||
        (board[6]==2&&board[7]==2&&board[8]==2)||
        (board[2]==2&&board[4]==2&&board[6]==2)||
        (board[0]==2&&board[4]==2&&board[8]==2)) {
        return 2;
    } else {
        return 0;
    }
    return 0;
}

/* get integer, character, or string from input*/
int in(int type,string prompt) {
    out(prompt,1);
    cin>>type;
    return type;
}
char in(char type,string prompt) {
    out(prompt,1);
    cin>>type;
    return type;
}
string in(string type,string prompt) {
    out(prompt,1);
    cin>>type;
    return type;
}

/* print string, integer, or float "output" to command line
    output will end with a new line if optional input "cr" = true
*/
void out(string output, bool cr) {
    (cr)? cout<<output<<endl: cout<<output;
}

void out(int output, bool cr) {
    (cr)? cout<<output<<endl: cout<<output;
}

void out(float output, bool cr) {
    (cr)? cout<<output<<endl: cout<<output;
}

/* Draw the grid based on input array "board" of nine integers:
    0 = empty square
    1 = player 1 square
    2 = player 2 square
    input string "player1" will be displayed in player 1 squares, default is "X"
    input string "player2" will be displayed in player 2 squares, default is "O"
*/
void drawBoard(int board[9], string player1, string player2){
    out(" ------------- ",1);
    for (int x=0;x<9;x+=3){
        out(" | ");
        for(int y=x;y<x+3;y++) {
            switch (board[y]) {
                case 1:
                    out(player1);
                    break;
                case 2:
                    out(player2);
                    break;
                default:
                    out(y+1);
            }
            out(" | ");
        }
        out("\n ------------- ",1);
    }
}