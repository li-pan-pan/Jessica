thread_safe.cpp  ⮀                                                                                                                                                                                                                                                                                                                                                    ⮂⮂ buffers 
    1 #include<stdio.h>
    2 #include<unistd.h>
    3 #include<pthread.h>
    4 
    5 #define THREAD_NUM 2
    6 
    7 int g_tickets=100;
    8 pthread_mutex_t my_lock;
    9 
W> 10 void* MyThreadStart(void* arg)
   11 {
   12     while(1)
   13     {
   14         pthread_mutex_lock(&my_lock);
   15         if(g_tickets>0)
   16         {
W> 17             printf("I am %d,I am %p\n",g_tickets,pthread_self());
   18             g_tickets--;
   19         }
   20         else
   21         {
   22             pthread_mutex_lock(&my_lock);
   23             pthread_exit(NULL);
   24         }
   25         pthread_mutex_unlock(&my_lock);
   26     }
   27     return NULL;
   28 }
   29 
   30 int main()
   31 {
   32     pthread_mutex_init(&my_lock,NULL);
   33 
   34     pthread_t tid[THREAD_NUM];                                                                                                                                                                                                                                                                                                                                                    
   35     for(int i=0;i<THREAD_NUM;i++)
   36     {
   37         int ret=pthread_create(&tid[i],NULL,MyThreadStart,NULL);
   38         if(ret<0)
   39         {
   40             perror("pthread_create");
   41             return 0;
   42         }
   43     }
   44 
   45     for(int i=0;i<THREAD_NUM;i++)
   46     {
   47         pthread_join(tid[i],NULL);
   48     }
   49 
   50     pthread_mutex_destroy(&my_lock);
   51     printf("pthread_join end...\n");
   52     return 0;
   53 }
