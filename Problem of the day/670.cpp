#include<bits/stdc++.h>
using namespace std;

int MaximumSwap(int num){
    string s = to_string(num);
    vector<int>last(10,-1);
    //In decimal number system we have 10 digit. So I want to store the last occurance of a perticular digit, that is present in the num.
    for(int i=0;i<s.size();i++){
        last[s[i]-'0'] = i; //Store the last occurance of a digit.
    }

    for(int i=0;i<s.size();i++){
        for(int d=9;d>s[i]-'0';d--){
            if(last[d]>i){
                swap(s[i],s[last[d]]);
                return stoi(s);
            }
        }
    }

    //if we don't find anything to change in num, then return as it is.
    return num;
}

int main()
{
    int num;
    cout<<"Enter your input number: ";
    cin>>num;
    cout<<"Maximum value we can get from the number is: "<<MaximumSwap(num)<<endl;
    return 0;
}