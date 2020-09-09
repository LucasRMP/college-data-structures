#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class BinaryTree {
  public:
  BinaryTree *left;
  BinaryTree *right;
  bool initialized;
  T value;

  BinaryTree() {
    this->initialized = false;
    this->left = NULL;
    this->right = NULL;
  }

  BinaryTree(vector<T> values) {
    this->left = NULL;
    this->right = NULL;
    this->initialized = true;
    this->insert(values);
  }

  BinaryTree(T value) {
    this->left = NULL;
    this->right = NULL;
    this->initialized = true;
    this->value = value;
  }

  bool insert(T value) {
    if (!this->initialized) {
      this->value = value;
      this->initialized = true;
      return true;
    }

    this->createNode(
      this->compareNodes(value, this->value) ? "right" : "left", 
      value
    );
    return true;
  }

  bool insert(vector<T> values) {
    for (T item : values) {
      if (!this->insert(item)) {
        return false;
      }
    }

    return true;
  }

  BinaryTree** getNode(string target) {
    if (target == "right") {
      return &this->right;
    }
    return &this->left;
  }

  bool createNode(string target, T item) {
    BinaryTree** targetNode = this->getNode(target); 
    if (!*targetNode) {
      *targetNode = new BinaryTree(item);
    } else {
      if (!(*targetNode)->insert(item)) {
        return false;
      }
    }

    return true;
  }

  bool compareNodes(T a, T b) {
    return a > b;
  }

  void printPre() {
    cout << " " << this->value;
    if (this->left) this->left->printPre();
    if (this->right) this->right->printPre();
  }

  void printIn() {
    if (this->left) this->left->printIn();
    cout << " " << this->value;
    if (this->right) this->right->printIn();
  }

  void printPost() {
    if (this->left) this->left->printPost();
    if (this->right) this->right->printPost();
    cout << " " << this->value;
  }
};

void processEntry(vector<int> entry, int index) {
  BinaryTree<int> bt;
  bt.insert(entry);

  cout << "Case " << index << ":" << endl;
  cout << "Pre.:";
  bt.printPre();
  cout << endl;
  cout << "In..:";
  bt.printIn();
  cout << endl;
  cout << "Post:";
  bt.printPost();
  cout << endl;
  cout << endl;
}

int main() {
  int numTests, size;  

  cin >> numTests;
  for(int i = 1; i <= numTests; i++) {
    cin >> size;

    vector<int> entry; 
    while(size--) {
      int num;
      cin >> num;

      entry.push_back(num);
    }

    processEntry(entry, i);
  }
}