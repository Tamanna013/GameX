#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random> 
#include <limits>
#include <iomanip>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <string>
using namespace std;


// HANGMAN
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool>& guessed) {
    for (size_t i = 0; i < guessed.size(); ++i) {
        if (!guessed[i]) return false;
    }
    return true;
}

void hangman() {
    std::vector<std::string> words = {
    	"abandon", "ability", "absence", "academy", "account", "achieve", "acquire", "address", "advance", "adviser", "affect", "against", "airline", "airport", 
    	"alcohol", "alleged", "already", "amazing", "analyze", "ancient", "another", "anxiety", "apology", "applied", "appoint", "approve", "arrival", "article", 
    	"artwork", "asphalt", "athlete", "attempt", "attract", "auction", "auditor", "balance", "bargain", "bathing", "battery", "believe", "benefit", "beneath", 
    	"billion", "biology", "bizarre", "blanket", "blessing", "boredom", "boulder", "builder", "bulldog", "cabinet", "caffeine", "campaign", "capsule", "capture", 
    	"careful", "carrier", "caution", "central", "century", "chamber", "charity", "chasing", "chicken", "chimney", "chronic", "clarify", "classic", "cleaner", 
    	"climate", "clothing", "cluster", "coastal", "college", "comfort", "command", "comment", "commute", "compact", "compare", "compass", "complex", "concept", 
    	"concert", "conduct", "confess", "confide", "confirm", "connect", "consent", "contest", "context", "control", "convert", "cookies", "counsel", "counter", 
    	"country", "courage", "cricket", "crimson", "crucial", "culture", "cupcake", "current", "curtain", "custody", "cycling", "cylinder", "darkest", "daylight", 
    	"decline", "defence", "deficit", "delight", "deliver", "density", "deposit", "depress", "derive", "descend", "descent", "deserve", "destroy", "detain", 
    	"develop", "diamond", "digital", "discuss", "disease", "disgust", "dismiss", "dispute", "distant", "diverse", "divided", "donation", "doorway", "driving", 
    	"drought", "dubious", "dynamic", "earlier", "earning", "economy", "edition", "educate", "ejected", "elastic", "elected", "elegant", "element", "embrace", 
    	"emerged", "emotion", "emperor", "endless", "enhance", "enforce", "enjoyed", "enlarge", "enquiry", "enrolls", "envious", "episode", "erosion", "eternal", 
    	"ethical", "evening", "evident", "exactly", "exhibit", "explain", "explore", "express", "extreme", "factory", "faculty", "failure", "fascism", "fashion", 
    	"federal", "feeling", "fencing", "fiction", "figures", "finance", "finding", "fingers", "firearm", "fitness", "flowers", "forgive", "fortune", "fossils", 
    	"freedom", "freeway", "freight", "frigate", "friendly", "frontal", "frosted", "genuine", "gesture", "giggles", "glacier", "glowing", "goodbye", "governs", 
    	"grocery", "growing", "guilty", "harmony", "harvest", "heading", "healthy", "hearing", "heights", "helipad", "helpers", "herself", "highway", "holiday", 
    	"horizon", "hostage", "housing", "howling", "humbled", "hunting", "illness", "imagine", "impacts", "impulse", "improve", "include", "incomes", "indices", 
    	"indoors", "infancy", "inferno", "inquiry", "insight", "instant", "insulin", "insurer", "intends", "intense", "intrude", "islands", "justice", "keepers", 
    	"kitchen", "lacking", "landing", "largest", "laundry", "leading", "letters", "liberty", "limited", "linking", "liquids", "literary", "listing", "loyalty", 
    	"luckily", "machine", "madness", "magnets", "magical", "mailbox", "manager", "mankind", "manners", "married", "marvels", "massive", "masters", "matches", 
    	"maximum", "meaning", "measure", "medical", "meeting", "mention", "message", "methods", "military", "minimum", "mineral", "miracle", "mission", "mixture", 
    	"mobiles", "moments", "monarch", "monster", "morning", "mystery", "natural", "nearest", "nervous", "network", "neutral", "notices", "numbers", "observe", 
    	"offense", "officer", "optimal", "options", "organic", "outdoor", "outlets", "overlap", "oversea", "painting", "panther", "paradox", "parents", "parking", 
    	"partial", "partner", "passage", "passion", "patriot", "payment", "pending", "percent", "perfect", "perform", "perhaps", "persist", "persona", "phobias", 
    	"phrases", "physics", "picking", "picture", "pioneer", "planner", "plastic", "plenary", "pledges", "plumber", "poetics", "pointer", "portals", "portray", 
    	"postage", "posture", "pottery", "poultry", "praising", "premium", "prepare", "present", "preview", "primary", "printed", "printer", "privacy", "probing", 
    	"product", "program", "project", "protect", "protest", "provide", "publish", "pyramid", "qualify", "quality", "quarter", "queries", "quickly", "radical", 
    	"railway", "rainbow", "randoms", "rations", "reading", "reality", "recall", "recover", "reflect", "reforms", "refresh", "refunds", "refusal", "regains", 
    	"regards", "regions", "register", "regrets", "reliable", "remarks", "remains", "remains", "removal", "renders", "renewal", "replace", "request", "reserve", 
    	"resolve", "respect", "respond", "restore", "retreat", "returns", "revenue", "reverse", "reviews", "rewards", "rewrite", "rigging", "roaming", "romance", 
    	"routine", "runaway", "safeguard", "sailing", "samurai", "satisfy", "scanner", "scarlet", "schools", "science", "scoring", "seasons", "secrets", "securer", 
    	"segment", "selling", "seniors", "sensors", "serious", "servant", "service", "session", "settled", "seventh", "several", "shadows", "shelter", "shorter", 
    	"showing", "shuttle", "signals", "sincere", "singing", "sitting", "skating", "smiling", "snowman", "society", "soldier", "solving", "sorcery", "sources", 
    	"special", "species", "sponsor", "staring", "station", "stature", "staying", "steward", "stories", "stormy", "strange", "streaks", "streets", "stretch", 
    	"student", "studied", "stunned", "suburbs", "success", "suffering", "sugared", "suggest", "summers", "sunrise", "superb", "support", "supreme", "surface", 
    	"surgeon", "surplus", "survive", "suspect", "sustain", "swallow", "swapped", "symbols", "symptom", "systemic", "tableau", "tackled", "tactics", "taking", 
    	"talents", "tangible", "targeted", "teacher", "teasing", "telecom", "tempers", "temples", "tending", "tension", "terrain", "testing", "textile", "theatre", 
    	"therapy", "thereof", "thermos", "thicker", "thought", "threats", "thrills", "through", "tickets", "tightly", "timbers", "timings", "tonight", "torches", 
    	"torture", "tourism", "trading", "traffic", "trained", "trainer", "transit", "treated", "treason", "trebles", "tremble", "trouble", "trusted", "tuition", 
    	"turmoil", "turning", "twinkle", "tyranny", "typical", "ultimate", "umpires", "undergo", "undertow", "unfolds", "uniform", "unifies", "unison", "unknown", 
    	"unlocks", "unveils", "updates", "upfront", "uplifts", "upright", "uprising", "uranium", "urgency", "utility", "utopian", "utmost", "vacancy", "vaccine", 
    	"vacuumed", "valiant", "valleys", "vanguard", "vantage", "various", "vehicle", "venture", "verdict", "version", "veteran", "victory", "village", "villain", 
    	"vintage", "visible", "visibly", "visitors", "volcano", "voltage", "volumes", "vowling", "vulture", "waiting", "walking", "warning", "warrior", "warship", 
    	"wasting", "watched", "watered", "weaving", "wedding", "weekend", "welfare", "western", "whistle", "whiting", "wildest", "winning", "wishing", "wonders", 
    	"working", "wounded", "writers", "writing", "written", "yanking", "yearned", "yelling", "yielded", "yogurts", "younger", "youthful", "zapping", "zealots", 
    	"zigzags", "zipping", "zodiacs", "zombie", "zooming", "zookeeper", "zymurgy", "zythums"
	};


    char playAgain;
    do {
        srand(static_cast<unsigned int>(time(0)));
        string word = words.at(rand() % words.size());

        vector<bool> guessed(word.length(), false);
        int attemptsLeft = 7;
        vector<char> incorrectGuesses;

        cout << endl;
    	cout << "=====================================\n";
    	cout << "           Welcome to Hangman        \n";
    	cout << "=====================================\n";

        while (attemptsLeft > 0 && !isWordGuessed(guessed)) {
            cout << "\nAttempts left: " << attemptsLeft << endl;
            cout << "Incorrect guesses: ";
            for (size_t i = 0; i < incorrectGuesses.size(); ++i) {
                cout << incorrectGuesses[i] << " ";
            }
            cout << endl;

            displayWord(word, guessed);

            cout << "Guess a letter: ";
            char guess;
            cin >> guess;

            bool correctGuess = false;
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    guessed[i] = true;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                --attemptsLeft;
                incorrectGuesses.push_back(guess);
                cout << "Incorrect guess!" << endl;
            }
        }

        if (isWordGuessed(guessed)) {
            cout << "\nCongratulations! You've guessed the word: " << word << endl;
        } else {
            cout << "\nGame Over! The word was: " << word << endl;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;
}


// ROCK-PAPER-SCISSORS
enum Choice { ROCK = 1, PAPER, SCISSORS };
string getChoiceName(int choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Invalid";
    }
}

