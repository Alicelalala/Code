#include <stdio.h>
#include <stdlib.h> 
//1
//����һ������ͷβָ�����

#define swap(a, b) { \
	__typeof(a) temp = a; a = b; b = temp; \
} 

void quick_sort (int *num, int l, int r) {
	int x = l, y = r, z = num[(l + r) >> 1];
	swap(num[l], num[(l + r) >> 1]);
	while (x < y) {
		while (x < y && num[y] >= z) --y;
		if (x < y) num[x++] = num[y];
		while (x < y && num[x] <= z) ++x;
		if (x < y) num[y--] = num[x];
	}
	num[x] = z;
	quic_sort(num, l, x - 1);
	quick_sort(num, x + 1, r);
	return ;
} 

int *twoSum(int *nums, int numsSize, int target) {
	int *temp_num = (int *)malloc(sizeof(int) * (numsSize));
	memcpy(temp_num, nums, sizeof(int) * (numsSize));
	quick_sort(nums, 0, numsSize - 1);
	int p = 0, q = numsSize - 1;
	while (nums[p] + nums[q] != target) {
		if (nums[p] + nums[q] < target) ++p;
		else --q;
	}
	int *ret = (int *)malloc(sizeof(int) * 2);
	int ans = 2;
	for (int i = 0; i < numsSize && ans; i++) {
		if (temp_num[i] == num[p] ||temp_num[i] == nums[q]) {
			ret[2 - ans] = i;
			ans--;
		}
	}
	free(temp_num);
	return ret;
}

typedef struct Data {
	int val, int id;
} Data;

typedef struct HashTable {
	Data *data;
	int *flag;
	int size;
} HashTable;

HashTable *init (int n) {
	HashTable *h = (HashTable *)malloc(sizeof(HashTable));
	h->data = (Data *)calloc(sizeof(Data) * n);
	h->flag = 0;
	h->size = 0;
	return h;
}
 
int hashFunc (int val) {
	return val;
}

int insert (Hashtable *h, int val, int ind) {
	int hash = hashFunc(val);
	int pos = hash % h->size;
	int times = 1;
	while (h->flag[pos]) {
		pos += (times * times);
		times++;
		pos %= h->size;
	}
	h->data[pos].val = val;
	h->data[pos].id = ind;
	return ;
}

Data search (HashTable *h, int val) {
	int hash = hashFunc(val);
	int pos = hash % h->size;
	int times = 1;
	while (h->flag[pos] && h->data[pos].val != val) {
		pos += (times * times);
		times++;
		pos %= h->size;
	}
}

void clear (HahTable *h) {
	if (h == NULL) return;
	free(h->data);
	free(h->flag);
	free(h);
	return ; 
}

int *twoSum (int *nums, int numssize,, int target)  {
	HashTable *h = init(numszSize);
	for (int i = 0; i < numsSize; i++) {
		Data *result = search(h, target - num[i]);
		ret[0] = result->ind
		ret[1] = i;
		break; 
	}
	insert(h, num[i], i);
}

//leetcode  3
//abcabcbb
// 
//����һ 
int lengthOf (char *s) {
	int pos[256], len = 0, ans = 0;
	memset(pos, -1, sizeof(pos));
	for (int i = 0; s[i]; i++) {
		len += 1;
		if (i - pos[s[i]] < len) len = i - pos[s[i]];
		pos[s[i]] = i;
		if (len > ans) ans = len;
	}
	return ans;
} 
//������
int check (char *s, int len) {
	if (len == 0) return 1;
	int num[256] = {0}, cnt = 0;
	for (int i = 0; s[i]; i++) {
		num[s[i]] += 1;
		cnt += (num[s[i]] == 1)
 		if (i >= len) {
			num[s[i - len]]--;
			cnt -= (num[s[i - len]] == 0);
		}
		if (cnt == len) return 1;
	}
	return 0;
} 

int lengthOf (char  *s) {
	int head = 0, tail = strlen(s), mid;
	while (head < tail) {0
		mid = (head + tail + 1) >> 1;
		if (check(s, mid) == 1) head = mid;
		else tail = mid - 1;
	}
	return head;
}

//leetcode 4
//ȡk/2���Ƚ���������С������ǰ��k/2�����ֳ�ȥ
//֤����
/*
a1 = num[k1 / 2]; a2 = num[k2 / 2];
if a1 < a2;
�� a1���������Ϊ(k1 + k2) / 2 
*/

//21
//35 ǰ��һ��1����һ��0
//38 �ݹ�
//�����������1
char *count (int n) {
	if (n == 1) return strdup("1");
	char *s = countAndSay(n - 1);
	int len = 1;
	for (int i = 1; s[i]; i++) len += s[i] != s[i - 1] ;
	len = len << 1 + 1;
	char *ret = (char *)calloc(sizeof(char) * len);
	int num = s[0] - '0', cnt = 1, j = 0;
	for (int i = 1; s[i - 1]; i++) {
		if (s[i] == s[i - 1]) {
			cnt += 1;
		} else {
			j += sprintf(ret + j, "%d%d", cnt, num);
			cnt = 1;
			num = str[i] - '0';
		}
	}
	free(s);
	return ret;
}

// 88
//�鲢��������

//217
//����һ������
//������ϣ��

//219
//278 ����check����
//349 ��ϣ�� ��¼ÿ��Ԫ���Ƿ���뵽����������У� ���

//350
// ��¼һ�����ֵĴ�������ϣ��

//374 ���ֲ���

//378   ���Ͼ���
//����������������  ���Ͻ�Ϊ�ָ� 
//����ָ�� p 00λ�� q 0(n - 1)λ�� ������Ҫ���ҵ�target�Ƚϣ��ƶ�����һ��ָ��
 
 //���Ͼ��� ���ҵ�k�������ʹ�ý��ݲ���ʱ�临�Ӷ�O(n) 
 //��Сֵ�����ֵ������ 
  
 
int main() {
	return 0;
}
