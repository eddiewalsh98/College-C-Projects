#include "Sort.h"

//K00238061 - Eddie Walsh

using namespace std;

void BinarySearch(string NameArray[], string target, bool& found, int& position, int size);

void ArrayPrint(string Array[], int size);

int main()
{
    //Initializing variables and arrays needed
    string userSearch = ""; 
    bool found; 
    int position = 0;

    string NameArray[] = { "Jon", "Dot", "Eva", "Roy", "Guy", "Jan", "Tom", "Jim", "Ann", "Kim", "Ron", "Tim", "Kay", "Amy" };
    //Size of The Array
    int ArrayLength = sizeof(NameArray) / sizeof(NameArray[0]);

    cout << "Unordered Array of Names: " << endl;
    //Printing Array (Prior To Sorting)
    ArrayPrint(NameArray, ArrayLength);
    //Sort Array by Calling Selection Sort
    BubbleSort(NameArray, ArrayLength);
    cout << "\n\nOrdered Array of Names : " << endl;
    //Printing Array (Post Sorting)
    ArrayPrint(NameArray, ArrayLength);

    cout << "\n\n\tEnter Name To Search: ";
    //User enters the name they wish to look up
    cin >> userSearch;
    //Call Binary Search function
    BinarySearch(NameArray, userSearch, found, position, ArrayLength);
    //If our found variable is changed to true, than we print the following message
    if (found == true)
    {
        cout << "\n\n" << userSearch << " was found at index " << position << "!! " << endl;
    } //else this message is printed
    else if (found == false)
    {
        cout << "\n\n" << userSearch << " was NOT found...." << endl;
    }
}

void BinarySearch(string NameArray[], string target, bool& found,int& position, int size)
{
    //Creating variables needed
    int midPoint;  int first = 0; int last = size;
   
    bool moretoSearch = (first <= last);
   
    found = false;
    //While(first is less than last and found is not false
    while (moretoSearch && !found)
    {   //we find our midpoint
        midPoint = (first + last) / 2;
        
        //if the first letter of our target comes before our midpoints first letter
        if (target[0] < NameArray[midPoint][0])
        {
            //we equal last to our midpoint and focus on the first half of the array
            last = midPoint - 1;
            //And we keep our moretosearch variable
            moretoSearch = (first <= last);       
        }//else if the first letter of our target comes after our midpoints first letter
        else if (target[0] > NameArray[midPoint][0])
        {
            //we focus on the second half of the array
            first = midPoint + 1;
            moretoSearch = (first <= last);
        }
        else 
        {
            found = true;
            position = midPoint;
        }
    }
}



void ArrayPrint(string Array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << "  ";
    }
}
