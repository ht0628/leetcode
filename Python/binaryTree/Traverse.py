from common import *

class Solution:
    #剑指 Offer 07. 重建二叉树
    ##1.切片法: 简单清晰
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder: return None
        #前序遍历的第一个元素就是根节点
        node = TreeNode(preorder[0])
        #在中序遍历中找到根节点的idx来划分左右子树
        idx = inorder.index(node.val)
        #将左树看成一个新树去递归解
        node.left = self.buildTree(preorder[1:idx+1], inorder[0:idx])
        #将右树看成一个新树去递归解
        node.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
        return node

    #102.二叉树的层序遍历
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []

        res = []
        q = deque([root])
        while q:
            n = len(q)
            tmp = []
            for _ in range(n):
                node = q.popleft()
                tmp.append(node.val)
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            res.append(tmp)
        return res

s = Solution()
root = s.buildTree([3,9,20,15,7],[9,3,15,20,7])
printTree(root)
