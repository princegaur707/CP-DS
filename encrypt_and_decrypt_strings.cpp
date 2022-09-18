//https://leetcode.com/problems/encrypt-and-decrypt-strings/
class Encrypter {
public:
    unordered_map<char, string>m;
    vector<string>d;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i = 0; i < n; i++)
        {
            m[keys[i]] = values[i];
        }
        d = dictionary;
    }
    
    string encrypt(string word1) {
        string enc = "";
        int n = word1.length();
        for(int i = 0; i < n; i++)
        {
            if(m.find(word1[i]) == m.end())
            {
                return "";
            }
            enc += m[word1[i]];
        }
        return enc;
    }
    
    int decrypt(string word2) {
        int count = 0;
        int n = d.size();
        for(int i = 0; i < n; i++)
        {
            if(encrypt(d[i]) == word2)//Instead of calculating no. of possible outcomes with given string we decided to
            {						//enrcypt given strings of dictionary as there is only one possible way of encrypting.
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(
 * keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */


/**
Questions is asking us to
1. Encrypt the given string word1.
2. Calculate the total no. of strings present in the given veector string dictionary are possible if we
will decrypt the string word2.
*/

