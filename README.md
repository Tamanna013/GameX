# GameX
Mini Game Console

I created a platform where the user can play 9 games in total all in one place. Its just for my C and C++ practice. The games are: Hangman, Rock-Paper-Scissors, Crossword, Maze-Solver, Memory-Game, Quiz-Game, Tic-Tac-Toe, Sudoku, and Number-Guessing-Game.

## Hangman:
#### displayWord(), isWordGuessed(), hangman()
1. words vector with 1000 words created.
2. do-while loop to ensure the game continues on and on
   - We randomly select a word out of words and display it using displayWord() function.
   - incorrectGuesses vector stores all the wrong character guesses and later this along with the number of attempts left is displayed.
   - This cycle is repeated until the number of attempts left is zero or the word is guessed.
   - Each input of the user is checked. If it matches the original word then the displayed word is modified accordingly, else "Incorrect guess!" message is displayed.

## Rock-Paper-Scissors:
#### enum Choice{ROCK=1, PAPER, SCISSORS}; getChoiceName(), determineRoundWinner(), rockPaperScissors()
1. User inputs the number of rounds they want to play and hence a loop is used. For each round, playerScore and computerScore are calculated accordingly.
2. User is asked their choice from rock, paper, and scissors and simultaneously computer's random choice is taken. Next both the choices are compared and the playerScore and computerScore is incremented accordingly.
3. getChoiceName() function has the cases for the user to choose from. determineRoundWinner() compares the priorities of rock, paper, and scissors and gives the scores accordingly.
4. At the end, playerScore and computerScore are compared and the winner is announced.

## Crossword:
#### const int SIZE=20; char grid[SIZE][SIZE]; crossword()
1. Time is provided as a seed to generate random characters.
2. The very first for loop is to initialize our crossword board.
3. Next we define words vector as a list of words to place in the grid. We add 5 words in the list.
4. With the next for loop, we randomly add these list of words in the crossword grid.
   - We take a flag variable placed which is turned true when all the letters of a word (from the words vector) are placed in the grid.
   - While placed is false, random row and column is selected. Now we randomly select if the word would go horizontal or vertical and consider the canPlace flag as true. This flag will turn to false when an already existing word is found at the supposed spot of placement of our current word.
   - The next comes a set of if-else statements which check if word can be placed; if yes then the word is placed on the grid and if no then the loop is repeated until the collision is resolved and all the words are placed.
5. The next for loop fills the rest of the grid with random characters.
6. Now the grid is printed and displayed in front of the user. Now comes the game loop:
   - User is asked to find each word in the crossword. When they enter the indexes of the word correctly, check its validity.
   - The next set of if-else statements check if the word (if it is found or not at the specified location). Later the user is displayed message if they found it correct or not.
7. Then the loop asks if the user wants to play again and the loop works accordingly.

## Maze Solver:
1. Maze Generation:  
   - The maze grid is initialized with walls (`#`) by default.  
   - A guaranteed path from the start (`S`) to the end (`E`) is created, ensuring the game is always solvable.  
   - Additional random paths are carved to add complexity.
2. Gameplay Mechanics:  
   - Players control their position in the maze, represented by `P`.  
   - Use **W (up), A (left), S (down), and D (right)** to move through the maze.  
   - Moves are validated to ensure players don't walk through walls. Invalid moves prompt a retry.
3. Objective:  
   - Successfully navigate from `S` (starting point) to `E` (exit) by finding the correct path.  
   - The player wins upon reaching the end.
4. Interactive Features:  
   - A graphical display of the maze updates in real-time, showing the player’s position.  
   - If you hit a wall, you'll be notified and can try another move.
5. Replayability:  
   - Once the player wins, they are asked if they want to play again. The maze is randomly regenerated for a fresh challenge each time.

## Memory Game:
1. *printBoard Function*  
This function is responsible for displaying the current state of the game board.  
   - The board is displayed as a grid where revealed numbers are shown, and hidden numbers are replaced with *.
   - Each cell in the grid is aligned neatly using setw() for formatting.
   - The revealed matrix is used to determine which numbers are visible.  
2. *initializeBoard Function*  
This function sets up the game board with pairs of random numbers.  
3. *Generating Pairs*
  The board is filled with pairs of numbers up to half the board size. For a 8x8 grid, it generates numbers from 1 to 16 (total 64 cells).  
4. *Shuffling*  
  The numbers are shuffled randomly using the C++ <random> library to ensure each game has a different layout.  
5. *Filling the Board*
  The shuffled numbers are distributed across a 2D vector that represents the grid.
