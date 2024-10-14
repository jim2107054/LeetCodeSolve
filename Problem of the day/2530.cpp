#include<bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int>& nums, int k) {
        //max-heap to always get the largest element
        priority_queue<int>maxHeap(nums.begin(),nums.end());
        long long score=0;

        while(k-->0 && !maxHeap.empty()){
            int top = maxHeap.top();
            maxHeap.pop();
            score+=top;

            //push the updated element back into the heap
            maxHeap.push(ceil(top/3.0));
        }
        return score;
}

int main()
{
    int k,n,ip;
    cout<<"Enter your array size: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>ip;
        nums.push_back(ip);
    }
    cout<<"k : ";
    cin>>k;
    cout<<"maximum score : "<<maxKelements(nums,k)<<endl;
    return 0;
}

//problem link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14