# GameX
Mini Game Console

I created a platform where the user can play 10 games in total all in one place. Its just for my C and C++ practice. The games are: Hangman, Rock-Paper-Scissors, Crossword, Maze-Solver, Memory-Game, Quiz-Game, Snake-Game, Tic-Tac-Toe, Sudoku, and Number-Guessing-Game.

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

## Number-Guessing-Game:
#### numberGuessingGame()
1. A range (ie., from 1 to 100) is selected and a random number (ie., the number to be guessed) is taken from this range.
2. A do-while loop is made for players to play again and again:
   - A random number (selected from 1 to 100) is stored in numberToGuess variable. This is what the user has to guess in attempts (=7) number of times (for which we make a loop)
   - Each time user input as guess is taken and checked if it is greater than or equal to or less than the numberToGuess. Accordingly a message is displayed. If guess=numberToGuess, the flag variable won is changed to true.
   - At last, the won flag is checked and if it's true, the user is declared winner.
   - At the very end, the user is asked if they'd like to play the game again and accordingly the loop continues or breaks.
