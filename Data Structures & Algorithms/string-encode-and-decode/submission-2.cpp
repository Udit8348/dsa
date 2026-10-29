class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        res.reserve(20000);


        for (auto& s : strs) {
            res += to_string(s.size());
            res += "#";
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        
        int seek = 0; // upper range bound
        int anchor = 0; // lower range bound

        while (seek < s.size()) {
            

            while (s.at(seek) != '#') {
                seek++;
            }

            int len = stoi(s.substr(anchor, seek));
            
            // base + offset
            anchor = seek + 1;
            string temp = s.substr(anchor, len);
            
            // align ptrs directly after current str to deserialize next size
            seek = anchor + len;
            anchor = seek;

            res.push_back(temp);
        }

        return res;

    }
};
