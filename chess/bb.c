#include <stdio.h>
#include<unistd.h>
#include"bb.h"

int main(int argc, const char *argv[])
{
    init_screen();//建立一个BUFF 对显示器进行操作；把显存首地址传给它，先打印点在打印线，然后对鼠标进行操作，打印鼠标，读他的设备文件，先打印一个中间鼠标然后根据操作全不操作使鼠标滑动，press flag 按下鼠标进行 2大块 
    //fb_one_pixel(512,284,0x000000ff);
    //fb_line(1000,400,0,300,0x0000ff00);
    //fb_line(0,400,1000,300,0x0000ff00);
    //fb_line(400,700,600,0,0x0000ff00);
    //fb_line(300,0,600,700,0x0000ff00);
    //fb_circle(500,400,50,0x00ffffff); 
    //fb_circle(300,400,50,0x00ff00ff); 
    //fb_circle(200,400,50,0x00ffff00); 
    //fb_circle(400,400,50,0x00ff0000); 
    //fb_circle(500,400,50,0x0000ff00); 
    //fb_circle(500,400,50,0x0000ffff); 
    //print_board();
    /*
    save_bg(512,394);
    draw_cursor(512,394);
    fb_circle(128,63,15,0x000000ff); 
    sleep(2);
    restore(512,394);
    draw_cursor(300,200);
    fb_circle(128,63,15,0x000000ff); 
    sleep(1);
    restore(300,200);
    draw_cursor(600,300);
    fb_circle(128,63,15,0x000000ff); 
    sleep(1);
    restore(600,300);
    draw_cursor(700,400);
    fb_circle(128,63,15,0x000000ff); 
    sleep(1);
    restore(700,400);
    draw_cursor(800,500);
    fb_circle(128,63,15,0x000000ff); */
    mouse_doing();
    //chess_do();
    
    
    return 0;
}