void determineRoundWinner(int playerChoice, int computerChoice, int& playerScore, int& computerScore) {
    if (playerChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) || (playerChoice == PAPER && computerChoice == ROCK) || (playerChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "You win this round!\n";
        playerScore++;
    } else {
        std::cout << "Computer wins this round!\n";
        computerScore++;
    }
}

void rockPaperScissors() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    bool playAgain = true;
    char choice;

    while (playAgain) {
    	cout << endl;
        cout << "----------------------------------------------------------------------------------------\n";
        cout << "                                     ROCK PAPER SCISSORS                                \n";
	cout << "----------------------------------------------------------------------------------------\n";

        int rounds, playerScore = 0, computerScore = 0;

        cout << "Enter the number of rounds you want to play (best of X): ";
        cin >> rounds;

        for (int i = 1; i <= rounds; i++) {
            cout << "\nRound " << i << " of " << rounds << ":\n";
            int playerChoice;
            cout << "Choose an option:\n";
            cout << "1. Rock\n2. Paper\n3. Scissors\n";
            cout << "Enter your choice (1-3): ";
            cin >> playerChoice;

            if (playerChoice < ROCK || playerChoice > SCISSORS) {
                std::cout << "Invalid choice! Skipping this round.\n";
                continue;
            }

            int computerChoice = rand() % 3 + 1;

            cout << "\nYou chose: " << getChoiceName(playerChoice) << "\n";
            cout << "Computer chose: " << getChoiceName(computerChoice) << "\n\n";

            determineRoundWinner(playerChoice, computerChoice, playerScore, computerScore);

            cout << "Current Score - You: " << playerScore << " | Computer: " << computerScore << "\n";
        }
		
		cout << endl;
		
        cout << "----------------------------------------------------------------------------------------\n";
        cout << "                                        FINAL RESULT                                    \n";
        cout << "----------------------------------------------------------------------------------------\n";

        if (playerScore > computerScore) {
            cout << "Congratulations! You won the best of " << rounds << " games!\n";
        } else if (computerScore > playerScore) {
            cout << "Computer wins the best of " << rounds << " games!\n";
        } else {
            cout << "It's a tie overall!\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    cout << "\nThank you for playing!\n";
}


// CROSSWORD
const int SIZE = 20;
char grid[SIZE][SIZE];
void crossword() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = '.';
        }
    }
    vector<string> words;
    words.push_back("CROSS");
    words.push_back("WORD");
    words.push_back("CODE");
    words.push_back("GAME");
    words.push_back("FUN");
    for (size_t i = 0; i < words.size(); ++i) {
        bool placed = false;
        while (!placed) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            bool isHorizontal = rand() % 2 == 0; 

            bool canPlace = true;
            if (isHorizontal) {
                if (col + words[i].length() > SIZE) canPlace = false;
                for (int j = 0; j < words[i].length(); ++j) {
                    if (grid[row][col + j] != '.' && grid[row][col + j] != words[i][j]) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    for (int j = 0; j < words[i].length(); ++j) {
                        grid[row][col + j] = words[i][j];
                    }
                    placed = true;
                }
            } else {
                if (row + words[i].length() > SIZE) canPlace = false;
                for (int j = 0; j < words[i].length(); ++j) {
                    if (grid[row + j][col] != '.' && grid[row + j][col] != words[i][j]) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    for (int j = 0; j < words[i].length(); ++j) {
                        grid[row + j][col] = words[i][j];
                    }
                    placed = true;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'A' + rand() % 26;
            }
        }
    }
    cout << "=====================================\n";
    cout << "          Welcome to Crossword       \n";
    cout << "=====================================\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "--------------------------------------\n";
    char playAgain;
    do {
        bool allFound = true;
        
        // Ask the user to find each word in the grid
        for (const string& word : words) {
            string inputWord;
            bool found = false;

            // Repeat until the user finds the word
            while (!found) {
                cout << "Enter the starting row and column for the word \"" << word << "\" (0 to " << SIZE - 1 << "): ";
                int startRow, startCol;
                char direction;
                cin >> startRow >> startCol;
                cout << "Is the word horizontal? (y/n): ";
                cin >> direction;
                bool isHorizontal = (direction == 'y' || direction == 'Y');

                // Verify if the word exists at the given location
                bool isCorrect = true;
                if (isHorizontal) {
                    for (int i = 0; i < word.length(); ++i) {
                        if (grid[startRow][startCol + i] != word[i]) {
                            isCorrect = false;
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < word.length(); ++i) {
                        if (grid[startRow + i][startCol] != word[i]) {
                            isCorrect = false;
                            break;
                        }
                    }
                }

                // Output the result of the guess
                if (isCorrect) {
                    cout << "Congratulations! You found the word \"" << word << "\"!\n";
                    found = true;
                } else {
                    cout << "Sorry, the word \"" << word << "\" is not found at the specified location. Try again.\n";
                }
            }
        }

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}


// QUIZ-GAME:
struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer;
};
vector<Question> initializeQuestions() {
    vector<Question> questions = {
        {"What is the time complexity of binary search?", {"A) O(n)", "B) O(log n)", "C) O(n^2)", "D) O(1)"}, 'B'},
        {"Which of the following is a dynamically typed language?", {"A) Java", "B) C++", "C) Python", "D) C"}, 'C'},
        {"Which sorting algorithm is the most efficient for large datasets?", {"A) Bubble Sort", "B) Selection Sort", "C) Merge Sort", "D) Insertion Sort"}, 'C'},
        {"What does SQL stand for?", {"A) Structured Query Language", "B) Simple Query Language", "C) Sorted Queue Language", "D) Styled Query Language"}, 'A'},
        {"In OOP, what does 'inheritance' allow?", {"A) Code reuse", "B) Memory management", "C) Debugging", "D) None of the above"}, 'A'},
        {"Which language is known as the backbone of web development?", {"A) Python", "B) Java", "C) JavaScript", "D) Swift"}, 'C'},
        {"What is the primary use of Git?", {"A) Project management", "B) Version control", "C) Task scheduling", "D) Error handling"}, 'B'},
        {"In C++, which keyword is used to define a constant?", {"A) define", "B) static", "C) const", "D) final"}, 'C'},
        {"Which symbol is used for comments in Python?", {"A) //", "B) /* */", "C) #", "D) %"}, 'C'},
        {"What is a pointer in C++?", {"A) A variable that stores a memory address", "B) A function", "C) A class", "D) A file handler"}, 'A'},
        {"What does CSS stand for?", {"A) Cascading Style Sheets", "B) Computer Styling System", "C) Creative Style Sheet", "D) Complex Style Sheet"}, 'A'},
        {"Which data structure uses LIFO order?", {"A) Queue", "B) Stack", "C) Tree", "D) Graph"}, 'B'},
        {"What is a binary tree?", {"A) A type of graph", "B) A tree with only two children per node", "C) A tree with two roots", "D) A linked list"}, 'B'},
        {"In HTML, which tag is used for links?", {"A) <a>", "B) <p>", "C) <link>", "D) <href>"}, 'A'},
        {"Which HTTP method is used to retrieve data?", {"A) POST", "B) GET", "C) PUT", "D) DELETE"}, 'B'},
        {"Which of the following is a NoSQL database?", {"A) MySQL", "B) PostgreSQL", "C) MongoDB", "D) SQLite"}, 'C'},
        {"In computer networks, what does DNS stand for?", {"A) Domain Name System", "B) Data Name System", "C) Digital Network Service", "D) Domain Network System"}, 'A'},
        {"Which protocol is used for secure communication over the internet?", {"A) HTTP", "B) FTP", "C) HTTPS", "D) SMTP"}, 'C'},
        {"Which language is primarily used for data analysis?", {"A) Java", "B) Ruby", "C) R", "D) PHP"}, 'C'},
        {"What is the use of the 'return' keyword in C++?", {"A) To end a program", "B) To repeat a loop", "C) To end a function and return a value", "D) To declare a variable"}, 'C'}
    };
    return questions;
}
void displayQuestion(const Question& q) {
    cout << q.questionText << "\n";
    for (const string& option : q.options) {
        cout << option << "\n";
    }
    cout << "Your answer (A, B, C, or D): ";
}

