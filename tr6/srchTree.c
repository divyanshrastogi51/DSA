#include "srchTree.h"
#include <assert.h>
#include <string.h>
#define SCRN_WIDTH 100
#define OFFSET 9
struct node
{
    int key;
    int height;
    int depth;
    struct node *left;
    struct node *right;
};
struct node *theTree;
int STEP;
struct node *makeNode(int key)
{
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->left = new->right = NULL;
    new->key = key;
    new->height = 0;
    new->depth = 0;
    return new;
}
void initTree()
{
    theTree = NULL;
}
int find(int key, struct node *t)
{
    if (t == NULL)
        return 0;
    if (t->key == key)
        return 1;
    if (t->key > key)
        return find(key, t->left);
    else
        return find(key, t->right);
}
int hasKey(int key)
{
    return find(key, theTree);
}

struct node *insert(int key, struct node *tree)
{
    struct node *t;
    if (tree == NULL)
    {
        t = makeNode(key);
        return t;
    }
    if(key<tree->key)
    {
        tree->left=insert(key,tree->left);
    }
    else if(key>tree->key)
    {
        tree->right=insert(key,tree->right);
    }
    return tree;
}
void insertKey(int key)
{
    theTree = insert(key, theTree);
}
int setNodeHeights(struct node *tree)
{
    int lh, rh;
    if (tree == NULL)
        return 0;
    lh = setNodeHeights(tree->left)+1;
    rh = setNodeHeights(tree->right)+1;
    tree->height = lh>rh?lh:rh;
    return tree->height;
}
void setHeights()
{
    theTree->height = setNodeHeights(theTree);
}
static void setNodeDepths(struct node *tree, int depth)
{
    if (tree == NULL)
        return;
    tree->depth = depth+1;
    setNodeDepths(tree->left, tree->depth);
    setNodeDepths(tree->right, tree->depth);
}
void setDepths()
{
    setNodeDepths(theTree, 0);
}

int graftReplacementKey(struct node *tree)
{
    struct node *parent;
    int replacementKey;
    assert(tree != NULL);
    while (tree->right != NULL)
    {
        parent = tree;
        tree = tree->right;
    }
    replacementKey = tree->key;
    parent->right = tree->left;
    free(tree);
    return replacementKey;
}
struct node * deleteNode(int key, struct node *tree)
{
    struct node * tmp;
    int replacementKey;
    if (tree == NULL)
        return tree;

    if (tree->key > key)
    {
        tree->left = deleteNode(key, tree->left);
        return tree;
    }
    else if (tree->key < key)
    {
        tree->right = deleteNode(key, tree->right);
        return tree;
    }
    /* The remaining case when node is deleted */
    assert(tree->key == key);
    if (tree->left == NULL)
    {
        tmp = tree->right;
        free(tree);
        return tmp;
    }
    else if (tree->right == NULL)
    {
        tmp = tree->left;
        free(tree);
        return tmp;
    }
    tmp->key=graftReplacementKey(tree->left);
    tree->key=tmp->key;
    tree->left=deleteNode(tmp->key,tmp->left);

    return tree;
}
void deleteKey(int key)
{
    theTree = deleteNode(key, theTree);
}

void printNode(struct node *tree, int spaces)
{
    if (tree == NULL)
    {
//printf("\n");
        return;
    }
    while (spaces-->0)
        printf(" ");
    printf("%d\n", tree->key);
}
void printWell(struct node *tree, int spaces)
{
    if (tree == NULL)
    {
        printNode(NULL, spaces);
        return;
    }
    /* TASK 02
    A SHORT SEQUENCE OF CODE REMOVED
    */
    printWell(tree->right,spaces+9);

    printNode(tree,spaces);
    printWell(tree->left,spaces+9);

}
void printTree()
{
    int i;
    if (theTree == NULL)
    {
        printf("START----> NULL\n");
        return;
    }
    setHeights();
    setDepths();
    STEP = SCRN_WIDTH/theTree->height;
    if (STEP>9)
        STEP = 9;
    printf("\n");
    printWell(theTree->right, OFFSET+STEP);
    printf("START -> %d\n", theTree->key);
    printWell(theTree->left, OFFSET+STEP);
}
