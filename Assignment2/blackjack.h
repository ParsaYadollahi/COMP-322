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

class Hand
{
protected:
    vector<Card> cards;

public:
    void add(Card card);
    void clear();
    int getTotal();
}
