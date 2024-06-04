#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
   if(n<=1) return n;

   vector<int>dp(n+1);

   //Base case.
   dp[0]=0;
   dp[1]=1;

   for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
   }
   return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<"n'th Fibonacci Number is: "<<solve(n)<<endl;
    return 0;
}
