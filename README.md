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

## Number-Guessing-Game:
#### numberGuessingGame()
1. A range (ie., from 1 to 100) is selected and a random number (ie., the number to be guessed) is taken from this range.
2. A do-while loop is made for players to play again and again:
   - A random number (selected from 1 to 100) is stored in numberToGuess variable. This is what the user has to guess in attempts (=7) number of times (for which we make a loop)
   - Each time user input as guess is taken and checked if it is greater than or equal to or less than the numberToGuess. Accordingly a message is displayed. If guess=numberToGuess, the flag variable won is changed to true.
   - At last, the won flag is checked and if it's true, the user is declared winner.
   - At the very end, the user is asked if they'd like to play the game again and accordingly the loop continues or breaks.
