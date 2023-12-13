/*
    Solution for: https://leetcode.com/problems/linked-list-cycle-ii
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        Trick: sau khi dùng fast, slow pointers cho 2 pointer gặp nhau. Ta cho slow pointer đứng yên tại chỗ gặp nhau

        Khởi tạo 1 pointer thứ 2 chạy từ head. Sau đó lần lượt cho 
        slow pointer và pointer mới khởi tạo chạy tịnh tiến 1 đơn vị

        => Hai pointer này chắc chắn gặp nhau tại nút thắt

        Ví dụ: 3 -> 2 -> 0 -> 1 -> 4
                         ^         |
                         |----------
        => Fast và slow gặp nhau tại 1 (gặp nhau tại điểm cách nút thắt bằng đúng khoảng cách từ head đến nút thắt)

        => Sau đó ta tịnh tiến 1 pointer từ head đến khi nào trùng với slow thì thôi
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;

        bool found = false;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = (f->next)->next;

            if (s == f) {
                found = true; break;
            }
        }
        if (!found) return NULL;

        ListNode* s1 = head;
        while (s != s1) {
            s = s->next;
            s1 = s1->next;
        }
        return s1;
    }
};

int main() {
    return 0;
}