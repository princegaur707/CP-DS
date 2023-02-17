class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      int n = asteroids.size();
      stack<int>s;
      for(int i = 0; i < n; i++) {
        int x = asteroids[i];
        if (!s.empty() and s.top() > 0 and x < 0) {//condn necessary for collision to occur latest rock should move left and earlier to the right(earlier one is in stack)
          bool flag = true;
          while(!s.empty() and s.top() > 0 and x < 0) {
            if(abs(x) == s.top()) {
              s.pop();
              flag = false;//both rocks destroyed no need to insert it
              break;
            }
            else if (abs(x) > s.top()) {
              s.pop();
              flag = true;//we need to insert as x will destory latest rock
              continue;
            }
            else {
              flag = false;//flag required to update here too otherwise x will be inserted at last in case of TC 10 2 -5
              break;
            }
          }
          if(flag == true)
            s.push(x);
        }
        else
          s.push(x);//No Collision
      }
      vector<int>v(s.size());
      int k = s.size() - 1;
      while(!s.empty()) {//inserting the rocks into vector array in reverse order
        v[k--] = s.top();
        s.pop();
      }
      return v;
    }
};