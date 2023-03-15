#include "hw2_functions.h"

int getRandomNumber(int max)
{
    return (rand() % max);
}

bool isCardSmaller(creature card1, creature card2)
{
    int number1 = (std::max(card1.height, card1.length) * 10) + std::min(card1.height, card1.length);
    int number2 = (std::max(card2.height, card2.length) * 10) + std::min(card2.height, card2.length);
    return number1 >= number2;

    // int card1Max = std::max(card1.height, card1.length);
    // int card1Min = std::min(card1.height, card1.length);
    // int card2Max = std::max(card2.height, card2.length);
    // int card2Min = std::min(card2.height, card2.length);
    // return card1Max > card2Max && card1Min > card2Min;
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

bool isStackOfSix(creature cards[], int size)
{

    int sixFlag = 6;
    creature topOfStack;
    int card1Max = 0;
    int card1Min = 0;
    int card2Max = 0;
    int card2Min = 0;

    for (int i = 0; i < size - 6; i++)
    {
        topOfStack = cards[i];
        card1Max = std::max(topOfStack.height, topOfStack.length);
        card1Min = std::min(topOfStack.height, topOfStack.length);
        for (int j = i + 1; j < size; j++)
        {
            card2Max = std::max(cards[j].height, cards[j].length);
            card2Min = std::min(cards[j].height, cards[j].length);
            if (((card1Max >= card2Max && card1Min > card2Min) || (card1Max > card2Max && card1Min >= card2Min)))
            {
                // std::cout << cards[j].name << "         \t" << cards[j].length << " x " << cards[j].height << "\n";
                // printCard(topOfStack);
                topOfStack = cards[j];
                card1Max = card2Max;
                card1Min = card2Min;
                sixFlag--;
                if (sixFlag == 0)
                {
                    return true;
                }
            }
        }
        sixFlag = 6;
        // system("clear");
    }
    return false;
}

int getNumberOfCards(creature cards[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if ((cards[i].name == "" && cards[i].height == 0 && cards[i].length == 0))
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

void printCard(creature card, bool flag)
{
    cout
        << setw(20) << left << card.name << "\t"
        << setw(2) << right << card.length << " x "
        << setw(2) << right << card.height;
    if (flag)
    {
        cout << " " << setw(3) << card.occurance << " time" << (card.occurance > 1 ? "s" : "") << "\n";
    }
    else
    {
        cout << "\n";
    }
}

void printCardList(creature cards[], int size, bool flag)
{
    for (int i = 0; i < size; i++)
    {
        if (cards[i].name == "" && cards[i].height == 0 && cards[i].length == 0)
        {
            break;
        }
        else
        {
            if (flag)
            {
                printCard(cards[i], flag);
            }
            else
            {
                printCard(cards[i]);
            }
        }
    }
}

void printStackOfSix(creature cards[], int size)
{
    int sixFlag = 6;
    int stackIndex = 0;
    creature topOfStack;
    creature stackOfSix[6];
    int card1Max = 0;
    int card1Min = 0;
    int card2Max = 0;
    int card2Min = 0;

    for (int i = 0; i < size - 6; i++)
    {
        topOfStack = cards[i];
        card1Max = std::max(topOfStack.height, topOfStack.length);
        card1Min = std::min(topOfStack.height, topOfStack.length);
        for (int j = i + 1; j < size; j++)
        {
            card2Max = std::max(cards[j].height, cards[j].length);
            card2Min = std::min(cards[j].height, cards[j].length);
            if (((card1Max >= card2Max && card1Min > card2Min) || (card1Max > card2Max && card1Min >= card2Min)))
            {
                stackOfSix[stackIndex] = topOfStack;
                topOfStack = cards[j];
                card1Max = card2Max;
                card1Min = card2Min;
                stackIndex++;
                sixFlag--;
                if (sixFlag == 0)
                {
                    printCardList(stackOfSix, 6);
                }
            }
        }
        stackIndex = 0;
        sixFlag = 6;
    }
}

void findOccurance(creature cards1[], int size1, creature cards2[], int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (cards1[i].name == cards2[j].name)
            {
                cards1[i].occurance++;
            }
        }
    }
}