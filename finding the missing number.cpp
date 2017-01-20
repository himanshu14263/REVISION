// PROBLEM : FIND THE MISSING NUMBER.
// number are given from 1 to n and one of them is missing, find the missing number.

#include <bits/stdc++.h>
using namespace std;


// using XOR APPROACH
void func(int a[],int n)
{
	int x1=a[0],x2=1;

	for(int i=1;i<n;i++)
		x1=(x1^a[i]);

	for(int i=2;i<=n+1;i++)
		x2=(x2^i);

	cout<<(x1^x2);
}
int main()
{

	int arr[]={1,2,3,5};
	int n=(sizeof(arr)/sizeof(arr[0]));

	func(arr,n);

}
