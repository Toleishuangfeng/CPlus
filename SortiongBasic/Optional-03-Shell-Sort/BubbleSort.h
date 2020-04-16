#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<typename T>
void bubbleSort1(T arr[], int n) {

	bool swapped;

	do {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}	
		}
		n--;
	} while (swapped);
}

template<typename T>
void bubbleSort2(T arr[], int n) {
	int newn;

	do {
		newn = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
			newn = i;
		}
		n = newn;
	} while (newn > 0);
}