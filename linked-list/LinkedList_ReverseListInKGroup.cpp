/**
 * Solution for: https://leetcode.com/problems/reverse-nodes-in-k-group
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k);

int main() {

  return 0;
}

// Using dummy node for edge case when the left node is the first node
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p = head;
    ListNode* prevGroup = &dummy;    // Prev of start node of current group

    // Get the len of the list first => To calculate how many group
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }

    // Reverse each group
    p = head;
    for (int i = 0; i < (int) len/k; i++) {
        ListNode* startGroup = p;       // Start node of the current group
        ListNode* prev = NULL;          // prev node of current node (for reversing linked list)
        for (int j = 0; j < k; j++) {
            ListNode* next = p->next;
            p->next = prev;
            prev=p;
            p = next;
        }
        prevGroup->next = prev;
        startGroup->next = p;
        prevGroup = startGroup;
    }

    return dummy.next; 
}