class Solution {
public:
    int compress(vector<char>& chars) {
      int i = 0, res = 0;
      while(i < chars.size()) {
        int length = 1;
        while(i + length < chars.size() and chars[i] == chars[i + length])
          length++;
        chars[res++] = chars[i];
        if (length > 1) {
          for(char ch : to_string(length))
            chars[res++] = ch;
        }
        i += length;
      }
      return res;
    }
};