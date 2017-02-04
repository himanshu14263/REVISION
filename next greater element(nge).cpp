// PROBLEM :: PRINT THE NEXT GREATER ELEMENT OF ALL ELEMENT OF ARRAY

#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[],int n)
{
	stack<int>s;
	s.push(arr[0]);

	for(int i=0;i<n;i++)
	{
		int next=arr[i];

		if(s.empty()==false)
		{
			int x=s.top();
			s.pop();

			while(x<next)
			{
				cout<<x<<"--->"<<next<<"\n";
				if(s.empty()==true)
					break;
				x=s.top();
				s.pop();
			}

			if(x > next)
				s.push(x);
		}
		s.push(next);
	}


	while(s.empty()==false)
	{
		int x=s.top();
		s.pop();

		cout<<x<<"--->"<<-1<<"\n";

	}
}
int main()
{
	int arr[]={5,4,3,2,1};
	int n=((sizeof(arr)/sizeof(arr[0])));


	printNGE(arr,n);
}
