#include <iostream>
#include <vector>

using namespace std;

bool isSubset(int array[], vector<bool> isUsed,vector< vector<bool> > &vec,int n,int sum)
{
	bool use;
	bool notuse;

	if(sum == 0){
		vec.push_back(isUsed);
		return 1;
	}		
	if(n==0){
		return 0;
	}

	isUsed[n-1] = 0;
	notuse = isSubset(array, isUsed, vec, n-1, sum);

	isUsed[n-1] = 1;
	use = isSubset(array, isUsed, vec, n-1, sum-array[n-1]);
		
	return notuse || use;
}

int main()
{
	int sum;
	cout<<"Enter the sum value:"<<endl;
	cin>>sum;

	int array[]= {-1, 2, -3};
	int nElements = sizeof(array)/sizeof(array[0]);
	vector<bool> isUsed(nElements,0);
	vector < vector<bool> > vec;
	bool isTrue = isSubset(array, isUsed, vec,  nElements, sum);

	for(int i=0; i < vec.size(); ++i){
		for(int j=0; j < vec[0].size(); ++j)
			cout<<vec[i][j]<<" ";	
		cout<<endl;
	}

	if(isTrue)
		cout<<"Has a nonempty subet"<<endl;
	else
		cout<<"No nonempty subset"<<endl;

	return 0;
}
