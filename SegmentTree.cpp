class SegmentTree{
    public:
    vector<int>seg;
    int n;
    
    void build(const vi &nums, int i, int l, int r){
        if(l == r){
            seg[i] = nums[r];
            return;
        }
        
        int mid = (l + r) >> 1;
        build(nums, 2 * i + 1, l, mid);
        build(nums, 2 * i + 2, mid + 1, r);
        
        seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]);
    }
    
    void update(int idx, int val, int i, int l, int r){
        if(l == r) {seg[i] = val; return;}
        
        int mid = (l + r) >> 1;
        if(idx <= mid)//left child
        {
            update(idx, val, 2 * i + 1, l, mid);
        }else//right child
        {
            update(idx, val, 2 * i + 2, mid + 1, r);
        }
        
        seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]);
    }
    
    int query(int start, int end, int i, int l, int r){
        if(l > end or r < start) return 0;
        
        if(l >= start and r <= end){
            return seg[i];
        }
        int mid = (l + r) >> 1;
        
        return query(start, end, 2 * i + 1, l, mid) + 
                query(start, end, 2 * i + 2, mid + 1, r);
    }
    
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n); 
        build(arr, 0, 0, n - 1);
    }
 
    
    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }
 
    
    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};
