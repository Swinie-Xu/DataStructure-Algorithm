class Solution {
public:
    int mem[1000];
    int rectCover(int number) {
        // 记忆化搜索的斐波那契数列
        // 自己写了半天没有通过，服了！
        if(mem[number]) return mem[number];
        if(number < 1) 
        {
            return 0;
        }
        if(number<=2) 
        {
            mem[number] = number;
        }
        else {
            mem[number] = rectCover(number-1) + rectCover(number-2);
        }
        return mem[number];
    }
};
