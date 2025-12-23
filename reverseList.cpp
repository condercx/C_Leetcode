#include <bits/stdc++.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur;
    struct ListNode* pre = NULL;
    while (head) {
        cur = head->next;
        head->next = pre;
        pre = head;
        head = cur;
    }
    return pre;
}

// 辅助函数：创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 辅助函数：根据数组创建链表
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* cur = head;
    
    for (int i = 1; i < size; i++) {
        cur->next = createNode(arr[i]);
        cur = cur->next;
    }
    
    return head;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    if (head == NULL) {
        printf("[]");
        return;
    }
    
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]");
}

// 辅助函数：释放链表内存
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// 辅助函数：比较两个链表是否相等
int isListEqual(struct ListNode* list1, struct ListNode* list2) {
    while (list1 && list2) {
        if (list1->val != list2->val) return 0;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == NULL && list2 == NULL;
}

// 测试函数
void testReverseList(int testNum, int* input, int inputSize, int* expected, int expectedSize) {
    printf("测试 %d: ", testNum);
    
    // 创建输入链表
    struct ListNode* head = createList(input, inputSize);
    
    printf("输入: ");
    printList(head);
    
    // 执行反转
    struct ListNode* result = reverseList(head);
    
    printf(" -> 输出: ");
    printList(result);
    
    // 创建期望结果链表进行比较
    struct ListNode* expectedList = createList(expected, expectedSize);
    
    // 验证结果
    if (isListEqual(result, expectedList)) {
        printf(" ✓ 通过\n");
    } else {
        printf(" ✗ 失败 (期望: ");
        printList(expectedList);
        printf(")\n");
    }
    
    // 释放内存
    freeList(result);
    freeList(expectedList);
}

int main() {
    printf("=== 链表反转函数测试 ===\n\n");
    
    // 示例 1：[1,2,3,4,5] -> [5,4,3,2,1]
    int input1[] = {1, 2, 3, 4, 5};
    int expected1[] = {5, 4, 3, 2, 1};
    testReverseList(1, input1, 5, expected1, 5);
    
    // 示例 2：[1,2] -> [2,1]
    int input2[] = {1, 2};
    int expected2[] = {2, 1};
    testReverseList(2, input2, 2, expected2, 2);
    
    // 示例 3：[] -> []
    testReverseList(3, NULL, 0, NULL, 0);
    
    // 额外测试用例
    printf("\n=== 额外测试用例 ===\n");
    
    // 测试 4：单个节点 [1] -> [1]
    int input4[] = {1};
    int expected4[] = {1};
    testReverseList(4, input4, 1, expected4, 1);
    
    // 测试 5：三个节点 [1,2,3] -> [3,2,1]
    int input5[] = {1, 2, 3};
    int expected5[] = {3, 2, 1};
    testReverseList(5, input5, 3, expected5, 3);
    
    // 测试 6：包含重复元素 [1,1,2,1] -> [1,2,1,1]
    int input6[] = {1, 1, 2, 1};
    int expected6[] = {1, 2, 1, 1};
    testReverseList(6, input6, 4, expected6, 4);
    
    // 测试 7：包含负数 [-1,0,1] -> [1,0,-1]
    int input7[] = {-1, 0, 1};
    int expected7[] = {1, 0, -1};
    testReverseList(7, input7, 3, expected7, 3);
    
    // 测试 8：较长链表 [1,2,3,4,5,6,7,8,9,10] -> [10,9,8,7,6,5,4,3,2,1]
    int input8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected8[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverseList(8, input8, 10, expected8, 10);
    
    printf("\n=== 性能测试 ===\n");
    
    // 创建一个较大的链表进行性能测试
    const int LARGE_SIZE = 100000;
    struct ListNode* largeHead = NULL;
    struct ListNode* cur = NULL;
    
    // 创建大链表
    for (int i = 1; i <= LARGE_SIZE; i++) {
        struct ListNode* node = createNode(i);
        if (largeHead == NULL) {
            largeHead = node;
            cur = node;
        } else {
            cur->next = node;
            cur = node;
        }
    }
    
    printf("性能测试：反转包含 %d 个节点的链表...", LARGE_SIZE);
    fflush(stdout);
    
    struct ListNode* reversedLarge = reverseList(largeHead);
    
    // 验证反转结果的前几个和后几个元素
    int isCorrect = 1;
    cur = reversedLarge;
    for (int i = LARGE_SIZE; i >= LARGE_SIZE - 2 && cur; i--, cur = cur->next) {
        if (cur->val != i) {
            isCorrect = 0;
            break;
        }
    }
    
    if (isCorrect) {
        printf(" ✓ 通过\n");
    } else {
        printf(" ✗ 失败\n");
    }
    
    // 释放大链表内存
    freeList(reversedLarge);
    
    printf("\n=== 所有测试完成 ===\n");
    
    return 0;
}