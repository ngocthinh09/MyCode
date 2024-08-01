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
const int N = 5e5;

int n,q;
int h[N + 5],query[N + 5],bit[2*N + 5];
int numValue;
vector<int> value;

void updatePoint(int x){
    for (;x <= numValue;x += (x & (-x)))
        bit[x]++;
}

int getPoint(int x){
    int ret = 0;
    for (;x > 0;x -= (x & (-x)))
        ret += bit[x];
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<= n;i++ ){
        cin>>h[i];
        value.push_back(h[i]);
    }
    for (int i=1;i<= q;i++ ){
        cin>>query[i];
        value.push_back(query[i]);
    }

    sort(ALL(value));
    UNIQUE(value);
    numValue = (int)value.size();
    
    for (int i=1;i<= n;i++ ){
        h[i] = lower_bound(ALL(value),h[i]) - value.begin() + 1;
        updatePoint(h[i]);
    }
    for (int i=1;i<= q;i++ ){
        query[i] = lower_bound(ALL(value),query[i]) - value.begin() + 1;
        cout<<getPoint(query[i]) + 1<<'\n';
        updatePoint(query[i]);
    }
}