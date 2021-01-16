/* An ACEASH Source code  */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>

#define vvi vector< vector < int > >
#define vvl vector< vector < ll > >

#define pii pair< int , int >
#define pll pair< ll , ll >

#define vpl vector< pll >
#define vpi vector< pii >

#define MOD 1000000007

#define mp make_pair
#define pb push_back

#define sare(v) (v).begin(),(v).end()
#define ulta(v) (v).rbegin(),(v).rend()

#define F first
#define S second

#define tez  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ld pie = 3.1415926535897932384626 ;
const ll N=2e5 +9;
vl adj[N];
ll n,k;

ll level[N];
ll subtree[N];

void dfs(ll node,ll parent=0)
{
    subtree[node]=1;
    for(auto x: adj[node])
    {
        if(x==parent){continue;}
        level[x]=1+level[node];
        dfs(x,node);
        subtree[node]+=subtree[x];
    }
}

int main()
{
    cin>>n>>k;
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);

    vl arr;
    for(ll i=1;i<=n;i++)
    {
        subtree[i]--;
        arr.pb(level[i]-subtree[i]);
    }
    ll ans=0;
    sort(ulta(arr));
    for(ll i=0;i<k;i++)
    {
        ans+=arr[i];
    }
    cout<<ans<<"\n";


    return 0;
}


 
