/**
 * Solution for: https://leetcode.com/problems/rotate-list
*/

#include <bits/stdc++.h>
using namespace std;

ListNode* rotateList(ListNode* head, int k);

int main() {
    
    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
        
    // 4 -> 5 -> 6 -> 1 -> 2 -> 3

    // Cut from 3 and 4 then re-union 6 and 1 using dummy node
    
    ListNode dummy(-1);
    dummy.next = head;
    int cnt = 0;
    ListNode* p = head;
    ListNode* last;
    while (p != NULL) {
        cnt++;
        last = p;
        p = p->next;
    }
    if (cnt == 0 || cnt == 1) return dummy.next;
    int tmp = cnt - k % cnt;
    if (tmp == cnt) return dummy.next;
    p = head;
    ListNode* prev = &dummy;
    while (tmp != 0) {
        prev = p;
        p = p->next;
        tmp--;
    }
    prev->next = NULL;
    last->next = dummy.next;
    dummy.next = p;
    return dummy.next;
}
