#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001
void stringCalculator(char* s, char* t);
int lengthCompare(char* s, char* t);
int main() {
    char* a = malloc(sizeof(char) * MAX);
    char* b = malloc(sizeof(char) * MAX);
    int i;
    scanf("%s %s", a, b);
    char* str1 = malloc(sizeof(char) * strlen(a) + 1);
    char* str2 = malloc(sizeof(char) * strlen(b) + 1);
    for (i = 0; i < strlen(a); i++) {
        str1[i] = a[i];
    }
    str1[i] = '\0';
    for (i = 0; i < strlen(b); i++) {
        str2[i] = b[i];
    }
    str2[i] = '\0';
    free(a);
    free(b);
    ///////////////////////////////////////////////////////문자 받아오기 완료

    stringCalculator(str1, str2);
    //printf("%s %s",str1,str2);
    free(str1);
    free(str2);

    return 0;
}
void stringCalculator(char* s, char* t) {
    char* sum = malloc(sizeof(char) * lengthCompare(s, t) + 2);
    int temp = 0;
    int stsum;
    sum[0] = '0';
    sum[lengthCompare(s, t) + 1] = '\0';
    if (strlen(s) > strlen(t)) {
        for (int i = strlen(s) - 1; i >= strlen(s) - strlen(t); i--) {
            stsum = (s[i] - '0') + (t[i-(strlen(s) - strlen(t))] - '0') + temp;
            sum[i + 1] = stsum % 10 + 48;
            temp = stsum / 10;
        }
        for (int i = strlen(s) - strlen(t) - 1; i >= 0; i--) {
            stsum = (s[i] - '0') + temp;
            if (i == 0 && stsum >= 10) {
                sum[i] = stsum / 10 + 48;
                sum[i + 1] = stsum % 10 + 48;
                break;
            }
            sum[i + 1] = stsum % 10 + 48;
            temp = stsum / 10;
        }
    }
    else if (strlen(s) < strlen(t)) {
        for (int i = strlen(t) - 1; i >= strlen(t) - strlen(s); i--) {
            stsum = (s[i - (strlen(t) - strlen(s))] - '0') + (t[i] - '0') + temp;
            sum[i + 1] = stsum % 10 + 48;
            temp = stsum / 10;
        }
        for (int i = strlen(t) - strlen(s) - 1; i >= 0; i--) {
            stsum = (t[i] - '0') + temp;
            if (i == 0 && stsum >= 10) {
                sum[i] = stsum / 10 + 48;
                sum[i + 1] = stsum % 10 + 48;
                break;
            }
            sum[i + 1] = stsum % 10 + 48;
            temp = stsum / 10;
        }
    }
    else {
        for (int i = strlen(s) - 1; i >= 0; i--) {
            stsum = (s[i] - '0') + (t[i] - '0') + temp;
            if (i == 0 && stsum >= 10) {
                sum[i] = stsum / 10 + 48;
                sum[i + 1] = stsum % 10 + 48;
                break;
            }
            sum[i + 1] = stsum % 10 + 48;
            temp = stsum / 10;
        }
    }
    if (sum[0] != '0') {
        for (int i = 0; i < strlen(sum); i++) {
            printf("%c", sum[i]);
        }
    }
    else {
        for (int i = 1; i < strlen(sum); i++) {
            printf("%c", sum[i]);
        }
    }
}
int lengthCompare(char* s, char* t) {
    if (strlen(s) > strlen(t)) {
        return strlen(s);
    }
    else if (strlen(s) < strlen(t)) {
        return strlen(t);
    }
    else {
        return strlen(s);
    }
}

