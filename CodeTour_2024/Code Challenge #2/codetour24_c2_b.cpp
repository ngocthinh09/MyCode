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
const ll N = 1e6;

bool isPrime[N + 5];
ll M;
vector<ll> prime,divs;

void eratos(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i=2;i*i<= N;i++ )
        if (isPrime[i])
            for (int j=2*i;j<= N;j+= i)
                isPrime[j] = false;

    for (int i=1;i<= N;i++ )
        if (isPrime[i])
            prime.push_back(i);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>M;
    eratos();

    ll val = M;
    for (int p : prime){
        if (val < p)    break;
        if (val % p == 0){
            divs.push_back(p % 26);
            while (val % p == 0)
                val /= p;
        }
    }

    if (val > 1)    divs.push_back(val % 26);

    sort(ALL(divs));

    for (int it : divs)     cout<<char('A' + it);
}