int main() {
    vector<Question> questions = initializeQuestions();
    srand(static_cast<unsigned int>(time(0)));

    int score = 0;
    int totalQuestions = 5;
    vector<int> askedQuestions;

    cout << "---------------------------------------\n";
    cout << "             Tech Quiz Game        \n";
    cout << "---------------------------------------\n\n";

    for (int i = 0; i < totalQuestions; ++i) {
        int questionIndex;
        do {
            questionIndex = rand() % questions.size();
        } while (find(askedQuestions.begin(), askedQuestions.end(), questionIndex) != askedQuestions.end());
        askedQuestions.push_back(questionIndex);
        displayQuestion(questions[questionIndex]);
        char answer;
        cin >> answer;
        answer = toupper(answer);
        if (answer == questions[questionIndex].correctAnswer) {
            cout << "Correct! \n";
            ++score;
        } else {
            cout << "Oops! The correct answer was " << questions[questionIndex].correctAnswer << ".\n";
        }
        cout << "-----------------------------------\n";
    }
    cout << "Quiz Complete!\n";
    cout << "Your Score: " << score << "/" << totalQuestions << "\n";
    if (score == totalQuestions) {
        cout << " Excellent! You nailed it! \n";
    } else if (score >= totalQuestions / 2) {
        cout << " Good job! Keep practicing!\n";
    } else {
        cout << " Better luck next time!\n";
    }

    return 0;
}


