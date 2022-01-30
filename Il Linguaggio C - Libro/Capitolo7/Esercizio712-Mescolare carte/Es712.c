#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define HAND 5
#define POINTS 10
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
          const char *wSuit[]); // dealing doesn't modify the arrays
void dealHand(unsigned int hand[][FACES], const char *wFace[],
              const char *wSuit[]); // dealing doesn't modify the arrays

void takeHand(unsigned int hand[][FACES], unsigned int wDeck[][FACES]);
int pointValue(unsigned int hand[][FACES]);
void orderFacesInAHand(unsigned int faces[HAND]);
int isColor(unsigned int suits[HAND]);
int isStraight(unsigned int faces[HAND]);
void printFaces(unsigned int faces[HAND]);
int sameCards(unsigned int faces[HAND]);

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
    // 0: 0 carte uguali
    // 1: coppia
    // 2: doppia coppia
    // 3: tris
    // 4: scala
    // 5: colore
    // 6: full
    // 7: poker
    // 8: Scala colore
    // 9: scala reale
    const char *points[POINTS] =
        {"No Pair", "One Pair", "Two Pairs", "Three of a Kind", "Straight",
         "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};

    printf("\n%s\n", "Shuffled deck");
    puts("");
    deal(deck, face, suit); // deal the deck

    printf("\n%s\n", "First hand");
    dealHand(hand, face, suit); // deal the hand

    int point = pointValue(hand);
    puts("");
    printf("%s%s", "Point for the hand is: ", points[point]);
    puts("");
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
    for (size_t card = 1; card <= HAND; ++card)
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
                    hands[row][column] = card;
                }
            }
        }
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
    for (size_t card = 1; card <= HAND; ++card)
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

// calcolo il punteggio
int pointValue(unsigned int hand[][FACES])
{
    int point = 0;
    int sameNumberFirst = 1;
    int sameNumberSecond = 1;
    unsigned int suits[5] = {0};
    unsigned int faces[5] = {0};

    puts("");

    for (size_t card = 1; card <= HAND; card++)
    {
        for (size_t row = 0; row < SUITS; ++row)
        {
            // loop through columns of wDeck for current row
            for (size_t column = 0; column < FACES; ++column)
            {
                if (hand[row][column] == card)
                {
                    suits[card - 1] = row;
                    printf("%s%d\t", "row:", row);
                    faces[card - 1] = column;
                    printf("%s%d\n", "column:", column);
                }
            }
        }
    }

    puts("");

    printFaces(faces);
    orderFacesInAHand(faces);
    printFaces(faces);

    int color = isColor(suits);
    int straight = isStraight(faces);

    if (straight == 1 && color == 1)
    {
        if (faces[4] == 0 || faces[0] == 0)
        {
            return 9;
        }
        return 8;
    }

    if (straight == 1)
    {
        return 4;
    }

    point = sameCards(faces);

    if (point >= 6)
    {
        return point;
    }

    if (color == 1)
    {
        return 5;
    }

    return point;
}

// stampa la faces
void printFaces(unsigned int faces[HAND])
{
    puts("");
    printf("\n%s\n", "stampo l'array");
    for (size_t i = 0; i < HAND; i++)
    {
        printf(" %d\t", faces[i]);
    }

    puts("");
}

// verifica il colore
int isColor(unsigned int suits[HAND])
{

    for (size_t i = 0; i < HAND-1; ++i)
    {
        if (suits[i] != suits[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// verifica la scala
int isStraight(unsigned int faces[HAND])
{
    for (size_t i = 0; i < HAND-1; i++)
    {
        if ((faces[i + 1] - faces[i]) != 1)
        {
            return 0;
        }
    }

    return 1;
}

// torna un int con il punto del risultato
// 0: 0 carte uguali
// 1: coppia
// 2: doppia coppia
// 3: tris
// 6: full
// 7: poker
int sameCards(unsigned int faces[HAND])
{
    unsigned int equalsCard1 = 1;
    int numberFirstSet = -1;
    unsigned int equalsCard2 = 1;
    int numberSecondSet = -1;

    for (size_t i = 1; i < HAND; i++)
    {
        if (faces[i] == faces[i - 1])
        {
            if (numberFirstSet == -1 || numberFirstSet == faces[i])
            {
                numberFirstSet = faces[i];
                equalsCard1++;
            }
            else
            {
                numberSecondSet = faces[i];
                equalsCard2++;
            }
        }
    }

    if (numberFirstSet != -1)
    {
        if (equalsCard1 == 2)
        {
            if (equalsCard2 == 2)
            {
                return 2;
            }
            if (equalsCard2 == 3)
            {
                return 6;
            }
            else
            {
                return 1;
            }
        }

        if (equalsCard1 == 3)
        {
            if (equalsCard2 == 2)
            {
                return 6;
            }
            else
            {
                return 3;
            }
        }
        if (equalsCard1 >= 4)
        {
            return 7;
        }
    }
    else
    {
        return 0;
    }
}

// ordina le carte per numero
void orderFacesInAHand(unsigned int faces[HAND])
{
    for (unsigned int pass = 1; pass < HAND; ++pass)
    {
        int exchangesFaces = 0;

        for (size_t i = 0; i < HAND - pass; ++i)
        {
            if (faces[i] > faces[i + 1])
            {
                int hold = faces[i];
                faces[i] = faces[i + 1];
                faces[i + 1] = hold;
                exchangesFaces++;
            }
        }

        if (exchangesFaces == 0)
        {
            break;
        }
    }
}
