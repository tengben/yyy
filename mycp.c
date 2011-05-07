#include<stdio.h>
#include<stdlib.h>
int mycp(char *src,char *dest)
{
    FILE *fps,*fpd;
    int size;
    char buf[4096];

    fps = fopen(src,"rb");
    if(fps == NULL)
    {
        printf("open %s fail\n",src);
        return (-1);
    }
    fpd = fopen(dest,"wb");
    if(fps == NULL)
    {
        printf("open %s fail\n",dest);
        return (-1);
    
    }
    while(size = fread(buf,1,4096,fps))
            fwrite(buf,1,size,fpd);

    fclose(fps);
    fclose(fpd);
    return 0;
}

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("mycp \n");
        exit(1);
        
    }
    mycp(argv[1],argv[2]);
    printf("sucess\n");
    return 0;
    
}
