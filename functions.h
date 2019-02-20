#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


using namespace std;

// *** MIND READER *** //
//  The two main functions for game number 1 //
void PressN2Continue()
{
	while (true)
	{
		srand(static_cast<unsigned int>(time(0)));

		int number = rand() % 100 + 1;
		int num_guess;

		int num_tries = 0;
		char response;

		// Loop to process the game functionality
		while (true) {
			std::cout << "Enter a number between 1 and 100 there are " << 35 - num_tries << " tries left: ";
			std::cin >> num_guess;
			std::cin.ignore();

			if (num_tries >= 35) {
				break;
			}

			if (num_guess > number) {
				std::cout << "Too high! Try again.\n";
			}
			else if (num_guess < number) {
				std::cout << "Too low! Try again.\n";
			}
			else {
				break;
			}
			// increment for wrong answers
			num_tries++;
		}

		// check for exceeded tries
		if (num_tries >= 35) {
			std::cout << "The game has ended. You have " << num_tries << " left!\n\n";
		}
		// end game if won
		else {
			std::cout << "You have beat the game! " << std::endl;
			std::cout << "You got the right number in " << num_tries << " tries!\n";
		}

		// prompt user to play again
		std::cout << "Would you like to play again (Y/N)? ";
		std::cin >> std::setw(1) >> response;
		std::cin.ignore();

		// if yes program restarts
		if (response == 'y' || response == 'Y') {
			return PressN2Continue();
		}
		// if not then leave program
		else {
			std::cout << "\n You did a great job! Goodbye. ";
			break;
		}

		if ('n' == getchar())
			break;
	}
}

void hello() {

	cout << "Welcome to the Best Game for Players!\n";
	PressN2Continue();
	return;
}

// *** DARK DUNGEON *** //
int dungeon_func() {
//Set up our variables

int num_warriors, num_killed, num_monsters, num_survivors;
const int gold = 10000;
string leader;

// Get input from the user 

// How many are in your squad?
cout << "Enter a number: ";
cin >> num_warriors;

// How many of them got killed on your quest?
cout << "Enter a number, smaller than the first: ";
cin >> num_killed;

// How many monsters attacked?
num_monsters = num_warriors * 10;

// How many of your warriors survived?
num_survivors = num_warriors - num_killed;

// Identify yourself!
cout << "Enter your last name: ";
cin >> leader;

cout << "Welcome, brave " << leader << "!" << endl;
cout << "You have " << num_warriors << " on your squad." << endl;
cout << num_killed << " of your warriors were killed by an attack of " << num_monsters << " monsters." << endl;
cout << "You have " << num_survivors << " warriors remaining." << endl;
cout << "Each member of your team was given " << gold / num_survivors << " pieces of gold." << endl;

}


// *** TIC-TACT-TOE *** //
// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

// main function
int tic_tac_toe()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);

    while (winner(board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;

        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }

    announceWinner(winner(board), computer, human);

    return 0;
}

void instructions()
{
     cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
     cout << "--where human brain is pit against silicon processor\n\n";

     cout << "Make your move known by entering a number, 0 - 8. The number\n";
     cout << "corresponds to the desired board position, as illustrated:\n\n";

     cout << "       0 | 1 | 2\n";
     cout << "       ------- \n";
     cout << "       3 | 4 | 5\n";
     cout << "       ------- \n";
     cout << "       6 | 7 | 8\n\n";

     cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will be your undoing...  I will go first.\n";
        return X;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    if (piece == EMPTY)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void displayBoard(const vector<char>& board)
{
     cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
     cout << "\n\t" << "------- ";
     cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
     cout << "\n\t" << "------- ";


    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board)
{
    // all possible winning rows
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
                                     
                                     const int TOTAL_ROWS = 8;

// if any winning row has three values that are the same (and not EMPTY),
// then we have a winner
for(int row = 0; row < TOTAL_ROWS; ++row)
{
    if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
         (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
         (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
    {
        return board[WINNING_ROWS[row][0]];
    }
}

     // since nobody has won, check for a tie (no empty squares left)
     if (count(board.begin(), board.end(), EMPTY) == 0)
         return TIE;
// since nobody has won and it isn't a tie, the game ain't over
     return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)
{
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine...\n";

    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    //if computer can win on next move, that's the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }
    
    //otherwise, if human can win on next move, that's the move to make
     if (!found)
     {
         move = 0;
         char human = opponent(computer);

         while (!found && move < board.size())
         {
             if (isLegal(move, board))
             {
                 board[move] = human;
                 found = winner(board) == human;
                 board[move] = EMPTY;
             }

             if (!found)
             {
                 ++move;
             }
         }
     }
     
     //otherwise, moving to the best open square is the move to make
     if (!found)
     {
         move = 0;
         unsigned int i = 0;

         const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
         //pick best open square
         while (!found && i <   board.size())
         {
             move = BEST_MOVES[i];
             if (isLegal(move, board))
             {
                 found = true;
             }

             ++i;
         }
     }
     
      cout << "I shall take square number " << move << endl;
     return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I, the computer, so swear it!\n";
    }

    else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate...  for this is the best you will ever achieve.\n";
    }
}


// *** WORD JUMBLER is the second greatest game *** //

int jumble() 
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about"}
    };
    
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  // word to guess
    string theHint = WORDS[choice][HINT]; // the hint for word
    
    string jumble = theWord;  // jumbled version of the word
    int length = jumble.size();
    for(int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }
    
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;
    
    string guess;
    cout << "\n\nYour guess is: ";
    cin >> guess;
    
    while((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else 
        {
            cout << "Sorry, that is not it.";
        }
        cout << "\n\nYour guess is: ";
        cin>>guess;
    }
    if(guess == theWord)
    {
        cout << "\nThat's it! You guessed correctly!\n";
    }
    cout << "\nThanks for playing.\n";
    return 0;
}

