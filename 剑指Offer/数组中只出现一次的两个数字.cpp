class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        
        // 学习的别人的想法
        
        // 使用 异或 的性质
          // （0） 只有在两个比较的位不同时其结果是1，否则结果为0
　　      //（1） 0^0=0，0^1=1 0异或任何数＝任何数
　　      //（2） 1^0=1，1^1=0 1异或任何数=任何数取反
　　      //（3） 任何数异或自己＝把自己置0
        
        // 我们要想对两者进行分组操作，就是需要找到两者中的那一位不同的二进制，然后得到分组的与值（去&的那个值）
        // &1 就是按最低位分奇偶 &0010按倒数第二位 &0100同理可推为倒数第三位
        
        // 先将全部数进行异或运算，得出最终结果 为两个不同数的异或结果
        int tmp = 0;
        for(auto num:array)
        {
            tmp^=num;
        }
        
        // 找到那个可以充当分组去进行与运算的数
        // 从最低位开始找起 mask=1 即0001;
        
        int mask = 1;
        while((tmp&mask)==0) mask<<=1;
        
        // 进行分组，分成两组，转换为两组 求出现一次的数字 去求
        int a=0;
        int b=0;
        for(auto num:array)
        {
            if((num&mask)==0)  // 这里只能判别==0哈，因为不同为0000，但是相同的话，结果不定
            {
                a^=num;
            }
            else
            {
                b^=num;
            }
        }
        
        // 因为题目要求小的数放前面，所以这一做个判断
        vector<int> res;
        res.resize(2);
        if(a>b)
        {
            res[0] = b;
            res[1] = a;
        }
        else
        {
            res[0] = a;
            res[1] = b;
        }
        return res;
        
        
    }
};