// NUMBER-GUESSING-GAME
void numberGuessingGame(){
    srand(static_cast<unsigned int>(time(0)));

    int rangeStart = 1, rangeEnd = 100;
    int attempts = 7; 
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int numberToGuess = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
        int guess;
        bool won = false;

        cout << "------------------------------------------\n";
    	cout << "          Number Guessing Game         \n";
    	cout << "------------------------------------------\n";
    	cout << "       Can you guess the number?       \n";
    	cout << "------------------------------------------\n\n";
        cout << " I'm thinking of a number between " << rangeStart << " and " << rangeEnd << ".\n";
    	cout << " You have " << attempts << " attempts to guess it.\n";
    	cout << "Good luck!\n\n";
    	
        for (int attempt = 1; attempt <= attempts; ++attempt) {
            cout << " Attempt " << attempt << " of " << attempts << ": ";
            cin >> guess;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << " Invalid input. Please enter a number: ";
                cin >> guess;
            }
            
            if (guess == numberToGuess) {
                won = true;
                break;
            } else if (guess < numberToGuess) {
                cout << " Too low! Try a higher number.\n";
            } else {
                cout << " Too high! Try a lower number.\n";
            }

            if (attempt < attempts) {
                cout << "-----------------------------------\n";
            }
        }
        
	cout << "-----------------------------------\n";
        if (won) {
        cout << " Congratulations! You guessed the number correctly! ??\n";
    	} else {
        cout << " Game Over! The correct number was " << number << ". Better luck next time!\n";
    	}
	cout << "-----------------------------------\n";
		
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    }

    cout << "Thanks for playing! See you next time!\n";
}


