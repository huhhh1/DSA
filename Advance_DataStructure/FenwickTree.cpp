#include <bits/stdc++.h>
using namespace std;
int fenwick[1000000];
// To build the fenwick Tree we also going to use this function
void update(int index,int add,int n ){
	while(index<n){
		fenwick[index]+=add;
		index =(index+(index&(-index))); // For Updating the value
	}
}
// This going to a left and right range difreeently and find the sum of  prefix before it q 
int fenwickSum(int index){
	int res = 0;
	while(index){
		res+=fenwick[index];
		index = index-(index&(-index));
	}
	return res;
}
// For provideing the single index Argument in the fenwickSum
int querySum(int l ,int r){
	return fenwickSum(r)-fenwickSum(l-1);
}

// For Lower-Bound of the prefix sum k
// This method called Binary-lifting 
int lower___Bound(int k,int n){
	int index = 0,prev = 0;
	for( int i = log2(n) ; i >= 0 ; i-- ){
		if(fenwick[index+(1<<i)] + prev < k){
			index+=(1<<i);
			prev+=fenwick[index];
		};
	}
	return index+1; // 1-Based Array in Question 
}

int main()
{	
	// build fenwick tree with help of the update function with all index 
	
	return 0;
}
