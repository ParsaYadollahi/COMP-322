using namespace std;
#include <vector>

enum Rank
{
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK,
    QUEEN,
    KING
};

enum Type
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

// Card class
class Card
{
private:
    // Create private const for the enums listed above
    enum Rank rank;
    enum Type type;

    // Public function for Card
public:
    Card(Rank rank, Type type);
    // Display the used functions
    int getValue();
    void displayCard();
};

// Hand class
class Hand
{
protected:
    // Create a protected contructor
    vector<Card> cards;

public:
    // Display functions
    void add(Card card);
    void clear();
    int getTotal();
    void displayHand();
};

class Deck : public Hand
{
private:
    vector<Card> deck;

public:
    void populate();
    void shuffle();
    Card deal();
};

// Abstract player class
class AbstractPlayer : public Hand
{
public:
    Hand hand;

public:
    virtual bool isDrawing() = 0;
    bool isBusted();
};

// Human class
class HumanPlayer : public AbstractPlayer
{
public:
    bool isDrawing();
    void announce(char &status, int hand_total);
};

// Computer class
class ComputerPlayer : public AbstractPlayer
{
public:
    bool isDrawing();
};

// BlackJack class
class BlackJackGame
{
private:
    Deck m_deck;
    ComputerPlayer m_casino;
    HumanPlayer m_player;

public:
    void play();
};
