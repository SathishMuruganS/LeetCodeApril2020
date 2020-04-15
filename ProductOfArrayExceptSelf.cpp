/**
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

**/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1, 1);
        vector<int> surf(n+1, 1);
        vector<int> ans(n);
        
        pref[0] = 1;
        for(int i = 1;i<=n; i++){
            pref[i] = nums[i-1] * pref[i-1];
        }
		
        surf[n] = 1;
        for(int i = n-1;i >= 0; --i){
            surf[i] = nums[i] * surf[i+1];
        }

        for(int i = n-1; i >= 0; --i){
            ans[i] = pref[i] * surf[i+1];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec{1,2,3,4};
	
    vector<int> ans = s.productExceptSelf(vec);
    return 0;
}
