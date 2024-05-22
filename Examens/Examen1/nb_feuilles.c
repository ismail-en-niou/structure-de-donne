int nb_feuilles(AB *x) {
    // If the tree is empty, return 0
    if (x == NULL)
        return 0;
    // If the current node is a leaf, return 1
    if (x->left == NULL && x->right == NULL)
        return 1;
    // Recursively count the leaf nodes in the left and right subtrees
    return nb_feuilles(x->left) + nb_feuilles(x->right);
}