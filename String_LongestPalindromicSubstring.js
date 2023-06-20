/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  return expandFromCenterSolve(s); // Time: O(n^2), Space: O(1)
  return dpSolve(s); // Time: O(n^2), Space: O(n^2)
};

// Expand from center solution
var expandFromCenterSolve = (s) => {
  let max = -1;
  let res = null;

  // Odd palindromic substring
  for (let i = 0; i < s.length; i++) {
    const maxPalindromicLengthFromCenter = expand(s, i, i);
    if (max < maxPalindromicLengthFromCenter) {
      max = maxPalindromicLengthFromCenter;
      res = [
        i - Math.floor(maxPalindromicLengthFromCenter / 2),
        i + Math.floor(maxPalindromicLengthFromCenter / 2),
      ];
    }
  }

  // Even palindromic substring
  for (let i = 0; i < s.length - 1; i++) {
    if (s[i] === s[i + 1]) {
      const maxPalindromicLengthFromCenter = expand(s, i, i + 1);
      if (max < maxPalindromicLengthFromCenter) {
        max = maxPalindromicLengthFromCenter;
        res = [
          i - maxPalindromicLengthFromCenter / 2 + 1,
          i + maxPalindromicLengthFromCenter / 2,
        ];
      }
    }
  }

  return s.slice(res[0], res[1] + 1);
};

var expand = (s, i, j) => {
  let l = i - 1;
  let r = j + 1;

  while (l >= 0 && r <= s.length - 1 && s[l] === s[r]) {
    l--;
    r++;
  }

  // Return max length of palindromic substring if center start in [i, j]
  return r - l + 1 - 2;
};

// DP solution
var dpSolve = (s) => {
  const dp = new Array(s.length)
    .fill()
    .map((row) => new Array(s.length).fill(-1));
  let max = -1000;
  let res = [];

  for (let i = 0; i < s.length; i++) {
    for (let j = i; j < s.length; j++) {
      if (dp[i][j] === -1) {
        dp[i][j] === lengthOfPalindromicFromLToR(s, i, j, dp);

        if (max < dp[i][j]) {
          max = dp[i][j];
          res = [i, j];
        }
      }
    }
  }

  return s.slice(res[0], res[1] + 1);
};

var lengthOfPalindromicFromLToR = (s, l, r, dp) => {
  if (l === r) return (dp[l][r] = 1);
  if (l === r - 1) {
    if (s[l] === s[r]) return (dp[l][r] = 2);
    else return (dp[l][r] = 0);
  }
  if (dp[l][r] !== -1) return dp[l][r];

  if (s[l] === s[r]) {
    const temp = lengthOfPalindromicFromLToR(s, l + 1, r - 1, dp);
    if (temp !== 0) dp[l][r] = temp + 2;
    else dp[l][r] = 0;
  } else {
    dp[l][r] = 0;
  }
  return dp[l][r];
};
