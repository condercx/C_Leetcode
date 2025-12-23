#include "bits/stdc++.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            struct ListNode* f = fast;
            struct ListNode* h = head;
            while (f != h) {
                f = f->next;
                h = h->next;
            }
            return h;
        }
    }
    return NULL;
}

/* 辅助函数：创建链表节点 */
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node) {
        node->val = val;
        node->next = NULL;
    }
    return node;
}

/* 辅助函数：打印测试结果 */
void printResult(const char* testName, struct ListNode* result, struct ListNode* expected) {
    printf("%s: ", testName);
    if (result == expected) {
        printf("PASS");
        if (result) {
            printf(" (环起始节点值: %d)", result->val);
        } else {
            printf(" (无环)");
        }
    } else {
        printf("FAIL");
    }
    printf("\n");
}

int main() {
    printf("=== 链表环检测测试 ===\n");
    
    /* 测试1: 无环链表 */
    {
        struct ListNode* node1 = createNode(1);
        struct ListNode* node2 = createNode(2);
        struct ListNode* node3 = createNode(3);
        struct ListNode* node4 = createNode(4);
        
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = NULL;
        
        struct ListNode* result = detectCycle(node1);
        printResult("测试1 - 无环链表", result, NULL);
        
        /* 清理内存 */
        free(node1); free(node2); free(node3); free(node4);
    }
    
    /* 测试2: 有环链表 (环从第2个节点开始) */
    {
        struct ListNode* node1 = createNode(3);
        struct ListNode* node2 = createNode(2);
        struct ListNode* node3 = createNode(0);
        struct ListNode* node4 = createNode(-4);
        
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2;  /* 形成环，指向node2 */
        
        struct ListNode* result = detectCycle(node1);
        printResult("测试2 - 有环链表(环起始于节点2)", result, node2);
        
        /* 断开环后清理内存 */
        node4->next = NULL;
        free(node1); free(node2); free(node3); free(node4);
    }
    
    /* 测试3: 单节点自环 */
    {
        struct ListNode* node1 = createNode(1);
        node1->next = node1;  /* 自己指向自己 */
        
        struct ListNode* result = detectCycle(node1);
        printResult("测试3 - 单节点自环", result, node1);
        
        node1->next = NULL; /* 断开环 */
        free(node1);
    }
    
    /* 测试4: 空链表 */
    {
        struct ListNode* result = detectCycle(NULL);
        printResult("测试4 - 空链表", result, NULL);
    }
    
    /* 测试5: 单个节点无环 */
    {
        struct ListNode* node1 = createNode(42);
        node1->next = NULL;
        
        struct ListNode* result = detectCycle(node1);
        printResult("测试5 - 单节点无环", result, NULL);
        
        free(node1);
    }
    
    /* 测试6: 较大的环 */
    {
        struct ListNode* nodes[6];
        int i;
        
        for (i = 0; i < 6; i++) {
            nodes[i] = createNode(i + 1);
        }
        
        /* 连接: 1->2->3->4->5->6->3 (环从节点3开始) */
        for (i = 0; i < 5; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[5]->next = nodes[2];  /* 6指向3，形成环 */
        
        struct ListNode* result = detectCycle(nodes[0]);
        printResult("测试6 - 较大环(环起始于节点3)", result, nodes[2]);
        
        /* 断开环后清理内存 */
        nodes[5]->next = NULL;
        for (i = 0; i < 6; i++) {
            free(nodes[i]);
        }
    }
    
    /* 测试7: 两个节点的环 */
    {
        struct ListNode* node1 = createNode(1);
        struct ListNode* node2 = createNode(2);
        
        node1->next = node2;
        node2->next = node1;  /* 形成环 */
        
        struct ListNode* result = detectCycle(node1);
        printResult("测试7 - 两节点环", result, node1);
        
        /* 断开环后清理内存 */
        node2->next = NULL;
        free(node1); free(node2);
    }
    
    printf("\n测试完成！\n");
    return 0;
}