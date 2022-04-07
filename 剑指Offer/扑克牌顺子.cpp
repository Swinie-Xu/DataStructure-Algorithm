class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 纯粹我自己写的哈，思路主要是
        // 先排序，当第一个不为零的数与末尾的数的差值等于对应索引的差值，肯定是连续，因为0是任意数
        // 或者当零的数量可以补足不为零的第一个数与末尾数的差值与索引差值的差值，也可以补成连续的
        // 注意的是，如果不为零的数有重复，直接返回false
        // 另外，如果第一个不为零的数不满足上述条件，可以直接返回false
        sort(numbers.begin(),numbers.end()); // 先排序

        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] != 0) 
            {
                for(int j = i;j<numbers.size();++j)   // 如果不为零的数有重复，直接返回false
                    for(int k=j+1;k<numbers.size();++k)
                    {
                        if(numbers[j] == numbers[k] ) return false;
                    }

                if(numbers.size()-1-i == numbers[numbers.size()-1] - numbers[i]) return true;
                if(numbers.size()-1 == numbers[numbers.size()-1] - numbers[i]) return true;
                
                return false;
            }
        }
        return false;
    }
};
