class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>maxi;
    priority_queue<int, vector<int>, greater<int>>mini;
    void addNum(int num) {
      maxi.push(num);
      mini.push(maxi.top());
      maxi.pop();
      if(mini.size() > maxi.size()) {
        maxi.push(mini.top());
        mini.pop();
      } 
    }
    
    double findMedian() {
      if((maxi.size() + mini.size()) % 2 == 0) {
        double ans = (double)(maxi.top() + mini.top()) / 2;
        return ans;
      }
      return maxi.top();
    }
};