/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 


*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(n,1,res);
        return res;
    }
    void helper(int target, int current, vector<int>& res) {
        if(current > target) return;
        res.push_back(current);
        helper(target, current*10, res);
        if(current%10 != 9) helper(target, current+1, res);
    }
};
