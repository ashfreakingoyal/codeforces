#include<bits/stdc++.h>

using namespace std;
int p[200005],a[200005];
int root(int x){
	if(p[x]==x)return x;
	else return p[x]=root(p[x]);
}
int main(){
	int n;
	cin>>n;
	int g=0;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[root(i)]=root(a[i]);
		if(a[i]==i)g=i;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(p[i]==i)cnt++;
	}
	if(g==0){
		cout<<cnt<<endl;
	}
	else{
		cout<<cnt-1<<endl;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(p[i]==i&&i!=g){
			if(!g)g=i;
			x=g;
		}
		cout<<x<<" ";
	}
	return 0;
}
