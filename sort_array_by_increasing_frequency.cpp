bool cmp(pair<int, int>a, pair<int, int>b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int, int>m;
        for(auto x : nums)
        {
            m[x]++;
        }
        vector<pair<int, int>>v;
        for(auto x : m)
        {
            v.push_back(x);
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j <v[i].second; j++)
            {
                ans.push_back(v[i].first);
            }
        }
        return ans;
    }
};