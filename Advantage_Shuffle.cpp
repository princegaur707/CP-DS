//https://leetcode.com/problems/advantage-shuffle/description/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size();
      sort(nums1.begin(), nums1.end());
      vector<pair<int, int>>v;
      for(int i = 0; i < n; i++)
        v.push_back({nums2[i], i});
      sort(v.begin(), v.end());//by default sorts acc. to first parameter
      vector<int>extra;
      vector<int>final(n, -1);
      int j = 0;
      for(int i = 0; i < n; i++) {
        if(nums1[i] > v[j].first) {
          final[v[j].second] = nums1[i];
          j++;
        }
        else {
          extra.push_back(nums1[i]);
        }
      }
      j = 0;
      for(int i = 0; i < n; i++) {
        if(final[i] == -1) {
          final[i] = extra[j];
          j++;
        }
        if(j == extra.size())
          break;
      }
      return final;
    }
};