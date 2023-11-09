/**
 * Solution for: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

  return 0;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* p = head;
    ListNode* prev = &dummy;
    while (p != NULL) {
        ListNode* start = p;
        p = p->next;
        bool notUnique = false;
        while (p != NULL && p->val == start->val) {
            p = p->next;
            notUnique = true;
        }
        if (notUnique) prev->next = p;
        else prev = start;
    }
    return dummy.next;
}
