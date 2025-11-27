#include <iostream>
using namespace std;
struct Node
{
int data;
Node *left;
Node *right;
Node(int val)
{
data = val;
left = right = nullptr;
}
};
int countNodesInRange(Node *root, int a, int b)
{
if (root == nullptr)
{
return 0;
}
if (root->data < a)
{
return countNodesInRange(root->right, a, b);
}
else if (root->data > b)
{
return countNodesInRange(root->left, a, b);
}
else
{
cout << root->data << " ";
return 1 + countNodesInRange(root->left, a, b) +
countNodesInRange(root->right, a, b);
}
}
int main()
{
Node *root = new Node(10);
root->left = new Node(5);
root->right = new Node(50);
root->left->left = new Node(1);
root->right->left = new Node(40);
root->right->right = new Node(100);
int a = 5, b = 45;
cout << "Nodes in range [" << a << ", " << b << "]: ";
int count = countNodesInRange(root, a, b);
cout << endl;
cout << "Total count of nodes in range: " << count << endl;
return 0;
}
