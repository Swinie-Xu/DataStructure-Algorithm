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
        // 啊啊啊啊啊啊 我自己写的BFS啊！！！！
        // 简直了，开心
        // 真就是最简单的BFS啊！！！我实现了，虽然性能依然垃圾，但是我自己做的
        vector<vector<int>> res;
        queue<TreeNode*> s;
    
        void bfs(TreeNode* root)
        {
            vector<int> tmp;
            
            while(!s.empty())
            {
                int cnt = s.size();
                for(int i=0;i<cnt;++i)
                {
                    if(s.front()->left) s.push(s.front()->left);
                    if(s.front()->right) s.push(s.front()->right);
                    tmp.push_back(s.front()->val);
                    s.pop();
                }
                res.push_back(tmp);
                tmp.clear();
            }
            
        }
        vector<vector<int> > Print(TreeNode* pRoot) {
            if(!pRoot) return res;
            s.push(pRoot);
            bfs(pRoot);
            return res;
        }
    
};
