/*************************************************************************
	> File Name: leetcode1.cpp
	> Author: caohaiyan
	> Mail: 877022406@qq.com
	> Created Time: 2018年11月12日 星期一 16时21分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int val, id;
} Data;

typedef struct HashTable {
    Data *data;
    int *flag;
    int size;
} HashTable;

int hashFunc (int val) {
    return val >= 0 ? val : -val;
}

HashTable *init (int len) {
    HashTable *hash = (HashTable *)malloc(sizeof(HashTable));
    hash->size = len << 1;
    hash->data = (Data *)calloc(hash->size, sizeof(Data));
    hash->flag = (int *)calloc(hash->size, sizeof(int));
    return hash;
}

void insert (HashTable *hash, int val, int ind) {
    int h = hashFunc(val);
    int pos = h % hash->size;
    int times = 1;
    while (hash->flag[pos]) {
        pos += (times * times);
        pos %= hash->size;
        times++;
    }
    hash->data[pos].val = val;
    hash->data[pos].id = ind;
    hash->flag[pos] = 1;
    return ;
}

int search (HashTable *hash, int value, int ans) {
    int pos = hashFunc(value);
    pos %= hash->size;
    int times = 1;
    while (hash->flag[pos]) {
        if (hash->data[pos].val == value && pos != ans) return hash->data[pos].id;
        pos += (times * times);
        pos %= hash->size;
        times++;
    }
    return -1;
}

int *twoSum (int *nums, int numsSize, int target) {
    HashTable *hash = init(numsSize);
    for (int i = 0; i < numsSize; i++) {
        insert(hash, nums[i], i);
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        int n = hashFunc(nums[i]);
        n %= hash->size;
        int ind = search(hash, target - nums[i], n);
        if (ind >= 0) {
            ret[0] = i;
            ret[1] = ind;
            break;
        }
    }
    printf("%d %d\n", ret[0], ret[1]);
    return ret;
}

int main() {
    int *b = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        b[i] = i + 1;
    }
    twoSum(b, 10, 19);
    return 0;
}
