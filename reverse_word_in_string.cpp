//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        char *c = &s[0]; //conversting string to character array
        char *token = strtok(c, " "); //generating token
        while(token != NULL)
        {
            v.push_back(token);
            token = strtok(NULL," ");//we don't need to give char array again it will already have the 
                                    //previous one stored.
        }
        reverse(v.begin(), v.end());//reversing the words
        int n = v.size();
        string ans = "";
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
/*
In Python we can use split function directly but in c++
strtok: works only for character array so firstly need to convert the string to character array
We cannot use vector directly as it will pick up every character one by one
t
h
e
 
s
k
y

so we need to use strtok to get words.
*/
