/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    // 开心，又是自己实现的一个BFS
    // 其实就是加了一个mark标记每一层的数据是否reverse
    // 性能还凑合，拉胯
    // mark判断奇偶性，反正用的就是mark&1 实现的，其实搞不太清什么奇还是偶时候翻转
    // 反正每一行都是反着来就行
    int mark = 0;
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            while(size--)
            {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                tmp.push_back(q.front()->val);
                q.pop();
            }
            if(mark++&1) reverse(tmp.begin(),tmp.end());
            res.emplace_back(tmp);
        }
        return res;
    }
    
};
