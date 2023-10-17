#include <iostream>
#include <vector>
#include "myQuickSort.h"

namespace utils {
	// function to swap elements
	void swap_values(int* p_a, int* p_b) {
		int temp = *p_a;
		*p_a = *p_b;
		*p_b = temp;
	}

	// function to rearrange array (find the partition point)
	// select p_high as the pivot
	int* partition_vector(std::vector<int>& vec, int* p_low, int* p_high) {
		// pointer for greater element (p_i)
		int* p_i = p_low;
		int* p_j = p_low;
		int* p_pivot = p_high;
		// traverse each element of the array with p_j
		while (p_j < p_high) {
			// compare them with the pivot
			if (*p_j <= *p_pivot) {
				// if element smaller than pivot is found
				// swap it with the greater element pointed by p_i
				swap_values(p_i, p_j);
				p_i++;
			}
			p_j++;
		}
		// swap pivot with the greater element at p_i
		swap_values(p_i, p_pivot);
		return p_i;
	}

	void quick_sort_recursive(std::vector<int>& to_sort, int* p_low, int* p_high) {
		if (p_low >= p_high) return;
		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on right of pivot
		int* partition_point = partition_vector(to_sort, p_low, p_high);
		// recursive call on the left of pivot
		quick_sort_recursive(to_sort, p_low, partition_point - 1);
		// recursive call on the right of pivot
		quick_sort_recursive(to_sort, partition_point + 1, p_high);
	}

	void myQuickSort(std::vector<int>& to_sort) {
		quick_sort_recursive(to_sort, &to_sort[0], &to_sort[to_sort.size() - 1]);
	}
}