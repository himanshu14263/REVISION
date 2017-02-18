#include <bits/stdc++.h>
using namespace std;

void func(int arr[],int n,int x)
{
	int s,i;
	s=0;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];

		while( sum>x && s<i)
			sum-=arr[s++];

		if(sum==x)
		{	
			cout<<s<<" "<<i<<"\n";
			return;
		}
	}
	cout<<"no such subarray exists\n";
}
int main()
{
	int arr[]={1,2,3,4, 23};
	int n=(sizeof(arr)/sizeof(arr[0]));
	int x=23;
	func(arr,n,x);
}