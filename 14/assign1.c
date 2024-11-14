#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>
#include <string.h>

#define SEM_KEY     0x4321
int semid;
union semun {
    int              val;    /* Value foror SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

void sigint_handler(int sig) {
    int s;
    semctl(semid, 0, IPC_RMID);
    waitpid(-1, &s, 0);
    _exit(1);
}

int main() {
    int ret, i;
    struct sigaction sa;
    union semun su;
    struct sembuf ops[1];

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigint_handler;
    ret = sigaction(SIGINT, &sa, NULL);

  
    semid = semget(SEM_KEY, 2, IPC_CREAT|0600);

    unsigned short init_cnts[]={1,0};
    su.array=init_cnts;
    ret = semctl(semid, 0, SETALL, su);
    if(ret<0)
    {
        perror("failed");
    }

    ret = fork();
    if(ret == 0) {
        
        char *str = "SUNBEAM\n";
        while(1){
            ops[0].sem_num=0;//to set index
            ops[0].sem_op=-1;
            ops[0].sem_flg=0;
            ret=semop(semid,ops,1);
            for(i=0; str[i]!='\0'; i++) {
                write(1, &str[i], 1);
                sleep(1); // print 1 char to stdout
            }
            // V(s);
            ops[0].sem_num = 1;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);
        }
    
    }
    else {// parent process -- print INFOTECH
        while(1){
            ops[0].sem_num=1;
            ops[0].sem_op=-1;
            ops[0].sem_flg=0;
            ret=semop(semid,ops,1);
            
            char *str = "INFOTECH\n";
            for(i=0; str[i]!='\0'; i++) {
                write(1, &str[i], 1);
                sleep(1); 
            }
            ops[0].sem_num = 0;
            ops[0].sem_op = +1;
            ops[0].sem_flg = 0;
            ret = semop(semid, ops, 1);
            // sleep(1);
        }

    }
    return 0;
}