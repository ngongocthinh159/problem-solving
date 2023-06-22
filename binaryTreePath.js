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
 * @return {string[]}
 */
var binaryTreePaths = function (root) {
  return iterativeStoreExtraImageSolve(root);
  return iterativeBackTrackingSolve(root);
  return recursiveDFSSolve(root);
  return recursivePreorderTraversalSolve(root);
};

var iterativeStoreExtraImageSolve = (root) => {
  const stack = [[root, [root.val]]];
  const res = [];

  // With each node, push to the stack that node with the path from root to current node
  // Each node will have its own image of the path from root the current node
  // By this way, no need to backtracking anymore (the image of the path is the backtracking)
  while (stack.length > 0) {
    const [cur, pathToCur] = stack.pop();

    if (cur.right) stack.push([cur.right, [...pathToCur, cur.right.val]]);
    if (cur.left) stack.push([cur.left, [...pathToCur, cur.left.val]]);
    if (!cur.left && !cur.right) {
      res.push(pathToCur.join('->'));
    }
  }

  return res;
};

var iterativeBackTrackingSolve = (root) => {
  const stack = [root];
  const res = [];
  const path = [];
  const map = new Map();

  for (; stack.length > 0; ) {
    const cur = stack.pop();

    // Backtracking until reach the node that push the current node to the stack
    // Because we are processing curNode, so if we want to push curNode to the path
    // we need to backtracking to the time the curNode was pushed into the stack
    // Map [key, value] = [curNode, node that push curNode to the stack]
    while (map.has(cur) && map.get(cur) !== path[path.length - 1]) {
      path.pop();
    }
    path.push(cur);

    if (cur.right) {
      stack.push(cur.right);
      map.set(cur.right, cur);
    }

    if (cur.left) {
      stack.push(cur.left);
      map.set(cur.left, cur);
    }

    if (!cur.left && !cur.right) {
      res.push(path.map((node) => node.val).join('->'));
      path.pop(); // Backtracking when traverse to a leaf node
    }
  }

  return res;
};

var recursiveDFSSolve = (root) => {
  const res = [];

  const dfs = (root, curPath) => {
    if (!root.left && !root.right) {
      res.push(curPath.join('->'));
      return;
    }

    if (root.left) {
      curPath.push(root.left.val);
      dfs(root.left, curPath, res);
      curPath.pop();
    }
    if (root.right) {
      curPath.push(root.right.val);
      dfs(root.right, curPath, res);
      curPath.pop();
    }
  };

  dfs(root, [root.val]);

  return res;
};

var recursivePreorderTraversalSolve = (root) => {
  const res = [];

  // With preorder => Backtracking when the cur node is leaf node or already traverse both left and right of cur node
  var preOrder = (root, curPath) => {
    if (!root) return;

    curPath.push(root.val);
    if (!root.left && !root.right) {
      res.push(curPath.join('->'));
      curPath.pop(); // Backtracking when cur node is leaf node
      return;
    }
    preOrder(root.left, curPath, res);
    preOrder(root.right, curPath, res);
    curPath.pop(); // Backtracking when already traverse both left and right tree of cur node
  };

  preOrder(root, []);

  return res;
};
