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
const int BLOCK_SIZE = 305;

ll p;
string str;
int n,q;

namespace Case1{
    ll prefixTwo[N + 5],prefixFive[N + 5];
    ll cntTwo[N + 5],cntFive[N + 5];

    ll solve(int l,int r,ll *cnt,ll *prefix){
        return (prefix[r] - prefix[l - 1]) - (l - 1)*(cnt[r] - cnt[l - 1]);
    }

    void process(){
        for (int i=1;i<= n;i++ ){
            int digit = str[i] - '0';
            cntTwo[i] = cntTwo[i - 1] + (digit % 2 == 0 ? 1 : 0);
            cntFive[i] = cntFive[i - 1] + (digit % 5 == 0 ? 1 : 0);
            prefixTwo[i] = prefixTwo[i - 1] + (digit % 2 == 0 ? i : 0);
            prefixFive[i] = prefixFive[i - 1] + (digit % 5 == 0 ? i : 0);
        }

        cin>>q;
        for (int i=1;i<= q;i++ ){
            int l,r;    cin>>l>>r;
            if (p == 2)
                cout<< solve(l,r,cntTwo,prefixTwo)<<'\n';
            else cout<< solve(l,r,cntFive,prefixFive)<<'\n';
        }
    }
};

namespace Case2{
    ll sum[N + 5],powBase[N + 5];
    vector<ll> value;
    int blockID[N + 5];
    ll res[N + 5],cnt[N + 5],total;
    struct Query{
        int l,r,id;
        Query (int _l = 0,int _r = 0,int _id = 0){
            l = _l, r = _r, id = _id;
        }

        bool operator < (const Query &other) const{
            if (blockID[l] == blockID[other.l])
                return r < other.r;
            return blockID[l] < blockID[other.l];
        }
    };
    Query query[N + 5];

    void add(ll num){
        total -= (cnt[num] - 1)*cnt[num]/2;
        cnt[num]++;
        total += (cnt[num] - 1)*cnt[num]/2;
    }

    void del(ll num){
        total -= (cnt[num] - 1)*cnt[num]/2;
        cnt[num]--;
        total += (cnt[num] - 1)*cnt[num]/2;
    }
    
    void process(){
        powBase[n] = 1;
        for (int i=n;i>= 1;i-- ){
            int digit = str[i] - '0';
            if (i < n)
                powBase[i] = (powBase[i + 1]*10LL) % p;
            sum[i] = (digit*powBase[i] + sum[i + 1]) % p;
        }
        for (int i=1;i<= n + 1;i++ )
            value.push_back(sum[i]);
        
        sort(ALL(value));
        UNIQUE(value);
        
        for (int i=1;i<= n + 1;i++ )
            sum[i] = lower_bound(ALL(value),sum[i]) - value.begin() + 1;

        cin>>q;
        for (int i=1;i<= q;i++ )
            blockID[i] = i/BLOCK_SIZE;
        for (int i=1;i<= q;i++ ){
            int l,r;    cin>>l>>r;
            query[i] = Query(l,r + 1,i);
        }
        sort(query + 1,query + q + 1);

        int l = 1,r = 1;
        add(sum[1]);
        
        for (int i=1;i<= q;i++ ){
            while (r < query[i].r){
                add(sum[r + 1]);
                r++;
            }
            while (l > query[i].l){
                add(sum[l - 1]);
                l--;
            }
            while (l < query[i].l){
                del(sum[l]);
                l++;
            }
            while (r > query[i].r){
                del(sum[r]);
                r--;
            }
            res[query[i].id] = total;
        }

        for (int i=1;i<= q;i++ )
            cout<<res[i]<<'\n';
    }
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>p>>str;
    n = (int)str.length();
    str = ' ' + str;
    if (p == 2 || p == 5)
        Case1 :: process();
    else Case2 :: process();
}