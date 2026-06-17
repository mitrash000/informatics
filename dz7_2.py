#coding=windows-1251
def anagramm(tree):
    def tre(left, right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        return (left['val'] == right['val'] and
                tre(left.get('left'), right.get('right')) and
                tre(left.get('right'), right.get('left')))
    if tree is None:
        return True
    return tre(tree.get('left'), tree.get('right'))
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


def build_tree_from_string(s):
    """Строит дерево из строки вида: 1 2 2 3 4 4 3"""
    if not s or s.strip() == '':
        return None
    parts = s.strip().split()
    if parts[0] == '-':
        return None
    nodes = []
    for val in parts:
        if val == '-':
            nodes.append(None)
        else:
            try:
                if val.isdigit() or (val[0] == '-' and val[1:].isdigit()):
                    val = int(val)
                elif val.replace('.', '').isdigit():
                    val = float(val)
            except:
                pass
            nodes.append({'val': val, 'left': None, 'right': None})
    for i in range(len(nodes)):
        if nodes[i] is not None:
            left_idx = 2 * i + 1
            right_idx = 2 * i + 2
            if left_idx < len(nodes):
                nodes[i]['left'] = nodes[left_idx]
            if right_idx < len(nodes):
                nodes[i]['right'] = nodes[right_idx]
    
    return nodes[0] if nodes else None

s=(str(input("Введите девево в виде строки, где первый элемент это корень дерева, следующие 2 элемента это узлы отходящие от корня и находящиеся на втрой строке дерева, записывайте их слева на право. Слеледующие 4 элемента это узлы третей строки и так далее. Для пропуска узла при его отсудствии вбить вместо него -. Все строке записывается слева на право.")))

s=build_tree_from_string(s)

print(anagramm(s))
