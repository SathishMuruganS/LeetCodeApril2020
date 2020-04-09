#include <iostream>

using namespace std;


class Solution {
    int removeBackspace(string& s){
		for(int i = 0; i < (int)s.size();i++){
			if (s[i] == '#'){
				int j = i;
				int count = 0;
				while (s[j] == '#'){
					count++;
					j++;
				}
				if ((i - count) < 0){
					auto start = s.begin() + 0;
					auto end = s.begin() + count;
					s.erase(start, end);
					i = -1;
				} else {
					auto start = s.begin() + (i-count);
					auto end = s.begin() + (i+count);
					s.erase(start, end);
					i = (i-(count*2)-1) < -1 ? -1: (i-(count*2)-1);
					
				}
			}
			
			
		}
		return 0;
	}
public:
    bool backspaceCompare(string S, string T) {
        removeBackspace(S);
        removeBackspace(T);
        return S==T;
    }
};

int main(){
	
	Solution s;
	
	
	cout<<s.backspaceCompare("ab#c", "ad#c")<<endl;
	cout<<s.backspaceCompare("ab##", "c#d#")<<endl;
	cout<<s.backspaceCompare("a##c", "#a#c")<<endl;
	cout<<s.backspaceCompare("a#c", "b")<<endl;
	
	return 0;
		
}
