#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    int fd_src,fd_dst;
    int n;
    char buf[2048];
    if(argc !=3)//命令行参数3个
    {
        printf("Usage:%s[source file][dest file]\n",argv[0]);
        exit(1);
    }
    fd_src = open(argv[1],O_RDONLY);
    if(fd_src < 0)
    {
        perror("open file error:");
        exit(1);
    }

    fd_dst = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0644);
    if(fd_dst < 0)
    {
        perror("open file error:");
        exit(1);
    }

    while((n = read(fd_src,buf,1024)))
    {
        write(fd_dst,buf,n);
    
    }
    close(fd_src);
    close(fd_dst);
    return 0;
}
