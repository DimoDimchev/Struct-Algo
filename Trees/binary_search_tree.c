#include<stdlib.h>
#include<stdio.h>

struct TreeNode{ // node for the binary tree
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* GenerateNode(int data){ // generate new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* Insert(struct TreeNode* root,int data){ // insert new node using recursion
    if(root == NULL){
        root = GenerateNode(data);
        return root;
    }
    if(data <= root->data){
        root->left = Insert(root->left, data); // recursion call
    } else {
        root->right = Insert(root->right, data); // recursion call
    }
    return root;
}

int Search(struct TreeNode* root, int data){ // search for a specific element recursively
    if(root == NULL) return 0;
    else if(root->data == data) return 1;
    else if(data <= root-> data) return Search(root->left, data);
    else return Search(root->right, data);
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);
    
    int num;
    printf("Enter a number to search\n");
    scanf("%d", &num);

    if(Search(root, num) == 1){
        printf("Found number\n");
    } else{
        printf("Didn't find number\n");
    } 
}