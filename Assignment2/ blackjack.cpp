// Library tings
#include <iostream>
#include <cstdlib>
#include <numeric>

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
}

////////// CARD CLASS //////////

// Add card to hand ftn
void Hand::add(Card card)
{
    this->cards.push_back(card);
}

// Clear cards from hand
void Hand::clear()
{
    this->cards.clear();
}

// Sum of cards in deck
int Hand::getTotal()
{
    cards = this->cards;
    int ret_value = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        ret_value += cards[i].getValue();
    }
    return ret_value;
    // return accumulate(cards.begin(), cards.end(), 0);
}
