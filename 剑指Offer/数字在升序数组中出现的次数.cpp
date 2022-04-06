class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        // 自己写的超级混乱的版本，逻辑根本不够健全
        int cnt = 0;
        if(data.size() == 1) data[0] == k ? ++cnt  : cnt;  // 不知道为啥，单个元素的数组无法在通用的处理中处理掉
        int left = 0, right = data.size()-1;
        int mid = (left+right)/2;
        int index = 0;
        while(left<right)   // 二分求解很难顶。。。估计是逻辑不够清晰，套路记得不熟练
        {
            if(data[mid]>k) right = mid-1;
            else if (data[mid]<k) left = mid+1;
            else if(data[mid] == k)
            {
                index = mid;
                ++cnt;
                // 下面两行，找到一个满足要求的元素以后就开始遍历，从中间往两边
                // 但后面感觉还不如直接循环来的简单，时间复杂度一样，服了，根本不满足要求
                for (int i = index-1,j = index+1;i>=0,j<=data.size();--i,++j)
                    {
                        if(data[i] == k) ++cnt;
                        if(data[j] == k) ++cnt;
                    }
                break;
            }
            mid = (left+right)/2;
        }
        return cnt;
    }
};
