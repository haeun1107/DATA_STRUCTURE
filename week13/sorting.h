#define	SIZE 10
#define EXP_SIZE 10000
#define	boolean	int
#define	true	1
#define	false	0

// 정렬할 테스트 데이터
int	original[SIZE] = { 46,9,35,78,24,65,53,81,22,18 };
int experiment[EXP_SIZE];
int sz;

// 키값 비교회수 카운트를 위한 변수
int	num_compare;

// insertion sort
void insertion_sort(int list[], int n, int show);

// quick sort
void quick_sort(int list[], int left, int right, int show);
int partition(int list[], int left, int right);

// merge sort
void merge_sort(int list[], int left, int right, int show);
void merge(int list[], int left, int mid, int right);

// list를 복사 
void copy_list(int original[], int list[], int n);
// list를 left 에서 right 까지만 출력 
void print_list(int list[], int left, int right);

void random_initialize(int list[], int n);
