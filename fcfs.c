#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int pid;
    int burst_time;
    int arr_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void print_table(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
    Process p[MAX];
    int i, j, n, burst=0, comp_T=0;
    int sum_waiting_time = 0, sum_turnaround_time=0;
    printf("Enter total number of process: ");
    scanf("%d", &n);
    printf("Enter Arrival time and Burst time of the process\n");
    for(i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("P[%d] : ", i+1);
        scanf("%d", &p[i].arr_time);
        scanf("%d", &p[i].burst_time);
    }

    for(i=0; i<n; i++) 
    {   
        if(i==0)
        {
            p[i].completion_time = p[i].burst_time + p[i].arr_time;
        }
        else
        {
            int arr=0;
            if(p[i].arr_time > p[i-1].completion_time)
                arr = p[i].arr_time-p[i-1].completion_time;
            p[i].completion_time = p[i].burst_time + p[i-1].completion_time + arr; 
        }    
        p[i].turnaround_time=p[i].completion_time-p[i].arr_time;
        sum_turnaround_time+=p[i].turnaround_time;
    }

    for(i=0; i<n; i++) {
        
        p[i].waiting_time = p[i].turnaround_time-p[i].burst_time;
        sum_waiting_time += p[i].waiting_time;
    }       
    puts(""); 
    print_table(p, n);
    puts(""); 
    printf("Total Waiting Time      : %-2d\n", sum_waiting_time);
    printf("Average Waiting Time    : %-2.2lf\n", (double)sum_waiting_time / (double) n);
    printf("Total Turnaround Time   : %-2d\n", sum_turnaround_time);
    printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);

    puts(""); 
    puts("          GANTT CHART          ");
    puts("          ***********          ");
    print_gantt_chart(p, n);
    return 0;
}


void print_table(Process p[], int n)
{
    int i;

    puts("+-----+--------------+------------+-----------------+--------------+-----------------+");
    puts("| PID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time |");
    puts("+-----+--------------+------------+-----------------+--------------+-----------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |      %2d      |     %2d     |        %2d       |      %2d      |        %2d       |\n"
               , p[i].pid, p[i].arr_time, p[i].burst_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time );
        puts("+-----+--------------+------------+-----------------+--------------+-----------------+");
    }

}


void print_gantt_chart(Process p[], int n)
{
    // int i, j;
    // // print top bar
    // printf(" ");
    // for(i=0; i<n; i++) {
    //     for(j=0; j<p[i].burst_time; j++) printf("--");
    //     printf(" ");
    // }
    // printf("\n|");

    // // printing process id in the middle
    // for(i=0; i<n; i++) {
    //     for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
    //     printf("P%d", p[i].pid);
    //     for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
    //     printf("|");
    // }
    // printf("\n ");
    // // printing bottom bar
    // for(i=0; i<n; i++) {
    //     for(j=0; j<p[i].burst_time; j++) printf("--");
    //     printf(" ");
    // }
    // printf("\n");

    // // printing the time line
    // printf("0");
    // for(i=0; i<n; i++) {
    //     for(j=0; j<p[i].burst_time; j++) printf("  ");
    //     if(p[i].completion_time > 9) printf("\b"); // backspace : remove 1 space
    //     printf("%d", p[i].completion_time);

    // }
    // printf("\n");
    int i, j, k;
    int last = p[n-1].completion_time + ( n== 1 ? 0 : p[n-1].completion_time);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        k=0;
        if(i==0)
        {    for(k=0;k<p[i].arr_time;k++) printf("--");
            printf(" ");
        }
        else
        {    for(k=0;k<p[i].arr_time-p[i-1].completion_time;k++) printf("--");
             if(p[i].arr_time-p[i-1].completion_time > 0)
            printf(" ");
        }
        if(k<0)
            k=0;
        for(j=k; j<p[i].burst_time+k; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    int flag=0;
    for(i=0; i<n; i++) {
        flag=0;
        k=0;
         if(i==0){
            for(k=0;k<p[i].arr_time;k++) printf("  ");
            printf("|");
            flag=1;
        }
        else
        {
            for(k=0;k<p[i].arr_time-p[i-1].completion_time;k++) printf("  ");
            if(p[i].arr_time-p[i-1].completion_time > 0){
            printf("|");
            flag=1;}
        }
        if(k<0)
            k=0;
        for(j=k; j<p[i].burst_time-1+k; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=k; j<p[i].burst_time-1+k; j++) printf(" ");
            printf("|");
    }
    printf("\n ");
    // bottom bar
    for(i=0; i<n; i++) {
        k=0;
        if(i==0)
        {
            for(k=0;k<p[i].arr_time;k++) printf("--");
            printf(" ");
        }
        else
        {    for(k=0;k<p[i].arr_time-p[i-1].completion_time;k++) printf("--");
            if(p[i].arr_time-p[i-1].completion_time > 0)
            printf(" ");
        }
        if(k<0)
            k=0;
        for(j=k; j<p[i].burst_time+k; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    // printing waiting time
    printf("0");
    int minus = 0;
    for(i=0; i<n; i++) {
        k=0;
        if(i==0)
        {
            for(k=0;k<p[0].arr_time;k++) printf("  ");
            printf("%d", p[0].arr_time);
        }
        else
        {
            for(k=0;k<p[i].arr_time-p[i-1].completion_time;k++) printf("  ");
            if(p[i].arr_time-p[i-1].completion_time > 0)
            printf("%d", p[i].arr_time);
        }
        // if(p[i].completion_time>9) printf(" ");
        if(k<0)
            k=0;
        // for(j=k; j<p[i].burst_time-minus+k; j++) printf("  ");
        // printf("%d", p[i].completion_time);
        // if(p[i+1].completion_time>9){
        //   minus = 1;
        // }
        // if(i+1 == n )  if (last>9) minus = 1;
        if(p[i].completion_time>9) printf(" ");
        if(p[i].completion_time > 9) printf("\b"); 
        for(j=k;j<p[i].burst_time-minus+k;j++) printf("  ");
        if(i+1 <= n)
        {
            if(p[i].completion_time > 9 && p[i+1].completion_time > 9)
                printf("\b");
        }
        printf("%d",p[i].completion_time);

    }

} 