#include <stdio.h>
#include <stdlib.h>
#include "TreeFuncs.c"

int main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("Inorder : ");
    inOrder(tree);
    printf("\nPre-Order : ");
    preOrder(tree);
    printf("\nPost-Order : ");
    postOrder(tree);
}

