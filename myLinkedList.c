#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* head;  // 哨兵节点
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;  // 单向链表，尾部指向NULL
    obj->head = head;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    
    Node* cur = obj->head;
    // 只能从头部开始遍历
    for (int i = 0; i <= index; i++) {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    
    node->next = obj->head->next;
    obj->head->next = node;
    
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    
    // 找到最后一个节点
    Node* cur = obj->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
    
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    
    // 找到插入位置的前一个节点
    Node* cur = obj->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    
    node->next = cur->next;
    cur->next = node;
    
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    
    // 找到要删除节点的前一个节点
    Node* cur = obj->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    
    Node* nodeToDelete = cur->next;
    cur->next = nodeToDelete->next;
    free(nodeToDelete);
    
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* cur = obj->head->next;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj->head);
    free(obj);
}

// 辅助函数：打印链表
void printList(MyLinkedList* obj) {
    printf("List (size=%d): ", obj->size);
    Node* cur = obj->head->next;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    // 测试示例
    printf("=== 测试示例 ===\n");
    MyLinkedList* list = myLinkedListCreate();
    
    printf("1. addAtHead(1)\n");
    myLinkedListAddAtHead(list, 1);
    printList(list);
    
    printf("2. addAtTail(3)\n");
    myLinkedListAddAtTail(list, 3);
    printList(list);
    
    printf("3. addAtIndex(1, 2)\n");
    myLinkedListAddAtIndex(list, 1, 2);
    printList(list);
    
    printf("4. get(1) = %d\n", myLinkedListGet(list, 1));
    
    printf("5. deleteAtIndex(1)\n");
    myLinkedListDeleteAtIndex(list, 1);
    printList(list);
    
    printf("6. get(1) = %d\n", myLinkedListGet(list, 1));
    
    myLinkedListFree(list);
    
    // 额外测试
    printf("\n=== 额外测试 ===\n");
    MyLinkedList* list2 = myLinkedListCreate();
    
    // 测试边界情况
    printf("Empty list get(0) = %d (should be -1)\n", myLinkedListGet(list2, 0));
    
    // 测试多个操作
    myLinkedListAddAtHead(list2, 5);
    myLinkedListAddAtHead(list2, 4);
    myLinkedListAddAtTail(list2, 6);
    myLinkedListAddAtIndex(list2, 1, 10);
    printList(list2);  // 应该是: 4 10 5 6
    
    printf("get(0) = %d\n", myLinkedListGet(list2, 0));  // 4
    printf("get(1) = %d\n", myLinkedListGet(list2, 1));  // 10
    printf("get(2) = %d\n", myLinkedListGet(list2, 2));  // 5
    printf("get(3) = %d\n", myLinkedListGet(list2, 3));  // 6
    
    myLinkedListDeleteAtIndex(list2, 0);
    printList(list2);  // 应该是: 10 5 6
    
    myLinkedListFree(list2);
    
    return 0;
}