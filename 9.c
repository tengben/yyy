#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
int main(int argc,char *argv[])
{
    int fd1,fd2;
    struct stat s;
    //fstat(fd1,&s);
    char *p;
    char *q;
    fd1 = open(argv[1],O_RDONLY);
    if(fd1 < 0)
    {
        perror("mmap pd1");
        exit(1);
    }
    if(stat(argv[1],&s) == -1)
    {
       
      perror("fail to start");
      exit(1);
    }
    int len = s.st_size;
    printf("size : %d\n",(int)len);
    p = mmap(NULL,len,PROT_READ,MAP_PRIVATE,fd1,0);
    if(p == MAP_FAILED)
        {
            perror("mmap fd1");
            exit(1);
        }
    
    fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd2 < 0)
    {
        perror("mmap pd2");
        exit(1);
    }
#if 1
    lseek(fd2,len-1,SEEK_SET);
    write(fd2,"",1);
#endif
    q = mmap(NULL,len,PROT_WRITE,MAP_SHARED,fd2,0);
    if(q == MAP_FAILED)
        {
            perror("mmap fd2");
            exit(1);
        }

    memcpy(q,p,len);
    close(fd1);
    close(fd2);
    munmap(p,len);
    munmap(q,len);
    return 0;
}