6. *Game Initialization*
The board is created using initializeBoard(), and a corresponding revealed matrix is initialized with false to hide all numbers.
7. *Game Loop* 
The game continues until all pairs are found.  
   - Display the Board: The printBoard function shows the current state of the board. Hidden cards are marked with *, while revealed cards display their numbers.  
   - First Card Input: The player enters the row and column coordinates for the first card. If the card is already revealed, the game prompts the player to pick another one.  
   - Second Card Input: The player enters coordinates for the second card. The game ensures the player doesn’t pick the same card twice or choose an already revealed card.  
   - Matching Logic: If the two selected cards have the same number, the pair is marked as matched, and the numbers remain visible. If they don’t match, the cards are flipped back (hidden) after showing the board temporarily.  
   - Attempt Counter: The attempts variable increments each time the player selects two cards.  
   - Win Condition: The game ends when all pairs are found (pairsFound == totalPairs), and the player is congratulated with their total attempts displayed. 
8. *Replayability:*
After the game ends, the user is prompted to play again. If they choose “yes,” the board is reinitialized, and the game restarts.  

## Quiz-Game:
1. *Question Struct:* 
   - Contains the question text, a list of options, and the correct answer.
2. *initializeQuestions Function:* 
   - Initializes a list of quiz questions with their options and correct answers.
3. *displayQuestion Function:*
   - Displays a question and its options to the player.
4. *main Function:*
   - Setup: Initializes the quiz questions and sets a score variable.
   - Quiz Loop: Randomly selects and displays 5 unique questions to the player.
   - Answer Validation: Compares the player’s input with the correct answer and updates the score.
   - Result Display: After all questions are answered, the final score and a message are shown based on performance.

## Tic-Tac-Toe:

1. *main()*
   - Initializes the game by creating an empty board. Alternates between players, calling playerMove() to make moves.  
   - After every move, calls checkWin() to see if someone has won and isBoardFull() to check for a draw. If the game ends, asks players if they want to reset the board using resetBoard() and play again.
2. *printBoard()*
   - Displays the current state of the board. Each cell is shown with proper formatting to make the board clear.  
   - Helps players know which cells are available or already occupied.
3. *playerMove()*
   - Asks the current player to enter the row and column of their move. Validates the input to ensure it's within bounds and the cell is empty.  
   - Updates the board with the player's symbol ('X' or 'O') once the move is valid.
4. *checkWin()* 
   - Checks all rows, columns, and diagonals to see if there are three identical symbols ('X' or 'O') in a line.  
   - If a winning condition is found, returns true; otherwise, returns false.
5. *isBoardFull()*
   - Loops through every cell in the board. If at least one cell is empty (' '), it returns false, meaning the board is not full. If all cells are occupied, returns true, indicating a draw.
6. *resetBoard()*
   - Resets the entire board to its initial empty state with all cells set to ' '. Prepares the game for a fresh start.  

## SUDOKU:
1. `printBoard()`: Displays the current Sudoku board with empty cells shown as dots (`.`) and filled cells showing their respective numbers.
2. `printSolution()`: Displays the fully solved Sudoku board.
3. `canPlace()`: Checks if a number can be placed at a given position (row, col) in the board by verifying the row, column, and 3x3 subgrid for conflicts.
4. `solveSudoku()`: Solves the Sudoku puzzle using a backtracking algorithm by trying numbers from 1 to 9 and recursively attempting to fill the board. If a number leads to an invalid state, it backtracks.
5. `fillBoard()`: Attempts to fill the Sudoku board with valid numbers. It randomly shuffles numbers (1-9) and tries placing them in empty cells until the board is completely filled.
6. `removeNumbers()`: Removes a set number (20 in this case) of randomly chosen numbers from the filled board to create the puzzle with some empty cells.
7. `isSolved()`: Checks if the Sudoku board is completely filled, i.e., no empty cells are left.
8. `generateSudoku()`: Generates a new Sudoku puzzle by filling the board with numbers and then removing some to create a puzzle for the player.
9. `playSudoku()`: Manages the gameplay loop where the user is prompted to input moves (row, column, number). It validates the moves and displays the updated board. If the user quits, it solves the puzzle automatically and displays the solution.
10. `sudoku()`: Initializes the game, repeatedly generates a new Sudoku puzzle, and lets the user play until they decide to quit. It handles the game restart prompt as well.

## Number-Guessing-Game:
#### numberGuessingGame()
1. A range (ie., from 1 to 100) is selected and a random number (ie., the number to be guessed) is taken from this range.
2. A do-while loop is made for players to play again and again:
   - A random number (selected from 1 to 100) is stored in numberToGuess variable. This is what the user has to guess in attempts (=7) number of times (for which we make a loop)
   - Each time user input as guess is taken and checked if it is greater than or equal to or less than the numberToGuess. Accordingly a message is displayed. If guess=numberToGuess, the flag variable won is changed to true.
   - At last, the won flag is checked and if it's true, the user is declared winner.
   - At the very end, the user is asked if they'd like to play the game again and accordingly the loop continues or breaks.
