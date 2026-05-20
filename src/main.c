#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

struct TreeNode* Inserir(struct TreeNode *root, int num) {
    if(root == NULL) {
        struct TreeNode* aux = malloc(sizeof(struct TreeNode));
        aux->val = num;
        aux->left = NULL;               
        aux->right = NULL;
        return aux;
    } else {
        if(num < root->val) {
            root->left = Inserir(root->left, num);
        } else {
            root->right = Inserir(root->right, num);
        }
        return root;
    }
} 
 
int ContarNos(struct TreeNode *root) {
    if(root == NULL) {
        return 0;
    } 
    return 1 + ContarNos(root->left) + ContarNos(root->right);
}

void Inorder(struct TreeNode *root, int *resultado, int *i) {
    if(root != NULL) {
        Inorder(root->left, resultado, i);
        resultado[*i] = root->val;
        (*i)++;
        Inorder(root->right, resultado, i);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = ContarNos(root);
    int *resultado = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    Inorder(root, resultado, &i);
    return resultado;
}


int main() {

    struct TreeNode *arv = NULL;
    int returnSize;

    arv = Inserir(arv, 10);
    arv = Inserir(arv, 6);
    arv = Inserir(arv, 14);
    arv = Inserir(arv, 8);
    arv = Inserir(arv, 12);

    int *vet = inorderTraversal(arv, &returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}

