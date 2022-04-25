/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    // 我自己写的哈！！！
    vector<TreeLinkNode*> arr;
    void Mid_order(TreeLinkNode* root)
    {
        if(!root) return;
        Mid_order(root->left);
        arr.push_back(root);
        Mid_order(root->right);
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        
        TreeLinkNode* pRoot=pNode;
        // 太傻了，我下面那个pRoot写成pNode了，结果错了半天，服了真的
        while(pRoot->next) pRoot = pRoot->next;  // 找到根节点
        
        Mid_order(pRoot);   // 中序遍历
        
        for(int i=0;i<arr.size();++i)
        {
            if(arr[i] == pNode && i+1!= arr.size()) return arr[i+1];
        }
        return nullptr;
    }
};
