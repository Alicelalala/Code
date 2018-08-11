/*************************************************************************
	> File Name: ol46_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月03日 星期四 12时15分13秒
 ************************************************************************/

#include<stdio.h>


const int maxn=1000000;
int num[maxn+1]={1,1},prime[maxn+1],cnt;

int main(){
    for (int i=2;i<=maxn;i++){
                if (num[i]==0)  prime[++cnt]=i;
        for (int j=1;j<=cnt&&i*prime[j]<=maxn;j++){
                        num[i*prime[j]]=1;
                    
        }
            
    }
    for (int i=35;;i+=2){
                if (num[i]==0)  continue;
                int boolean=0;
        for (int j=1;2*j*j<=i;j++){
            if (num[i-j*j*2]==0){
                                boolean=1;
                                break;
                            
            }
                    
        }
        if (!boolean){
                        cout<<i<<endl;
                        return 0;
                    
        }
            
    }

}
