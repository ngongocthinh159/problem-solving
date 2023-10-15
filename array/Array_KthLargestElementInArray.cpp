/*
  Solution for: https://leetcode.com/problems/kth-largest-element-in-an-array
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */

/* Main()  function */
int main() {
    vecotr<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << QuickSelect_findKthLargest(nums, 0, nums.size(), k);
}

/**
 * QUICK SELECT (QUICK SORT)
*/
// Chose a random pivot, pivot will eliminate approximately half of array
// => Next iteration will only check of half size array compared to the prev iteration
// O(n) in average case: N + N/2 + N/4 + ... = 2N => O(N)
// O(n^2) in worst case (all elements are almost the same)
int QuickSelect_findKthLargest(vector<int>& nums, int low, int high, int k) {
    if (low < high) {
        // Choose random pivot
        int min = low;
        int max = high - 1;
        int randomIndex = rand()%(max + 1 - min) + min;

        // Swap pivot with the first element
        swap(&nums[low], &nums[randomIndex]);

        int pivotIndex = partition(nums, low, high);
        if (pivotIndex == nums.size() - k) {
            return nums[pivotIndex];
        } else if (pivotIndex < nums.size() - k) {
            return QuickSelect_findKthLargest(nums, pivotIndex + 1, high, k);
        } else {
            return QuickSelect_findKthLargest(nums, low, pivotIndex, k);
        }
    } else return nums[low];
}
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    int i = low;
    int j = high;
    while (i < j) {
        do {
            i++;
        } while (i < high && nums[i] <= pivot);
        do {
            j--;
        } while (j >= low && nums[j] > pivot);
        if (i < j) swap(&nums[i], &nums[j]);
    }
    swap(&nums[j], &nums[low]);
    return j;
}
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}



/**
 * PRIORITY QUEUE (MAX HEAP)
*/
// O(n) for building max heap (average case), O(k*logn) for popping the first k max elements from heap
int PriorityQueue_findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++) {
        int cur = pq.top();
        pq.pop();
        if (i == k - 1) {
            return cur;
        }
    }
    return -1;
}



/**
 * COUNTING SORT
*/
// O(max(maxNum, nums.length)) - max num in leet code is 10^4 => So this is actually O(n)
int CountingSort_findKthLargest(vector<int>& nums, int k) {
    vector<int> cnt(2*(1e4) + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
        cnt[nums[i] + 1e4]++;
    }
    int find = nums.size() - k + 1;
    int cur = 0;
    for (int i = 0; i < cnt.size(); i++) {
        cur += cnt[i];
        if (cur >= find) return i - 1e4;
    }
    return -1;
}


/* Main() Ends Here */