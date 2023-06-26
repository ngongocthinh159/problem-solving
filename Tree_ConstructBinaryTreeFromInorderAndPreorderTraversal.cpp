#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // [number, pos]
        }
        return recursiveBuild(preorder, inorder, inorderMap, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* recursiveBuild(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootPos = inorderMap[root->val]; // Index of root in inorder array

        root->left = recursiveBuild(preorder, inorder, inorderMap, preStart + 1, (preStart + 1) + ((rootPos - 1) - inStart + 1) - 1, inStart, rootPos - 1);
        root->right = recursiveBuild(preorder, inorder, inorderMap, (preStart + 1) + ((rootPos - 1) - inStart + 1) - 1 + 1, preEnd, rootPos + 1, inEnd);
        return root;
    }
};