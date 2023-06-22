/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
  return iterativeSolve(root, p, q);
  return recursiveSolve(root, p, q);
};

var iterativeSolve = (root, p, q) => {
  let pointer = root;
  for (;;) {
    if (pointer.val < p.val && pointer.val < q.val) {
      pointer = pointer.right;
    } else if (pointer.val > p.val && pointer.val > q.val) {
      pointer = pointer.left;
    } else {
      break;
    }
  }

  return pointer;
};

var recursiveSolve = (root, p, q) => {
  if (root.val < p.val && root.val < q.val)
    return lowestCommonAncestor(root.right, p, q);
  if (root.val > p.val && root.val > q.val)
    return lowestCommonAncestor(root.left, p, q);
  return root;
};
