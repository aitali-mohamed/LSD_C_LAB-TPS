include "header.h"
  

int leaf_sum(tree T){
    if (T==NULL)
        return 0;
    return 1+leaf_sum(T)
}

int tree_depth(tree T){
    if (T==NULL)
        return 0;
    if (T->left==NULL && T->right == NULL)
        return 1;
    if ( T->left==NULL)
        return 1+tree_depth(T->right);
    if (T->right==NULL)
        return 1+tree_depth(T->left);
    return max(tree_depth(T->left),tree_depth(T->right));
}

int tree_diameter(tree T){
    if (T==NULL)
        return 0;
    if (T->left==NULL && T->right == NULL)
        return 1;
    return 1+tree_depth(T->left)+tree_depth(T->right);
}
tree insert(tree T,int x){
    if (T==NULL)
        return T=faireArbre(x,NULL,NULL);
    if (x==T->value)
        return T;
    if (x<T->value){
        insert(T->left,x);
        return T;
    }
    if (x>T->value){
        insert(T->right,x);
        return T;
    }    
}


int max_depth(tree T){
    if (T==NULL)
        return 0;
    if(T->left==NULL && T->right==NULL)
        return 1;
    if (T->left==NULL)
        return;
}

int recherche(int x, tree T){
    if (T=NULL)
        return 0;
    if (T->value ==x)
        return 1;
    if (T->value>x)
        return recherche(x,T->left);
    if (T->value<x)
        return recherche(x,T->right);    
}

int tree_size(tree T){
    if (T==NULL)
        return 0;
    if (T->left==NULL && T->right==NULL)
        return 1;
    if (T->left==NULL)
        return 1+tree_size(T->right);
    if (T->right==NULL)
        return 1+tree_size(T->left);
    return 1+tree_size(T->left)+tree_size(T->right);
}
