#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

class Solution
{
    private:
    pair<bool,int> sumTree(Node* root){
        // Base case
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right==NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        
        // check weather the left subtree is sumtree or not
        pair<bool,int>left =  sumTree(root->left);
        // check weather the left subtree is sumtree or not
        pair<bool,int>right =  sumTree(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool sum = (root->data) == (left.second + right.second);
        
        pair<bool,int>ans;
        ans.second = left.second + right.second + root->data;
        
        if(leftAns && rightAns && sum){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return sumTree(root).first;
    }
};

int main(){

    // Solution function is at the top

    return 0;
}