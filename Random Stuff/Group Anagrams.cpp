// problem link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map < string, vector<string> > mp;
		vector < vector < string > > ans;

		for (auto s : strs) {
			int frq[26] = {};
			for (auto ch : s)
				frq[ch - 'a']++;
			string key = "";
			for (int i = 0 ; i < 26 ; ++i) {
				key += "#";
				key += to_string(frq[i]);
			}
			mp[key].push_back(s);
		}
		for (auto k : mp) {
			vector<string> cur;
			for (auto s : k.second)
				cur.push_back(s);
			ans.push_back(cur);
		}
		return ans;
	}
};
