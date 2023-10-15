/*
  Solution for: https://leetcode.com/problems/median-of-two-sorted-arrays
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */
double TraverseApproach_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double BinarySearchApproach_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

/* Main()  function */
int main() {
    
    cout << TraverseApproach_findMedianSortedArrays(nums1, nums2);
}

// O(N) time, O(1) space approach can be come up during the interview
// Use one variable cnt to keep track the current index when merge two array:
// Actually, the solution below is not merging two array, but traverse two arrays
// follow the rules of merging (visit smaller element first). Then gradually increasing
// the counter until the counter reach first or second need-to-found indexes
double TraverseApproach_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int firstIndex = -1, secondIndex = -1;
    int totalLen = nums1.size() + nums2.size();
    if (totalLen%2 == 0) {
        firstIndex = totalLen/2;
        secondIndex = totalLen/2-1;
    } else {
        firstIndex = totalLen/2;
    }
    int firstNum, secondNum;
    int cnt = -1;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        cnt++;
        if (nums1[i] <= nums2[j]) {
            if (cnt==firstIndex) {
                firstNum = nums1[i];
            } else if (cnt == secondIndex) {
                secondNum = nums1[i];
            }
            i++;
        }
        else {
            if (cnt==firstIndex) {
                firstNum = nums2[j];
            } else if (cnt == secondIndex) {
                secondNum = nums2[j];
            }
            j++;
        }
    }
    while (i < nums1.size()) {
        cnt++;
        if (cnt==firstIndex) {
            firstNum = nums1[i];
        } else if (cnt == secondIndex) {
            secondNum = nums1[i];
        }
        i++;
    }
    while (j < nums2.size()) {
        cnt++;
        if (cnt==firstIndex) {
            firstNum = nums2[j];
        } else if (cnt == secondIndex) {
            secondNum = nums2[j];
        }
        j++;
    }
    if (totalLen%2 != 0) return firstNum;
    else return (double) (firstNum + secondNum)/2;
}

// Can not come up during interview
double BinarySearchApproach_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
}

/* Main() Ends Here */