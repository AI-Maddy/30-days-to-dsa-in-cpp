/*
 * Solution 3: Serialize/Deserialize
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
string serialize(TreeNode* root){
    if(!root)return"";
    string s;queue<TreeNode*>q;q.push(root);
    while(!q.empty()){auto n=q.front();q.pop();if(!n){s+="# ";continue;}s+=to_string(n->val)+" ";q.push(n->left);q.push(n->right);}
    return s;
}
TreeNode* deserialize(const string& data){
    if(data.empty())return nullptr;
    istringstream ss(data);string tok;ss>>tok;
    TreeNode* root=new TreeNode(stoi(tok));queue<TreeNode*>q;q.push(root);
    while(ss>>tok){auto p=q.front();q.pop();
        if(tok!="#"){p->left=new TreeNode(stoi(tok));q.push(p->left);}
        ss>>tok;if(tok!="#"){p->right=new TreeNode(stoi(tok));q.push(p->right);}
    }return root;
}
void io(TreeNode* n){if(!n)return;io(n->left);cout<<n->val<<" ";io(n->right);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    TreeNode* r=new TreeNode(1);r->left=new TreeNode(2);r->right=new TreeNode(3);
    string s=serialize(r);io(deserialize(s));cout<<"\n";}
