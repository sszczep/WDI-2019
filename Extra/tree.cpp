#include <iostream>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
};

void print(node *proot) {
    if (proot == nullptr) {
        return;
    }
    cout << proot->val << endl;
    print(proot->left);
    print(proot->right);
}

int count(node *proot) {
    if (proot == nullptr) {
        return 0;
    }
    return 1 + count(proot->left) + count(proot->right);
}

int height(node *proot) {
    if (proot == nullptr) {
        return 0;
    }
    return 1 + max(height(proot->left), height(proot->right));
}

int leaves(node *proot) {
    if (proot == nullptr) {
        return 0;
    }
    if (proot->left == nullptr and proot->right == nullptr) { //lub (proot->left == proot->right)
        return 1;
    }
    return leaves(proot->left) + leaves(proot->right);
}

int at_depth(node *proot, int depth) {
    if (proot == nullptr) {
        return 0;
    }
    if (depth == 0) {
        return 1;
    }
    return at_depth(proot->left, depth - 1) + at_depth(proot->right, depth - 1);
}

bool tree_search(node *proot, int n) {
    if (proot == nullptr) {
        return false;
    }
    if (proot->val == n) {
        return true;
    }
    return tree_search(proot->left, n) or tree_search(proot->right, n);
}

bool bst_search(node *proot, int n) {
    if (proot == nullptr) {
        return false;
    }
    if (proot->val == n) {
        return true;
    }
    return proot->val > n ? bst_search(proot->left, n) : bst_search(proot->right, n);
}

struct word_node {
    string w;
    int wCount;
    word_node *left;
    word_node *right;
};

void insert(word_node *&tree, string word) {
    if (tree == nullptr) {
        tree = new word_node;
        tree->w = word;
        tree->wCount = 1;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else {
        if (tree->w == word) {
            tree->wCount;
        }
        else if (tree->w > word) {
            insert(tree->left, word);
        }
        else {
            insert(tree->right, word);
        }
    }
}