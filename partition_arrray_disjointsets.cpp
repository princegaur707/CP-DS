//https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& a) 
    {
        int left_max=a[0], curr_max=a[0], len=0;
        for (int i=1;i<size(a); i++)
        {
            curr_max= max(a[i],curr_max);
            if (a[i]<left_max)
            {
                len=i;
                left_max=curr_max;           
            }
        }
        return len+1;
    }
};


//In this we followed approach that if some no. is less than the left_max then it will 
//difintely required
//to be added to left side so we needed left_max  but if the no. is greater than left_max
//then we cannot say anything about it as there can be any no. after is smaller than the 
//left_max so we will need curr_max as to have knowledge of current maximum which we will
//need to consider as left_max if some number after it is found less than left_max.