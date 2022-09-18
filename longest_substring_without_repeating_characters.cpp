class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char, int>m;
        for(int l = 0, r = 0; r < n; r++)
        {
            if(m.count(s[r]) == 1)
            {
                l = max(l, m[s[r]] + 1);    
            }
            m[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};