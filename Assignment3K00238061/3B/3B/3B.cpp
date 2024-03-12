#include "3BGuess.h"

using namespace std;

//K00238061 - Eddie Walsh 

void HeaderPrint();

void EnterNumber(int x);

int main()
{   //Calling our random generator
    srand((unsigned)time(0));
    //Creating our random number
    int target = 1 + (rand() % 1000);   int NoGuesses = 0;   int userGuess = 0;
    //Printing the header
    HeaderPrint();
    //Printing PRompt
    EnterNumber(NoGuesses);
    //user enters the number
    cin >> userGuess;
    //Guesses is implemented
    NoGuesses++;

    system("cls");
    //if the user doesnt get it right the first try, its entered into our do while loop
    if (userGuess != target)
    {
        do
        {   //we reprint our header
            HeaderPrint();
            //if the user guessed too high
            if (userGuess > target)
            {
                cout << "\n\tGUESS IS TOO HIGH\n";
            } //or too low
            else if (userGuess < target)
            {
                cout << "\n\tGUESS IS TOO LOW\n";
            }
            //Else we go back again 
            EnterNumber(NoGuesses);
            //and get another guess from the user until they run out of guesses
            cin >> userGuess;

            NoGuesses++;

            system("cls");

        } while (NoGuesses < 10 && userGuess != target);

        HeaderPrint();
        //if the user doesnt guess it right in 10 trys
        if (NoGuesses >= 10 && userGuess != target)
        {
            cout << "\n\n\t  YOU SHOULD BE ABLE TO DO BETTER!\n\n" << endl;
        }//else if the user guesses it exactly 10 tries
        else if (NoGuesses == 10 && userGuess == target)
        {
            cout << "\n\n\t  YOU KNOW THE SECRET!\n\n" << endl;
        }//if the user guesses it in less than 10 tries
        else if (NoGuesses < 10 && userGuess == target)
        {
            cout << "\n\n\t  EITHER YOU KNOW THE SECRET OR YOU GOT LUCKY....\n\n";
        }

        return 0;

    }// if the user guesses it in the first try, they brought here
    else

        system("cls");

    HeaderPrint();
    //And this message is printed to them
    cout << "\n\n\tEITHER YOU KNOW THE SECRET OR YOU GOT LUCKY....\n\n";

    return 0;
}

void HeaderPrint()
{
    cout << "\t**********************************\n";
    cout << "\t*\t GUESS THE NUMBER\t *\n";
    cout << "\t**********************************\n";
}

void EnterNumber(int x)
{
    //Creating a Countdown of tries they have
    int guess = 10 - x;
    //If the user is on their last turn, they get a last attempt warning 
    if (guess == 1)
    {
        cout << "\n\tNumber Of Attempts: LAST ATTEMPT" << endl;

        cout << "\tGuess A Number Between 1 and 1000 : ";
    }
    else
    {
        cout << "\n\tNumber Of Attempts: " << guess << endl;

        cout << "\tGuess A Number Between 1 and 1000 : ";
    }
}
