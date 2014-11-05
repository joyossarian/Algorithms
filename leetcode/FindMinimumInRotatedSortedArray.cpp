class Solution {
public:
    int findMinHelper(vector<int> &num, int s, int e)
    {
        if ( s == e )
            return num[s];
        int mid = s / 2 + e / 2;
        bool leftOrder = num[s] <= num[mid];
        bool rightOrder = num[mid] <= num[e];
        if (leftOrder && rightOrder)
        {
            return num[s];
        }
        else if (leftOrder)
        {
            return std::min(num[s], findMinHelper(num, mid + 1, e));
        }
        else 
        {
            return std::min(num[mid], findMinHelper(num, s, mid - 1));
        }
    }
    
    int findMin(vector<int> &num) {
        int size = num.size();
        return findMinHelper(num, 0, size - 1);
    }
};
