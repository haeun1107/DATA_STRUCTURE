#include "queue_simulation.h"

int main(void) {
    front = rear = NULL;
    srand(time(NULL));
    int duration;
    while (current_time < MAX_SIMUL_TIME) { 
        printf("\n----- time %d ----- \n", current_time);
        // 새 job이 들어오면 큐에 삽입 
        if (is_job_arrived()) {
            ++new_job_id;
            duration = get_random_duration(); 
            insert_job_into_queue(new_job_id, current_time, duration);
            }
        // 프린터가 놀고 있으면 다음 job을 수행 
        if (is_printer_idle()) {
            if (!is_queue_empty()) process_next_job();
        }
        // 아직 프린트 중
        else {
            printf("아직 Jop <%d>을 프린트하고 있습니다 ...남은 시간 : %d \n", current_job_id, remaining_time);
            --remaining_time;
        }
        // 현재 큐의 상태를 보여줌 
        queue_show();
        ++current_time;
    } 
    double avg = (double)total_wait_time / num_printed_jobs;
    printf("완료된 프린트 job = %d개\n", num_printed_jobs);
    printf("평균 지연 시간 = %f 단위 시간\n", avg);
}