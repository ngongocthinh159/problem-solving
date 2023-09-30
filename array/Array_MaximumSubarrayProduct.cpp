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
ll mod(ll x, ll _mod) { return (((x%_mod) + _mod) % _mod); }
ll addMod(ll a, ll b, ll _mod) { return mod(mod(a, _mod) + mod(b, _mod), _mod); }
ll subMod(ll a, ll b, ll _mod) { return mod(mod(a, _mod) - mod(b, _mod), _mod); }
ll mulMod(ll a, ll b, ll _mod) { return mod(mod(a, _mod) * mod(b, _mod), _mod); }
ll powMod(ll x, ll n, ll _mod) { if (n == 0) return 1%_mod; ll u = powMod(mod(x,_mod),n/2,_mod); u = (u*u)%_mod; if (n%2 == 1) u = (u*(mod(x,_mod)))%_mod; return u; } // (x^n)%_mod
ll inverseMod(ll a, ll _mod) { if (gcd(a, _mod) != 1) {cout << "There is no inverse mod of " << a << " and " << _mod << "\n"; return -1;}; return powMod(mod(a,_mod), _mod-2, _mod); } // Return -1 if ((1/a)%_mod) not exist (a and _mod not coprime)
ll divMod(ll a, ll b, ll _mod) { ll tmp = inverseMod(b, _mod); if (tmp == -1) {cout << "There is no divided mod of " << a << " and " << b << "\n"; return -1;} return (((mod(a, _mod))*inverseMod(mod(b, _mod), _mod))%_mod); } // Return -1 if ((1/b)%_mod) not exist (b and _mod not coprime)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
void OPEN() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */
int solveKadaneAlgorithm(vector<int>& nums);
int solvePrefixProductAndMonotoniqueQueue(vector<int>& nums);

/* Main()  function */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> nums = {2,-5,-2,-4,3};


    // Skip all zero number, for each segment not have zero, find the maximum product on that segment
    // Save an dp vector dp[i] = {first, second}:
    // 1. dp[i].first is maximum positive subarray can reach if subarray end at i
    // 2. dp[i].second is minimum negative subarray can reach if subarray end at i
    // For each index i, we will decide if we will concat the current nums[i] with the subarray from i - 1 (Kadane algorithm)
    // We only concat if the new product get to a higher total product (idea of Kadane when deal with problem Maximum Subarray Sum)
    cout << solveKadaneAlgorithm(nums) << "\n";

    // Skip all zero number, for each segment not have zero, find the maximum product on that segment
    // Using the idea of monotonique queue and prefix product, traverse from left 
    // 1. Get the maximum prefix if current number > 0
    // 2. Get minimum prefix if current number < 0
    cout << solvePrefixProduct(nums) << "\n";
}

int solveKadaneAlgorithm(vector<int>& nums) {
    vector<pair<long long, long long>> dp(nums.size());
    long long ans = LLONG_MIN;
    for (int i = 0; i < nums.size();) {
        if (nums[i] == 0) {if (ans < 0) ans = 0; i++; continue;}
        int j = i;
        for (; j < nums.size(); j++) {
            if (nums[j] == 0) break;

            if (j == i) {
                if (nums[j] > 0) dp[j] = {nums[j], 0};
                else if (nums[j] < 0) dp[j] = {0, nums[j]};
                if (ans < nums[j]) ans = nums[j];
            }
            else {
                if (nums[j] > 0) {
                    dp[j] = {0, 0};
                    if (!dp[j - 1].first) {
                        dp[j].first = nums[j];
                    } else {
                        dp[j].first = nums[j]*dp[j - 1].first;
                    }
                    if (!dp[j - 1].second) {

                    } else {
                        dp[j].second = nums[j]*dp[j - 1].second;
                    }
                } else if (nums[j] < 0) {
                    dp[j] = {0, 0};
                    if (!dp[j - 1].second) {

                    } else {
                        dp[j].first = nums[j]*dp[j - 1].second;
                    }
                    if (!dp[j - 1].first) {
                        dp[j].second = nums[j];
                    } else {
                        dp[j].second = nums[j]*dp[j - 1].first;
                    }
                }
                if (dp[j].first != 0) ans = max(ans, dp[j].first);
                else if (dp[j].second != 0) ans = max(ans, dp[j].second);
            }
        }

        i = j;
    }
    return ans;
}

int solvePrefixProduct(vector<int>& nums) {
    bool haveZero = false;
    int start = 0;
    long long res = LLONG_MIN;
    vector<long long> preproduct(nums.size(), 1);

    while (start < nums.size()) {
        while (start < nums.size() && nums[start] == 0) {start++; haveZero = true;}
        int end = start;
        while (end < nums.size() && nums[end] != 0) end++;
        end--;
        for (int i = start; i <= end; i++) {
            preproduct[i] = nums[i] * (i == start ? 1 : preproduct[i - 1]);
        }
        long long curMin = LLONG_MAX, curMax = LLONG_MIN, ans = LLONG_MIN;
        for (int i = end; i >= start; i--) {
            if (curMin > preproduct[i]) curMin = preproduct[i];
            if (curMax < preproduct[i]) curMax = preproduct[i];
            long long tmp = (i == start ? 1 : preproduct[i - 1]);
            if (tmp > 0) {
                if (ans < (curMax / tmp)) ans = curMax / tmp;
            } else {
                if (ans < (curMin / tmp)) ans = curMin / tmp;
            }
        }
        start = end+1;
        if (res < ans) res = ans;
    }
    

    return (haveZero ? (res < 0 ? 0 : res) : res);
}

/* Main() Ends Here */