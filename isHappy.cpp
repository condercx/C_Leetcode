#include <bits/stdc++.h>

int get_sum(int n) {
    int sum = 0;
    div_t n_div = {.quot = n};
    while (n_div.quot != 0) {
        n_div = div(n_div.quot, 10);
        sum += n_div.rem * n_div.rem;
    }
    return sum;
}

bool isHappy(int n) {
    int fast = n, slow = n;

    do {
        slow = get_sum(slow);
        fast = get_sum(get_sum(fast));
    }while (slow != fast);

    return (fast == 1);
}