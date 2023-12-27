import heapq
def best_fit(weights):
    bins = [ ]
    for w in weights:
        if bins and bins[0] >= w:
            leftover = heapq.heappop(bins) - w
            heapq.heappush(bins, leftover)
        else: heapq.heappush(bins, 1-w)
    return len(bins)
def worst_fit(weights):
    bins = []
    for w in weights:
        if bins and -bins[0] >= w:
            leftover = -heapq.heappop(bins) -w
            heapq.heappush(bins, -leftover)
        else: heapq.heappush(bins, -(1-w))
        
    return len(bins)