// *** CRITTER TIME / Zoo-keeper game! *** //
class Critter 
{
    public: 
        Critter(int hunger = 0, int boredom = 0);
        void Talk();
        void Eat(int food = 4);
        void Play(int fun = 4);
    
    private:
        int m_Hunger;
        int m_Boredom;
        
        int GetMood() const;
        void PassTime(int time=1);
};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger),
    m_Boredom(boredom)
    {}
    
inline int Critter::GetMood()const
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel ";
    int mood = GetMood();
    
    if(mood > 15)
    {
        cout << "mad.\n";
    }
    else if (mood > 10)
    {
        cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "okay.\n";
    }
    else 
    {
        cout << "happy.\n";
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brrupp.\n";
    
    m_Hunger -= food;
    if(m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Whee!\n";
    
    m_Boredom -= fun;
    if(m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

int critt() 
{
    Critter crit;
    crit.Talk();
    
    int choice;
    do
    {
        cout << "\nCritter Caretaker\n\n";
        cout <<"0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";
        
        cout << "Choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 0:
                cout << "Good-bye.\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            default:
                cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    } while(choice != 0);
    return 0;
}

// *** HANG-MAN *** 
int hang()
{
    const int MAX_WRONG = 8; // maximum number of incorrect guesses
    
    vector<string> words; // collection of possible words
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    
    cout << "Welcome to Hangman. Good luck!\n";
    
    while((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left. \n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar <<endl;
        
        char guess;
        cout <<"\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // make the guess uppercase
        
        while(used.find(guess) != string::npos)
        {
            cout <<"\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        
        used += guess;
        
        if(THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";
            
            //update soFar to include newly guessed letter
            for(int i=0; i < THE_WORD.length(); ++i)
            {
                if(THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout <<"Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    
    //shut down
    if(wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout <<"\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}

//*** BLACK-JACK ***
class Card
{
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    //overloading << operator so can send Card object to standard output
    friend ostream& operator<<(ostream& os, const Card& aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    //returns the value of a card, 1 - 11
    int GetValue() const;

    //flips a card; if face up, becomes face down and vice versa
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    //if a cards is face down, its value is 0
    int value = 0;
    if (m_IsFaceUp)
    {
        //value is number showing on card
        value = m_Rank;
        //value is 10 for face cards
        if (value > 10)
		{
            value = 10;
		}
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
    Hand();

    virtual ~Hand();

    //adds a card to the hand
    void Add(Card* pCard);

    //clears hand of all cards
    void Clear();

    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
    vector<Card*> m_Cards2;
};

Hand::Hand()
{
    m_Cards.reserve(7);
    m_Cards2.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
    m_Cards2.push_back(pCard);
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    //if no cards in hand, return 0
    if (m_Cards.empty())
	{
        return 0;
	}

    //if a first card has value of 0, then card is face down; return 0
    if (m_Cards[0]->GetValue() == 0)
	{
        return 0;
	}

    //add up card values, treat each Ace as 1
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
        total += (*iter)->GetValue();
	}

    //determine if hand contains an Ace
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
        if ((*iter)->GetValue() == Card::ACE)
		{
            containsAce = true;
		}
	}

    //if hand contains Ace and total is low enough, treat Ace as 11
    if (containsAce && total <= 11)
	{
        //add only 10 since we've already added 1 for the Ace
        total += 10;
	}

    return total;
}

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name = "");

    virtual ~GenericPlayer();

    //indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;

    //announces that the generic player busts
    void Bust() const;

protected:
    string m_Name;
};

GenericPlayer::GenericPlayer(const string& name):
    m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    cout << m_Name << " busts.\n";
}

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();

    //returns whether or not the player wants another hit
    virtual bool IsHitting() const;

    //announces that the player wins
    void Win() const;

    //announces that the player loses
    void Lose() const;

    //announces that the player pushes
    void Push() const;
};

Player::Player(const string& name):
    GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
    cout << m_Name <<  " wins.\n";
}

void Player::Lose() const
{
    cout << m_Name <<  " loses.\n";
}

void Player::Push() const
{
    cout << m_Name <<  " pushes.\n";
}

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    virtual ~House();

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};

House::House(const string& name):
    GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
	{
        m_Cards[0]->Flip();
	}
    else
	{
		cout << "No card to flip!\n";
	}
}

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    //create a standard deck of 52 cards
    void Populate();

    //shuffle cards
    void Shuffle();

    //deal one card to a hand
    void Deal(Hand& aHand);
    void Deal2(Hand& aHand);

    //give additional cards to a generic player
    void AdditionalCards(GenericPlayer& aGenericPlayer);
    void AdditionalCards2(GenericPlayer& aGenericPlayer);
};

class Deck2 : public Hand
{
public:
    Deck2();

    virtual ~Deck2();

    //create a standard deck of 52 cards
    void Populate();

    //shuffle cards
    void Shuffle();

    //deal one card to a hand
    void Deal2(Hand& aHand);

    //give additional cards to a generic player
    void AdditionalCards2(GenericPlayer& aGenericPlayer);
};

Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}

Deck2::Deck2()
{
    m_Cards2.reserve(52);
    Populate();
}

Deck::~Deck()
{}

Deck2::~Deck2()
{}

void Deck::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}

void Deck2::Populate()
{
    Clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck2::Shuffle()
{
    random_shuffle(m_Cards2.begin(), m_Cards2.end());
}

void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck2::Deal2(Hand& aHand)
{
    if (!m_Cards2.empty())
    {
        aHand.Add(m_Cards2.back());
        m_Cards2.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while ( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() )
    {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBusted())
		{
            aGenericPlayer.Bust();
		}
    }
}

void Deck2::AdditionalCards2(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while ( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() )
    {
        Deal2(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBusted())
		{
            aGenericPlayer.Bust();
		}
    }
}

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    //plays the game of blackjack
    void Play();

private:
    Deck m_Deck;
    Deck2 m_Deck2;
    House m_House;
    vector<Player> m_Players;
};

Game::Game(const vector<string>& names)
{
    //create a vector of players from a vector of names
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
	{
        m_Players.push_back(Player(*pName));
	}

	//seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
    m_Deck2.Populate();
    m_Deck2.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    //deal initial 2 cards to everyone
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
            m_Deck.Deal(*pPlayer);
            
            
		}
        m_Deck.Deal(m_House);
    }

    //hide house's first card
    m_House.FlipFirstCard();

    //display everyone's hand
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        cout << *pPlayer << endl;
	}
    cout << m_House << endl;
    
    char deck2;
    cout << "\n Would you like to have an additional card from deck two? Press Y/y for yes or N/n for no." << endl;
    cin >> deck2;
    
    if (deck2 == 'y' || deck2 == 'Y')
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) 
        {
            cout << "\n*** Dealing from the second deck ***" << endl;
            m_Deck2.Deal2(*pPlayer);
            cout << *pPlayer;
        }
    }
        
    //deal additional cards to players
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        m_Deck.AdditionalCards(*pPlayer);
	}

    //reveal house's first card
    m_House.FlipFirstCard();
    cout << endl << m_House;

    //deal additional cards to house
    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        //everyone still playing wins
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
            if ( !(pPlayer->IsBusted()) )
			{
                pPlayer->Win();
			}
		}
    }
    else
    {
         //compare each player still playing to house
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer)
        {
            if ( !(pPlayer->IsBusted()) )
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    //remove everyone's cards
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
        pPlayer->Clear();
	}
    m_House.Clear();
}

//function prototypes
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

int blackj()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    //the game loop
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}

//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

//overloads << operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }


        if (aGenericPlayer.GetTotal() != 0)
		{
            cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
    }
    else
    {
        os << "<empty>";
    }

    return os;
}