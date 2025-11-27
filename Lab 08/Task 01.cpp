#include <iostream>
using namespace std;
struct Node
{
int data;
Node *left;
Node *right;
Node(int value)
{
data = value;
left = right = NULL;
}
};
Node *insert(Node *root, int value)
{
if (root == NULL)
{
return new Node(value);
}
else
{
if (value < root->data)
{
root->left = insert(root->left, value);
}
else if (value > root->data)
{
root->right = insert(root->right, value);
}
}
return root;
}
bool search(Node *root, int key)
{
if (root == NULL)
{
return false;
}
else
{
if (root->data == key)
{
return true;
}
else if (key < root->data)
{
return search(root->left, key);
}
else
{
return search(root->right, key);
}
}
}
Node *findMin(Node *root)
{
while (root != NULL && root->left != NULL)
{
root = root->left;
}
return root;
}
Node *deleteNode(Node *root, int key)
{
if (root == NULL)
{
return root;
}
else
{
if (key < root->data)
{
root->left = deleteNode(root->left, key);
}
else if (key > root->data)
{
root->right = deleteNode(root->right, key);
}
else
{
if (root->left == NULL)
{
return root->right;
}
else if (root->right == NULL)
{
return root->left;
}
else
{
Node *temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
}
}
return root;
}
void inorder(Node *root)
{
if (root != NULL)
{
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}
}
void preorder(Node *root)
{
if (root != NULL)
{
cout << root->data << " ";
preorder(root->left);
preorder(root->right);
}
}
void postorder(Node *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
cout << root->data << " ";
}
}
int main()
{
Node *root = NULL;
int choice, value;
do
{
cout << "1. Insert Node" << endl;
cout << "2. Delete Node" << endl;
cout << "3. Search Node" << endl;
cout << "4. Display Inorder" << endl;
cout << "5. Display Preorder" << endl;
cout << "6. Display Postorder" << endl;
cout << "7. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice)
{
case 1:
{
cout << "Enter value to insert: ";
cin >> value;
root = insert(root, value);
cout << "Node inserted successfully." << endl;
break;
}
case 2:
{
cout << "Enter value to delete: ";
cin >> value;
root = deleteNode(root, value);
cout << "Node deleted successfully (if it existed)." << endl;
break;
}
case 3:
{
cout << "Enter value to search: ";
cin >> value;
if (search(root, value))
{
cout << value << " found in the tree." << endl;
}
else
{
cout << value << " not found in the tree." << endl;
}
break;
}
case 4:
{
cout << "Inorder Traversal: ";
inorder(root);
cout << endl;
break;
}
case 5:
{
cout << "Preorder Traversal: ";
preorder(root);
cout << endl;
break;
}
case 6:
{
cout << "Postorder Traversal: ";
postorder(root);
cout << endl;
break;
}
case 7:
{
break;
}
default:
{
cout << "Invalid choice! Try again." << endl;
break;
}
}
} while (choice != 0);
return 0;
}
