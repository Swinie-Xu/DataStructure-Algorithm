class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        // 双指针的方法，牛逼的说！！！
        int left = 0;
        int right = array.size()-1;
        while(left<right)
        {
            while(array[left]%2 == 1 && left<right) ++left; // 左边的是奇数就右移指针
            while(array[right]%2 == 0 && left<right) --right; // 注意这里 && left<right是必要的哈，不然会越界啊
            int temp = array[left];
            array[left++] = array[right];
            array[right--] = temp;
        }
        return array;
    }
};
