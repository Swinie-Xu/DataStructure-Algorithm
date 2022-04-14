/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 这个思路太牛比了
        // 两个指针总会相遇！！！
        // 感觉没有更好的办法了。。。
        // https://blog.nowcoder.net/n/35c57499566646e7b3ecb250d0b99907?f=comment
        ListNode* l1=pHead1;
        ListNode* l2=pHead2;
        while(l1 != l2)
        {
            l1 = (l1==nullptr)?pHead2:l1->next;
            l2 = (l2==nullptr)?pHead1:l2->next;
        }
        return l1;
    }
};
