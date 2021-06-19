    #include<stdio.h>
  2 #include<unistd.h>
  3 #include<fcntl.h> 
  5 int main()
  6 {
  7    int fd=open("_shm.c",O_RDWR);                                                                                                        
  8    if(fd<0)
  9    {
 10        perror("open");
 11        return 0;
 12    }
 14    while(1)
 15    {
 16        write(fd,"I am process A",14);
 17        sleep(1);
 18    }
 19    close(fd);
 20    return 0;
 22 }
