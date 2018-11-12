#include<ctime>
#include<cstdlib>
#include<iostream>

using namespace std;
const int MAX = 100; 
int n = MAX,max_w = MAX,max_v;
int w[MAX],v[MAX],best[MAX],ans[MAX];

void knapsack(int l,int cw,int cv) {
	int i;
	if(l >= n+1) {
		if(cv >max_v) {
			max_v = cv;
			for(i = 1;i <=n;i++)
				best[i] = ans[i];
		}
	}
	else {
		if(cw >= w[l+1]) {
			cw -= w[l+1];
			cv += v[l+1];
			ans[l+1] = 1;
			knapsack(l+1,cw,cv);
			ans[l+1] = 0;
			cw += w[l+1];
			cv -= v[l+1];
		}
		knapsack(l+1,cw,cv);
	}
}

int main() {
	time_t start,end;
	int i,x;
	
	cout<<"物品数，背包容量为:";
	cout<<" "<<max_w<<endl;
	for(i = 1;i<=n;i++) {
		x= rand() % max_w;
		w[i] = x;
	}
	for(i = 1;i <= n;i++) {
		x= rand() % max_w;
		v[i] = x;
	}
	max_v = 0;
	for(i = 1;i <= n;i++) ans[i] = 0;
	
	start = clock();
	knapsack(0,max_w,0);
	end = clock();
	
	cout<<"背包的最优价值为:"<<max_v<<endl;
	cout<<"背包可装的物品序号为:"<<endl; 
	for(i = 1;i <= n;i++)
		if(best[i] == 1)
			cout<<i<<":w="<<w[i]<<",v="<<v[i]<<endl;
	
	cout<<endl<<"耗时Time："<<(end - start) * 1.0 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
	
	return 0;
}
