#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<ll>> vv;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		vector<ll> tmp;
		tmp = {a,b,c};
		vv.push_back(tmp);
	}
	vector<ll> Cost(n,LLONG_MIN/2);
	Cost[0]=0;
	for(int t=0;t<n;t++){
		bool flg = true;
		for(auto &i:vv){
			if(Cost[i[0]]==LLONG_MIN/2)continue;
			if(Cost[i[0]]+i[2]>Cost[i[1]]){
				Cost[i[1]]=Cost[i[0]]+i[2];
				flg=false;
			}
		}
		if(flg){
			break;
		}
	}
	vector<bool> ng(n);

	for(int t = 0;t<n;t++){
		bool flg = true;
		for(auto &i:vv){
			if(Cost[i[0]]==LLONG_MIN/2)continue;
			if(Cost[i[0]]+i[2]>Cost[i[1]]){
				ng[i[1]] = true;
				Cost[i[1]]=Cost[i[0]]+i[2];
				flg=false;
			}
			if(ng[i[0]])ng[i[1]]=true;
		}
		if(flg){
			break;
		}
	}
	if(ng[n-1])cout<<"inf"<<endl;
	else cout<<Cost[n-1]<<endl;
}
