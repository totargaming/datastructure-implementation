class Node:
    def __init__(self,key = 0, left = None, right = None) -> None:
        self.key = key
        self.left = left
        self.right = right

class BST:
    def __init__(self) -> None:
        self.root = None
        self.min,self.max = None, None

    def insert(self,key):
        new_node = Node(key)
        if not self.root:
            self.root = new_node
            self.min = self.max = new_node
        else:
            self.root = self._insert(self.root,new_node)
        if key < self.min.key:
            self.min = new_node
        elif key>self.max.key:
            self.max = new_node
            
            
    def _insert(self,root,node):
        if not root:
            return node
        
        if node.key<root.key:
            root.left = self._insert(root.left,node)
        
        if node.key>root.key:
            root.right = self._insert(root.right,node)
            
        return root
    def _find(self,root,key):
        if not root or root.key == key:
            return root
        return self._find(root.left,key) if key < root.key else self._find(root.right,key)
    def delete(self,key):
        node = self._find(self.root,key)
        self.root = self._delete(self.root,node)
        
    def _delete(self,root,node):
        if not root:
            return root
        if node.key <root.key:
            root.left = self._delete(root.left,node)
        
        elif node.key >root.key:
            root.right = self._delete(root.right,node)
            
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
        temp = self._find_min(node.right)
        root.key = temp.key
        node.right = self._delete(node.right,temp)
        return node
    
    def _find_min(self, node):
        current = node
        while current.left:
            current = current.left
        return current
    
    def _find_max(self, node):
        current = node
        while current.right:
            current = current.right
        return current
    
    def get_min(self):
        return self.min.key if self.min else None
    
    def get_max(self):
        return self.max.key if self.max else None
    