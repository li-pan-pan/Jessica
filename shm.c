 #include<stdio.h>
  2 #include<unistd.h>
  3 #include<sys/shm.h>
  4 
  5 #define key 0x23232323
  6 
  7 int main()
  8 {
  9     int shmid=shmget(key,1024,IPC_CREAT|0664);
 10     if(shmid<0)
 11     {
 12         perror("shmget");
 13         return 0;
 14     }
 15     return 0;                                                                                                                           
 16 }
~
