#coding=windows-1251
def anagramm(tree):
    def tree(left, right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        return (left['val'] == right['val'] and
                tree(left.get('left'), right.get('right')) and
                tree(left.get('right'), right.get('left')))
    if tree is None:
        return True
    return tree(tree.get('left'), tree.get('right'))
#Ïðîâåðêà:
tree1 = {'val': 1,
         'left': {'val': 2,'left': {'val': 3, 'left': None, 'right': None},'right': {'val': 4, 'left': None, 'right': None}},
         'right': {'val': 2,'left': {'val': 4, 'left': None, 'right': None},'right': {'val': 3, 'left': None, 'right': None}}}
tree2 = {}
tree3 = None
tree4 = {'val': 1,
         'left': {'val': 3, 'left': 3, 'right': None},
         'right': {'val': 3, 'left': 3, 'right': None}}
tree5 = {'val': 1,
         'left': {'val': 2,'left': {'val': 3, 'left': None, 'right': None},'right': {'val': 4, 'left': None, 'right': None}},
         'right': {'val': 2,'left': {'val': 4, 'left': None, 'right': None},'right': {'val': 4, 'left': None, 'right': None}}}
print(anagramm(tree1))
print(anagramm(tree2))
print(anagramm(tree3))
print(anagramm(tree4))
print(anagramm(tree5))
