#include <iostream>
#include <algorithm>
#include "hw2_functions.h"
// #include <cstdlib>
// #include <ctime>
using namespace std;

// struct creature {
//     string name = "";
//     int length = 0;
//     int heigth = 0;
// };

int main()
{

    const short CARD_SIZE = 14;
    const short SAYING_SIZE = 14;
    const int KRUSTY_MAX_CARD = 150;

    string sayings[SAYING_SIZE];
    creature cards[CARD_SIZE];
    creature krustyCards[KRUSTY_MAX_CARD];

    srand(time(NULL));

    cards[0].name = "Wanda Walrus";
    cards[0].length = 2;
    cards[0].heigth = 6;
    cards[1].name = "Stanley Sardine";
    cards[1].length = 3;
    cards[1].heigth = 1;
    cards[2].name = "Sylvia Seahorse";
    cards[2].length = 4;
    cards[2].heigth = 2;
    cards[3].name = "Janie Jellyfish";
    cards[3].length = 1;
    cards[3].heigth = 10;
    cards[4].name = "Doris Dolphin";
    cards[4].length = 8;
    cards[4].heigth = 4;
    cards[5].name = "Bob Blobfish";
    cards[5].length = 1;
    cards[5].heigth = 5;
    cards[6].name = "Sammy Shark";
    cards[6].length = 8;
    cards[6].heigth = 4;
    cards[7].name = "Walter Whale";
    cards[7].length = 6;
    cards[7].heigth = 2;
    cards[8].name = "Stevie Salmon";
    cards[8].length = 2;
    cards[8].heigth = 3;
    cards[9].name = "Sheila Shellfish";
    cards[9].length = 1;
    cards[9].heigth = 3;
    cards[10].name = "Daniel Octopus";
    cards[10].length = 3;
    cards[10].heigth = 7;
    cards[11].name = "Mark Herring";
    cards[11].length = 9;
    cards[11].heigth = 5;
    cards[12].name = "Bernie Tuna";
    cards[12].length = 3;
    cards[12].heigth = 5;
    cards[13].name = "Oscar Tilapia";
    cards[13].length = 5;
    cards[13].heigth = 3;

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

    for (int i = 0; i < 20; i++)
    {
        std::cout << "Picking up a card from a stranger.\n";
        int randomNum = getRandomNumber(14);
        std::cout << "Stranger says: \"" << sayings[getRandomNumber(14)] << "\"\n";
        krustyCards[i] = cards[randomNum];
        cards[randomNum].flag = true;
        std::cout << "Stranger gave you the " << krustyCards[i].name << "'s card.\n\n";
    }
    getchar();

    printCardList(krustyCards, KRUSTY_MAX_CARD);
    std::cout << getNumberOfCards(krustyCards, KRUSTY_MAX_CARD) << endl;
    std::sort(krustyCards, krustyCards + getNumberOfCards(krustyCards, KRUSTY_MAX_CARD), isCardSmaller);
    printCardList(krustyCards, KRUSTY_MAX_CARD);
    std::cout << isCollectionComplete(krustyCards, getNumberOfCards(krustyCards, KRUSTY_MAX_CARD)) << endl;
    return 0;
}