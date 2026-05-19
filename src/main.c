#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
};

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

    //o código funciona no leet, não fiz esse main, testei direto pelo leet!

    return 0;
}

