from math import pow

class BinaryTree:
    parent = None
    leftChild = None
    rightChild = None
    key = None

    def __init__(self, key, parent = None):
        self.key = key
        self.leftChild = None
        self.rightChild = None
        self.parent = parent





    @property
    def degree(self):
        count = 0
        if self.leftChild != None:
            count += 1
        if self.rightChild != None:
            count += 1
        return count


    @classmethod
    def build_from_list(cls, tree):
        def helper(tree, parent):
            if tree == [] or type(tree) != list or tree == None:
                return ;
            branches = tree[1:]
            BT = BinaryTree(tree[0], parent)

            if len(branches) == 1 and branches != []:
                BT.leftChild = helper(tree[1], BT)
            if len(branches) == 2:
                if branches[0] == [] and branches[1] != []:
                    BT.rightChild = helper(tree[2], BT)
                if branches[0] != [] and branches[1] == []:
                    BT.leftChild = helper(tree[1])
                if branches[0] != [] and branches[1] != []:
                    BT.leftChild = helper(tree[1], BT)
                    BT.rightChild = helper(tree[2], BT)
            return BT
        return helper(tree, None)


class BT_Operation:


    @classmethod
    def is_leaf(cls, node):
        if node.leftChild == None and node.rightChild == None:
            return True
        else:
            return False


    @classmethod
    def degree_of_tree(cls, node):
        if node == None:
            return 0

        return max([node.degree, cls.degree_of_tree(node.leftChild), cls.degree_of_tree(node.rightChild)])

    @classmethod
    def depth(cls, node):
        if node == None:
            return 0

        return 1 + max(cls.depth(node.leftChild), cls.depth(node.rightChild))

    @classmethod
    def preorder_traversal(cls, node):
        if node != None:
            print(node.key, end='')
            cls.preorder_traversal(node.leftChild)
            cls.preorder_traversal(node.rightChild)

    @classmethod
    def swap_binary_tree(cls, node):
        if node == None:
            return
        node.leftChild, node.rightChild = node.rightChild, node.leftChild

        cls.swap_binary_tree(node.leftChild)
        cls.swap_binary_tree(node.rightChild)

    @classmethod
    def convert_to_list(cls, node):
        if node == None:
            return []
        tree_list = []
        tree_list.append(node.key)
        if node.leftChild == None and node.rightChild != None:
            tree_list.append([])
            tree_list.append(cls.convert_to_list(node.rightChild))

        if node.leftChild != None and node.rightChild == None:
            tree_list.append(cls.convert_to_list(node.leftChild))

        if node.leftChild != None and node.rightChild != None:
            tree_list.append(cls.convert_to_list(node.leftChild))
            tree_list.append(cls.convert_to_list(node.rightChild))

        return tree_list

    @classmethod
    def count_leaves(cls, node):
        if node == None:
            return 0
        if cls.is_leaf(node):
            return 1
        return cls.count_leaves(node.leftChild) + cls.count_leaves(node.rightChild)


    @classmethod
    def count_node(cls, node):
        if node == None:
            return 0
        return 1 + cls.count_node(node.leftChild) + cls.count_node(node.rightChild)


    @classmethod
    def is_equal(cls, nodeA, nodeB):
        return (nodeA == None and nodeB == None) or ((nodeA != None) and (nodeB != None) and (nodeA.key == nodeB.key) and cls.is_equal(nodeA.leftChild, nodeB.leftChild) and cls.is_equal(nodeA.rightChild, nodeB.rightChild))


    @classmethod
    def is_full_BT(cls, node):
        return (pow(2, cls.depth(node)) - 1) == cls.count_node(node)

    @classmethod
    def is_strict_BT(cls, node):
        if cls.is_leaf(node):
            return True
        return (node.degree == 2) and cls.is_strict_BT(node.leftChild) and cls.is_strict_BT(node.rightChild)

    @classmethod
    def is_complete_BT(cls, node):
        pass

    @classmethod
    def apply_to_node(cls, map_fn, node):
        if node != None:
            node.key = map_fn(node.key)
            cls.apply_to_node(map_fn, node.leftChild)
            cls.apply_to_node(map_fn, node.rightChild)

    @classmethod
    def search(cls, node, x):
        # if x in tree , than return how many step can find x from root, else return False
        if node == None:
            return False

        if node.key == x:
            return 1
        else:
            left_search = cls.search(node.leftChild, x)
            right_search = cls.search(node.rightChild, x)

            if(left_search != False and right_search != False):
                return 1 + min(left_search, right_search)
            if(left_search == False and right_search != False):
                return 1 + right_search
            if(left_search != False and right_search == False):
                return 1 + left_search
            if(left_search == False and right_search == False):
                return False

    @classmethod
    def find_path(cls, node, x):
        if node == None:
            return

        if node.key == x:
            return [x]
        else:
            left_path = cls.find_path(node.leftChild, x)
            right_path = cls.find_path(node.rightChild, x)

            if left_path:
                return [node.key] + left_path
            if right_path:
                return [node.key] + right_path

        return False

    @classmethod
    def flatten_list(cls, node):
        pass
