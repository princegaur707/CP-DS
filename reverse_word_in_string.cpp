//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        char *token = strtok((char*)s.c_str(), " ");
        vector<string>v;
        while(token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL, " ");
        }
        reverse(v.begin(), v.end());
        string ans = "";
        int n = v.size();
        for(int i = 0; i < n; i++)
        {
            if(i == n - 1)
            {
                ans += v[i];
            }
            else
            {
                ans += v[i] + " ";
            }
        }
        return ans;
    }
};