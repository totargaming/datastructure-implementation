class Node: 
    def __init__(self,val = 0, left =None, right = None) -> None:
        self.val = val 
        self.left = left
        self.right = right 
        
def sorted_array_to_bst(nodes):
    if not nodes:
        return None 
    mid = len(nodes)//2
    node = Node(node[mid])
    node.left = sorted_array_to_bst(node[:mid])
    node.right = sorted_array_to_bst(node[mid+1:])
    
    return node

def in_order_traversal(root,nodes = []):
    if root:
        in_order_traversal(root.left,nodes)
        nodes.append(root.val)
        in_order_traversal(root.right,nodes)
    return nodes

def bst_to_balanced_bst(root):
    node = in_order_traversal(root)
    return sorted_array_to_bst(node)
        