class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // depending on sparsity choose a vector (uniformly distributed) since it can be pre-allocated and low cost indexing
        // otherwise unordered_map is good if you dont know the distribution (overhead from dynamic alloc and hashing)

        std::unordered_set<int> lut;
        
        for (auto n : nums) {
            auto [a, unique] = lut.insert(n);
            if (!unique) return true;
        }

        return false;
        
    }
};