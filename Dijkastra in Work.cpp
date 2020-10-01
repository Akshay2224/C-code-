#include<bits/stdc++.h>
#define INF pow(10, 9)+7
using namespace std;

template <typename T>
class HeapMap {
		void addInHeap(T vx) {
			if (um.count(vx) == 0) {
				heap.push_back(make_pair(vx, INF));
				um[vx] = ++heapLen;
			}
		}
	public:
		vector<pair<T, int>> heap;
		unordered_map<T, int> um;
		int heapLen = -1;
		
		void addNode(T a, T b) {
			addInHeap(a);
			addInHeap(b);
		}
		
		void siftup(int ix) {
			while (ix > 0) {
				if (heap[ix].second < heap[(ix-1)/2].second) {
					swap(heap[ix], heap[(ix-1)/2]);
					um[heap[ix].first] = ix;
					um[heap[(ix-1)/2].first] = (ix-1)/2;
					ix = (ix-1)/2;
				}
				else
					break;
			}
		}
		
		void siftDown(int ix) {
			while (2*ix+1 <= heapLen) {
				int b = 2*ix+1;
				if (b+1 <= heapLen and heap[b].second > heap[b+1].second)
					b++;
				if (heap[ix].second > heap[b].second) {
					swap(heap[ix], heap[b]);
					um[heap[ix].first] = ix;
					um[heap[b].first] = b;
					ix = b;
				}
				else
					break;				
			}
		}
		
		void setSource(T vx) {
			heap[um[vx]].second = 0;
			siftup(um[vx]);
		}
		
		void decreaseKey(T vx, int data) {
			heap[um[vx]].second = data;
			siftup(um[vx]);
		}
		
		pair<T, int> extractMin() {
			pair<T, int> p = heap[0];
			swap(heap[0], heap[heapLen--]);
			um[heap[0].first] = 0;
			heap.pop_back();
			siftDown(0);
			um.erase(p.first);
			return p;
		}
		
		void deleteKey(T a) {
			um.erase(a);
		}
		
		bool isEmpty() {
			return heapLen == -1;
		}
		
		bool contains(T vx) {
			return um.count(vx)>0;
		}
};

void printPath(unordered_map<char, char> parent, char vx) {
	if (parent[vx] == vx) {
		cout<<vx<<" -> ";
		return;
	}
	printPath(parent, parent[vx]);
	cout<<vx<<" -> ";
}

void dijkastra(unordered_map<char, vector<pair<char, int>>> edges, int V, int E, HeapMap<char> hmp) {
	unordered_map<char, char> parents;
	unordered_map<char, int> distances;
	char src;
	cin>>src;
	hmp.setSource(src);
	parents[src] = src;
		
	for (int i = 0; i <= hmp.heapLen; i++) 
		cout<<hmp.heap[i].first<<" "<<hmp.heap[i].second<<" "<<i<<" "<<hmp.um[hmp.heap[i].first]<<"\n";
	cout<<"\n";
		
	while (!hmp.isEmpty()) {
		cout<<"***************************************\n";
		pair<char, int> p = hmp.extractMin();
		char curr = p.first;
		distances[curr] = p.second;
		cout<<"Curr Edge: "<<curr<<"  Distance: "<<distances[curr]<<endl;
		for (int i = 0; i <= hmp.heapLen; i++) 
			cout<<hmp.heap[i].first<<" "<<hmp.heap[i].second<<" "<<i<<" "<<hmp.um[hmp.heap[i].first]<<"\n";
		cout<<"\n";
		for (auto i: edges[curr]) {
			if (hmp.contains(i.first)) {
				cout<<"Current Adjacent Edge: "<<i.first<<"\n";
				if (hmp.heap[hmp.um[i.first]].second > i.second + distances[curr]) {
					hmp.decreaseKey(i.first, i.second+distances[curr]);
					parents[i.first] = curr;
//					distances[i.first] = i.second+distances[curr];
					printf("Distance of %c from %c is updated by %d\n", curr, i.first, i.second+distances[curr]);
				}
				else {
					cout<<i.first<<" "<<hmp.heap[hmp.um[i.first]].second<<" "<<i.second<<" "<<distances[curr]<<endl;
				}
			}
		}
		for (int i = 0; i <= hmp.heapLen; i++) 
			cout<<hmp.heap[i].first<<" "<<hmp.heap[i].second<<" "<<i<<" "<<hmp.um[hmp.heap[i].first]<<"\n";
//		for (auto i: hmp.heap) 
//			cout<<i.first<<" "<<i.second<<"\n";
		cout<<"\n";
//		hmp.deleteKey(curr);
	}
	cout<<"*********************************************\n";
	for (auto i: distances) {
		cout<<i.first<<":"<<i.second<<"\n";
	}
	
	for (auto i: parents) {
		cout<<i.first<<":"<<i.second<<"\n";
		printPath(parents, i.first);
		cout<<endl;
	}
}

void addEdge(unordered_map<char, vector<pair<char, int>>> &uom, char src, char dst, int wt) {
	if (uom.count(src) == 0) {
		vector<pair<char, int>> v;
		v.push_back(make_pair(dst, wt));
		uom[src] = v;
	}
	else {
		uom[src].push_back(make_pair(dst, wt));
	}
}

/*
4 4
A B 2
B D 2
B C 6
C D 2
A
C D 2
B C 6
A B 2
*/

int main() {
	int V, E;
	cin>>V>>E;
	unordered_map<char, vector<pair<char, int>>> uom;
	HeapMap<char> hmp;
	for (int i = 0; i < E; i++) {
		char a, b;
		int c;
		cin>>a>>b>>c;
		addEdge(uom, a, b, c);
		addEdge(uom, b, a, c);
		hmp.addNode(a, b);
	}
	
	for (int i = 0; i <= hmp.heapLen; i++) 
		cout<<hmp.heap[i].first<<" "<<hmp.heap[i].second<<" "<<i<<" "<<hmp.um[hmp.heap[i].first]<<"\n";
	cout<<"\n";
	
	for (auto i: uom) {
		cout<<i.first<<" ";
		for (auto j: i.second) 
			cout<<j.first<<" "<<j.second<<" " ;
		cout<<endl;
	}
	cout<<"\n";
	
	
	dijkastra(uom, V, E, hmp);
	
	return 0;
}
