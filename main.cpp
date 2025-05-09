/* 
    Tic Tac Toe program in C++
    Max Davy for WSU CS211 Spring 2025
*/
#include <iostream>
#include <string>
using namespace std;

/*
    declare output functions for convenience
*/
void out(string output="",bool cr = false);
void out(int output=0,bool cr = false);
void out(float output=0,bool cr = false);
void out(char output=0,bool cr = false);

void drawBoard(int board[9],char player1='X',char player2='O');//function to draw board
int in(int type, string prompt, bool cr=1);//function to get numeric input
char in(char type, string prompt, bool cr=1);//function to get character input
string in(string type, string prompt, bool cr=1);//function to get string input
bool validMove(int board[9],int move);//function to get if move is valid
int winner(int board[9]);//function to get if player has won
void announceWinner(int winner, int board[9]);//function to output winner

int main() {
    char cont = 'y';
    int board[9];
    char player1;
    char player2;
    int win;
    int move;
    
    while (cont=='y') {
        for(int i=0;i<=9;i++) {
            board[i]=0;
        }
        win = 0;
        out("Welcome to Tic Tac Toe", 1);
        player1 = in(' ',"Enter player 1 symbol:");
        player2 = in(' ',"Enter player 2 symbol:");
        drawBoard(board, player1, player2);
        
        while (win==0) {
            //player 1's turn
            move = in(0,"Choose player 1 move (square 1 through 9):")-1;
            while (!validMove(board, move)) {
                out("Invalid move. Please try again.", 1);
                move = in(0,"Choose player 1 move (square 1 through 9):")-1;
            }
            board[move] = 1;
            drawBoard(board, player1, player2);
            win = winner(board);
            if(win){break;}
            
            //player 2's turn
            move = in(0,"Choose player 2 move (square 1 through 9):")-1;
            while (!validMove(board, move)) {
                out("Invalid move. Please try again.", 1);
                move = in(0,"Choose player 2 move (square 1 through 9):")-1;
            }
            board[move] = 2;
            drawBoard(board, player1, player2);
            win = winner(board);
        }
        announceWinner(win, board);
        cont = in(' ',"Continue (y/n)?",1);
    }
    out("Exiting program", true);
    return 0;
}

/*
    display winner and winning board;
*/
void announceWinner(int winner, int board[9]) {
    out("Game over. ",0);
    if(winner==3) {
        out("Game is a tie!", 1);
    } else{
        out("Player ",0);out(winner);out(" wins!",1);
    }
    drawBoard(board);
}

/* get if move is valid based on board
    input board same as drawBoard function below
    move is int 0-9 based on board index
*/
bool validMove(int board[9],int move) {
    return move<=8&&move>=0&&board[move]==0;
}

/* 
    get if game has been won
    input "board" same as drawBoard function
    outputs 0 if no win, 1 if player 1 win, 2 if player 2 win, 3 if tie
*/
int winner(int board[9]){
    if ((board[0]==1&&board[3]==1&&board[6]==1)||/*col 1*/
        (board[1]==1&&board[4]==1&&board[7]==1)||/*col 2*/
        (board[2]==1&&board[5]==1&&board[8]==1)||/*col 3*/
        (board[0]==1&&board[1]==1&&board[2]==1)||/*row 1*/
        (board[3]==1&&board[4]==1&&board[5]==1)||/*row 2*/
        (board[6]==1&&board[7]==1&&board[8]==1)||/*row 3*/
        (board[2]==1&&board[4]==1&&board[6]==1)||/*diagonals*/
        (board[0]==1&&board[4]==1&&board[8]==1)) {
        return 1;//player 1 win
    } else if((board[0]==2&&board[3]==2&&board[6]==2)||/*col 1*/
        (board[1]==2&&board[4]==2&&board[7]==2)||/*col 2*/
        (board[2]==2&&board[5]==2&&board[8]==2)||/*col 3*/
        (board[0]==2&&board[1]==2&&board[2]==2)||/*row 1*/
        (board[3]==2&&board[4]==2&&board[5]==2)||/*row 2*/
        (board[6]==2&&board[7]==2&&board[8]==2)||/*row 3*/
        (board[2]==2&&board[4]==2&&board[6]==2)||/*diagonals*/
        (board[0]==2&&board[4]==2&&board[8]==2)) {
        return 2;//player 2 win
    } else if(board[0]!=0&&board[1]!=0&&board[2]!=0&&board[3]!=0&&board[4]!=0&&board[5]!=0&&board[6]!=0&&board[7]!=0&&board[8]!=0){
        return 3;//tie
    } else {
        return 0;//no win yet
    }
    return 0;
}

/* display prompt then get integer, character, or string from input*/
int in(int type,string prompt, bool cr) {
    out(prompt,1);
    cin>>type;
    return type;
}

char in(char type,string prompt, bool cr) {
    out(prompt,1);
    cin>>type;
    return type;
}

string in(string type,string prompt, bool cr) {
    out(prompt,1);
    cin>>type;
    return type;
}

/* print string, integer, float, or char "output" to command line
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

void out(char output, bool cr) {
    (cr)? cout<<output<<endl: cout<<output;
}

/* Draw the grid based on input array "board" of nine integers:
    0 = empty square
    1 = player 1 square
    2 = player 2 square
    input character "player1" will be displayed in player 1 squares, default is "X"
    input character "player2" will be displayed in player 2 squares, default is "O"
*/
void drawBoard(int board[9], char player1, char player2){
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