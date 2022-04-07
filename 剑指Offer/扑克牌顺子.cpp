class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 这是别人的代码，思路是一样的，但是实现好像简洁一些
        // 主要就是代码结构安排比较好
        // interval的想法比较好
        
        /*
            顺子牌的特点：
            1、顺子一定没有相等的牌；
            2、顺子中两张相邻的扑克牌的数值差为1，即满足interrapt=numbers[i + 1] - numbers[i] - 1==0;
            3、当interrapt不为0，代表需要在顺子中插入对应interrapt张牌；
            4、只有两张王牌；
            主要思路：
            1、排序五张牌；
            2、遍历5张牌，并求出大小王的数量zero_num，与interrapt的大小；
            3、判断interrapt的大小。
            (1)interrapt==0,除大小王之外的牌本来就是顺子，大小王随便补齐在头部或者尾部；
            (2)interrapt<=zero_num,除大小王之外的牌不是顺子，可以通过大小王变成特定的牌补在其中，使其成为顺子；
            (2)interrapt>zero_num,除大小王之外的牌不是顺子,即使有大小王也补不成顺子。
        */
        
        sort(numbers.begin(), numbers.end());
        int zero_num = 0;//统计大小王数量
        int i = 0;
        while (numbers[i] == 0)zero_num++,i++;
        int interrapt = 0;//记录五张牌中最大值max到最小值min的距离
        for (; i < numbers.size()-1; ++i) {
            if (numbers[i] == numbers[i + 1])return false;//出现相同的扑克牌
            interrapt += numbers[i + 1] - numbers[i] - 1;//计算距离
        }
        if (zero_num >= interrapt) return true;
        return false;
    }
};
