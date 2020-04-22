/**
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
 1. The length of the array is in range [1, 20,000].
 2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

**/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        long long sum = 0;

        for(int i=0;i<n;i++){
            sum = 0;

            for(int j = i;j<n;j++){
                sum += nums[j];

                if (sum == k){
					ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums{{1,1,1}, {1,2,3}, {28,54,7,-70,22,65,-6}};
    vector<int> k_val{2,3,100};

    for(int i = 0;i<3;i++){
        cout<<s.subarraySum(nums[i], k_val[i])<<endl;
    }

    return 0;
}
