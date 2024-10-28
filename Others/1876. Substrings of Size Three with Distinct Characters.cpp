#include<bits/stdc++.h>
using namespace std;

int countdistinctsubstring(string s){
        unordered_set<char>ch;
        for(int i=0;i<s.size();i++){
            ch.insert(s[i]);
        }
        if(ch.size()!=3) return 0;
        else return 1;
}

int countGoodSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            string sub=s.substr(i,3);
            count+=countdistinctsubstring(sub);
        }
        return count;
}

int main(){
  string s;
  cin>>s;
  cout<<countGoodSubstrings(s)<<endl;
}
