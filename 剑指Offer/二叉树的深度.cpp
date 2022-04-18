/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        // 层序遍历BFS实现
        // 广度优先遍历，就是说，一层一层的遍历
        // https://blog.nowcoder.net/n/649bd2d6be1a4963894ef055282795d5?f=comment
        if(!pRoot) return 0;
        queue<TreeNode*> q;
        q.push(pRoot);    // 根节点入队
        int hight = 0;    // 记录深度
        while(!q.empty())    // 当队列不为空的时候
        {
            int size = q.size();    // 当前层的节点数
            while(size != 0)    // 将当前层的节点的左右子节点都入队
            {
                TreeNode * node = q.front();    // 出队
                q.pop();
                if(node->left) q.push(node->left);    // 有左节点的时候
                if(node->right) q.push(node->right);    // 有右节点的时候
                size--;    // 出一个
            }
            hight++;    // 里层循环结束则证明一走完一层，所以深度加1
        }
        return hight;
    }
};
