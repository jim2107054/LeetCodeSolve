#include<bits/stdc++.h>
using namespace std;

long long minimumSteps(string s) {
        int countOne=0;
        long long ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1') countOne++;
            else{
                ans+=countOne;
            }
        }
        return ans;
}

int main()
{
    string s;
    cout<<"Enter your input string: ";
    cin>>s;
    cout<<"Minimum step: "<<minimumSteps(s)<<endl;
    return 0;
}
//link: https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15