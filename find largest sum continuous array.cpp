// PROBLEM :: finding the largest sum continuous array

#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l,int r,int key)
{
	if(l>r)return -1;

	int md=(l+r)/2;

	if(arr[md]==key)
		return md;

	if(arr[l]<=arr[md])
	{
		if(key>=arr[l] && key<=arr[md])
			return search(arr,l,md-1,key);
		else
			return search(arr,md+1,r,key);
	}

	if(key>=arr[md] && key<=arr[r])
		return search(arr,md+1,r,key);
	return search(arr,l,md-1,key);
}

void kadane(int a[],int n)
{
	int msf=0,currMax=0;

	int s=0,e=0;

	for(int i=0;i<n;i++)
	{
			currMax+=a[i];

			if(currMax>msf)
			{
					msf=currMax;
					e=i;
			}

			if(currMax<0)
			{
					currMax=0;
					s=i+1;
			}

	}

	cout<<msf<<"\n";

	for(int i=s;i<=e;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void kadaneImproved(int a[],int n)
{
	int msf=0,currMax=0;
	int s=0,e=0;

	for(int i=0;i<n;i++)
	{
		currMax=max(a[i],currMax+a[i]);

		if(currMax==a[i])
			s=i;

		msf=max(msf,currMax);

		if(msf==currMax)
			e=i;
	}
	cout<<msf<<"\n";
	for(int i=s;i<=e;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{

	int arr[]={-3,-4,5,6,7,-1,-2};

	int n = sizeof(arr)/sizeof(arr[0]);

	kadaneImproved(arr,n);
}

