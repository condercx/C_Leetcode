#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
// 创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 从数组创建链表
struct ListNode* createListFromArray(int arr[], int size) {
    if (size <= 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 打印链表
void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
    printf("]\n");
}

// 释放链表内存
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode* shead;
    shead = (struct ListNode*)malloc(sizeof(struct ListNode));
    shead->next = head;
    struct ListNode* cur  = shead;
    while (cur->next != NULL)
    {
        if(cur->next->val == val)
        {
            struct ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        else{
            cur = cur->next;
        }
    }
    head = shead->next;
    free(shead);
    return head;
}

int main()
{
    // 测试用例1：题目给出的例子
    printf("测试用例1:\n");
    int arr1[] = {1, 2, 6, 3, 4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    struct ListNode* head1 = createListFromArray(arr1, size1);
    
    printf("输入: head = ");
    printList(head1);
    printf("val = 6\n");
    
    head1 = removeElements(head1, 6);
    printf("输出: ");
    printList(head1);
    printf("期望: [1,2,3,4,5]\n\n");
    freeList(head1);
    
}