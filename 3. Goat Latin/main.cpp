#include "test_runner.h"
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	string toGoatLatin(string S) {
		istringstream input(S);
		ostringstream output;
		string tempString;
		int i=1;
		
		while (input>>tempString){
			if (i!=1){
				output<<' ';
			}
			if (isVowel(tempString[0])){
				output<<tempString;
			} else {
				rollLetters(tempString,output);
			}
			
			output<<"ma";
			for (int j=0;j<i;j++){
				output<<'a';
			}
			
			i++;
		}
		
		return output.str();
	}
//private:
	bool isVowel(char c){
		//Является ли символ - гласной? (a, e, i, o, or u)
		return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
	}
	
	void rollLetters(const string & s, ostringstream & output){
		//Перемещает первый символ слова в конец
		//И выводит в поток
		
		if (s.size()<2){
			output<<s;
			return;
		}
		
		bool firstSimvol=true;
		//ostringstream output;
		for (auto t:s){
			if (firstSimvol){
				firstSimvol = false;
			} else {
				output<<t;
			}
		}
		output<<s[0];
		
		//return output.str();
	}
};


int main() {
	
	{
		string input = "I speak Goat Latin";
		string output = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
		ASSERT_EQUAL(output, Solution().toGoatLatin(input));
	}
	
	{
		string input = "The quick brown fox jumped over the lazy dog";
		string output = "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
		ASSERT_EQUAL(output, Solution().toGoatLatin(input));
	}

	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*		Словарик
vowel		-	гласная
consonant	-	согласная
*/

/*
Goat Latin
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.

*/