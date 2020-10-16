#include "test_runner.h"
#include <iostream>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word){
		if (word.size()<2) return true;
		
		bool is_firstchar_upper = (word[0] == static_cast<char>(toupper(word[0])));
		
		if (is_firstchar_upper){
			bool is_secondchar_upper = (word[1] == static_cast<char>(toupper(word[1])));
			
			for (int i=2;i<word.size();i++){
				if ( (word[i] == static_cast<char>(toupper(word[i]))) != is_secondchar_upper )
					return false;
				}
			return true;
			
		} else {
			for (int i=1;i<word.size();i++){
				if (word[i] == static_cast<char>(toupper(word[i])))
					return false;
				}
			return true;
		}
	}
};


int main() {
	
	ASSERT( Solution().detectCapitalUse("USA"));
	ASSERT(!Solution().detectCapitalUse("FlaG"));
	ASSERT( Solution().detectCapitalUse("Flag"));
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}
