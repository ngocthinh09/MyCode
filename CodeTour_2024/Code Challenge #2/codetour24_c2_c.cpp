#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;
const int N = 2e6;

const ll mod = 1e18 + 7;
const ll base = 1000033;

int n;
char s[N + 5];
int prefix[N + 5];
vector<int> pos;
string str[N + 5];
ll subStr[N + 5],numSub;
map<string,ll> mp;
ll hashNum[N + 5],powBase[N + 5];
set<ll> mys;

ll binaryMul(ll a,ll b){
    if (b == 0) return 0;
    ll x = binaryMul(a,b/2);
    if (b & 1)  return (2LL*x + a) % mod;
    else return (2LL*x) % mod;
}

inline ll getHash(int l,int r){
    return ((hashNum[r] - binaryMul(hashNum[l - 1],powBase[r - l + 1]))%mod + mod)%mod;
}

inline int toValue(char u){
    return (u == '(' ? 1 : -1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n;
    for (int i=1;i<= n;i++ ){
        cin>>s[i];
        prefix[i] = prefix[i - 1] + toValue(s[i]);
    }

    pos.push_back(0);
    for (int i=1;i<= n;i++ )
        if (prefix[i] == 0)
            pos.push_back(i);
    
    numSub = (int)pos.size() - 1;
    for (int i=1;i< (int)pos.size();i++ ){
        for (int j=pos[i - 1] + 1;j<= pos[i];j++ )
            str[i] += s[j];

        if (mp.find(str[i]) == mp.end())
            mp[str[i]] = (int)mp.size() + 1;

        subStr[i] = mp[str[i]];
    }

    for (int i=numSub + 1;i<= 2*numSub;i++ )
        subStr[i] = subStr[i - numSub];

    powBase[0] = 1;
    for (int i=1;i<= 2*numSub;i++ )
        powBase[i] = 1LL*binaryMul(powBase[i - 1],base);

    for (int i=1;i<= 2*numSub;i++ )
        hashNum[i] = (1LL*binaryMul(hashNum[i - 1],base) + subStr[i]) % mod;

    for (int i=1;i<= numSub;i++ ){
        ll hashVal = getHash(i,i + numSub - 1);
        mys.insert(hashVal);
    }

    cout<<(int)mys.size();
}