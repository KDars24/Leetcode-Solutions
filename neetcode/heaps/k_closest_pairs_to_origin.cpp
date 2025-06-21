/*
21-06-2025

K Closest Points to Origin

You are given an 2-D array points where points[i] = [xi, yi] represents the coordinates of a point on an X-Y axis plane. You are also given an integer k.

Return the k closest points to the origin (0, 0).

The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).

You may return the answer in any order.
*/
class Compare {
    public:
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< vector<int>, vector<vector<int>>, Compare> pq;
        for(auto& point: points) {
            pq.push(point);
        } 
        vector<vector<int>> res;
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top()); 
            pq.pop();
        }
        return res;
    }
};
