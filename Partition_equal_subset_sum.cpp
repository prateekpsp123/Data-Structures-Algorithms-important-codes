#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void isSubset(int arr[],int n,int sum, vector<vector<bool>>&dp){
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        sum = sum/2;
        vector<vector<bool>>dp(N+1,vector<bool>(sum+1));
        for(int i=0; i<N+1; i++){
            for(int j=0; j<sum+1; j++){
                
                if(i==0&&j==0)dp[i][j]=true;
    
                else if(i==0){
                    dp[i][j] = false;
                }
                else if(j==0){
                    dp[i][j] = true;
                }
            }
        }
        isSubset(arr,N,sum,dp);
        return dp[N][sum];
    }
};

int main(){

    int arr[] = {1, 5, 11, 5};
    int n = 4;
    
    Solution Sol;

    bool ans = Sol.equalPartition(n,arr);
    cout<<ans<<endl;
    return 0;
}