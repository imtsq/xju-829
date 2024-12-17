#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新的二叉树节点
TreeNode *createTreeNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// 插入节点到二叉树（这里简单实现为插入到合适位置，保持二叉搜索树的特性，仅作示例）
void insertNode(TreeNode **root, int value) {
    if (*root == NULL) {
        *root = createTreeNode(value);
        return;
    }

    if (value < (*root)->data) {
        insertNode(&(*root)->left, value);
    } else {
        insertNode(&(*root)->right, value);
    }
}

// 中序遍历二叉树并打印节点值
void inorderTraversal(TreeNode *root) {
    if (root!= NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 释放二叉树内存（后序遍历释放节点内存）
void freeTree(TreeNode *root) {
    if (root!= NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode *root = NULL;

    // 插入一些节点到二叉树
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);
    insertNode(&root, 6);
    insertNode(&root, 8);

    // 中序遍历并打印二叉树节点值
    printf("中序遍历结果: ");
    inorderTraversal(root);
    printf("\n");

    // 释放二叉树内存
    freeTree(root);

    return 0;
}