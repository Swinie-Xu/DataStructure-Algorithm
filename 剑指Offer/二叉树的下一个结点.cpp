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
    // 看的讲解，最优解法
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(!pNode) return nullptr;
        
        // 1、有右子树，下一结点是右子树中的最左结点
        if(pNode->right)
        {
            pNode = pNode->right;
            while(pNode->left) pNode = pNode->left;
            return pNode;
        }
        
        // 无右子树，且结点是该结点父结点的左子树，则下一结点是该结点的父结点
        // 无右子树，且结点是该结点父结点的右子树，则一直沿着父结点追朔，
        // 直到找到某个结点是其父结点的左子树，如果存在这样的结点，那么这个结点的父结点就是我们要找的下一结点。
        while(pNode->next)
        {
            if(pNode->next->left == pNode) return pNode->next; 
            pNode = pNode->next;
        }
        return nullptr;
    }
};
