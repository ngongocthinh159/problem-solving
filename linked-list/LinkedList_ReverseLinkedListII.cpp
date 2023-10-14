/**
 * Solution for: https://leetcode.com/problems/reverse-linked-list-ii/
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

ListNode* reverseBetween(ListNode* head, int left, int right);

int main() {

  return 0;
}

// Using dummy node for edge case when the left node is the first node
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* l = head;
    ListNode* r = head;
    ListNode* prevL = dummy;
    ListNode* nextR = r->next;

    int cnt = 1;
    while (cnt < right) {
        cnt++;
        if (cnt <= left) {
            prevL = l;
            l = l->next;
        }
        if (cnt <= right) {
            r = r->next;
            nextR = r->next;
        }
    }

    ListNode* prev = nextR;
    ListNode* p = l;
    cnt = right - left + 1;
    while (true) {
        cnt--;
        ListNode* next = p->next;
        p->next = prev;
        prev = p;
        p = next;
        if (cnt == 0) break;
    }
    prevL->next = prev;
    return dummy->next;
}