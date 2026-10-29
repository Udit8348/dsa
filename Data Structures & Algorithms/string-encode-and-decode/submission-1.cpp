class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        res.reserve(20000);


        for (auto s : strs) {
            int sz = s.size();
            string delim = "#";
            string temp;
            temp += to_string(sz);
            temp += delim;
            temp += s;
            
            res += temp;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        
        int seek = 0; // upper range bound
        int anchor = 0; // lower range bound

        while (seek < s.size()) {
            anchor = seek;

            while (s.at(seek) != '#') {
                seek++;
            }

            int len = stoi(s.substr(anchor, seek));
            
            // one past detected '#'
            anchor = seek + 1;

            // one past str's buffer
            seek = anchor + len;

            // cout << seek << endl;
            // cout << anchor << endl;

            string temp = s.substr(anchor, seek-anchor);
            // cout << temp << endl;

            res.push_back(temp);
        }

        return res;

    }
};
