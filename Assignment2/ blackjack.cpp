// Library tings
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// File tings
#include "blackjack.h"
using namespace std;

// Card class
Card::Card(Rank rank, Type type)
{
    this->rank = rank;
    this->type = type;
}
int Card::getValue()
{
    int ret_value = 0;
    Rank rank = this->rank;
    switch (rank)
    {
    case ACE:
        ret_value = 1;
        break;
    case TWO:
        ret_value = 2;
        break;
    case THREE:
        ret_value = 3;
        break;
    case FOUR:
        ret_value = 4;
        break;
    case FIVE:
        ret_value = 5;
        break;
    case SIX:
        ret_value = 6;
        break;
    case SEVEN:
        ret_value = 7;
        break;
    case EIGHT:
        ret_value = 8;
        break;
    case NINE:
        ret_value = 9;
        break;
    case TEN:
    case JACK:
    case QUEEN:
    case KING:
        ret_value = 10;
        break;
    };
    return ret_value;
}

void Card::displayCard()
{
    Rank rank = this->rank;
    Type type = this->type;

    // Display the card Number
    switch (rank)
    {
    case ACE:
        cout << "1";
        break;
    case TWO:
        cout << "2";
        break;
    case THREE:
        cout << "3";
        break;
    case FOUR:
        cout << "4";
        break;
    case FIVE:
        cout << "5";
        break;
    case SIX:
        cout << "6";
        break;
    case SEVEN:
        cout << "7";
        break;
    case EIGHT:
        cout << "8";
        break;
    case NINE:
        cout << "9";
        break;
    case TEN:
        cout << "10";
        break;
    case JACK:
        cout << "J";
        break;
    case QUEEN:
        cout << "Q";
        break;
    case KING:
        cout << "K";
        break;
    };

    // Display the type of card
    switch (type)
    {
    case CLUBS:
        cout << 'C';
        break;
    case DIAMONDS:
        cout << 'D';
        break;
    case HEARTS:
        cout << 'H';
        break;
    case SPADES:
        cout << 'S';
        break;
    }
};

////////// CARD CLASS //////////
// Add card to hand ftn
void Hand::add(Card card) { this->cards.push_back(card); };

// Clear cards from hand
void Hand::clear() { this->cards.clear(); };

// Sum of cards in deck
int Hand::getTotal()
{
    int ret_value = 0;
    int nb_aces = 0;
    int size = this->cards.size();
    for (int i = 0; i < size; i++)
    {
        if (this->cards[i].getValue() == 11)
        {
            nb_aces++;
        }
        // Incremmeent return value
        ret_value += this->cards[i].getValue();
    };
    // Iterate throught the ret_value and check if can remove some aces
    while (ret_value > 21 && nb_aces > 0)
    {
        ret_value -= 10;
    }
    return ret_value;
}
//Display hand
void Hand::displayHand()
{
    // Iterate thru cards and display them
    int i = 0;
    int size = this->cards.size();
    while (i < size)
    {
        // Return the card at index
        this->cards[i].displayCard();
        cout << " ";
        i++;
    }
}

////////// DECK CLASS //////////
void Deck::populate()
{
    // Iterate through both enums
    for (int rank = ACE; rank < KING; rank++)
    {
        for (int type = CLUBS; type < SPADES; type++)
        {
            // Add the element to the back of the vector
            this->deck.push_back(Card((Rank)rank, (Type)type));
        };
    };
};

void Deck::shuffle()
{
    // Shuffle the vector (BLESS Stack overflow)
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    auto gen = std::default_random_engine(seed);
    std::shuffle(this->deck.begin(), this->deck.end(), gen);
}

Card Deck::deal()
{
    // Access the last element in the vector
    int last_index = this->deck.size() - 1;
    Card card = this->deck[last_index];
    // remove the last element
    this->deck.pop_back();
    return card;
}

