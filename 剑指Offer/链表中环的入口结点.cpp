/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> st;  // 哈希集合
        while(pHead)
        {
            if(st.count(pHead))return pHead; // 若已经记录过，直接返回
            st.insert(pHead);// 记录当前结点
            pHead = pHead->next;
        }
        return nullptr;// 无环
    }
};
