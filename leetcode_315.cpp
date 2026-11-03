class Solution {
public:
    vector<int> count;
    vector<pair<int, int>> arr;

    void mergeSort(int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;
        int smaller = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                smaller++;
                j++;
            }
            else {
                count[arr[i].second] += smaller;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            count[arr[i].second] += smaller;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        count.assign(n, 0);
        arr.clear();

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(0, n - 1);

        return count;
    }
};
