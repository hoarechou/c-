#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<list<int>> vec;
bool subset(int array[], int sum, int left, int right)
{
	if(left==right)
		return 0;
	if(array[left]+array[right]<sum)
		subset(array,sum,++left,right);
	else if(array[left]+array[right] > sum)
		subset(array,sum,left,--right);
	else{
		list<int> *list=new list<int>;
		list->push_back(left);
		list->push_back(right);
		vec.push_back(list);
		return 1;
	}	
}
int main()
{
	int array[]={1,3,5,8,9};
	cout<<subset(array,11,0,4)<<endl;
	return 0;
}
