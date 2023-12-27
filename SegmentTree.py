class SegmentTree:
    def __init__(self):
        self.t = []

    def _build(self, arr, v, tl, tr):
        if tl == tr:
            self.t[v] = arr[tl]
        else:
            tm = (tl + tr) // 2
            self._build(arr, v*2, tl, tm)
            self._build(arr, v*2+1, tm+1, tr)
            self.t[v] = self.t[v*2] + self.t[v*2+1]

    def build(self, arr):
        self.t = [None] * 4 * len(arr)
        v = 1
        tl, tr = 0, len(arr) - 1 
        self._build(arr, v, tl, tr)
        
    def sum(self,l,r):
        return self._sum(1,0,len(self.t)//4,l,r)
    
    def _sum(self, v , tl ,tr, l, r):
        if l>r:
            return 0
        if l == tl and r == tr:
            return self.t[v]
        tm = (tl+tr)//2
        return self._sum(2*v,tl, tm, l, min(r,tm)) + self._sum(2*v+1,tm+1,tr, max(l,tm+1),r)
    