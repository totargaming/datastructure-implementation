import heapq
from typing import NamedTuple
class PriorityQueue(NamedTuple):
    priority: int
    work_item: str
    
class MedianFinder:
    def __init__(self) -> None:
        self.heaps = [], []
        
    def insert(self, num):
        small, large = self.heaps
        heapq.heappush(small, -heapq.heappushpop(large, num))
        if len(large) <len(small):
            heapq.heappush(large, -heapq.heappop(small))
            
    def median(self):
        small,large = self.heaps
        if len(large) > len(small):
            return float(large[0])
        return (large[0]-small[0])/2.0