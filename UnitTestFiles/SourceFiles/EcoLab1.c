#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IEcoLab1.h"

void asserts(int32_t actual, int32_t expected) {
    if (actual != expected) {
        printf("TEST FAILED!\n");
        return;
    }
    printf("TEST PASSED!\n");
}

void test_performance(struct IEcoLab1* pIEcoLab1, void* pIMem) {
    const uint32_t sizes[] = {1000, 10000, 100000};
    int i, j;

    for (i = 0; i < 3; i++) {
        uint32_t size = sizes[i];
        clock_t start, end;
        double time_spent;

        // Тест для int
        int* arr_int = (int*)malloc(size * sizeof(int));
        for (j = 0; j < size; j++) arr_int[j] = j;
        start = clock();
        pIEcoLab1->pVTbl->linearSearchInt(pIEcoLab1, arr_int, size, size - 1);
        end = clock();
        time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linearSearchInt (size=%u): %.6f seconds\n", size, time_spent);
        free(arr_int);

        // Тест для long
        int64_t* arr_long = (int64_t*)malloc(size * sizeof(int64_t));
        for (j = 0; j < size; j++) arr_long[j] = j;
        start = clock();
        pIEcoLab1->pVTbl->linearSearchLong(pIEcoLab1, arr_long, size, size - 1);
        end = clock();
        time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linearSearchLong (size=%u): %.6f seconds\n", size, time_spent);
        free(arr_long);

        // Тест для float
        float* arr_float = (float*)malloc(size * sizeof(float));
        for (j = 0; j < size; j++) arr_float[j] = (float)j;
        start = clock();
        pIEcoLab1->pVTbl->linearSearchFloat(pIEcoLab1, arr_float, size, (float)(size - 1));
        end = clock();
        time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linearSearchFloat (size=%u): %.6f seconds\n", size, time_spent);
        free(arr_float);

        // Тест для double
        double* arr_double = (double*)malloc(size * sizeof(double));
        for (j = 0; j < size; j++) arr_double[j] = (double)j;
        start = clock();
        pIEcoLab1->pVTbl->linearSearchDouble(pIEcoLab1, arr_double, size, (double)(size - 1));
        end = clock();
        time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linearSearchDouble (size=%u): %.6f seconds\n", size, time_spent);
        free(arr_double);

        // Тест для long double
        long double* arr_long_double = (long double*)malloc(size * sizeof(long double));
        for (j = 0; j < size; j++) arr_long_double[j] = (long double)j;
        start = clock();
        pIEcoLab1->pVTbl->linearSearchLongDouble(pIEcoLab1, arr_long_double, size, (long double)(size - 1));
        end = clock();
        time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linearSearchLongDouble (size=%u): %.6f seconds\n", size, time_spent);
        free(arr_long_double);
    }
}

void test_allFunctions(struct IEcoLab1* pIEcoLab1, void* pIMem) {
    printf("\n=== Testing linearSearchInt ===\n");
    {
        int arr[] = {2, 5, 1, 0, -3, 8, 2};
        uint32_t n = 7;
        int target = 1;
        int32_t result = pIEcoLab1->pVTbl->linearSearchInt(pIEcoLab1, arr, n, target);
        printf("Input: arr = [2,5,1,0,-3,8,2], target=1\n");
        printf("Index: %d (expected 2)\n", result);
        asserts(result, 2);
    }

    printf("\n=== Testing linearSearchLong ===\n");
    {
        int64_t arr[] = {20000, 50000, -10012, 0, -3653, 89753, 203};
        uint32_t n = 7;
        int64_t target = 0;
        int32_t result = pIEcoLab1->pVTbl->linearSearchLong(pIEcoLab1, arr, n, target);
        printf("Input: arr = [20000,50000,-10012,0,-3653,89753,203], target=0\n");
        printf("Index: %d (expected 3)\n", result);
        asserts(result, 3);
    }

    printf("\n=== Testing linearSearchFloat ===\n");
    {
        float arr[] = {1.2f, -0.05f, -8.2f, 9.3f, 5.4f, 0.5f, 9.32f};
        uint32_t n = 7;
        float target = 5.4f;
        int32_t result = pIEcoLab1->pVTbl->linearSearchFloat(pIEcoLab1, arr, n, target);
        printf("Input: arr = [1.2,-0.05,-8.2,9.3,5.4,0.5,9.32], target=5.4\n");
        printf("Index: %d (expected 4)\n", result);
        asserts(result, 4);
    }

    printf("\n=== Testing linearSearchDouble ===\n");
    {
        double arr[] = {1.2, -0.05, -8.2, 9.3, 5.4, 0.5, 9.32};
        uint32_t n = 7;
        double target = 9.32;
        int32_t result = pIEcoLab1->pVTbl->linearSearchDouble(pIEcoLab1, arr, n, target);
        printf("Input: arr = [1.2,-0.05,-8.2,9.3,5.4,0.5,9.32], target=9.32\n");
        printf("Index: %d (expected 6)\n", result);
        asserts(result, 6);
    }

    printf("\n=== Testing linearSearchLongDouble ===\n");
    {
        long double arr[] = {1.2L, -0.05L, -8.2L, 9.3L, 5.4L, 0.5L, 9.32L};
        uint32_t n = 7;
        long double target = -8.2L;
        int32_t result = pIEcoLab1->pVTbl->linearSearchLongDouble(pIEcoLab1, arr, n, target);
        printf("Input: arr = [1.2,-0.05,-8.2,9.3,5.4,0.5,9.32], target=-8.2\n");
        printf("Index: %d (expected 2)\n", result);
        asserts(result, 2);
    }

    printf("\n=== Performance Testing ===\n");
    test_performance(pIEcoLab1, pIMem);
}

int main() {
    extern IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl;
    struct IEcoLab1 mockLab1 = { &g_x277FC00C35624096AFCFC125B94EEC90VTbl };
    test_allFunctions(&mockLab1, NULL);
    return 0;
}