// DRIVER CODE
int main() {
    vector<string> games = {"Hangman", "Rock, Paper, Scissors", "Crossword", "Maze Solver", "Memory Game", "Quiz Game", "Snake Game", "Tic-Tac-Toe", "Sudoku", "Number Guessing Game"};
    int choice;

    do {
    	#ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
    	cout << "=====================================\n";
    	cout << "            Welcome to GameX         \n";
    	cout << "=====================================\n";
    	
        cout << "\nSelect a game to play:\n";
    	for (size_t i = 0; i < games.size(); ++i) {
        	cout << " [" << i + 1 << "] " << games[i] << "\n";
    	}
    	cout << " [0] Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }
        
        if (choice == 1) hangman();
        else if (choice == 2) rockPaperScissors();
        else if (choice == 3) crossword();
        else if (choice == 4) mazeSolver();
        else if (choice == 5) memoryGame();
        else if (choice == 6) quizGame();
        else if (choice == 7) snakeGame();
        else if (choice == 8) ticTacToe();
        else if (choice == 9) sudoku();
        else if (choice == 10) numberGuessingGame();
    	else if (choice == 0) cout << "\nExiting the console. Goodbye!\n";
    	else cout << "\nInvalid choice. Please try again.\n";
    } while (choice != 0);

    return 0;
}
