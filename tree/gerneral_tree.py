def root(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_leaf(tree):
    return not branches(tree)

def degree(tree):
    return len(branches(tree))

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def tree(root , branches = []):
    for branch in branches:
        assert is_tree(branch), 'branches must be tree'
    return [root] + list(branches)


def is_equal(tree_a, tree_b):

    if(root(tree_a) != root(tree_b)):
        return False

    tree_a_branches = branches(tree_a)
    tree_b_branches = branches(tree_b)
    number_of_tree_a_branches = len(branches(tree_a_branches))
    number_of_tree_b_branches = len(branches(tree_b_branches))

    if number_of_tree_a_branches != number_of_tree_b_branches:
        return False

    for i in range(1,number_of_tree_a_branches + 1): # index 0 is root of tree
        if(not is_equal(tree_a_branches[i], tree_b_branches[i])):
            return False
    return True

def count_leaves(tree):
    assert is_tree(tree)
    if is_leaf(tree):
        return 1
    else:
        branches_count = [count_leaves(branch) for branch in branches(tree)]
    return sum(branches_count)

def count_node(tree):
    assert is_tree(tree), "input is not a tree"
    branches_count = [count_node(branch) for branch in branches(tree)]
    return 1 + sum(branches_count)

def height (tree):
    assert is_tree(tree), "input is not a tree"
    branches_count = [height (branch) for branch in branches(tree)]

    if branches_count : # if branches_counts has at least one element
        return 1 + max(branches_count) # root node + branches node
    else:
        return 1;


def apply_to_node(map_fn, tree):
    assert is_tree(tree), "input is not a tree"
    map_root = [map_fn(root(tree))]
    map_branches = [apply_to_node(map_fn, branch) for branch in branches(tree)]
    return map_root + map_branches

def apply_to_node2(map_fn, tree):
    if(type(tree) == list):
        return [apply_to_node2(map_fn, node) for node in tree]
    else:
        return map_fn(tree)

def apply_to_leaves(map_fn, tree):
    assert is_tree(tree), "input is not a tree"
    if(is_leaf(tree)):
        return map_fn(root(tree))
    else:
        original_root = [root(tree)]
        map_branches = [apply_to_node(map_fn, branch) for branch in branches(tree)]
        return original_root + map_branches


def print_tree(tree, indent = 0):
    if(is_tree(tree)):
        print(" " * indent + str(root(tree)))
        for branch in tree:
            print_tree(branch, indent + 1)


def copy_tree(tree):
    assert is_tree(tree), "input is not a tree"
    return [root(tree)] + [copy_tree(branch) for branch in branches(tree)]

def search(tree ,x):
    assert is_tree(tree), "input is not a tree"
    if root(tree) == x:
        return 1
    else:
        branch_count = [search(branch, x) for branch in branches(tree)]
        branch_clear_false = [ branch for branch in branch_count if branch is not False]
        if not branch_clear_false: # if branch_clear_false is empty
            return False
        return 1 + min(branch_clear_false)

def find_path(tree, x):
    assert is_tree(tree), "input is not a tree"
    if root(tree) == x:
        return [x]
    else:
        bra = [find_path(branch, x) for branch in branches(tree)]
        for path in bra:
            if path:
                return [root(tree)] + path
    return False
