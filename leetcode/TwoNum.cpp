class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> vpMap;
        vector<int> result;
        
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            vpMap[numbers[i]] = i;
        }
        
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            int toFind = target - numbers[i];
            unordered_map<int, int>::iterator iter = vpMap.find(toFind);
            if (iter != vpMap.end())
            {
                result.push_back(i + 1);
                result.push_back(iter->second + 1);
                break;
            }
        }
        return result;
    }
};
