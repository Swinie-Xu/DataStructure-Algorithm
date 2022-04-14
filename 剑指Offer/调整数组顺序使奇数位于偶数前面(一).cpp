class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
        vector<int> reOrderArray(vector<int>& array) {
        // write code here
        // 属于是骚操作了！！！值得学习！
        // STL+Lambda
        stable_partition(array.begin(), array.end(),[](int x){
            return x&1;    // 匿名函数实现筛选规则
        });
        return array;
    }

};
