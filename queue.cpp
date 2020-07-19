#include<iostream>
#include<queue>

using namespace std;

//用bfs解决二叉树层序遍历问题
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
        ,left(nullptr)
        ,right(nullptr)
    {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; i ++) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main(){

}