
class Solution {
public:
    
        // 中序遍历，非递归写法
        // 只是缕了一下运行过程，但是其实并不熟悉
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if(proot==nullptr) return -1;
        int cnt = 0;    //记录遍历了多少个数
        TreeNode* p = nullptr;
        stack<TreeNode*> s;    //用栈辅助建立中序
        while(!s.empty() || proot != nullptr)
        {
            while(proot != nullptr)
            {
                s.push(proot);
                proot = proot->left;    //中序遍历每棵子树从最左开始
            }
            p = s.top();
            s.pop();
            cnt++;
            if(cnt == k) return p->val;    //第k个直接返回
            proot = p->right;
        }
        return -1;    //没有找到
        
    }
};
