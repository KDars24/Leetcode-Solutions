class Solution {
    char smallest_char(vector<int>& frequency_store) {
        for(int i = 0; i < 26; i++){
            if(frequency_store[i] > 0) {
                return 'a' + i;
            }
        }
        return 'a'; // default return, should not be reached
    }
    public:
        string robotWithString(string s) {
            vector<int> frequency_store(26, 0);
            for(char ch: s) {
                frequency_store[ch - 'a']++;
            }
            string result = "" ;
            stack<char>st;

            for(char ch: s) {
                st.push(ch);
                frequency_store[ch - 'a']--;

                while(!st.empty() && smallest_char(frequency_store) >= st.top()) {
                    result += st.top();
                    st.pop();
                }

            }
            while(!st.empty()) {
                result += st.top();
                st.pop();
            }
            return result;
        }
    };