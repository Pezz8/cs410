#ifndef HW2_FUNCTIONS_H
#define HW2_FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct creature
{
    string name = "";
    int length = 0;
    int height = 0;
    bool flag = false;
    int occurance = 0;
};

struct cardFlag
{
    string name = "";
    bool flag = false;
};

int getRandomNumber(int max);
int getNumberOfCards(creature cards[], int size);
bool isCardSmaller(creature card1, creature card2);
bool isStackOfSix(creature cards[], int size);
bool isCollectionComplete(creature cards[], int size);
void printCard(creature card, bool flag = false);
void printCardList(creature cards[], int size, bool flag = false);
void printStackOfSix(creature cards[], int size);
void findOccurance(creature cards1[], int size1, creature cards2[], int size2);

#endif