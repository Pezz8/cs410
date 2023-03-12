#include <iostream>
using namespace std;

void printWelcomeMessage();
void printSelectionMenu();
void printSelectionIndicator();
void printLegPrompt();
void printAnxietyPrompt();
void printDayOfWeekPrompt();
void printHoursSleptPrompt();
void printBodyWeightPrompt();
void printBodyHeightPrompt();
void printRoomTempPrompt();
void printWrongSelectionError();
void printLazyError();
void pressEnterToContinue();
void printNumberOfStepsMessage(int steps);
void printNumberOfPillsMessage(int pills);
void printNapTimeMessage(double napTime);
void printAllowedCaloriesMessage(double calories);
char getCharInRange(int min, int max);
int getPositiveInt();
int getPositiveInt(int min, int max);
int calcNumOfSteps(int legs);
int calcNumOfPills(int anxLevel, int dayOfWeek);
double calcNumNapTime(int hrsSleep, int distWalked, int pillCount);
double calcCalories(int wt, int ht, double temp, int distWalked);

int main()
{
    int legs = 0;
    int anxietyLevel = 0;
    int dayOfTheWeek = 0;
    int hoursSlept = 0;
    int wt = 0;
    int ht = 0;
    double temp = 0;
    bool walkFlag = false;
    bool medFlag = false;

    //   printWelcomeMessage();
    //   printSelectionMenu();

    while (true)
    {
        system("clear");
        printWelcomeMessage();
        printSelectionMenu();

        printSelectionIndicator();
        char ch = getchar();
        switch (ch)
        {
        case '1':
            printLegPrompt();
            legs = getPositiveInt();
            printNumberOfStepsMessage(calcNumOfSteps(legs));
            pressEnterToContinue();
            walkFlag = true;
            break;
        case '2':
            printAnxietyPrompt();
            anxietyLevel = getPositiveInt(1, 10);
            printDayOfWeekPrompt();
            dayOfTheWeek = getPositiveInt(1, 7);
            printNumberOfPillsMessage(calcNumOfPills(anxietyLevel, dayOfTheWeek));
            pressEnterToContinue();
            medFlag = true;
            break;
        case '3':
            if ((walkFlag == true) && (medFlag == true))
            {
                printHoursSleptPrompt();
                hoursSlept = getPositiveInt();
                printNapTimeMessage(calcNumNapTime(hoursSlept, calcNumOfSteps(legs), calcNumOfPills(anxietyLevel, dayOfTheWeek)));
                pressEnterToContinue();
            }
            else
            {
                printLazyError();
                pressEnterToContinue();
            }
            break;
        case '4':
            if (walkFlag == true)
            {
                printBodyWeightPrompt();
                wt = getPositiveInt();
                printBodyHeightPrompt();
                ht = getPositiveInt();
                printRoomTempPrompt();
                temp = getPositiveInt();
                printAllowedCaloriesMessage(calcCalories(wt, ht, temp, calcNumOfSteps(legs)));
                pressEnterToContinue();
            }
            else
            {
                printLazyError();
                pressEnterToContinue();
            }
            break;
        case '5':
            return 0;
            break;
        default:
            printWrongSelectionError();
            pressEnterToContinue();
            break;
        }
    }
    return 0;
}

void printWelcomeMessage()
{
    cout << "Welcome to Health-o-Matic please make a selection "
         << "from the listed options.\n\n";
}

void printSelectionMenu()
{
    cout << "Health-o-Matic Options\n"
         << "----------------------\n"
         << "1. Taking a Walk!\n"
         << "2. Your Medications\n"
         << "3. Nap Time!\n"
         << "4. Caloric Intake\n"
         << "5. Quit\n";
}

void printSelectionIndicator()
{
    cout << "\nSelection: ";
}

void printLegPrompt()
{
    cout << "Please enter the number of legs of the walk that you wish to have: ";
}

void printAnxietyPrompt()
{
    cout << "Please enter your anxiety level from 1 to 10: ";
}

void printDayOfWeekPrompt()
{
    cout << "Please enter the current day of the week: ";
}

void printHoursSleptPrompt()
{
    cout << "Please enter the number of hours slept yesterday: ";
}

void printWrongSelectionError()
{
    cout << "\nPlease enter the right selection!\n";
}

void printBodyWeightPrompt()
{
    cout << "Please enter your body weight in pounds: ";
}

void printBodyHeightPrompt()
{
    cout << "Please enter your body height in inches: ";
}

void printRoomTempPrompt()
{
    cout << "Please enter the room temperature Fahrenheit : ";
}

void printLazyError()
{
    cout << "\nUnable to select this option!\n";
}

void pressEnterToContinue()
{
    cout << "\nPress Enter to continue ";
    getchar();
    getchar();
}

void printNumberOfStepsMessage(int steps)
{
    cout << "The total number of steps from the legs provided is: " << steps << endl;
}

void printNumberOfPillsMessage(int pills)
{
    cout << "Based on your anxiety level and the day of the week you can take " << pills << " pills." << endl;
}

void printNapTimeMessage(double napTime)
{
    cout << "Based on the number of hours slept, number of steps taken and the medicine taken you can nap for " << napTime << " minutes." << endl;
}

void printAllowedCaloriesMessage(double calories)
{
    cout << "Based on the distance walked, body weight, body height and room temperature you are allowed " << calories << " calories.\n";
}

char getCharInRange(int min, int max)
{
    char select = getchar();
    while ((select < min) && (select > max))
    {
        select = getchar();
    }
    return select;
}

int getPositiveInt()
{
    int positiveNumber;
    cin >> positiveNumber;
    cin.ignore(200, '\n');
    while (positiveNumber <= 0) // If the value is less than equal than zero it will ask for a different value
    {
        cout << "Positive numbers only please. Try again: ";
        cin >> positiveNumber;
        cin.ignore(200, '\n');
    }
    return positiveNumber; // Returning the correct number
}

int getPositiveInt(int min, int max)
{
    int positiveNumber;
    cin >> positiveNumber;
    cin.ignore(200, '\n');
    while ((positiveNumber < min) || (positiveNumber > max)) // If the value is less than equal than zero it will ask for a different value
    {
        cout << "Only number between " << min << " and " << max << ". Try again: ";
        cin >> positiveNumber;
        cin.ignore(200, '\n');
    }
    return positiveNumber; // Returning the correct number
}

int calcNumOfSteps(int legs)
{
    int steps = legs;
    for (int i = (legs - 1); i > 0; i--)
    {
        steps *= i;
    }
    return steps;
}

int calcNumOfPills(int anxLevel, int dayOfWeek)
{
    int pillCount = 0;

    if ((anxLevel - dayOfWeek) > 0)
    {
        pillCount = anxLevel - dayOfWeek;
    }
    else
    {
        pillCount = 0;
    }
    return pillCount;
}

double calcNumNapTime(int hrsSleep, int distWalked, int pillCount)
{
    return ((hrsSleep + distWalked) / (pillCount > 0 ? pillCount : 1));
}

double calcCalories(int wt, int ht, double temp, int distWalked)
{
    return ((6 * wt) + (2 * ht) + (1 / temp) + distWalked);
}