// PROBLEM : FINDING ELEMENT IN SORTED AND ROTATED ARRAY
// required time complexity is : O(log n)

#include<bits/stdc++.h>
using namespace std;

int  func(int arr[],int l,int h,int key)
{
	if(l>h)return -1;

	int md=(l+h)/2;

	if(arr[md]==key)return md;

	//check if sorted or not
	if(arr[0]<=arr[md])
	{
		// check if key lie in range of first half or second half
		if(key>=arr[l] && key<=arr[md])
			return func(arr,l,md-1,key);
		return func(arr,md+1,h,key);
	}

	// if first half isn't sorted then second half will be sorted
	if(key>=arr[md] && key<=arr[h])
		return func(arr,md+1,h,key);
	return func(arr,l,md-1,key);
}
int main()
{

	int arr[]={1,2,3,5};
	int n=(sizeof(arr)/sizeof(arr[0]));


	int x;
	cin>>x;

	cout<<func(arr,0,n-1,x);

}
