#include <stdio.h>

void test_arr () {
    int array[2][2] = {
        {3,4},
        {2,5}
    };
    printf("%p %p\n", (void *)&array[0][0], (void *)&array[0][1]);
    printf("%p %p\n", (void *)&array[1][0], (void *)&array[1][1]);
}

void main(){
    test_arr();
    return;
}