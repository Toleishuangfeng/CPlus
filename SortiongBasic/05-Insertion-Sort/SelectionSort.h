#pragma once

#include<iostream>
#include<algorithm>

using namespace std;

//—°‘Ò≈≈–ÚÀ„∑®
template <typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int mixIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[mixIndex])
				mixIndex = j;
		}
		swap(arr[i], arr[mixIndex]);
	}
}