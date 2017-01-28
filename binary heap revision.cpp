// binary head revision

#include<bits/stdc++.h>
using namespace std;

// METHOD 1 ::


int parent(int i)
{
	return (i-1)/2;
}

int size=0;
int harr[10];
void insert(int d)
{
	harr[size]=d;
	size++;

	int i=size-1;
	while((i!=0) && (harr[i]<harr[parent(i)]))
	{
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}
}

// GEDID
// GET, EXTRACT , DELETE , INSERT , DECREASE VALUE


int getMin()
{
	return harr[0];
}


void decreaseValue(int indx,int val)
{
	harr[indx]=val;
	while((indx!=0) && (harr[indx]<harr[parent(indx)]))
	{
		swap(harr[indx],harr[parent(indx)]);
		indx=parent(indx);
	}
}

void heapify(int i)
{
	int lchild=(2*i)+1;
	int rchild=(2*i)+2;

	int min;
	if(lchild<size && harr[lchild]<harr[i])
		min=lchild;
	if(rchild<size && harr[rchild]<harr[min])
		min=rchild;

	if((min<size) && (min!=i))
	{
		swap(harr[min],harr[i]);
		heapify(min);
	}
}
int extractMin()
{
	if(size<1)
		return -1;
	if(size==1)
	{
		size--;
		return harr[0];
	}

	int root=harr[0];
	harr[0]=harr[size-1];
	size--;

	heapify(0);

	return root;
}

void deleteVal(int indx)
{
	harr[indx]=INT_MIN;

	while((indx!=0) && (harr[indx]<harr[parent(indx)]))
		{
			swap(harr[indx],harr[parent(indx)]);
			indx=parent(indx);
		}

	extractMin();


}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	insert(3);
	insert(5);
	insert(1);

	display(harr,3);

	deleteVal(0);

	display(harr,3);

}

