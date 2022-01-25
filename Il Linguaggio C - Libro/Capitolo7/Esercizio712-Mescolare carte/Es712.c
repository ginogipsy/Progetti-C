// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define HANDS 5
#define POINTS 7
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
          const char *wSuit[]); // dealing doesn't modify the arrays
void dealHand(unsigned int hand[][FACES], const char *wFace[],
          const char *wSuit[]); // dealing doesn't modify the arrays
void takeHand(unsigned int hand[][FACES], unsigned int wDeck[][FACES]);

int main(void)
{
    // initialize deck array
    unsigned int deck[SUITS][FACES] = {0};
    unsigned int hand[SUITS][FACES] = {0};

    srand(time(NULL)); // seed random-number generator

    shuffle(deck); // shuffle the deck
    takeHand(hand, deck);

    // initialize suit array
    const char *suit[SUITS] =
        {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] =
        {"Ace", "Deuce", "Three", "Four",
         "Five", "Six", "Seven", "Eight",
         "Nine", "Ten", "Jack", "Queen", "King"};

    // initialize points array
    const char *points[POINTS] =
        {"No Pair", "One Pair", "Two Pairs", "Three of a Kind",
         "Four of a Kind", "Flush", "Straight"};

    //deal(deck, face, suit); // deal the deck
    dealHand(hand, face, suit); // deal the hand
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card)
    {
        size_t row;    // row number
        size_t column; // column number

        // choose new random location until unoccupied slot found
        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0); // end do...while

        // place card number in chosen slot of deck
        wDeck[row][column] = card;
    }
}

void takeHand(unsigned int hands[][FACES], unsigned int wDeck[][FACES])
{
    for (size_t card = 0; card < HANDS; ++card)
    {
        hands[card][card] = wDeck[card][card];
    }
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
          const char *wSuit[])
{
    // deal each of the cards
    for (size_t card = 1; card <= CARDS; ++card)
    {
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row)
        {
            // loop through columns of wDeck for current row
            for (size_t column = 0; column < FACES; ++column)
            {
                // if slot contains current card, display card
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                           card % 2 == 0 ? '\n' : '\t'); // 2-column format
                }
            }
        }
    }
}

    // deal cards in deck
void dealHand(unsigned int hand[][FACES], const char *wFace[],
          const char *wSuit[])
{
    // deal each of the cards
    for (size_t card = 1; card <= HANDS; ++card)
    {
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row)
        {
            // loop through columns of wDeck for current row
            for (size_t column = 0; column < FACES; ++column)
            {
                // if slot contains current card, display card
                if (hand[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                           card % 2 == 0 ? '\n' : '\t'); // 2-column format
                }
            }
        }
    }
}
