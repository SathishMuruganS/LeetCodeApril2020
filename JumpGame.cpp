/**
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
             
**/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for(int i = 0;i<n; i++){
            if (answer < i){
                return false;
            }
            answer = max(answer, i + nums[i]);
        }

        return true;
    }
};

int main()
{
    vector<int> nums{2,3,1,1,4};
    vector<int> nums1{3,2,1,0,4};
    vector<int> nums2{0,1};
    vector<int> nums3{10000,1};
    vector<int> nums4{2,0};
    vector<int> nums5{0};
    vector<int> nums6{5};
    vector<int> nums7{2,0,0};
    Solution s;

    cout<<s.canJump(nums)<<endl;
    cout<<s.canJump(nums1)<<endl;
    cout<<s.canJump(nums2)<<endl;
    cout<<s.canJump(nums3)<<endl;
    cout<<s.canJump(nums4)<<endl;
    cout<<s.canJump(nums5)<<endl;
    cout<<s.canJump(nums6)<<endl;
    cout<<s.canJump(nums7)<<endl;

    return 0;
}
