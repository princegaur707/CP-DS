//https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
    bool compare(int *counts, int *countp)
    {
        for(int i = 0; i < 26; i++)
        {
            if(counts[i] != countp[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        vector<int>arr;
        if(lens < len)p
        {
            return arr;
        }
        int counts[26] = {0};
        int countp[26] = {0};
        for(int i = 0; i < lenp; i++)
        {
            countp[p[i] - 'a']++;
        }
        
        for(int i = 0; i < lens; i++)
        {
            counts[s[i] - 'a']++;
            if(i >= lenp)
            {
                counts[s[i - lenp] - 'a']--;
            }
            if(i >= lenp - 1)
            {
                if(compare(counts, countp))
                {
                    arr.push_back(i - lenp + 1);
                }
            }
        }
        return arr;
    }
};
//Do by this approach once have knowledge of syntax of c++  
//class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int len1 = s.length();
//         int len2 = p.length();
//         vector<int>arr;
//         vector<string> arr1;
//         sort(p.begin(), p.end());
//         for(int i = 0; i < len1 - len2 -1; i++)
//         {
//             for(int j = 0; j < len2; j++)
//             {
//                 arr1[i][j]= s[i + j];
//             }
//         }    
//         for(int i = 0; i < len1 -len2; i++)
//         {
//             for(int j = 0; j < len2; j++)
//             {
//                 cout<<arr1[i][j];
//             }
//         }
//         return arr;
//     }
// };