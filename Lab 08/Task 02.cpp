#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Combatant{
string name;
int hp;
int attack;
int id;
Combatant(string n = "", int h = 0, int a = 0, int i = 0)
{
name = n;
hp = h;
attack = a;
id = i;
}
};
struct Node
{
Combatant data;
Node *left;
Node *right;
Node(Combatant c)
{
data = c;
left = right = NULL;
}
};
Node *insert(Node *root, Combatant c)
{
 if (root == NULL)
{
return new Node(c);
}
else{
if (c.id < root->data.id)
{
root->left = insert(root->left, c);
}
else if (c.id > root->data.id)
{
  root->right = insert(root->right, c);
}
}
return root;
}
Node *findMin(Node *root)
{
while (root != NULL && root->left != NULL)
{
root = root->left;
}
return root;
}
Node *deleteNode(Node *root, int id)
{
if (root == NULL)
{
return root;
}
else
{
if (id < root->data.id){
root->left = deleteNode(root->left, id);
}
else if (id > root->data.id){
root->right = deleteNode(root->right, id);
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
root->right = deleteNode(root->right, temp->data.id);
}
}
}
return root;
}
void displayBST(Node *root)
{
if (root != NULL)
{
displayBST(root->left);
cout << root->data.name << " (HP: " << root->data.hp << ", ATK: " <<
root->data.attack << ") ";
displayBST(root->right);
}
}Node *getFrontline(Node *root)
{
return findMin(root);
}
int countNodes(Node *root)
{
if (root == NULL)
{
return 0;
}
else
{
return 1 + countNodes(root->left) + countNodes(root->right);
}
}
int main()
{
srand(time(0));
Node *player = NULL;
Node *enemy = NULL;
Combatant heroes[5] = {
{"Mohsin", 40, 10, 10},
{"Bilal", 35, 8, 20},
{"Ali", 30, 12, 30},
{"Ahmed", 25, 7, 40},
{"Shayan", 45, 9, 50}};
Combatant enemies[5] = {
{"Hamza", 25, 6, 15},
{"Haider", 40, 9, 25},
{"Usaid", 50, 11, 35},
{"Kaif", 30, 8, 45},
{"Shahzaib", 60, 13, 55}};
for (int i = 0; i < 5; i++)
{
player = insert(player, heroes[i]);
enemy = insert(enemy, enemies[i]);
}
int round = 1;
while (player != NULL && enemy != NULL)
{
cout << "\n============" << endl;
cout << "Round " << round << endl;
cout << "============" << endl;
cout << "\nPlayer Team: ";
displayBST(player);
cout << "\nEnemy Team: ";
displayBST(enemy);
cout << endl;
Node *pFront = getFrontline(player);
Node *eFront = getFrontline(enemy);
if (pFront == NULL || eFront == NULL)
{
break;
}
int playerDamage = pFront->data.attack + (rand() % 5);
eFront->data.hp -= playerDamage;
cout << "\n"
<< pFront->data.name << " attacks " << eFront->data.name << " for " <<
playerDamage << " damage!" << endl;if (eFront->data.hp <= 0)
{
cout << eFront->data.name << " has been defeated!" << endl;
enemy = deleteNode(enemy, eFront->data.id);
}
if (enemy == NULL)
{
cout << "\nAll enemies defeated! Player wins!" << endl;
break;
}
Node *eFront2 = getFrontline(enemy);
int enemyDamage = eFront2->data.attack + (rand() % 5);
pFront->data.hp -= enemyDamage;
cout << eFront2->data.name << " attacks " << pFront->data.name << " for "
<< enemyDamage << " damage!" << endl;
if (pFront->data.hp <= 0)
{
cout << pFront->data.name << " has been defeated!" << endl;
player = deleteNode(player, pFront->data.id);
}
if (player == NULL)
{
cout << "\nAll heroes defeated! Enemy wins!" << endl;
break;
}
round++;
}
cout << "\nBattle Over!" << endl;
return 0;
}
