class Solution {
public:
    // 用了堆数据结构（priority_queue）来实现
    
    #define SCD static_cast<double>
    priority_queue<int> min_q;  // 默认是大顶堆
    priority_queue<int,vector<int>, greater<int>> max_q; // 这就是小顶堆
    
    void Insert(int num) {
        min_q.push(num);// 试图加入到大顶推
        
        max_q.push(min_q.top());// 之所以先进大顶堆，就是因为可以将大的数放到右边的小顶堆
        min_q.pop();
        
        // 平衡两个堆 
        if(min_q.size()<max_q.size())  // 这里也一样，就是右边多了，就扔到左边，也是仍小的到左边
        {
            min_q.push(max_q.top());
            max_q.pop();
        }
    }

    double GetMedian() { 
        /*
        假设[0 ... median - 1]的长度为l_len, [median + 1 ... arr.sise() - 1]的长度为 r_len.
            1.如果l_len == r_len + 1, 说明，中位数是左边数据结构的最大值
            2.如果l_len + 1 == r_len, 说明，中位数是右边数据结构的最小值
            3.如果l_len == r_len, 说明，中位数是左边数据结构的最大值与右边数据结构的最小值的平均值。
        */
        
        return min_q.size()>max_q.size() ? SCD(min_q.top()) : SCD(min_q.top()+max_q.top())/2;
    }

};
