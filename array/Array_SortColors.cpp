/*
  Solution for: https://leetcode.com/problems/sort-colors
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */
void sortColors(vector<int>& nums);
int partition(vector<int>& nums, int low, int high);
void swap(int*x, int*y);

/* Main()  function */
int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

void sortColors(vector<int>& nums) {
    // Choose pivot = 1
    // After parition:   1 0 1 0   1   2 ... 2
    //                           pivot 
    // We ensure 2 always in it's own partition (right side > pivot, left side <= pivot) 
    int index = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {index=i; break;}
    } 
    int pivotIndex = -1;
    if (index != -1) {
        swap(&nums[0], &nums[index]);
        pivotIndex = partition(nums, 0, nums.size());
    }

    // Choose pivot = 0
    // After parition:  0 ...0   0   1 ... 1   2 ... 2
    //                         pivot 
    // We ensure 1 always in it's own partition (right side > pivot, left side <= pivot) 
    index = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {index = i; break;}
    }
    if (index != -1) {
        swap(&nums[0], &nums[index]);
        if (pivotIndex != -1) pivotIndex = partition(nums, 0, pivotIndex);
        else partition(nums, 0, nums.size());
    }
}
int partition(vector<int>& nums, int low, int high) {
    int i = low, j = high;
    int pivot = nums[low];
    while (true) {
        do {
            i++;
        } while (i < high && nums[i] <= pivot);
        do {
            j--;
        } while (j >= low && nums[j] > pivot);
        if (i < j) swap(&nums[i], &nums[j]);
        else break;
    }
    swap(&nums[low], &nums[j]);
    return j;
}
void swap(int*x, int*y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}