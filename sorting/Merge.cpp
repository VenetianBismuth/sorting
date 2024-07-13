#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <thread>         
#include <chrono>


#include "Merge.hpp"
/*
void merge(std::vector<int> values, const int left, const int right, const int mid) {
	

	const int arr1 = mid - left + 1;
	const int arr2 = right - mid;

	auto* leftArray = new int[arr1],
		* rightArray = new int[arr2];

	for (auto i = 0; i < arr1; i++)
		leftArray[i] = values[left + i];
	for (auto j = 0; j < arr2; j++)
		rightArray[j] = values[mid + 1 + j];

	auto ind_arr1 = 0, ind_arr2 = 0;
	int ind_mergedArr = left;

	while (ind_arr1 < arr1 && ind_arr2 < arr2) {
		if (leftArray[ind_arr1] <= rightArray[ind_arr2]) {
			values[ind_mergedArr] = leftArray[ind_arr1];
			ind_arr1++;
		}
		else {
			values[ind_mergedArr]
				= rightArray[ind_arr2];
			ind_arr2++;
		}
		ind_mergedArr++;
		bars(ind_mergedArr);
	}

	while (ind_arr1 < arr1) {
		values[ind_mergedArr]
			= leftArray[ind_arr1];
		ind_arr1++;
		ind_mergedArr++;
	}

	delete[] leftArray;
	delete[] rightArray;

}

void mergeSort(std::vector<int> values, int l, int r) {
	if (l >= r) {
		return;
	}
	else {
		int m = l + (r - 1) / 2;
		mergeSort(values, l, m);
		mergeSort(values, m + 1, r);
		merge(values, l, m, r);
	}

	if (l == 0 && r == n - 1) { // If this is the final merge
		sorted = true;
		bars(-1);
	}
}
*/

