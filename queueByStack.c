#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int stack_in_top, stack_out_top;
	char stack_in[100], stack_out[100];  // 使用 char 节省内存
} MyQueue;

MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->stack_in_top = queue->stack_out_top = 0;  // 合并初始化
	return queue;
}

void myQueuePush(MyQueue* obj, int x) {
	obj->stack_in[obj->stack_in_top++] = (char)x;
}

static inline void transferIfNeeded(MyQueue* obj) {
	if (obj->stack_out_top == 0) {
		while (obj->stack_in_top > 0) {
			obj->stack_out[obj->stack_out_top++] = obj->stack_in[--obj->stack_in_top];
		}
	}
}

int myQueuePop(MyQueue* obj) {
	transferIfNeeded(obj);
	return (int)obj->stack_out[--obj->stack_out_top];
}

int myQueuePeek(MyQueue* obj) {
	transferIfNeeded(obj);
	return (int)obj->stack_out[obj->stack_out_top - 1];
}

bool myQueueEmpty(MyQueue* obj) {
	return (obj->stack_in_top | obj->stack_out_top) == 0;  // 位运算优化
}

void myQueueFree(MyQueue* obj) {
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/