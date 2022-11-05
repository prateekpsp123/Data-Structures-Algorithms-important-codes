#include<bits/stdc++.h>
using namespace std;

// Example 1 :-
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2 :-
// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40 

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

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>result;
    if(root == NULL){
        return result;
    }
    bool flag = false;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        vector<int>ans(size);
        
        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();
            if(flag == false){
                ans[size-i-1] = frontNode->data;
            }
            else{
                ans[i] = frontNode->data;
            }
            if(frontNode->left)q.push(frontNode->left);
            
            if(frontNode->right)q.push(frontNode->right);
        }
        for(auto i:ans){
            result.push_back(i);
        }
        flag = !flag;
    }
    return result;
}

int main(){
    
    // function for solution is given above
    return 0;
}
