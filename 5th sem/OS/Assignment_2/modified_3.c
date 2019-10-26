#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int N = 25;


int *x;
sem_t *left;
sem_t *mutex;
sem_t *empty;
sem_t *full;
int *in;
int *out;
int *tl;
int *total;

void produce()
{
//printf("tttt\n");
sem_wait(empty);
sem_wait(mutex);

long s = time(NULL);
s = (s*11)%100;
s = (s*s);

x[*in] = s%80 + 1;
printf("Producer:%6d  %2d:%2d  ", getpid(), *in, x[*in]);
*in = (*in+1)%N;

for(int i = 0; i < N; i++)
{
if(x[i] == -1) printf("__ ");
else printf("%2d ", x[i]);
}printf("\n\n");

sleep(1);

sem_post(mutex);
sem_post(full);

}

void consume()
{
//if(sem_trywait(left) == -1) return;
sem_wait(full);
sem_wait(mutex);

*total = *total + x[*out];
printf("Consumer:%6d  %2d:%2d  ", getpid(), *out, x[*out]);
x[*out] = -1;
*out = (*out+1)%N;


for(int i = 0; i < N; i++)
{
if(x[i] == -1) printf("__ ");
else printf("%2d ", x[i]);
}
printf("total = %d\n\n", *total);
//sem_getvalue(left, tl);
//printf("left=%d\n\n", *tl);

sleep(1);

sem_post(mutex);
sem_post(empty);

}

int main()
{
printf("\n\n");
srand(time(0));

int P = 30, C = 7,i;

int pid = getpid(),wpid;

x = mmap(NULL, N*sizeof(int), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

mutex = mmap(NULL, sizeof(*mutex), PROT_READ | PROT_WRITE, MAP_SHARED
| MAP_ANONYMOUS, -1, 0);
empty = mmap(NULL, sizeof(*empty), PROT_READ | PROT_WRITE, MAP_SHARED
| MAP_ANONYMOUS, -1, 0);
full = mmap(NULL, sizeof(*full), PROT_READ | PROT_WRITE, MAP_SHARED |
MAP_ANONYMOUS, -1, 0);
left = mmap(NULL, sizeof(*left), PROT_READ | PROT_WRITE, MAP_SHARED |
MAP_ANONYMOUS, -1, 0);
in = mmap(NULL, sizeof(*in), PROT_READ | PROT_WRITE, MAP_SHARED |
MAP_ANONYMOUS, -1, 0);
out = mmap(NULL, sizeof(*out), PROT_READ | PROT_WRITE, MAP_SHARED |
MAP_ANONYMOUS, -1, 0);
total = mmap(NULL, sizeof(*total), PROT_READ | PROT_WRITE, MAP_SHARED
| MAP_ANONYMOUS, -1, 0);

sem_init(mutex, 1, 1);
sem_init(empty, 1, N);
sem_init(full, 1, 0);
sem_init(left, 1, P); // food left
*in = 0; *out = 0; *total = 0;
for(i=0;i<N;i++) x[i] = -1;

for(i=1; i<=P; i++) if(pid != 0)
{
  pid = fork();
} // producers
if(pid == 0) produce();
if(pid == 0) return 0; // producer exit



for(i=1; i<=C; i++) if(pid != 0) pid = fork(); // consumers

while(pid == 0 && (sem_trywait(left) != -1))
consume();

if(pid == 0) return 0; // comsumer exit

while ((wpid = wait(NULL)) > 0);

printf("\n\n");
return 0;
}
