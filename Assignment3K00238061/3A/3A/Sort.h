#pragma once
#include <iomanip>
#include <iostream>
#include <string>


template <class ItemType>
void Swap(ItemType& item1, ItemType& item2)
{
	ItemType tempItem;  // temporary holding area for swap

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}



template <class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex, bool& sorted)
{
	sorted = true;
	for (int index = endIndex; index > startIndex; index--)
	{
		if (values[index][0] < values[index - 1][0])
		{
			Swap(values[index], values[index - 1]);
			sorted = false;
		}
	}
}


template < class ItemType>
void BubbleSort(ItemType values[], int numValues)
{
	int current = 0;
	bool sorted = false;
	while (current < numValues - 1 && !sorted)
	{
		BubbleUp(values, current, numValues - 1, sorted);
		current++;
	}
}