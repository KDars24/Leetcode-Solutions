/*
3170. Lexicographically Minimum String After Removing Stars

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.
*/

class Solution {
public:
    typedef pair<char, int> P;
    
    //custom comparator for prio queue; 
    struct comp {
        bool operator()(P& p1, P& p2) {
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        int n = s.size();

        priority_queue<P, vector<P>, comp> pq;
        
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                pq.push({s[i], i});
            } else {
                int index = pq.top().second;
                pq.pop();
                s[index] = '*';
            }
        }

        string result = "";
        for(char c: s) {
            if(c == '*')continue;
            result += c;
        }
        return result;
        
    }
};
