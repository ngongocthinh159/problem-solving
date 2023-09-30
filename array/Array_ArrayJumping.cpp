/* 
Problem from coderbyte.com

Have the function ArrayJumping(arr) take the array of numbers stored in arr
and first determine the largest element in the array,
and then determine whether or not you can reach that same element within
the array by moving left or right continuously according to whatever integer
is in the current spot. If you can reach the same spot within the array,
then your program should output the least amount of jumps it took.

For example: if the input is [2, 3, 5, 6, 1] you'll start at the spot where
6 is and if you jump 6 spaces to the right while looping around the array you
end up at the last element where the 1 is. Then from here you jump 1 space to
the left and you're back where you started, so your program should output 2.
If it's impossible to end up back at the largest element in the array your
program should output -1. The largest element in the array will never equal
the number of elements in the array. The largest element will be unique. 

Input:1,2,3,4,2
Output:3

Input:1,7,1,1,1,1
Output:2
*/

#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=(s);i<(e);i++)
#define cf(i,s,e) for(long long int i=(s);i<=(e);i++)
#define rf(i,e,s) for(long long int i=(e);i>=(s);i--)
#define fe(a, b) for (auto&(a) : (b))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
ll directions[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}}; // UP-RIGHT-BOTTOM-DOWN || NORTH-EAST-SOUTH-WEST, From dir[4] Right of Up then clock wise
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); } // Greatest common divisor (Uoc chung lon nhat): O(log(min(a,b))
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; } // Lowest common mutiple (Boi chung nho nhat): O(log(min(a,b))
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
string int_to_string(ll a) { char x[100]; sprintf(x, "%lld", a); string s = x; return s; }
ll string_to_int(string a) { char x[100]; ll res; strcpy(x, a.c_str()); sscanf(x, "%lld", &res); return res; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
ll mod(ll x) { return (((x%MOD) + MOD) % MOD); }
ll addMod(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll subMod(ll a, ll b) { return mod(mod(a) - mod(b)); }
ll mulMod(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll powMod(ll x, ll n) { if (n == 0) return 1%MOD; ll u = powMod(mod(x),n/2); u = (u*u)%MOD; if (n%2 == 1) u = (u*(mod(x)))%MOD; return u; } // (x^n)%MOD
ll powMod(ll x, ll n, ll mod) { if (n == 0) return 1%mod; ll tmp = powMod(x,n/2,mod); if (n%2==0) return (tmp*tmp)%mod; else return (((tmp*tmp)%mod)*(x%mod))%mod; } // Custom mod number
ll inverseMod(ll a) { if (gcd(a, MOD) != 1) return -1; return powMod(mod(a), MOD-2); } // Return -1 if ((1/a)%MOD) not exist (a and MOD not coprime)
ll divMod(ll a, ll b) { ll tmp = inverseMod(b); if (tmp == -1) return -1; return (((mod(a))*inverseMod(mod(b)))%MOD); } // Return -1 if ((1/b)%MOD) not exist (b and MOD not coprime)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void OPEN(string s) {
#ifndef TESTING
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */
void solveDFS(vector<int>& arr);
void dfs(vector<int>& arr, int curIndex, vector<bool>& visited, int maxIndex, int level, int& ans);
void solveBFS(vector<int>& arr);

/* Main()  function */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> A = { 2, 3, 5, 6, 1 };
	vector<int> B = { 1, 2, 3, 4, 2 };
	vector<int> C = { 1, 7, 1, 1, 1, 1 };
	vector<int> D = { 1, 2, 1, 2, 1, 12 };
	vector<int> E = { 0, 5, 2 };
    
    // solveDFS(A);
    // solveDFS(B);
    // solveDFS(C);
    // solveDFS(D);
    // solveDFS(E);

    solveBFS(A);
    solveBFS(B);
    solveBFS(C);
    solveBFS(D);
    solveBFS(E);
}

void solveBFS(vector<int>& arr) {
    vector<bool> visited(arr.size(), false);
    
    // Get index of max number
    int maxIndex = -1, max = -1, ans = -1, level = 1;
    f(i,0,arr.size()) {
        if (max < arr[i]) {max = arr[i]; maxIndex = i;}
    }

    queue<int> q;
    q.push(maxIndex);
    visited[maxIndex] = true;

    while (q.size() > 0) {
        int levelLength = q.size();
        
        for (int i = 0; i < levelLength; i++) {
            int curIndex = q.front();
            visited[curIndex] = true;
            q.pop();

            int leftIndex = curIndex - arr[curIndex]%arr.size();
            if (leftIndex < 0) leftIndex += arr.size();
            int rightIndex = curIndex + arr[curIndex]%arr.size();
            if (rightIndex > arr.size() - 1) rightIndex -= arr.size();

            if (leftIndex == maxIndex || rightIndex == maxIndex) {
                cout << level << "\n";
                return;
            }
            if (!visited[leftIndex]) {
                q.push(leftIndex);
            }
            if (!visited[rightIndex]) {
                q.push(rightIndex);
            }
        }
        
        level++;
    }

    cout << "-1\n";
}

void solveDFS(vector<int>& arr) {
    vector<bool> visited(arr.size(), false);

    // Get index of max number
    int maxIndex = -1, max = -1, ans = INT_MAX;
    f(i,0,arr.size()) {
        if (max < arr[i]) {max = arr[i]; maxIndex = i;}
    }

    dfs(arr, maxIndex, visited, maxIndex, 1, ans);
    if (ans != INT_MAX) cout << ans << "\n";
    else cout << -1 << "\n";
}

void dfs(vector<int>& arr, int curIndex, vector<bool>& visited, int maxIndex, int level, int& ans) {
    visited[curIndex] = true;
    int leftIndex = curIndex - arr[curIndex]%arr.size();
    if (leftIndex < 0) leftIndex += arr.size();
    int rightIndex = curIndex + arr[curIndex]%arr.size();
    if (rightIndex > arr.size() - 1) rightIndex -= arr.size();
    
    if (!visited[leftIndex]) {
        // cout << "From index " << curIndex << " go left to index " << leftIndex << "\n";
        dfs(arr, leftIndex, visited, maxIndex, level + 1, ans);
        visited[leftIndex] = false;
    } else if (leftIndex == maxIndex) {
        // cout << "Find at: " << level << "\n";
        if (ans > level) ans = level;
        return;
    }
    if (!visited[rightIndex]) {
        // cout << "From index " << curIndex << " go right to index " << rightIndex << "\n";
        dfs(arr, rightIndex, visited, maxIndex, level + 1, ans);
        visited[rightIndex] = false;
    } else if (rightIndex == maxIndex) {
        // cout << "Find at: " << level << "\n";
        if (ans > level) ans = level;
        return;
    }
}

/* Main() Ends Here */