#include <iostream>
#include <vector>

using namespace std;

void graphToString(const vector<vector<int> > &adj, std::vector<int> A) {
	for (int i=0; i<adj.size(); i++)
	{
		cout << A[i] << " -> ";
		for (int j=0; j<adj[i].size(); j++)
		{
			/* code */
			cout << adj[i][j] << ", ";
		}
		cout << endl;
	}
}

bool evaluate(const vector<vector<int> > &adj) {
	vector<vector<int> > rev(adj.size(), vector<int>(0, 0));
	for (int i=0; i<adj.size(); i++)
	{
		for (int j=0; j<adj[i].size(); j++)
		{
			/* code */
			rev[adj[i][j]].push_back(i);
		}
	}
	for (int i=0; i<rev.size(); i++) 
	{
		if (rev[i].size() > 1) 
		{
			return true;
		}
	}
	return false;
}

int main() {
	int t; 
	cin >> t;
	int l;
	while(t--) 
	{
		cin >> l;
		std::vector<int> A(l);
		vector<vector<int> > adj(l, vector<int>(0, 0));
		for (int i=0; i<l; ++i)
		{
			/* code */
			cin >> A[i];
			A[i]--;
		}
		for (int i=0; i<l; ++i)
		{
			if (std::find(adj[A[i]].begin(), adj[A[i]].end(), A[A[i]]) == adj[A[i]].end())
			{
				adj[A[i]].push_back(A[A[i]]);
			}
		}
		if (evaluate(adj)) 
		{
			cout << "Truly Happy" << endl;
		}
		else 
		{
			cout << "Poor Chef" << endl;
		}
	}
}