#include<bits/stdc++.h>
using namespace std;
int cur = 0;
int matrix[12][12] = {{0, 0, 0, 1, 0, 0, 0, 0, 00}, {0,1,0,0,0,0,0,0,1}, {0,0,1,1,1,0,0,0,1},{0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,1,0},{0,1,1,0,0,0,1,0},{0,0,0,1,0,0,0,1,0},{1,0,0,0,1,0,1,0,0},{1,0,1,0,0,0,1,0,0},{0,1,0,0,1,0,1,0,1},{0,0,0,0,1,0,0,0,0}};

bool visited[12];
deque <int> queue;

void function(int n);

int main() {
	int num = 0;
	int n = 11;
		function(n);
	return 0;
}

void function(int n) {
	cout<<cur<<" ";
	visited[cur] = true;
	queue.push_back(cur);
	
	do {
		for (int j = 0; j < n; j++) {
			if (matrix[cur][j] == 1 && !visited[j]) {
				queue.push_back(j);
				cout<<j<<" ";
				visited[j] = true;
			}
		}
		queue.pop_front();
		if(!queue.empty())
			cur = queue.front();
	}while(!.queue.empty());
}
