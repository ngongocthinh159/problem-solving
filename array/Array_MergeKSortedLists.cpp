/**
 * Solution for: https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Idea: use priority queue to always fetch the smallest among k first elements from each array
 * => Pop the smallest, and push the next element of the array have the smallest
*/
class Solution {
public:
    struct P {
        ListNode* node;
        int val;
        P (ListNode* _node, int _v): node(_node), val(_v) {}
    };
    struct comparator {
        bool operator() (const P &a, const P &b) {
            if (b.val < a.val) return true;
            return false;
        } 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<P, vector<P>, comparator> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pq.push(P(lists[i], lists[i]->val));
        }
        ListNode dummy(-1);
        ListNode* p = &dummy;
        while (pq.size()) {
            auto smll = pq.top(); pq.pop();
            ListNode* smllNode = smll.node;
            ListNode* nxtNode = smllNode->next;
            if (nxtNode != NULL) pq.push(P(nxtNode, nxtNode->val));
            p->next = smllNode;
            smllNode->next = NULL;
            p = p->next;
        }
        return dummy.next;
    }
};

int main() {
    return 0;
}