#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	int rank;
	node *parent;
};

class disJointSet {
	vector<node*> loc;
public:
	
	disJointSet(int n) {
		for (int i = 0; i < n; i++) {
			node *newnode = new node;
			newnode->data = i;
			newnode->rank = 0;
			newnode->parent = newnode;
			loc.push_back(newnode);
		}	
	}
	
	int getRank(int n) {
		node *curr = loc[n];
		while (curr->parent != curr) {
			curr = curr->parent;
		}
		return curr->data;
	}
	
	void unionSet(int a, int b) {
		if (loc[a]->rank > loc[b]->rank) {
			loc[b]->parent = loc[a];
		} else if (loc[a]->rank < loc[b]->rank) {
			loc[a]->parent = loc[b];
		} else {
			loc[b]->parent = loc[a];
			loc[a]->rank++;
		}
	}
};

double Kruskal(vector<vector<double>> &edges, int V) {
	disJointSet dj(V);
	
	double ans = 0;
	
	for (auto i: edges) {
		int a = dj.getRank(i[0]), b = dj.getRank(i[1]);
		if (a == b) continue;
		ans += i[2];
		
		dj.unionSet(a, b);

	}
	
	return ans;
}


bool cmp(vector<double> i, vector<double> j) {
	return i[2] < j[2];
}

int main() {
	int n;
	cin>>n;
	vector<pair<int, int>> points;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin>>a>>b;
		points.push_back(make_pair(a, b));
	}
	
	vector<vector<double>> edges;
	
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) continue;
			double dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
			vector<double> v;
			v.push_back(i);
			v.push_back(j);
			v.push_back(dist);
			edges.push_back(v);
		}
	}
	
//	for (auto i : edges) {
//		printf("%f %f %f\n", i[0], i[1], i[2]);
//	}
	
	sort(edges.begin(), edges.end(), cmp);
//	cout<<endl;
	
//	for (auto i : edges) {
//		printf("%f %f %f\n", i[0], i[1], i[2]);
//	}
	
	double ans = Kruskal(edges, n);
	printf("%.7f\n", ans);
	
	return 0;
}
