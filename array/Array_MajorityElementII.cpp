/*
  Solution for: https://leetcode.com/problems/find-peak-element
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Trick: với bài majority element thì chọn các pair gồm 2 số unique (num1, num2)
     * => Chia cả array thành các pair, với mỗi pair thì số lượng mỗi phần tử chiếm là 50%
     * => Nếu tồn tại majority element thì pair cuối cùng chắc chắn chứa major ele (vì major ele > 50%)
     *      Kể cả trường hợp xấu nhất major ele nằm trong tất cả các pair, thì major ele vẫn nằm trong pair cuối vì > 50%
     * 
     * Trick 2: tương tự áp dụng với bài toán này thì tìm các tuple gồm 3 số unique (num1, num2, num3)
     * + Trong mỗi tuple số lượng phần tử là 30%
     * + Nếu tồn tại ít nhất 1 major ele thì luôn đảm bảo pair cuối chứa major ele
     * 
     * Trick 3: làm sao để chia thành pair hoặc tuple?
     * + Tưởng tượng với mỗi phần tử ta push phần tử đó lên 1 stack riêng của phần tử đó.
     * + Với 2 phần tử unique đầu tiên ta có 2 stack.
     * + Khi gặp phần tử thứ 3 nghĩa là ta tạo được 1 tuple => Pop phần tử từ 2 stack ban đầu.
     * + Trường hợp gặp phần tử thứ 3 mà 1 trong 2 phần tử kia đã hết (ko còn ele trong stack) thì ta chọn phần tử mới làm phần tử trong stack.
     * + Tiếp tục tạo các tuple đến khi nào ko thể tạo được nữa thì thôi.
     * + Để ý thấy, ta chỉ quan tâm số lượng của mỗi phần tử hiện tại trong stack nên ta thay stack bằng biến count là được, mỗi lần pop count--.
     * 
     * Explain more: https://leetcode.com/problems/majority-element-ii/solutions/543672/boyer-moore-majority-vote-algorithm-explained/
    */
    vector<int> majorityElement(vector<int>& nums) {
        int c1, c2; int cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (num == c1) cnt1++;
            else if (num == c2) cnt2++;
            else if (cnt1 == 0) {c1 = num; cnt1 = 1;}
            else if (cnt2 == 0) {c2 = num; cnt2 = 1;}
            else {cnt1--; cnt2--;}
        }
        cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (num == c1) cnt1++;
            else if (num == c2) cnt2++;
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3) res.push_back(c1);
        if (cnt2 > nums.size() / 3) res.push_back(c2);
        return res;
    }
};

int main() {
    vector<int> nums = {3,2,3};
    cout << Solution().majorityElement() << "\n";
    return 0;
}