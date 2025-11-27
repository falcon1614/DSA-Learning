#include <iostream>
#include <vector>
#include <algorithm>

template <typename T, int M>
class BTreeNode {
public:
    bool leaf;
    std::vector<T> keys;
    std::vector<BTreeNode<T, M>*> children;

    BTreeNode(bool leaf1) : leaf(leaf1) {}

    int findKey(const T& k) {
        return std::lower_bound(keys.begin(), keys.end(), k) - keys.begin();
    }

    void insertNonFull(const T& k) {
        int i = keys.size() - 1;
        if (leaf) {
            keys.push_back(T());
            while (i >= 0 && k < keys[i]) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && k < keys[i])
                i--;
            i++;
            if (children[i]->keys.size() == 2 * M - 1) {
                splitChild(i, children[i]);
                if (k > keys[i])
                    i++;
            }
            children[i]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode<T, M>* y) {
        BTreeNode<T, M>* z = new BTreeNode<T, M>(y->leaf);
        z->keys.resize(M - 1);
        z->children.resize(M);
        for (int j = 0; j < M - 1; j++)
            z->keys[j] = y->keys[j + M];
        if (!y->leaf) {
            for (int j = 0; j < M; j++)
                z->children[j] = y->children[j + M];
            y->children.resize(M);
        }
        y->keys.resize(M - 1);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[M - 1]);
    }
};

template <typename T, int M>
class BTree {
public:
    BTreeNode<T, M>* root;

    BTree() : root(new BTreeNode<T, M>(true)) {}

    void insert(const T& k) {
        if (root->keys.size() == 2 * M - 1) {
            BTreeNode<T, M>* s = new BTreeNode<T, M>(false);
            s->children.push_back(root);
            splitRoot(s);
            root = s;
        }
        root->insertNonFull(k);
    }
    
    void splitRoot(BTreeNode<T, M>* s) {
        s->splitChild(0, s->children[0]);
    }

    void traverse(BTreeNode<T,M>* node) {
        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (node->leaf == false)
                traverse(node->children[i]);
            std::cout << " " << node->keys[i];
        }
        if (node->leaf == false)
            traverse(node->children[i]);
    }
    
    void traverse() {
        traverse(root);
    }
};