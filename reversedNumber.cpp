#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string addStringAsNumber(string str1, string str2)
{
	int sum = 0, carry = 0, setbit = 0;
	
	string *addend = &str1;
	string *summand = &str2;
  	stringstream oss("");
	int str1_size = str1.size();
	int str2_size = str2.size();
	int max_size = str1_size;
	int delta = str1_size - str2_size;
	if(str1_size < str2_size){
		addend = &str2;
		summand = &str1;
		max_size = str2_size;
		delta = -delta;
	}

	for(int i = max_size-1; i >= 0; --i){
		if( (i - delta) >= 0)
			sum = ((*addend)[i]-'0')+((*summand)[i-delta]-'0') + carry;
		else
			sum = ((*addend)[i]-'0')+carry;
		carry = sum > 9 ? 1 : 0;
		if((sum%10) != 0)
			setbit = 1;
			
		if(setbit)
			oss << (sum%10);
	}

	if(carry)
		oss<<carry;	
	return oss.str();
	
}	

	
void xswap(string& str, int left, int right)
{
	char tmp = 0;
	if(left < right){
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		++left;
		--right;
		xswap(str,left,right);
	}
}
void reverseString(string& str)
{

	xswap(str, 0, str.size()-1);
	
}
void omittzeros(string& str)
{
	int size = str.size();
	
	while(str[size-1] == '0'){
		str.erase(size-1);
		size--;
		if(size < 1)
			break;
	}
}

int main()
{

	vector<string> result;
	int cases;
	string number1,number2;
	string sum;
	cin>>cases;

	for(int i = 0; i < cases; ++i){
		cin>>number1;
		cin>>number2;
		omittzeros(number1);
		omittzeros(number2);
		reverseString(number1);
		reverseString(number2);
		sum = addStringAsNumber(number1,number2);
		result.push_back(sum);
	}
	

	for(vector<string>::iterator it = result.begin();it != result.end();it++) {
      	    cout << *it <<endl;
	}

	return 0;

}



