class Solution {
public:
    string ReverseSentence(string str) {
        // 完全我自己写的东西
        // 首先用临时字符串记录整个单词，遇到空格就执行插入空格和插入完整单词的操作
        // 需要注意，第一次是不需要插入空格的，只需要插入临时字符串，用cnt标记是否为第一次
        // 需要注意，末尾还差一次插入操作，因为没有空格去触发了
        // 另外还需要注意，如果是单个单词的话，也需要加入一个标记变量single去判别
        string dd;
        string tmp;
        bool cnt = false;
        bool single = true;
        if(str.empty()) return str;
        for(auto k:str)
        {
            if(k!=' ')   // 首先用临时字符串记录整个单词
            {
                tmp.append(1,k);
            }
            
            if(k == ' ')
            {
                single = false;
                if( !cnt )     // 需要注意，第一次是不需要插入空格的，只需要插入临时字符串，用cnt标记是否为第一次
                {
                    dd.append(tmp);
                    tmp.clear();
                    cnt = true;
                }
                else
                {
                    dd.insert(dd.begin(),' ');
                    dd.insert(0, tmp);
                    tmp.clear();
                }

            }
            if(k == str[str.size()-1])   // 需要注意，末尾还差一次插入操作，因为没有空格去触发了
            {
                if(single) return str;
                dd.insert(dd.begin(),' ');
                dd.insert(0, tmp);
                tmp.clear();
            }
        }

        return dd;
    }
};
