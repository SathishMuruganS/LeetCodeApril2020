/**
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4

**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
			val ^= nums[i];
		}
		return val;
    }
};


int main()
{
	Solution s;
	vector<int> vec1{2,2,1};
	vector<int> vec2{4,1,2,1,2};
	
	cout<<s.singleNumber(vec1)<<endl;
	cout<<s.singleNumber(vec2)<<endl;
	
	return 0;
}

