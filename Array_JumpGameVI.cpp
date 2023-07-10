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
int priorityQueueSolver(vector<int>& nums, int k);
int twoPointersSolver(vector<int>& nums, int k);

/* Main()  function */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {1,-1,-2,4,-7,3};
    int k = 2;

    // O(n*log(k))
    cout << priorityQueueSolver(nums, k);

    // Faster O(N) but harder to implement
    // The idea is maintain the maximum dp in the previous range
    // From max in previous range we induce the max in the current range
    cout << twoPointersSolver(nums, k);
}

int priorityQueueSolver(vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    dp[nums.size() - 1] = nums[nums.size() - 1];
    priority_queue<pair<int, int>> pq; // Max heap, to get the max dp in range [i+1, i+k]

    for (int i = nums.size() - 2; i >= 0; i--) {
        int startIndex = i + 1;
        int endIndex = min(i + k, (int) nums.size() - 1);

        pq.push({dp[startIndex], startIndex});
        while (pq.size() > 0 && pq.top().second > endIndex) pq.pop(); // Pop max value that out of range [i+1, i+k] (not valid anymore)
        dp[i] = nums[i] + pq.top().first;
    }

    return dp[0];
}

int twoPointersSolver(vector<int>& nums, int k) {
    vector<int> dp(nums.size());
    dp[nums.size() - 1] = nums[nums.size() - 1];
    int l = nums.size() - 1, r = nums.size() - 1;
    int maxInLR = nums[nums.size() - 1];
    int maxNum = 0;

    for (int i = nums.size() - 2; i >= 0; i--) {
        int startIndex = i + 1;
        int endIndex = min(i + k, (int) nums.size() - 1);

        // Get the max of dp in range [i + 1, min(i + k, n - 1)]
        if (endIndex == r) {
            if (dp[startIndex] == maxInLR) {
                maxNum++;
            } else if (dp[startIndex] > maxInLR) {
                maxInLR = dp[startIndex];
                maxNum = 1;
            }
            l = startIndex;
        } else {
            if (dp[startIndex] > maxInLR) {
                maxInLR = dp[startIndex];
                maxNum = 1;
            } else if (dp[startIndex] == maxInLR) {
                if (dp[r] != maxInLR) maxNum++;
            } else if (dp[startIndex] < maxInLR) {
                if (dp[r] == maxInLR) {
                    maxNum--;
                    if (maxNum == 0) {
                        int tmp = (int) INT_MIN;
                        for (int j =  startIndex; j <= endIndex; j++) {
                            if (tmp < dp[j]) {
                                tmp = dp[j];
                                maxNum = 1;
                            } else if (tmp == dp[j]) maxNum++;
                        }
                        maxInLR = tmp;
                    }
                }
            }

            l = startIndex;
            r = endIndex;
        }

        dp[i] = nums[i] + maxInLR;
    }

    return dp[0];
}

/* Main() Ends Here */