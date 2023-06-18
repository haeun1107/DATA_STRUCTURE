#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
// 시뮬레이션 설정 상수
#define MAX_SIMUL_TIME 20 // 시뮬레이션 진행 시간
#define MAX_PRINTING_TIME 5 // 각 Job의 가능한 최대 프린트 시간
#define JOB_ARRIVAL_PROB  0.5 // 매 시각 새로운 Job의 도착 확률
#define boolean unsigned char 
#define true 1
#define false 0

// 시뮬레이션을 위한 global variables
int current_time = 0; // 현재 시각
int new_job_id = 0; // 새로운 Job의 ID
int current_job_id; // 현재 프린트하고 있는 Job의 ID
int remaining_time; // 현재 프린트하고 있는 Job의 남은 프린트 시간. 매 시각 1씩 감소
int total_wait_time; // 프린트를 시작한 모든 Job의 대기시간(start time - arrival time)
int num_printed_jobs; // 시뮬레이션이 끝날 때까지 프린트가 시작된 Job의 총 수

typedef struct { 
    int id; // Job ID
    int arrival_time; // Job이 요청된(도착한) 시간
    int duration; // Job의 프린트 시간
} Job;

// Global queue
typedef struct queue* queue_pointer; 
typedef struct queue {
    Job item;
    queue_pointer link; 
} queue;
queue_pointer front, rear;

void addq(Job e);
Job deleteq();
boolean is_queue_empty(); 
void queue_show();

void insert_job_into_queue (int id, int arrival_time, int duration);
void process_next_job();
boolean is_job_arrived();
boolean is_printer_idle();

double randomm();
int get_random_duration();

void addq(Job e) {
    queue_pointer q = (queue_pointer)malloc(sizeof(queue));
    q->item = e;
    q->link = NULL;

    if (is_queue_empty()) front = rear = q;
    else {
        rear->link = q;
        rear = q;
    }
}

Job deleteq() {
    Job e;
    queue_pointer tmp;

    e = front->item;
    tmp = front;
    front = front->link;
    free(tmp);
    return e;
}

boolean is_queue_empty() {
    if (front == NULL)
		return true;
	else
		return false;
}

void queue_show() {
    queue_pointer tmp = front;
    printf("현재 프린터 큐 : [ ");
    while (tmp != NULL) {
        printf("%d<%d>, ", tmp->item.id, tmp->item.duration);
        tmp = tmp->link;
    }
    printf("]\n");
}

// 새 Job을 큐에 삽입
void insert_job_into_queue(int id, int arrival_time, int duration) {
    Job p;
    p.id = id;
    p.arrival_time = arrival_time;
    p.duration = duration;
    addq(p);
    // id, arrival_time, duration 등 설정 후 job p를 큐에 삽입 
    // addq() 사용
    printf("새 jop <%d>이 들어 왔습니다. 프린트 시간은 = %d 입니다. \n", id, duration); 
}

// 다음 job을 큐에서 꺼내 수행(현재 job id, remaining time 등 설정) 
void process_next_job() {
    Job p;
    p = deleteq();
    current_job_id = p.id;
    remaining_time = p.duration - 1;
    total_wait_time += current_time - p.arrival_time;

    // deleteq() 사용 - 다음 job을 큐에서 꺼내 와서
    // current_job_id,
    // remaining_time (duration – 1),
    // total_wait_time (total_wait_time + (current_time – arrival_time)) 등 설정
    ++num_printed_jobs;
    printf(" 프린트를 시작합니다 - jop <%d>... \n", current_job_id); 
}

// 새로운 job이 도착했는지를 랜덤하게 결정. True일 확률은 ARRIVAL_PROB 
boolean is_job_arrived() {
    if(randomm() < JOB_ARRIVAL_PROB) 
        return true;
    else
        return false;
}

// 프린터가 놀고 있으면(현재 job의 remaining time <= 0) true 
boolean is_printer_idle() {
    if(remaining_time <= 0) 
        return true;
    else
        return false;
}

// 0.0 ~ 1.0 사이의 랜덤 값을 반환 
double randomm() {
    return rand() / (double)RAND_MAX;
}

// 1 ~ MAX_PRINTING_TIME+1 사이의 랜덤 값을 반환 
int get_random_duration() {
    return (int)(rand() % MAX_PRINTING_TIME) + 1; 
}