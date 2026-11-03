class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid)
            updateTree(2 * node + 1, start, mid, index, val);
        else
            updateTree(2 * node + 2, mid + 1, end, index, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        if (start > right || end < left)
            return 0;

        if (start >= left && end <= right)
            return tree[node];

        int mid = start + (end - start) / 2;

        int a = query(2 * node + 1, start, mid, left, right);
        int b = query(2 * node + 2, mid + 1, end, left, right);

        return a + b;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
