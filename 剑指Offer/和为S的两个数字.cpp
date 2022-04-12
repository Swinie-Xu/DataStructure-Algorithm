class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        // 就自己写的
        // 头+尾，大于sum就是右边大了，右边左移
        // 小于sum，就是左边小了，往右边移 
        int left = 0;
        int right = array.size()-1;
        vector<int> ret;
        while(left<right) 
        {
            if(array[left]+array[right]>sum) --right;
            else if(array[left]+array[right]<sum) ++left;
            else {
                ret.push_back(array[left]);
                ret.push_back(array[right]);
                return ret;
            }
        }
        return ret;
    }
};
