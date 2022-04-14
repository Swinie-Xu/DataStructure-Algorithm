class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        // 我的想法是构建一个循环链表，再每次去剔除,可以用数组来实现循环链表啊！！
        // 当时脑子浆糊了，没想到每次报数的mm是和m相关的，m-1
        // 后来好几天以后，一下子发现了！！！
        vector<int> vec(n,0);
        int cnt=0; // 记录扔出去的个数，n-1个就停
        int mm=0;    // 每一轮的报数
        for(int i=0;cnt!=n-1;i = (++i)%n)
        {
            
            if(vec[i]==-1) continue;
            else if(mm==m-1) vec[i] = -1, cnt++, mm=0;  // 到了报数的人，就出列（置为-1）并计数，并重置计数器
            else ++mm;
        }
        for(int i=0;i<n;++i)
        {
            if(vec[i]!=-1) return i;
        }
        return -1;
    }
};
