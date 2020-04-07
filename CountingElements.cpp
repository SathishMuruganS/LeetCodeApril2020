/**

Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

 

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
Example 3:

Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
Example 4:

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
 

Constraints:

1 <= arr.length <= 1000
0 <= arr[i] <= 1000

**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n; i++){
			int val = arr[i]+1;
			int flag = true;
			for(int j = i+1; j < n;j++){
				if (val == arr[j] && flag){
					ans++;
					flag = false;
				} else if (val < arr[j]){
					break;
				}
			}
		}
		
		return ans;
    }
};

int main()
{
	Solution s;
	vector<int> vec{1,2,3};
	vector<int> vec1{1,1,3,3,5,5,7,7};
	vector<int> vec2{1,3,2,3,5,0};
	vector<int> vec3{1,1,2,2};
	
	cout<<"Result"<<s.countElements(vec)<<endl;
	cout<<"Result"<<s.countElements(vec1)<<endl;
	cout<<"Result"<<s.countElements(vec2)<<endl;
	cout<<"Result"<<s.countElements(vec3)<<endl;
	
	return 0;
}
