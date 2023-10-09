/*
  Solution for: https://leetcode.com/problems/copy-list-with-random-pointer
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    return 0;
}

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}

/**
 * Intuitive approach O(1) space, O(n) time, just traverse the original list, and mark visited node,
 * and for each visited node link it with the counterpart node from the duplicated list 
*/
Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    // Remember visited node in original list and map it to the visited node in copied list
    unordered_map<Node*,Node*> map;

    Node* p = head;
    Node* res = new Node(p->val);
    Node* copyP = res;
    map[p] = copyP;
    
    while (p != NULL) {
        Node* randomNode = p->random;
        Node* nextNode = p->next;

        Node* copyRandomNode;
        Node* copyNextNode;

        if (randomNode == NULL) {
            copyRandomNode = NULL;
        } else if (map.find(randomNode) != map.end()) {
            copyRandomNode = map[randomNode];
        } else {
            copyRandomNode = new Node(randomNode->val);
            map[randomNode] = copyRandomNode;
        }

        if (nextNode == NULL) {
            copyNextNode = NULL;
        } else if (map.find(nextNode) != map.end()) {
            copyNextNode = map[nextNode];
        } else {
            copyNextNode = new Node(nextNode->val);
            map[nextNode] = copyNextNode;
        }

        copyP->random = copyRandomNode;
        copyP->next = copyNextNode;

        copyP = copyNextNode;
        p = nextNode;
    }

    return res;
}

/**
 * This solution is O(1) space, O(n) time, but use a tricky technic
 * Very not intuitive, but optimize space.
 * It use 3 iteration:
 * 1. Duplicate each node by one node after it
 * 2. Link random node
 * 3. Separate first list and duplicate list
*/
Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    Node* p = head;
    while (p != NULL) {
        Node* next = p->next;
        Node* dup = new Node(p->val);
        p->next = dup;
        dup->next = next;
        p = next;
    }

    p = head;
    while (p != NULL) {
        Node* random = p->random;
        Node* dupRandom = NULL; 
        if (random != NULL) dupRandom = random->next;
        Node* dup = p->next;
        dup->random = dupRandom;
        p = p->next->next;
    }

    p = head;
    Node* res;
    int cnt = 0;
    while (p != NULL) {
        Node* dup = p->next;
        Node* next = p->next->next;
        Node* dupNext = NULL;
        if (next != NULL) dupNext = p->next->next->next;
        p->next = next;
        dup->next = dupNext;
        if (cnt == 0) {
            res = dup; cnt++;
        }
        p = next;
    }
    return res;
}