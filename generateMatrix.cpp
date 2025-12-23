#include <bits/stdc++.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);

    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int startX = 0;
    int startY = 0;
    int offset = 0;
    int count = 1;
    for(int k = 0; k < n / 2; k++)
    {
        int i = startX;
        int j = startY;
        for(; j < startY + n - offset; j++)
        {
            ans[startX][j] = count++;
        }
        j--;
        i++;
        for(; i < startX + n - offset; i++)
        {
            ans[i][j] = count++;
        }
        i--;
        j--;
        for(; j > startY; j--)
        {
            ans[i][j] = count++;
        }
        for(; i > startX; i--)
        {
            ans[i][j] = count++;
        }
        offset += 2;
        startX++;
        startY++;
    }
    if(n % 2)
    {
        ans[n / 2 ][n / 2] = count;
    }
    return ans;
}

int main()
{
    int n = 3;
    int returnSize;
    int* returnColumnSizes;
    
    // 调用函数生成螺旋矩阵
    int** matrix = generateMatrix(n, &returnSize, &returnColumnSizes);
    
    // 打印结果
    printf("输出：[");
    for(int i = 0; i < returnSize; i++)
    {
        printf("[");
        for(int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d", matrix[i][j]);
            if(j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]");
        if(i < returnSize - 1) printf(",");
    }
    printf("]\n");

    return 0;

}



// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
// int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
//     *returnSize = n;
//     *returnColumnSizes = (int*)malloc(sizeof(int) * n);

//     // 使用连续内存分配优化
//     int* data = (int*)malloc(sizeof(int) * n * n);
//     int** ans = (int**)malloc(sizeof(int*) * n);
    
//     for (int i = 0; i < n; i++) {
//         ans[i] = data + i * n;
//         (*returnColumnSizes)[i] = n;
//     }
    
//     // 边界定义
//     int t = 0;      // top
//     int b = n - 1;  // bottom
//     int l = 0;      // left
//     int r = n - 1;  // right
//     int k = 1;
    
//     while (k <= n * n) {
//         // 从左到右填充上边
//         for (int i = l; i <= r && k <= n * n; i++, k++) {
//             ans[t][i] = k;
//         }
//         t++;
        
//         // 从上到下填充右边
//         for (int i = t; i <= b && k <= n * n; i++, k++) {
//             ans[i][r] = k;
//         }
//         r--;
        
//         // 从右到左填充下边
//         for (int i = r; i >= l && k <= n * n; i--, k++) {
//             ans[b][i] = k;
//         }
//         b--;
        
//         // 从下到上填充左边
//         for (int i = b; i >= t && k <= n * n; i--, k++) {
//             ans[i][l] = k;
//         }
//         l++;
//     }
    
//     return ans;
// }