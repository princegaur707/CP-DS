//https://leetcode.com/problems/permutation-in-string/description/
//Helpful video: https://www.youtube.com/watch?v=UbyhOgBN834
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int s1map[26] = {0};
        int s2map[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(s1map[i] == s2map[i])
                matches++;
        }
        for(int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a', l = s2[i] - 'a';
            if (matches == 26)
                return true;
            s2map[r]++;
            if(s2map[r] == s1map[r])
                matches++;
            else if(s2map[r] == s1map[r] + 1)
                matches--;
            s2map[l]--;
            if(s2map[l] == s1map[l])
                matches++;
            else if(s2map[l] == s1map[l] - 1)
                matches--;
        }
        return matches == 26;
    }
};