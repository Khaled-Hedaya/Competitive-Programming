// problem link: https://leetcode.com/problems/find-median-from-data-stream/
// idea: divide the problem into two parts to keep track the elements in sorted order then keep two heaps (min & max) to and try to make them equal in size as possible 
// --> they will be equal in size if number of elements is even otherwise the maxHeap will will 1 extra value

class MedianFinder { // max Heap || minHeap --> {1 , 3 || 4 , 5}
public:
	priority_queue <int> mxH;
	priority_queue < int, vector < int > , greater<int>> mnH;

	MedianFinder() {

	}
	// 1 , 4
	// mxH = {3} , mnH = {5}
	void addNum(int num) {
		if ((int)mxH.size() == 0) { // first element
			mxH.push(num);
			return;
		}
		if ((int)mnH.size() == 0) {
			if (num < mxH.top()) {
				int tmp = mxH.top();
				mxH.pop();
				mxH.push(num);
				mnH.push(tmp);
			}
			else
				mnH.push(num);
			return;
		}
		if (mxH.size() == mnH.size()) {
			if (num < mnH.top())
				mxH.push(num);
			else {
				int tmp = mnH.top();
				mnH.pop();
				mxH.push(tmp);
				mnH.push(num);
			}
			return;
		}
		// we are here sure that mxH size = mnH size + 1
		if (num < mxH.top()) {
			int tmp = mxH.top();
			mxH.pop();
			mnH.push(tmp);
			mxH.push(num);
		}
		else
			mnH.push(num);
	}

	double findMedian() {
		int szMx = (int)mxH.size(), szMn = (int)mnH.size();
		if (szMx == szMn)
			return (1.0 * mxH.top() + mnH.top()) / 2.0;
		else
			return (mxH.top());
	}
};
