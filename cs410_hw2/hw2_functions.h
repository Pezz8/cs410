#ifndef HW2_FUNCTIONS_H
#define HW2_FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct creature
{
    string name = "";
    int length = 0;
    int heigth = 0;
    bool flag = false;
};

struct cardFlag
{
    string name = "";
    bool flag = false;
};

int getRandomNumber(int max);
int getNumberOfCards(creature cards[], int size);
bool isCardSmaller(creature card1, creature card2);
bool isCollectionComplete(creature cards[], int size);
void printCardList(creature cards[], int size);

#endif