#include<bits/stdc++.h>
using namespace std;

class TreeNode{
 public:
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int data){
       this->val=data;
       this->left=NULL;
       this->right=NULL;
     }
};

class Solution{
  private:
      void solve(TreeNode* root, vector<int>&v){
         //Base case.
         if(root==NULL) return;
         //if left part exist, then go to left
         if(root->left){
            solve(root->left,v);
         }
         //push the value in v.
         v.push_back(root->val);
          //if right part exist, then go to right
         if(root->right){
            solve(root->right,v);
         }
      }

  public:
    vector<int> inorderTraversal(TreeNode* root){
          vector<int>v;//to store result.
          solve(root,v);
          return v;
    }
};

int main()
{
    // Example.
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s; // creating an object of Solution class.
    vector<int>ans = s.inorderTraversal(root);

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;


    //clean up memory.
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
