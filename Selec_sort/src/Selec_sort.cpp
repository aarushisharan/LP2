//============================================================================
// Name        : Selec_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
	for(int i=0;i<=n-2;i++)
	{
		int mini=i;
		for(int j=i+1;j<=n-1;j++)
		{
			if(arr[j]<arr[mini])
				mini=j;
			//update the value of the minimum index
		}
		//swap mini with the 1st element of the unsorted part
		swap(arr[i],arr[mini]);
	}
	cout << "After selection sort: " << "\n";
	  for (int i = 0; i < n; i++) {
	    cout << arr[i] << " ";
	  }
	  cout << "\n";
}

int main()
{
	int arr[] = {13,46,24,52,20,9};
	  int n = sizeof(arr) / sizeof(arr[0]);
	   cout << "Before selection sort: " << "\n";
	   for (int i = 0; i < n; i++) {
	    cout << arr[i] << " ";
	  }
	  cout << "\n";
	  selection_sort(arr, n);
	  return 0;

}
