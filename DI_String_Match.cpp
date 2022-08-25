//https://leetcode.com/problems/di-string-match/submissions/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l=s.length();
        vector<int>arr;
        int cnt1=0;
        int cnt2=0;
        for (int i=0; i<=l; i++)
        {
            if (s[i]=='I')
            {   
                arr.push_back(cnt1);
                cnt1++;
            }
            else
            {  
                arr.push_back(l-cnt2);
                cnt2++;
            }
                
        }
        return arr;   
    }
};