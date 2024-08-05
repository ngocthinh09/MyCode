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
const int N = 2e5;
const ll mod = 1e9 + 7;

string str;
ll n,prefix[N + 5];
vector<ll> value,pos[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    while (numTest-- ){
        cin>>str;
        n = (ll)str.length();
        str = ' ' + str;
        for (int i=1;i<= n;i++ )
            prefix[i] = prefix[i - 1] + (str[i] == '0' ? -1 : 1);

        vector<ll> ().swap(value);
        value.push_back(prefix[0]);
        for (int i=1;i<= n;i++ )
            value.push_back(prefix[i]);
        
        sort(ALL(value));
        UNIQUE(value);

        for (int i=1;i<= (int)value.size();i++ )
            vector<ll> ().swap(pos[i]);

        for (int i=0;i<= n;i++ ){
            prefix[i] = lower_bound(ALL(value),prefix[i]) - value.begin() + 1;
            pos[prefix[i]].push_back(i);
        }

        ll res = 0;
        for (int i=1;i<= (int)value.size();i++ )
            if (pos[i].size() > 1){
                ll sum = pos[i][0];
                for (int x=1;x< (int)pos[i].size();x++ ){
                    res = (res + 1LL*(n - pos[i][x] + 1)*(sum + x) % mod) % mod;
                    sum = (sum + pos[i][x]) % mod;
                }
            }

        cout<<res<<'\n';
    }
    
}