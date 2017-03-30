#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(list<int>*adjList,bool visited[],bool inStack[],int strt)
{
	if(visited[strt]==false)
	{
		visited[strt]=true;
		inStack[strt]=true;

		list<int>::iterator it;
		for(it=adjList[strt].begin();it!=adjList[strt].end();++it)
		{
			if(visited[*it]==false && isCycleUtil(adjList,visited,inStack,*it))
				return true;
			else if(inStack[*it])
				return true;
		}
	}

	inStack[strt]=false;
	return false;
}

bool isCycle(list<int>*adjList,int v,int strt)
{
	bool visited[v];
	bool inStack[v];

	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		inStack[i]=false;
	}

	for(int i=0;i<v;i++)
	{
		if(isCycleUtil(adjList,visited,inStack,strt))
			return true;
	}
	return false;
}
int main()
{
	list<int> * adjList=new list<int>[5];

	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[2].push_back(3);

	// these two edges creates cycle in the graph

	adjList[2].push_back(0);		
	adjList[3].push_back(3);

	int v=4;
	int strt=0;
	if(isCycle(adjList,v,strt))
		cout<<"cycle is present\n";
	else
		cout<<"cycle isn't present\n";

}