////////// ABSTRACTPLAYER CLASS //////////
bool AbstractPlayer::isBusted()
{
    // if the total of the hand is greater than 21
    if (this->hand.getTotal() > 21)
    {
        return true;
    }
    // Stop drawing
    return false;
}

////////// HUMANPLAYER CLASS //////////
bool HumanPlayer::isDrawing()
{
    char response;
    cout << "Would you like to draw a card? (y/n) ";
    // Take the response
    cin >> response;
    if (response == 'y')
    {
        return true;
    }
    return false;
}

void HumanPlayer::announce(char &status, int caz_hand)
{
    if (isBusted())
    {
        status = 'B';
        cout << "Player busts." << endl;
        cout << "Casino wins.\n"
             << endl;
    }
    else if (caz_hand > 21)
    {
        status = 'B';
        cout << "Casino busts. " << endl;
        cout << "Player wins.\n"
             << endl;
    }
    else if (caz_hand == 21 && this->hand.getTotal() == 21)
    {
        status = 'P';
        cout << "Push: No one wins.\n"
             << endl;
    }
    else
    {
        status = 'U';
    }
}

////////// COMPUTERPLAYER CLASS //////////
bool ComputerPlayer::isDrawing()
{
    //
    if (ComputerPlayer::hand.getTotal() <= 16)
    {
        return true;
    }
    // Stop drawing
    return false;
}

////////// BLACKJACK CLASS //////////
void BlackJackGame::play()
{
    HumanPlayer player = this->m_player;
    ComputerPlayer casino = this->m_casino;
    Deck deck = this->m_deck;

    //Create a deck and shuffle it
    deck.clear();
    deck.populate();
    deck.shuffle();

    // Clear both parties hands
    casino.hand.clear();
    player.hand.clear();

    // Initially both parties get a card
    casino.hand.add(deck.deal());
    cout << "Casino: ";
    // Show the caz hand
    casino.hand.displayHand();
    // Display the caz total
    cout << "[" << casino.hand.getTotal() << "] " << endl;

    //Player gets a card
    player.hand.add(deck.deal());
    cout << "Player: ";
    // Show the caz hand
    player.hand.displayHand();
    // Display the player total
    cout << "[" << player.hand.getTotal() << "]" << endl;

    // character to determine status of game
    char status = 'X';

    // iterate until the user decides to not draw
    while (player.isDrawing())
    {
        cout << "Player: ";
        // deal a new card
        Card dealing_card = deck.deal();
        // add the card to the hand
        player.hand.add(dealing_card);
        // display hand and value of hand
        player.hand.displayHand();
        // display total of hand
        cout << " [" << player.hand.getTotal() << "]" << endl;
        // Display the status of the game
        player.announce(status, casino.hand.getTotal());

        if (status == 'B')
        {
            // Exit current game -> player busted
            return;
        }
        else if (player.hand.getTotal() == 21)
        {
            // Player has 21, caz turn
            break;
        }
    }

    while (casino.isDrawing())
    {
        // Deal card to computer and add to hand
        casino.hand.add(deck.deal());
        cout << "Casino: ";
        // display hand of cazino
        casino.hand.displayHand();
        // Display total
        cout << " [" << casino.hand.getTotal() << "]" << endl;
    }
    // Display end status of game
    player.announce(status, casino.hand.getTotal());

    // Both players havent gotten to 21
    if (status == 'U')
    {
        // Case 1: Both equal (Push)
        if (player.hand.getTotal() == casino.hand.getTotal())
        {
            cout << "Push: No one wins.\n"
                 << endl;
        }
        // Case 2: Caz wins
        else if (player.hand.getTotal() < casino.hand.getTotal())
        {
            // casino wins with score under 21
            cout << "Casino wins.\n"
                 << endl;
        }
        // Case 3: Player wins
        if (player.hand.getTotal() > casino.hand.getTotal())
        {
            // player wins with score under 21
            cout << "Player wins.\n"
                 << endl;
        }
    }
}
