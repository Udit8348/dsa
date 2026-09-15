class Solution {
public:
    // helper function to generate upper alpha letter using a numberical offset from 'A'
    char get_alpha(int offset) {
        return 'A' + offset; // [0,25] are valid offsets
    }
    
    string convertToTitle(int columnNumber) {
        std::string res = "";
        
        while (columnNumber > 0) {
            columnNumber -= 1;
            int remainder = columnNumber % 26;
            res = get_alpha(remainder) + res;
            columnNumber /= 26;
        }

        return res;
    }
};