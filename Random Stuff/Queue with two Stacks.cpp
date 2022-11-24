#include <bits/stdc++.h>
 
using namespace std; 
#define fastIO ios::sync_with_stdio(false), cin.tie(0);
#define ll long long

const int N = 2e5 + 10, mod = 1e9 + 7, OO = 0x3f3f3f3f;


class MyQueue{

	stack < int > newSt, oldSt;
public:
	
	void push(int val){
		newSt.push(val);
	}
	void shiftStacks(){
		if(oldSt.empty()){
			while(!newSt.empty()){
				oldSt.push(newSt.top());
				newSt.pop();
			}
		}
	}
	void pop(){
		shiftStacks();
		if(oldSt.empty()){
			cout << "Error queue has no elements to pop from!\n";
			return;
		}
		oldSt.pop();
	}
	int front(){
		shiftStacks();
		if(oldSt.empty()){
			cout << "Error queue has no elements to get front!\n";
			return -1; // invalid value just for explanation purpose, not pratical.
		}
		return oldSt.top();
	}
	int size(){
		return (int)(oldSt.size() + newSt.size());
	}

};

int main(){

	fastIO

	#ifdef ONPC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif


	MyQueue q;
	int n;
	cin >> n;
	while(n--){
		int op, x;
		cin >> op;
		if(op == 1){
			cin >> x;
			q.push(x);
		}
		else if(op == 2){
			q.pop();
		}
		else if(op == 3){
			cout << q.front() << "\n";
		}
		cout << "queue current size = " << q.size() << "\n";
	}



	return 0;
}
