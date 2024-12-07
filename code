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
