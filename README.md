# Tic Tac Toe program in C++ for CS211 Spring 2025
## Max Davy

## Program Overview
- The board is stored as an array of integers with length 9. Each integer can be zero (empty space), 1 (player 1 space), or 2 (player 2 space)
- The board is visually displayed to the user with numbers 1 to 9 as placeholders for available spaces. On their turn, the player is prompted to enter the number of the space they want to play. If the player enters the number of a space that is already occupied, they are prompted to choose again until they choose correctly
- The game tracks the win condition by checking against a database of possible 3-in-a-row win configurations for each user. Upon one player winning, or the board being filled (i.e. a tie), the game announces the winner and prompts the player whether they want to continue playing or exit.

## Program structure

## ```main``` function
- Initializes the board array
- Loops until a win or tie:
  - Displays the board using the ```drawBoard``` function
  - Prompts Player 1 for their move
  - Checks that the move is valid using the ```validMove`` function
      - If move is invalid repeats until valid move is obtained
  - Saved the move
  - Draws the board using the ```drawBoard``` function
  - Checks for a winner using the ```winner``` function
      - If winner exits loop, else continues to player 2
  - Prompts Player 2 for their move
  - Checks that the move is valid using the ```validMove`` function
      - If move is invalid repeats until valid move is obtained
  - Saved the move
  - Draws the board using the ```drawBoard``` function
  - Checks for a winner using the ```winner``` function
- Prompts user for another game
  - Resets board if yes
  - Exits if no
 
## ```announceWinner``` function
- Inputs:
  - Board array
  - Winner integer (see ```winner``` function)
- Function:
  - Displays winner to console
- Outputs:
  - None
 
## ```validMove``` function
- Inputs:
  - Board array
  - Move square integer
- Function:
  - Checks that move square is within board range and empty
- Outputs:
  - Boolean whether move is valid
 
## ```winner``` function
- Inputs:
  - Board array
- Function:
  - Checks if board is full
  - Checks against database of possible three-in-a line for each player
- Outputs:
  - Winner integer (1 for player 1, 2 for player 2, 3 for tie)
 
## ```in``` function
- Inputs:
  - type - used for function overrides for different input types; type must be the same as desired input type, actual value does not matter
  - prompt string - will be displayed to console before getting input
  - cr boolean - see ```out``` function
- Function:
  - Displays prompt to console
  - Gets input from console
- Outputs:
  - user input
 
## ```out``` function
- Inputs:
  - output - output to display to console; function overrides for different input types
  - cr - whether to output newline after prompt
- Function:
  - Displays output to console
- Outputs:
  - None
