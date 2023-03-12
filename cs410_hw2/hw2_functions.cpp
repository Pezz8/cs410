#include "hw2_functions.h"

int getRandomNumber(int max)
{
    return (rand() % max);
}

bool isCardSmaller(creature card1, creature card2)
{
    int array1[2] = {std::max(card1.heigth, card1.length), std::min(card1.heigth, card1.length)};
    int array2[2] = {std::max(card2.heigth, card2.length), std::min(card2.heigth, card2.length)};
    return array1[0] > array2[0];
    return ((card1.heigth * card1.length) < (card2.heigth * card2.length));
}

bool isCollectionComplete(creature cards[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cards[i].flag == false)
        {
            return false;
        }
    }
    return true;
}

int getNumberOfCards(creature cards[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if ((cards[i].name == "" && cards[i].heigth == 0 && cards[i].length == 0))
        {
            break;
        }
        else
        {
            counter++;
        }
    }
    return counter;
}

void printCardList(creature cards[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cards[i].name == "" && cards[i].heigth == 0 && cards[i].length == 0)
        {
            break;
        }
        else
        {
            cout << cards[i].name << "\t" << cards[i].heigth << " x " << cards[i].length << "\n";
        }
    }
}