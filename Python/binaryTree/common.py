from typing import *

from sympy import N

class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(l:List, index=0) -> TreeNode:
    if not l: return None
    
    if index >= len(l) or l[index] == '#': return None
    
    node = TreeNode(int(l[index]))
    node.left = buildTree(l, 2 * index + 1)
    node.right = buildTree(l, 2 * index + 2)
    return node      
def buildTree1(l:List) -> TreeNode:
    if not l:
        return
    q = []
    root = TreeNode(val=int(l.pop(0)))
    q.append(root)
    while q:
        t = q.pop(0)
        if l:
            if l[0] != '#':
                t.left = TreeNode(val=int(l.pop(0)))
                q.append(t.left)
            else:
                l.pop(0)
        if l:
            if l[0] != '#':
                t.right = TreeNode(val=int(l.pop(0)))
                q.append(t.right)
            else:
                l.pop(0)
    return root

# 二叉树按层序转换为列表
def treeArray(pRoot):
    if not pRoot:
        return []
    resultList = []
    curLayer = [pRoot]
    while curLayer:
        curList = []
        nextLayer = []
        for node in curLayer:
            if node == '.':
                curList.append('.')
            else:
                curList.append(node.val)
                if node.left:
                    nextLayer.append(node.left)
                else:
                    nextLayer.append('.')
                if node.right:
                    nextLayer.append(node.right)
                else:
                    nextLayer.append('.')
        resultList.append(curList)
        curLayer = nextLayer
    return resultList
# 打印为树状图
def toTree4(t):
    n = len(t) - 1
    for i in range(1, n - 1):
        for j in range(2 * i):
            if t[i][j] == '.':
                t[i + 1].insert(j + 1, '.')
                t[i + 1].insert(j + 1, '.')
    result = []
    result.append('       {}       '.format(t[0][0]))
    result.append('    /     \\    ')
    result.append('   {}       {}   '.format(t[1][0], t[1][1]))
    result.append('  / \\     / \\  ')
    result.append(' {}   {}   {}   {} '.format(*t[2]))
    result.append('/ \\ / \\ / \\ / \\')
    result.append(' '.join([str(i) for i in t[3]]))
    for i in result[:2 * n - 1]:
        print(i)
# 深度小于等于3
def toTree3(t):
    n = len(t) - 1
    for i in range(1, n - 1):
        for j in range(2 * i):
            if t[i][j] == '.':
                t[i + 1].insert(j + 1, '.')
                t[i + 1].insert(j + 1, '.')
    result = []
    result.append('   {}   '.format(t[0][0]))
    result.append('  / \\  ')
    result.append(' {}   {} '.format(t[1][0], t[1][1]))
    result.append('/ \\ / \\')
    result.append('{} {} {} {}'.format(*t[2]))
    for i in result[:2 * n - 1]:
        print(i)
# 将上两个函数合并
def printTree(tree):
    a = treeArray(tree)
    if len(a) < 5:
        toTree3(a)
    else:
        toTree4(a)


# test
if __name__ == "__main__":
    root = buildTree(['1','2','3','4','#','5','6'])
    printTree(root)
    root1 = buildTree1(['1','2','3','4','#','5','6'])
    printTree(root1)