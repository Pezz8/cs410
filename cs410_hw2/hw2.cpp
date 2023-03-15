#include <iostream>
#include <algorithm>
#include "hw2_functions.h"
using namespace std;

int main()
{

    const short CARD_SIZE = 14;
    const short SAYING_SIZE = 14;
    const int KRUSTY_MAX_CARD = 150;

    string sayings[SAYING_SIZE];
    creature cards[CARD_SIZE];
    creature krustyCards[KRUSTY_MAX_CARD];

    // srand(37);
    srand(time(NULL));

    cards[0].name = "Wanda Walrus";
    cards[0].length = 2;
    cards[0].height = 6;
    cards[1].name = "Stanley Sardine";
    cards[1].length = 3;
    cards[1].height = 1;
    cards[2].name = "Sylvia Seahorse";
    cards[2].length = 4;
    cards[2].height = 2;
    cards[3].name = "Janie Jellyfish";
    cards[3].length = 1;
    cards[3].height = 10;
    cards[4].name = "Doris Dolphin";
    cards[4].length = 8;
    cards[4].height = 4;
    cards[5].name = "Bob Blobfish";
    cards[5].length = 1;
    cards[5].height = 5;
    cards[6].name = "Sammy Shark";
    cards[6].length = 8;
    cards[6].height = 4;
    cards[7].name = "Walter Whale";
    cards[7].length = 6;
    cards[7].height = 2;
    cards[8].name = "Stevie Salmon";
    cards[8].length = 2;
    cards[8].height = 3;
    cards[9].name = "Sheila Shellfish";
    cards[9].length = 1;
    cards[9].height = 3;
    cards[10].name = "Daniel Octopus";
    cards[10].length = 3;
    cards[10].height = 7;
    cards[11].name = "Mark Herring";
    cards[11].length = 9;
    cards[11].height = 5;
    cards[12].name = "Bernie Tuna";
    cards[12].length = 3;
    cards[12].height = 5;
    cards[13].name = "Oscar Tilapia";
    cards[13].length = 5;
    cards[13].height = 3;

    sayings[0] = "Whazzup?";
    sayings[1] = "Duuude, totally love the clown head and human body combo!";
    sayings[2] = "Looking for a card (shark)?";
    sayings[3] = "Are you someone famous?";
    sayings[4] = "You look fishy to me; or are you clowning around?";
    sayings[5] = "Don't trust the salmon!!!";
    sayings[6] = "Here's some advice: the shark wants you to be his chum!";
    sayings[7] = "Better to take some paper towels if you visit the blobfish";
    sayings[8] = "Hey man, got any sea-weed?";
    sayings[9] = "Let me give you my card...my phone number is on the back";
    sayings[10] = "I'd gladly pay you tuesday for a lobster roll today.";
    sayings[11] = "Don't be so crabby!";
    sayings[12] = "Just keep swimming, swimmin, swimming, ...";
    sayings[13] = "You just keep sinking, sinking, sinking,...";

    for (int i = 0; i < 150; i++)
    {
        if (isCollectionComplete(cards, CARD_SIZE))
        {
            std::cout << "After collecting " << getNumberOfCards(krustyCards, KRUSTY_MAX_CARD) << " cards you completed the whole set.\n";
            findOccurance(cards, CARD_SIZE, krustyCards, getNumberOfCards(krustyCards, KRUSTY_MAX_CARD));
            printCardList(cards, CARD_SIZE, true);
            break;
        }
        else if (isStackOfSix(krustyCards, getNumberOfCards(krustyCards, KRUSTY_MAX_CARD)))
        {
            std::cout << "You were able to stack 6 cards\n";
            printStackOfSix(krustyCards, getNumberOfCards(krustyCards, KRUSTY_MAX_CARD));
            break;
        }
        else
        {
            int randomNum = getRandomNumber(14);
            krustyCards[i] = cards[randomNum];
            cards[randomNum].flag = true;
            std::sort(krustyCards, krustyCards + getNumberOfCards(krustyCards, KRUSTY_MAX_CARD), isCardSmaller);
        }
    }
    // printCardList(krustyCards, KRUSTY_MAX_CARD);
    // std::cout << isCollectionComplete(cards, CARD_SIZE) << endl;
    getchar();

    return 0;
}