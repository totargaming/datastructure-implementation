class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0]*(self.n*2)
        self.buildTree(nums)

    def buildTree(self, nums):
        for i in range(self.n):
            self.tree[i+self.n] = nums[i]
        for i in range(self.n-1, 0, -1):
            self.tree[i] = min(self.tree[i*2], self.tree[i*2+1])

    def query(self, i, j):
        i += self.n
        j += self.n
        min_val = float('inf')
        while i <= j:
            if (i % 2 == 1):
                min_val = min(min_val, self.tree[i])
                i += 1
            if (j % 2 == 0):
                min_val = min(min_val, self.tree[j])
                j -= 1
            i //= 2
            j //= 2
        return min_val