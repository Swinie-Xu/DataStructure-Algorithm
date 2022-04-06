class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int lbound = 0,rbound = 0;
        // 寻找上界，这里只移动左下标就可以实现最终的下标指向上届（左界）
        int l=0,r=data.size();  // 二分查找，一定记住右边界r在外面需要写A.size()不需要-1，这样对于size = 1的数组也可以判断
        while(l<r)
        {
            int mid = (l+r-1)/2;   // 因为r是size所以实际索引需要-1哈
            if(data[mid]<k)  // 指向左边第一个目标位置，不用等号data[mid]<=k
            {
                l = mid+1;    
            }
            else r = mid;    // 下界就是mid；
        }
        lbound = l;       // 不加等号，搜出来就是左（上）边界
        
        // 寻找下界
        l=0,r=data.size();
        while(l<r)
        {
            int mid = (l+r-1)/2;
            if(data[mid] <= k)  // 指向右边第一个目标位置，加等号data[mid]<=k
            {
                l = mid+1;    
            }
            else r = mid;    // 下界就是mid；
        }
        rbound = l;       // 不加等号，搜出来就是左（上）边界
        return rbound - lbound;
        
    }
};
