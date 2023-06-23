#include <stdio.h>
#include <stdlib.h>
typedef struct node *AVLTree;
struct node
{
    int Data;
    AVLTree Left;
    AVLTree Right;
};
int High(AVLTree T)
{
    if (!T)
        return 0;
    int left = High(T->Left) + 1;
    int right = High(T->Right) + 1;
    return left > right ? left : right;
}
AVLTree LL(AVLTree T)
{
    AVLTree T1;
    T1 = T->Right;
    T->Right = T1->Left;
    T1->Left = T;
    return T1;
}
AVLTree RR(AVLTree T)
{
    AVLTree T1;
    T1 = T->Left;
    T->Left = T1->Right;
    T1->Right = T;
    return T1;
}
AVLTree LR(AVLTree T)
{
    AVLTree T1, T2;
    T1 = T->Left;
    T2 = T1->Right;
    T->Left = NULL;
    T2->Right = T;
    T1->Right = NULL;
    T2->Left = T1;
    return T2;
}
AVLTree RL(AVLTree T)
{
    AVLTree T1, T2;
    T1 = T->Right;
    T2 = T1->Left;
    T->Right = NULL;
    T2->Left = T;
    T1->Left = NULL;
    T2->Right = T1;
    return T2;
}
AVLTree Insert(AVLTree T, int x)
{
    if (!T)
    {
        AVLTree T = (AVLTree)malloc(sizeof(struct node));
        T->Data = x;
        T->Left = T->Right = NULL;
        return T;
    }
    else if (x > T->Data)
    {
        T->Right = Insert(T->Right, x);
        if ((High(T->Right) - High(T->Left)) >= 2)
        {
            if (x > T->Right->Data)
                T = LL(T);
            else
                T = RL(T);
        }
    }
    else if (x < T->Data)
    {
        T->Left = Insert(T->Left, x);
        if ((High(T->Left) - High(T->Right)) == 2)
        {
            if (x < T->Left->Data)
                T = RR(T);
            else
                T = LR(T);
        }
    }
    return T;
}
int main()
{
    int n, x;
    AVLTree T = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        T = Insert(T, x);
    }
    printf("%d\n", T->Data);
    return 0;
}