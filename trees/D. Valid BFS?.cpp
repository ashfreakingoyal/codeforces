
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

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 1 , 0 , -1 , -1 , 1 , 1 } ;
const int dy[] = { 0 , 1 , 0 , -1 , -1 , 1 , -1 , 1 } ;

const ld pie = 3.1415926535897932384626 ;
////////START/////////
const ll N= 2e5+9;
vl adj[N];
ll vis[N]={0};
vl ans;
ll re_order[N];
bool cmp(ll a,ll b)
{
    return re_order[a]<re_order[b];
}
void bfs(ll node)
{
    vis[node]=1;
    ans.pb(node);
    queue<ll> q;
    q.push(node);
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        for(ll i=0;i<adj[x].size();i++)
        {
            ll u=adj[x][i];
            if(vis[u]==0)
            {
                vis[u]=1;
                q.push(u);
                ans.pb(u);
            }
        }
    }
}
int main()
{

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        re_order[arr[i]]=i;
    }
    for(ll i=1;i<=n;i++)
    {
        sort(sare(adj[i]),cmp);
    }
    bfs(1);
    ll f=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]!=ans[i]){f=1; break;}
    }
    if(f==0){cout<<"Yes";}
    else{cout<<"No";}


    return 0;
}
 
