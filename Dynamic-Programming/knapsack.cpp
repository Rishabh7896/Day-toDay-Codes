#include<bits/stdc++.h>
using namespace std;

int KnapSackDP(int* wts,int* val,int W,int N){
int dp[100][100];

//Columns Weights,Rows items
for(int i=0;i<=N;i++){
    for(int wt=0;wt<=W;wt++){
        if(i==0||wt==0){
            dp[i][wt] =0;
        }
        else if(wts[i-1]>wt){
            //Ignore i-1th item
            dp[i][wt] = dp[i-1][wt];
        }
        else{
            dp[i][wt] = max(val[i-1]+dp[i-1][wt-wts[i-1]],dp[i-1][wt]);
        }


    }


}


return dp[N][W];
}


//Items are assumed as 1,2,3....N.
int KnapSackRecursive(int *wt,int *val,int w,int n){
if(n==0||w==0){
    return 0;
}

if(wt[n-1]<=w){
        return max(val[n-1]+KnapSackRecursive(wt,val,w-wt[n-1],n-1),KnapSackRecursive(wt,val,w,n-1));
}
else{
        return KnapSackRecursive(wt,val,w,n-1);
    }

}



int main(){
    
    //input N(size of array/ available items ) then value array and then weight array and then Final Weight
    int N;
    cin>>N;
    int val[N];
    int wt[N];
    int  W;
    for(int i=0;i<N;i++){
        cin>>val[i];
    }
    for(int i=0;i<N;i++){
        cin>>wt[i];
    }
    cin>>W;
    printf("%d\n", KnapSackRecursive(wt, val, W, N));
    printf("%d\n", KnapSackDP(wt, val, W, N));
    return 0;

}
