#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>


//declare mutex
int flag1=1;
int flag2=0;
pthread_cond_t c;
pthread_mutex_t m;
int cnt=0;
void* loop1inc(void *para)
{
    while(1)
    {
    while(flag1!=1)
    {

    }
    pthread_mutex_lock(&m);
  char *str="SUNBEAM\n";
  for(int i=0;str[i]!='\0';i++)
  {
    write(1,&str[i],1);
    sleep(1);
  }
flag1=0;
flag2=1;
pthread_cond_signal(&c);
  pthread_mutex_unlock(&m);
    }
    return NULL;
}

void* loop2dec(void *para)
{
    while(1){
    pthread_mutex_lock(&m);
    while(flag2==0)
    {
        pthread_cond_wait(&c,&m);
    }
     char *str="INFOTECH\n";
  for(int i=0;str[i]!='\0';i++)
  {
    write(1,&str[i],1);
    sleep(1);
  }
  flag1=1;
  flag2=0;
  pthread_mutex_unlock(&m);
    }    
    return NULL;
}

int main()
{
    pthread_t th1;
    pthread_t th2;
    pthread_mutex_init(&m,NULL);
    pthread_create(&th1,NULL,loop1inc,NULL);
    pthread_create(&th2,NULL,loop2dec,NULL);
    printf("Enter to exit\n");
    getchar();
    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&c);
    return 0;

}


