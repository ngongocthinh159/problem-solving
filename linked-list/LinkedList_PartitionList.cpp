/*
  Solution for: https://leetcode.com/problems/partition-list/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    return 0;
}

ListNode* partition(ListNode* head, int x) {
    ListNode dummy1(-1);
    ListNode dummy2(-2);
    ListNode* p = head;
    ListNode* i = &dummy1;
    ListNode* j = &dummy2;

    while (p != NULL) {
        ListNode* next = p->next;
        if (p->val < x) {
            i->next = p;
            p->next = NULL;
            i = p;
        } else {
            j->next = p;
            p->next = NULL;
            j = p;
        }
        p = next;
    }
    i->next = dummy2.next;
    return dummy1.next;
}