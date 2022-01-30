class Solution {
public:
    static bool comp(string& a, string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    string kthLargestNumber(vector<string>& a, int k) {
       sort(a.begin(), a.end(), comp);
       return a[a.size()-k];
    }
};