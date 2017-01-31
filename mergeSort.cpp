// PROLEM :: FIND THE TWO REPEATING ELEMENT IN THE ARRAY

#include <bits/stdc++.h>
using namespace std;

void findRepeat(int arr[],int n)
{
	map<int,int>mp;

	for(int i=0;i<n;i++)
	{
		if(!mp[arr[i]])
			mp[arr[i]]=1;
		else
			cout<<arr[i]<<" ";
	}
}
void mA(int temp[],int arr[],int l,int md,int h)
{
	int i=l;
	int j=md;
	int k=l;

	while((i<=md-1) && (j<=h))
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}

	while(i<=md-1)
		temp[k++]=arr[i++];
	while(j<=h)
		temp[k++]=arr[j++];

	for(int i=l;i<=h;i++)
		arr[i]=temp[i];

}
void _ms(int temp[],int arr[],int l,int h)
{
	if(l<h)
	{
		int md=(l+h)/2;
		_ms(temp,arr,l,md);
		_ms(temp,arr,md+1,h);
		mA(temp,arr,l,md+1,h);
	}
}
void ms(int arr[],int n)
{
	int temp[n];
	return _ms(temp,arr,0,n-1);
}
int main()
{
	int arr[]={1,2,3,4,5,2,4};
	int n=(sizeof(arr)/sizeof(arr[0]));

	for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";

	cout<<"\n";


	ms(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";



}
