/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function (root) {
  let res = -Infinity;

  // For each node:
  // 1. Calculate the maximum path sum without split at that node (DFS)
  // 2. Calculate the maximum path sum when choose to split at that node (res variable)
  const maxFrom = (root) => {
    if (!root) return 0;

    const maxFromLeft = Math.max(maxFrom(root.left), 0);
    const maxFromRight = Math.max(maxFrom(root.right), 0);
    res = Math.max(res, maxFromLeft + maxFromRight + root.val);
    return root.val + Math.max(maxFromLeft, maxFromRight);
  };
  maxFrom(root);

  return res;
};
