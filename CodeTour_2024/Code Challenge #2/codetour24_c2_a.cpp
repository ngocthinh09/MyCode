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
const int N = 1e5;

ll n,q;
pll work[N + 5];
ll prefix[N + 5];
pll pupil[N + 5];
ll res[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<= n;i++ )    cin>>work[i].se>>work[i].fi;
    sort(work + 1,work + n + 1);
    for (int i=1;i<= n;i++ )
        prefix[i] = prefix[i - 1] + work[i].se;
    for (int i=1;i<= q;i++ )
        cin>>pupil[i].fi,pupil[i].se = i;
    sort(pupil + 1,pupil + q + 1);

    int it = 0;
    for (int i=1;i<= q;i++ ){
        while (it < n && work[it + 1].fi <= pupil[i].fi)
            it++;

        res[pupil[i].se] = prefix[it];
    }

    for (int i=1;i<= q;i++ )
        cout<<res[i]<<'\n';
}