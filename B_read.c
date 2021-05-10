  1 #include<stdio.h>
  2 #include<unistd.h>
  3 #include<fcntl.h>
  4 
  5 int main()
  6 {
  7     int fd=open ("_shm.c",O_RDWR);
  8     if(fd<0)
  9     {
 10         perror("open");
 11         return 0;
 12     }
 13     while(1)
 14     {
 15         char buf[1024]={0};
 16         read(fd,buf,sizeof(buf)-1);
 17 
 18         printf("buf: %s\n",buf);
 19         sleep(1);
 20     }                                                                                                                                   
 21     close(fd);
 22     return 0;
 23 }
