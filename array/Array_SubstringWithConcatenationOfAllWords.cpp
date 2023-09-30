/*
  Solution for: https://leetcode.com/problems/substring-with-concatenation-of-all-words
  O(N*wordlen) solution
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
vector<int> findSubstring(string s, vector<string>& words);

/* Main()  function */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    
    vector<int> res = findSubstring(s, words);
    fe(i,res)
        cout << i << " ";
}

// maintain a window
// extend the window by adding more words to the window. 3 scenarios:
//  1. The extended word not in the word list => Narrow window to zero, and start counting from beginning
//  2. The extended word count is not enough => Keep adding more words
//  3. The extended word count is exceeding => Keep removing word from the beginning until not exceed anymore

// The start poistion of the window can be from index 0 -> (wordLen - 1)
vector<int> findSubstring(string s, vector<string>& words) {
    int wordLen = words[0].size();
    int totalWord = words.size();
    if (s.size() < wordLen*totalWord) return vector<int>();
    unordered_map<string,int> map;
    vector<int> res;
    for (int i = 0; i < words.size(); i++) {
      map[words[i]]++;
    }
    
    unordered_map<string,int> map2;
    for (int i = 0; i <= wordLen - 1; i++) {
      int j = i;
      int start = i;
      int matched = 0;

      while (j + wordLen - 1 <= s.size() - 1) {
        string word = s.substr(j, wordLen);
        
        // Current word not found in the word list
        // => Start again from the next word
        if (map.find(word) == map.end()) {
          map2.clear();
          j += wordLen;
          start = j;
          matched = 0;
          continue;
        }

        int& cnt1 = map[word];
        int& cnt2 = ++map2[word];

        // Found word, and the word count is not enough
        if (cnt1 > cnt2) {
          matched++;
          j += wordLen;
        
        // Found word, and the word count is enough
        } else if (cnt1 == cnt2) {
          matched++;
          if (matched == totalWord) {
            res.push_back(start);
          }
          j += wordLen;
        
        // Found word, but the word count is exceed 
        // => Begin to delete from the start
        // Until the exceeding is solved
        } else if (cnt1 < cnt2) {
          matched--;    // Matched-- for the exceeding word
          do {
            string startWord = s.substr(start, wordLen);  // Delete the first word in left side
            int& c1 = map[startWord];
            int& c2 = map2[startWord];
            c2--;
            if (c1 != c2) matched--;    // After delete c1 != c2 => Matched--
            else matched++;             // After delete c1 == c2 => Delete the exceeding word => Matched++
            start += wordLen;
            if (matched == totalWord) {
              res.push_back(start);
            }
          } while (cnt1 < cnt2);
          j += wordLen;
        }
      }
      map2.clear();
    }

    return res;
}

/* Main() Ends Here */