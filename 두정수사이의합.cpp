#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


long long solution(int a, int b) {
    long long answer = 0;
    int maximum = a>b?a:b;
    int minimum = a<b?a:b;
    for(int i=minimum; i<=maximum; i++)
        answer+=i;

    return answer;
}