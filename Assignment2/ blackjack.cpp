// Library tings
#include <iostream>
#include <cstdlib>
#include <numeric>
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
    this->rank = rank;
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
    this->rank = rank;
    this->type = type;

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
        cout << 'C' << endl;
        break;
    case DIAMONDS:
        cout << 'D' << endl;
        break;
    case HEARTS:
        cout << 'H' << endl;
        break;
    case SPADES:
        cout << 'S' << endl;
        break;
    }
};

////////// CARD CLASS //////////

// Add card to hand ftn
void Hand::add(Card card)
{
    this->cards.push_back(card);
};

// Clear cards from hand
void Hand::clear()
{
    this->cards.clear();
};

// Sum of cards in deck
int Hand::getTotal()
{
    cards = this->cards;
    int ret_value = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        ret_value += cards[i].getValue();
    };
    return ret_value;
    // return accumulate(cards.begin(), cards.end(), 0);
}
//Display hand
void Hand::displayHand()
{
    for (int i = 0; i < this->cards.size(); i++)
    {
        this->cards[i].displayCard();
        cout << " ";
    }
}

////////// DECK CLASS //////////
void Deck::populate()
{
    deck = this->deck;
    for (int type = CLUBS; type < SPADES; type++)
    {
        for (int rank = ACE; rank < KING; rank++)
        {
            deck.push_back(Card((Rank)rank, (Type)type));
        };
    };
};

void Deck::shuffle()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    auto gen = std::default_random_engine(seed);
    std::shuffle(this->deck.begin(), this->deck.end(), gen);
}

Card Deck::deal()
{
    Card card = this->deck[this->deck.size()];
    this->deck.pop_back();
    return card;
}

////////// ABSTRACTPLAYER CLASS //////////
bool AbstractPlayer::isBusted()
{
    if (this->hand.getTotal() > 21)
    {
        return true;
    }
    else
    {
        return false;
    }
}

////////// HUMANPLAYER CLASS //////////
bool HumanPlayer::isDrawing()
{
    char response;
    cout << "Would you like to draw a card? (y/n)";
    cin >> response;
    if (response == 'y')
    {
        return true;
    }
    else
    {
        return false;
    };
}

void HumanPlayer::announce(char &status, int caz_hand)
{
    if (isBusted())
    {
        status = 'B';
        cout << "Player busts.";
        cout << "Casino wins";
    }
    else if (caz_hand > 21)
    {
        status = 'B';
        cout << "Casino busts.";
        cout << "Player wins";
    }
    else
    {
        status = 'P';
        cout << "Push: No one wins.";
    }
}

////////// COMPUTERPLAYER CLASS //////////
bool ComputerPlayer::isDrawing()
{
    if (ComputerPlayer::hand.getTotal() < 16)
    {
        return true;
    }
    else
    {
        return false;
    };
}

////////// COMPUTERPLAYER CLASS //////////
void BlackJackGame::play()
{
    cout << "Welcome to the Comp322 Blackjack table!";

    //Create a deck and shuffle it
    this->m_deck.clear();
    this->m_deck.populate();
    this->m_deck.shuffle();

    // Clear both parties hands
    this->m_casino.hand.clear();
    this->m_player.hand.clear();

    // Initially both parties get a card
    this->m_casino.hand.add(this->m_deck.deal());
    cout << "Casino: ";
    // Show the caz hand
    m_casino.hand.displayHand();
    // Display the caz total
    cout << "[";
    cout << this->m_casino.hand.getTotal();
    cout << "]";

    this->m_player.hand.add(this->m_deck.deal());
    cout << "Player: ";
    // Show the caz hand
    m_player.hand.displayHand();
    // Display the caz total
    cout << "[";
    cout << this->m_player.hand.getTotal();
    cout << "]";
}
