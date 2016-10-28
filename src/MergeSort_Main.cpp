//============================================================================
// Name        : MergeSort_Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;


void mergeTwoArea(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
		mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);

		//merge two area.
		mergeTwoArea(arr, left, mid, right);
	}
}

void mergeTwoArea(int arr[], int left, int mid, int right)
{
	//create new array.
	//int* tempArray = new int[right + 1];
	int tempArray[right + 1];

	//compare element of two area, smaller number goes array first.
	int leftIndex = left;
	int rightIndex = mid + 1;
	int iterator = left;

	while( (leftIndex <= mid) && (rightIndex <= right) )
	{
		//compare left value and right value.(two areas)
		if(arr[leftIndex] <= arr[rightIndex]) //left value is bigger,
		{
			//save left index value to array, increase lefttIndex
			tempArray[iterator] = arr[leftIndex++];
		}
		else
		{
			//save right index value to array, increase right index
			tempArray[iterator] = arr[rightIndex++];
		}
		iterator++;
	}

	if(leftIndex > mid)
	{
		for(int i = rightIndex; i <= right; i++)
		{
			tempArray[iterator] = arr[i];
			iterator++;
		}
	}
	else
	{
		for(int i = leftIndex; i <= mid; i++)
		{
			tempArray[iterator] = arr[i];
			iterator++;
		}
	}

	for(int i = left; i <= right; i++)
		arr[i] = tempArray[i];

	//delete tempArray;
}


int main()
{
	int arr[7] = {3,2,4,1,7,6,5};

	for(int i = 0; i < 7; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;

	//sort with merget sort
	mergeSort(arr, 0, 6);

	for(int i = 0; i < 7; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;


	return 0;
}
