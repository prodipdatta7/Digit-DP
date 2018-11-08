//problem link : https://www.spoj.com/problems/LUCIFER/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
/*#include <bits/stdc++.h>*/
using namespace std ;

typedef long long               ll ;
typedef long double             ld ;
typedef unsigned long long      ull ;
typedef pair<int,int>           pii ;
typedef pair<ll,ll>             pll ;
typedef vector<int>             vi ;
typedef vector<ll>              vll ;
typedef vector<vector<int>>     vvi ;

int Int(){int x ; scanf("%d",&x) ; return x ;}
ll Long(){ll x ; scanf("%lld",&x) ; return x ;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

const int N         = (int)2e5 + 5 ;
const int maxN      = (int)1e6 + 6 ;
const ll Mod        = (ll)1e9 + 7 ;

#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     Int         Int()
#define     Long        Long()
#define     all(x)      x.begin() , x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back

vi d ;
ll dp[11][91][91][2] ;
int len ;
bitset < 91 > prime ;

void make(){
    for(int i = 2 , j ; i <= 90 ; i++){
        for(j = 2 ; j * j <= i ; j++){
            if(i % j == 0)break ;
        }
        prime[i] = (j * j > i) ;
    }
}

ll call(int cur , int odd , int even , int f){
    if(cur == len){
        return (even - odd) > 0 ? prime[even - odd] : 0 ;
    }
    ll& ret = dp[cur][odd][even][f] ;
    if(ret != -1)return ret ;
    ret = 0 ;
    int L = (f) ? d[cur] : 9 ;
    int mod = (len & 1) ? 0 : 1 ;
    for(int i = 0 ; i <= L ; i++){
        if(!cur and !i)continue ;
        int e = even , o = odd ;
        if(cur % 2 == mod)o += i ;
        else e += i ;
        ret += call(cur + 1 , o , e , f and i == L) ;
    }
    return ret ;
}

ll solve(int n){
    if(n <= 0)return 0;
    d.clear() ;
    while(n > 0)d.pb(n % 10) , n /= 10 ;
    reverse(all(d)) ;
    len = sz(d) ;
    memset(dp , -1 , sizeof dp) ;
    ll res = call(0, 0, 0, 1) ;
    return res ;
}

int get(int l){
    int n = 0 ;
    while(l--)n = (n * 10) + 9 ;
    return n ;
}
int main(){
    int test = Int , tc = 0 ; make() ;
    while(test--){
        int l = Int , r = Int ;
        ll res = solve(r) ;
        int i = get(len - 1) ;
        for( ; i >= l - 1 and i ; i /= 10){
            res += solve(i) ;
        }
        res -= solve(l - 1) ;
        cout << res << '\n' ;
    }
    return 0 ;
}
