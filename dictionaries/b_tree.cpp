//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#include "b_tree.h"
#include <queue>
#include <iostream>

namespace dictionaries {

// constructor
BTree::BTree() {
    root = nullptr;
}

// search for class object
BTree::node *BTree::search(int v) {
    return searchR(root, v);
}

// searches for v in BTree recursively
BTree::node *BTree::searchR(node *root, int v) {
    if (!root)
        return nullptr;

    // sentinel
    root->key[0] = -100000000; // minimal value to stop the loop
    int i = root->k; // number of keys on the given page

    while (root->key[i] > v)
        i--;

    // if v on this page, return
    if (root->key[i] == v)
        return root;

    // if not, search on the lower level
    return searchR(root->next[i],v);
}

// insert to BTree
void BTree::insert(int v) {
    // empty tree, insert to root
    if (root == nullptr) {
        // initialize new node
        root = new node;
        root->k = 1;
        root->key[1] = v;
        for(int i = 0; i <= 2*M; i++)
            root->next[i] = nullptr;
        root->key[0] = -100000000;
        return;
    }

    // check if v exists
    if (search(v))
        return;

    // check if root is full
    if (root->k == 2 * M) {
        // create new root
        node *s = new node;
        s->k = 0;
        s->next[0] = root;
        for(int i = 1; i <= 2*M; i++)
            s->next[i] = nullptr;

        // split old root (0-child of s)
        split(s, 0);

        // insert v value to leaf of tree with s root
        insertR(s, v);

        // update root to the new value
        root = s;
    }
    else {
        // root isn't full, insert recursively
        insertR(root, v);
    }
}

// split i-child of root page (when i-child is full)
void BTree::split(node *root, int i) {
    // full child
    node *child = root->next[i];
    // new child
    node *newChild = new node;
    for(int i = 0; i <= 2*M; i++)
        newChild->next[i] = nullptr;

    // half of the full child keys will go to new child
    newChild->k = M;
    for (int j = 1; j <= M; j++) {
        newChild->key[j] = child->key[j + M];
    }

    // if child is not a leaf, we also need to copy pointers to children
    if (child->next[0] != nullptr) {
        for (int j = 0; j <= M; j++) {
            newChild->next[j] = child->next[j + M];
        }
    }

    // update child leaf, M keys went to new page, 1 key will go to parent
    child->k = M - 1;

    // update parents pointers and add pointer to new child
    for (int j = root->k; j >= i + 1; j--) {
        root->next[j + 1] = root->next[j];
    }
    root->next[i + 1] = newChild;

    // update parent keys and insert key from full child
    for (int j = root->k; j >= i + 1; j--) {
        root->key[j + 1] = root->key[j];
    }

    // insert middle key from child to parent
    root->key[i + 1] = child->key[M];
    root->k += 1;
}

// insert recursively to not full page
void BTree::insertR(node *root, int v) {
    // start from the end
    int i = root->k;

    // check if page is a leaf
    if (root->next[0] == nullptr) {
        // if page is a leaf, we just insert in correct place
        // we assume that leaf is not full
        // this function takes care of that in the 'else' statement below
        while (i >= 1 && v < root->key[i]) {
            root->key[i + 1] = root->key[i];
            i--;
        }

        // insert if v doesnt exist
        root->key[i + 1] = v;
        root->k += 1;
        return;
    }

    // if page isn't a leaf we search for child where v should be inserted
    while (i >= 1 && v < root->key[i]) {
        i--;
    }

    // check if child is full
    if (root->next[i]->k == 2 * M) {
        // split child
        split(root, i);

        // one of the keys from child was inserted to root page
        // we have to check if v is smaller or bigger than this new element
        if (v > root->key[i + 1]) {
            i++;
        }
    }

    // insert recursively to proper child
    insertR(root->next[i], v);
}

// print level order for class object
void BTree::printLevelOrder() {
    printLevelOrderR(root);
}

// print level order recursive method
void BTree::printLevelOrderR(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    int n = 0;
    while (!q.empty()) {
        n++;
        node *p = q.front();
        q.pop();

        if (p->next[0])
            q.push(p->next[0]);

        std::cout<<"PAGE "<<n<<" [k="<<p->k<<"]: ";
        for (int i = 1; i <= p->k; i++) {
            std::cout<<p->key[i]<<" ";
            if (p->next[i])
                q.push(p->next[i]);
        }
        std::cout<<std::endl;
    }
}

// borrows key from the left neighboring page
void BTree::borrowFromPrev(node *root, int idx) {
    node *child = root->next[idx];
    node *sibling = root->next[idx - 1];

    // move keys to the right in the child page
    for (int i = child->k; i >= 1; --i)
        child->key[i + 1] = child->key[i];

    // if it has children, move pointers
    if (child->next[0] != nullptr) {
        for (int i = child->k; i >= 0; --i)
            child->next[i + 1] = child->next[i];
    }

    // get key from parent
    child->key[1] = root->key[idx];

    // last key from sibling goes to parent to replace borrowed key
    root->key[idx] = sibling->key[sibling->k];

    // move child from sibling to child
    if (child->next[0] != nullptr)
        child->next[0] = sibling->next[sibling->k];

    // update k in child and siblingą
    child->k += 1;
    sibling->k -= 1;
}

// borrows key from the right neighboring page
void BTree::borrowFromNext(node *root, int idx) {
    node *child = root->next[idx];
    node *sibling = root->next[idx + 1];

    // key from parent goes to the end of child
    child->key[child->k + 1] = root->key[idx + 1];

    // move child from sibling to child
    if (child->next[0] != nullptr)
        child->next[child->k + 1] = sibling->next[0];

    // first key from sibling goes to parent
    root->key[idx + 1] = sibling->key[1];

    // move other keys to the left in the sibling page
    for (int i = 1; i < sibling->k; ++i)
        sibling->key[i] = sibling->key[i + 1];

    // if sibling has children, move pointers also
    if (sibling->next[0] != nullptr) {
        for (int i = 0; i < sibling->k; ++i)
            sibling->next[i] = sibling->next[i + 1];
    }

    // update k in child and sibling
    child->k += 1;
    sibling->k -= 1;
}

// merges two pages together (page idx with idx + 1)
void BTree::merge(node *root, int idx) {
    node *child = root->next[idx];
    node *sibling = root->next[idx + 1];

    // insert key from parent (child has only M - 1 keys)
    child->key[M] = root->key[idx + 1];

    // copy keys from sibling to child
    for (int i = 0; i < sibling->k; ++i)
        child->key[i + M + 1] = sibling->key[i + 1];

    // copy pointers from sibling to child
    if (child->next[0] != nullptr) {
        for (int i = 0; i <= sibling->k; ++i)
            child->next[i + M] = sibling->next[i];
    }

    // move keys in parent to cover hole from borrowed key
    for (int i = idx + 1; i < root->k; ++i)
        root->key[i] = root->key[i + 1];

    // move pointers in parent
    for (int i = idx + 2; i <= root->k; ++i)
        root->next[i - 1] = root->next[i];

    // update k in child and parent
    child->k += sibling->k + 1;
    root->k--;

    // free memory after sibling
    delete sibling;
}

// easiest case, just removes element from leaf
void BTree::removeFromLeaf(node *leaf, int idx) {
    // move elements to the left
    for (int i = idx + 1; i <= leaf->k; ++i)
        leaf->key[i - 1] = leaf->key[i];

    // udpate k
    leaf->k--;
}

// removes element from non leaf page
void BTree::removeFromNonLeaf(node *root, int idx) {
    int k = root->key[idx];

    // check if left child has enough keys (k > M)
    if (root->next[idx - 1]->k >= M) {
        int pred = getPred(root, idx);
        root->key[idx] = pred;
        // delete the pred key from right subtree recursively
        deleteVR(root->next[idx - 1], pred);
    }
    // check if right child has enough keys
    else if (root->next[idx]->k >= M) {
        int succ = getSucc(root, idx);
        root->key[idx] = succ;
        // delete the succ key from the left subtree recursively
        deleteVR(root->next[idx], succ);
    }
    // if both don't have enough keys, we merge them
    else {
        // merge right child with left child
        merge(root, idx - 1);
        // delete k from the new page
        deleteVR(root->next[idx - 1], k);
    }
}

// Finds the biggest element in the left subtree
int BTree::getPred(node *root, int idx) {
    node *curr = root->next[idx - 1];
    while (curr->next[0] != nullptr)
        curr = curr->next[curr->k];
    return curr->key[curr->k];
}

// Finds the smallest element in the right subtree
int BTree::getSucc(node *root, int idx) {
    node *curr = root->next[idx];
    while (curr->next[0] != nullptr)
        curr = curr->next[0];
    return curr->key[1];
}

// Repairs page with not enough elements
void BTree::fill(node *root, int idx) {
    // we try to borrow from left sibling page
    if (idx != 0 && root->next[idx - 1]->k >= M)
        borrowFromPrev(root, idx);
    // we try to borrow from right sibling page
    else if (idx != root->k && root->next[idx + 1]->k >= M)
        borrowFromNext(root, idx);
    // if we can't borrow, we need to merge pages
    else {
        // if not last page, merge with right sibling
        if (idx != root->k)
            merge(root, idx);
        // else merge with left sibling
        else
            merge(root, idx - 1);
    }
}

// deletes element v recursively and decides how to balance pages of the tree
void BTree::deleteVR(node *root, int v) {
    // we search for the v element
    int idx = 1;
    while (idx <= root->k && root->key[idx] < v)
        idx++;

    // check if v is in this page
    if (idx <= root->k && root->key[idx] == v) {
        // check if page is a leaf
        if (root->next[0] == nullptr)
            // remove from leaf case
            removeFromLeaf(root, idx);
        else
            // remove from non leaf case
            removeFromNonLeaf(root, idx);
    }

    // if v is not in this page, we go deeper in the tree
    else {
        // if this page is a leaf, element wasn't found
        if (root->next[0] == nullptr) {
            return;
        }

        // we go to the left child or last child
        int childIdx = idx - 1;
        // flag if we delete from the last child
        bool flag = (childIdx == root->k);

        // check if child has enough keys, if not repair it
        if (root->next[childIdx]->k < M)
            fill(root, childIdx);

        // check if merge happened and the childIdx now points to non existing child
        if (flag && childIdx > root->k)
            deleteVR(root->next[childIdx - 1], v);
        else
            deleteVR(root->next[childIdx], v);
    }
}

// deletes element
void BTree::deleteV(int v) {
    // empty tree
    if (!root) {
        return;
    }

    // recursive function call
    deleteVR(root, v);

    // if root is empty after the operation it means it was merged
    // now first child becomes new root of the B-Tree
    if (root->k == 0) {
        node *tmp = root;
        if (root->next[0] != nullptr)
            root = root->next[0];
        else
            root = nullptr;

        delete tmp;
    }
}

} // dictionaries