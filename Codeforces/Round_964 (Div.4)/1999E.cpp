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

ll numMod[N + 5];
ll prefix[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin>>numTest;
    for (ll i=1;i<= N;i++ ){
        ll base = 3,num = 1;
        while (base <= i){
            base *= 3;
            num++;
        }
        numMod[i] = num;
        prefix[i] = prefix[i - 1] + numMod[i];
    }
    while(numTest-- ){
        int l,r;    cin>>l>>r;
        cout<<(prefix[r] - prefix[l - 1] + numMod[l])<<'\n';
    }
}