#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// create a tree given a vector of input elements
// returns root of tree
TreeNode *createTree(vector<int> input) {
  queue<TreeNode *> nodes;
  TreeNode *node, *parent, *root;

  if (input.size() == 0) {
    return nullptr;
  }

  // First element of input vector will always be the root node
  root = new TreeNode(input[0]);

  if (input.size() == 1) {
    return root;
  }

  parent = root;
  bool isLeftFilled = false;

  for (long unsigned int i = 1; i < input.size(); i++) {
    // cout << input[i] << ": ";
    if (input[i] != NULL) {
      node = new TreeNode(input[i]);
      // add node to queue
      nodes.push(node);
      if (!isLeftFilled) {
        parent->left = node;
        // cout << "adding " << node->val << " to left of " << parent->val << endl;
        isLeftFilled = true;
      } else {
        parent->right = node;
        // cout << "adding " << node->val << " to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
      // cout << "adding " << node->val << " to " << parent->val << endl;
    } else {
      if (!isLeftFilled) {
        parent->left = nullptr;
        isLeftFilled = true;
        // cout << "adding null to left of " << parent->val << endl;
      } else {
        parent->right = nullptr;
        // cout << "adding null to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
    }
  }

  return root;
}

void printTree(TreeNode *root) {
  TreeNode *node;
  queue<TreeNode *> q;

  if (root == nullptr)
    return;

  // Root node does not have any child nodes
  if ((root->left == nullptr) && (root->right == nullptr)) {
    cout << root->val << endl;
    return;
  }

  q.push(root);

  while (!q.empty()) {
    if (q.front() == nullptr) {
      cout << "NULL, ";

    } else {
      node = q.front();
      cout << node->val << ", ";

      q.push(node->left);

      q.push(node->right);
    }
    q.pop();
  }

  cout << endl;
}

// Recursive algorithm
// Runtime 0 ms Beats 100%
// Memory 10.1 MB Beats 51.63%
bool isSameTree(TreeNode *p, TreeNode *q) {
  if ((p == nullptr) && (q == nullptr))
    return true;

  if (((p == nullptr) && (q != nullptr)) || ((p != nullptr) && (q == nullptr))) {
    return false;
  }

  if (p->val != q->val)
    return false;

  return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main(int argc, char const *argv[]) {
  TreeNode *root1 = createTree({3, 9, 20, NULL, NULL, 15, 7});
  TreeNode *root2 = createTree({3, 9, 20, NULL, 15, 7});

  // TreeNode *root = createTree({1, NULL, 2});
  printTree(root1);
  printTree(root2);

  cout << isSameTree(root1, root2) << endl;

  return 0;
}
