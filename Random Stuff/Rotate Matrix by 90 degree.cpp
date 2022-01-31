#include <bits/stdc++.h>

using namespace std;

void printGrid(const vector < vector<int> > &g){
	int n = (int)g.size();
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n; ++j){
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}		
	
}


void solve(){
	int n, m; // n: No.of Rows , m: No.of Columns
	cin >> n >> m;
	vector < vector<int> > grid(n, vector<int>(m));
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m; ++j)
			cin >> grid[i][j];
			
	if(n == 0 || n != m){
		cout << "invalid input\n";
		return;
	}
	for(int layer = 0 ; layer < n / 2 ; ++layer){
		int first = layer;
		int last = n - layer - 1;
		for(int c = first ; c < last ; ++c){
			int offset = c - first;
			int top = grid[first][c]; // save top
			// left -> top
			grid[first][c] = grid[last - offset][first];
			// bottom -> left;
			grid[last - offset][first] = grid[last][last - offset];
			// right -> bottom
			grid[last][last - offset] = grid[c][last];
			// top -> right
			grid[c][last] = top;
		}	
	}	
	cout << "--------------------\n";
	printGrid(grid);
}


int main(){
		
	int tc = 1;
	//scanf("%d" , &tc);
	while(tc--){
		solve();
		#ifdef ONPC
			puts("-----------");
		#endif
	}
	
	return 0;
}
