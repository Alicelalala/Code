#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_F 10000000
#define MAX_N 10000000

#define TEST_TIME(func)  ({ \
    int begin = clock();\
    int ret = func; \
    int end = clock(); \
    printf("[ %s ] lasttime : %lfms\n", #func, (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000); \
    ret; \
}) 

int buffer_qsort[MAX_N];   //
int buffer_line[MAX_N];

void file_num () {
	FILE *fp = fopen("RandNum", "w");
	int num, i;
	for (i = 0; i < MAX_F; i++) {
		num = rand() % MAX_N;
		fprintf(fp, "%d ", num);		
	}
	fclose(fp);
}

int binarysearch (int a[], int value, int n) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == value) return mid;
		if (a[mid] < value) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int quick_sort (int *data, int left, int right) {
    if (left > right) {
        return 1;
    }
    int pivot = data[left], low = left, high = right;
    while (low < high) {
        while (low < high && data[high] >= pivot) {
            high--;
        }
        data[low] = data[high];
        while (low < high && data[low] <= pivot) {
            low++;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    quick_sort(data, left, low - 1);
    quick_sort(data, low + 1, right);
}

void qsort_print (int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int p,int r, int x)//快排的部分
{
    int i = p- 1, j;
    for(j = p;j<=r;j++)
        {
            if(a[j] <= x)
            {
                i = i + 1;
                swap(&a[j],&a[i]);
            }
        }
    return i;
}

int xian_xing_select (int a[], int p, int r, int k) {
	if ((r - p) < 9)  {
		quick_sort(a, p, r);
		return a[p + k - 1];
	}
	
	int i, j;
	for (i = 0; i <= (r - p - 8) / 9; i++) {
		int s = p + 9 * i;
		int t = s + 8;
		quick_sort(a, s, t);
		swap(&a[p + i], &a[s + 4]);
	}
	int x = xian_xing_select (a, p, p + (r - p - 8) / 9, (r - p + 10) / 10);
	i = partition(a, p, r, x),
	j = i - p + 1;
	if (k <= j) return xian_xing_select(a, p, i, k);
	else return xian_xing_select(a, i + 1, r, k - j);
}

int main() {

	FILE *fr = fopen("RandNum", "r");
    if (fr == NULL) {
	    file_num(); //RandNum文件不存在，创建生成一亿个随机数并存入RandNum文件中 
        fr = fopen("RandNum", "r");
    }
	
	int ans = 0, ans_max;
    printf("please inputing test number need how much : "); //输入用于测试的数据的个数
	scanf("%d", &ans_max);
	
	while (!feof(fr)) {
		if (ans == ans_max) break;
		fscanf(fr, "%d", &buffer_qsort[ans]);
        buffer_line[ans] = buffer_qsort[ans]; //保持用于快排和线性选择的数组初始数组是一样的
		ans++;
	}
	fclose(fr);
		
	int k;
	TEST_TIME(k = xian_xing_select(buffer_line, 0, ans - 1, ans));
	//printf("排在第 %d 位的数为: %d\n", ans, k);
    printf("the %dth number is: %d\n", ans, k);
    
	TEST_TIME(quick_sort(buffer_qsort, 0, ans - 1));
	//printf(": %d\n", buffer_qsort[ans - 1]);
	//qsort_print(buffer_qsort, ans);
	
	int value, location;
	//printf("请输入需要查找的数: "); 
    printf("please input need search number : ");
	scanf("%d", &value);
	location = binarysearch(buffer_qsort, value, ans);
    printf("%d search %s, location : %d\n", value, location >= 0 ? "Success" : "Faluse", location);
	return 0;
}
