class Solution {
public:
  priority_queue<int> q;
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      // 将数组里面的数字都放入一个优先队列里面
      // 抄的代码，大顶堆就是优先队列（默认从小到大）
      for(auto x:input){
          q.push(x);
          if(q.size()>k){
              q.pop();
          }
      }
      // 对input数组
      input.clear();
      // 如果达不到k个数字
      if(q.size()<k){  
          return input;
      }
      while(!q.empty()){
          input.push_back(q.top());
          q.pop();
      }
      return input;
  }
};
