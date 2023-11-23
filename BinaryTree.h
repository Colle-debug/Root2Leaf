#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <climits>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool maxPath;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
        this->maxPath = false;
    }
};

Node* generateRandomBinaryTree(int guaranteedLevels, int maxDepth, int startingDepth);
void visualizeTree(Node* root, QGraphicsScene &scene, int x, int y, int xOffset, int yOffset);
void deallocateTree(Node* root);
void refreshTree(QGraphicsScene &scene, int guaranteedLevels, int maxDepth);

// Mie reimplementazioni dell'algortimo
int maxR2L(Node* root);
bool printPath(Node* root, int sum, vector<int>& path);

#endif // BINARYTREE_H
