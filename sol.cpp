class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mx = *max_element(arr2.begin(), arr2.end());
        mx = max(mx, *max_element(arr1.begin(), arr1.end()));
        int order[mx+1];
        memset(order, -1, sizeof(order));
        for (int i = 0; i < (int) arr2.size(); i++) {
            order[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end());
        vector<int> new_arr;
        for (int& x : arr1) {
            if (order[x] != -1) {
                new_arr.push_back(x);
            }
        }
        sort(new_arr.begin(), new_arr.end(), [&](const int& x, const int& y) {
            return order[x] < order[y];
        });
        for (int& x : arr1) {
            if (order[x] == -1) {
                new_arr.push_back(x);
            }
        }
        return new_arr;
    }
};
