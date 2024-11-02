class DSU {
private:
    vector<int> parent, rank, setSize;

public:
    // Constructor to initialize DSU with 'n' elements
    DSU(int n) {
        parent.resize(n);
        setSize.resize(n, 1);
        rank.resize(n, 0); // Initialize rank to 0 for each element
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function by rank
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) { // Only unite if roots are different
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                setSize[rootY] += setSize[rootX];
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                setSize[rootX] += setSize[rootY];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                setSize[rootX] += setSize[rootY];
            }
        }
    }

    // Check if two elements are in the same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return setSize[find(x)];
    }
};
