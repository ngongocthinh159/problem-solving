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
  return iterativeBackTrackingSolve(root, p, q);
  return iterativeStorePathCurNodeSolve(root, p, q);
  return recursiveSolve(root, p, q);
};

var recursiveSolve = (root, p, q) => {
  let pathToP = [];
  let pathToQ = [];
  var dfs = (root, target, pathToTarget, res) => {
    if (root.val === target) {
      for (let i = 0; i < pathToTarget.length; i++) {
        res[i] = pathToTarget[i];
      }
      return;
    }

    if (root.left) {
      pathToTarget.push(root.left);
      dfs(root.left, target, pathToTarget, res);
      pathToTarget.pop();
    }

    if (root.right) {
      pathToTarget.push(root.right);
      dfs(root.right, target, pathToTarget, res);
      pathToTarget.pop();
    }
  };

  dfs(root, p.val, [root], pathToP);
  dfs(root, q.val, [root], pathToQ);

  let i = 0;
  for (
    ;
    i < pathToP.length &&
    i < pathToQ.length &&
    pathToP[i].val === pathToQ[i].val;
    i++
  ) {}
  return pathToP[i - 1];
};

var iterativeBackTrackingSolve = (root, p, q) => {
  const stack = [[root, null]];
  const path = [];
  let pathP = null;
  let pathQ = null;

  for (; stack.length > 0; ) {
    const [cur, parent] = stack.pop();

    // Backtracking until parent node that push curNode to the stack
    while (parent !== null && path[path.length - 1] !== parent) {
      path.pop();
    }
    path.push(cur);

    if (cur.val === p.val) {
      pathP = [...path];
    }
    if (cur.val === q.val) {
      pathQ = [...path];
    }
    if (pathP && pathQ) break;

    if (cur.right) stack.push([cur.right, cur]);
    if (cur.left) stack.push([cur.left, cur]);
    if (!cur.left && !cur.right) {
      path.pop(); // Backtracking when reach a leaf node
    }
  }

  let i = 0;
  for (
    ;
    i < pathP.length && i < pathQ.length && pathP[i].val === pathQ[i].val;
    i++
  ) {}
  return pathP[i - 1];
};

var iterativeStorePathCurNodeSolve = (root, p, q) => {
  const stack = [[root, [root]]];
  let pathP = null;
  let pathQ = null;

  // For each node store the extra path to current node
  // => This extra path help us to not need to backtracking
  for (; stack.length > 0; ) {
    const [cur, pathToCur] = stack.pop();
    if (cur.val === p.val) {
      pathP = pathToCur;
    }
    if (cur.val === q.val) {
      pathQ = pathToCur;
    }

    if (pathP && pathQ) break;

    if (cur.right) stack.push([cur.right, [...pathToCur, cur.right]]);
    if (cur.left) stack.push([cur.left, [...pathToCur, cur.left]]);
  }

  let i = 0;
  for (
    ;
    i < pathP.length && i < pathQ.length && pathP[i].val === pathQ[i].val;
    i++
  ) {}
  return pathP[i - 1];
};
