#include<bits/stdc++.h>
using namespace std;


int getHeight(int n, int **edges, int st) {
        bool *visited = new bool[n];
        memset(visited, false, sizeof(visited));
        visited[st] = true;
        queue<int> q;
        int height = 0;
        q.push(st);
        q.push(INT_MAX); 
        while (q.size() > 1) {
            int ix = q.front();
            q.pop();
            if (ix == INT_MAX) {
                if (q.size() == 1 and q.front() == INT_MAX)
                    break;
                height++;
                q.push(INT_MAX);
                continue; 
            }
            for (int i = 0; i < n; i++) {
                cout<<visited[i]<<i<<ix<<endl;
                if (i == ix || visited[i] == true)
                    continue;
                if (edges[ix][i] == 1) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return height;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edge) {
        int **edges = new int*[n];
        for (int i = 0; i<n; i++) {
            edges[i] = new int[n];
            for (int j = 0; j < n; j++) {
                edges[i][j] = 0;
            }
        }
        for (auto i: edge) {
            edges[i[0]][i[1]] = 1;
            edges[i[1]][i[0]] = 1;
        }
        
        int minHeight = INT_MAX;
        vector<int> v;
        for (int i = 0; i<n; i++) {
            int temp = getHeight(n, edges, i);
            if (minHeight > temp) {
                minHeight = temp;
                v.clear();
                v.push_back(i);
            }
            else if (minHeight == temp) {
                v.push_back(i);
            }
        }
        return v;
    }
    
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> v;
	int n;
	cin>>n;
	for (int i= 0; i<n; i++) {
		vector<int> tt;
		int a, b;
		cin>>a>>b;
		v.push_back(tt);
	}
	vector<int> res = findMinHeightTrees(n, v);
	for (auto i: res)
		cout<<i<<" ";
	return 0;
}
