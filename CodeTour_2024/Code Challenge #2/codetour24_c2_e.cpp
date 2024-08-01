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
const int N = 1e6;
const int LIM = 1e3;

int n;
int a[N + 5];
bool isPrime[LIM + 5];
vector<int> prime[N + 5];
int cnt[N + 5];

void eratos(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i=2;i*i<= LIM;i++ )
        if (isPrime[i])
            for (int j=i*i;j<= LIM;j+= i)
                isPrime[j] = false;

    for (int i=17;i<= LIM;i++ )
        if (isPrime[i])
            for (int j=i;j<= N;j+= i)
                prime[j].push_back(i);
}

inline int countExpo(int &x,int p){
    int num = 0;
    while (x % p == 0)
        num++, x /= p;
    return num;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin>>n;
    eratos();
    for (int i=1;i<= n;i++ ){
        cin>>a[i];
        int val = a[i];
        int num = 0;
        if (val % 2 == 0){
            num = countExpo(val,2);
            cnt[2] += num;
        }
        if (val % 3 == 0){
            num = countExpo(val,3);
            cnt[3] += num;
        }
        if (val % 5 == 0){
            num = countExpo(val,5);
            cnt[5] += num;
        }
        if (val % 7 == 0){
            num = countExpo(val,7);
            cnt[7] += num;
        }
        if (val % 11 == 0){
            num = countExpo(val,11);
            cnt[11] += num;
        }
        if (val % 13 == 0){
            num = countExpo(val,13);
            cnt[13] += num;
        }
        for (int it : prime[a[i]]){
            num = countExpo(val,it);
            cnt[it] += num;
        }
        if (val > 1)    cnt[val]++;
    }

    int numTest;    cin>>numTest;
    while (numTest-- ){
        int x,p;    cin>>x>>p;
        int val = x;
        bool flag = true;
        int num = 0;
        if (val % 2 == 0){
            num = countExpo(val,2);
            if (cnt[2] < num*p) flag = false;
        }
        if (val % 3 == 0){
            num = countExpo(val,3);
            if (cnt[3] < num*p) flag = false;
        }
        if (val % 5 == 0){
            num = countExpo(val,5);
            if (cnt[5] < num*p) flag = false;
        }
        if (val % 7 == 0){
            num = countExpo(val,7);
            if (cnt[7] < num*p) flag = false;
        }
        if (val % 11 == 0){
            num = countExpo(val,7);
            if (cnt[11] < num*p) flag = false;
        }
        if (val % 13 == 0){
            num = countExpo(val,7);
            if (cnt[13] < num*p) flag = false;
        }
        for (int it : prime[x]){
            num = countExpo(val,it);
            if (cnt[it] < num*p) flag = false;
        }

        if (val > 1 && cnt[val] < p)    flag = false;

        cout<<flag;
    }
}