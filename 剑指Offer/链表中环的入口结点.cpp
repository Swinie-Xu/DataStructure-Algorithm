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
        // https://blog.nowcoder.net/n/4c6d12e823344a42a51164a127208265?f=comment
        // 快慢指针，可以很同意判断是否有环
        // 快指针每次走两步，慢指针每次走一步，那么若进入环中，每次他们之间的相对距离都会-1，直到两者相遇。
        // 可知，两指针相遇时，慢指针已经走了nb步，已知我们要走到入口节点，需要走a + kb步，而这时s = nb只要再走a即可到达入口，我们把快指针移动到头节点，然后两个指针一步一步往后走，当它们相遇时所处的位置就是入口节点
        
        ListNode* fast = pHead,*slow = pHead;    // 快慢指针一开始都指向头
        while(fast) 
        {
            slow = slow->next;    // 慢指针走一步
            if(fast->next == nullptr) return nullptr;    // 若快指针的下一步不能走，则说明两指针不会相遇
            fast = fast->next->next;    // 快指针向后走两步
            if(fast == slow)    // 找到相交节点, 此时慢指针已经走了nb步
            {
                fast = pHead;    // 快指针重新移动到头
                while(fast!=slow)    // 直到两指针相遇位置，每次向后走一步
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;    // 找到入口节点，直接返回
            }
        }
        return nullptr;
    }
};
