#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define HEIGHT 500
#define WIDTH 500

int main(){
    int fd = open("pic.ppm", O_CREAT | O_WRONLY, 0644);
    int w, h, r, g, b;
    char * header = "P3\n500 500\n255\n";
    write(fd, header, strlen(header));
    char pixel[14];
    for(h=0;h<HEIGHT;h++){
        for(w=0;w<WIDTH;w++){
            r = 255 * ((float)(h*w*w % 255) / 255);
            g = 255 * ((float)((h*h-9*w) % 255) / 255);
            b = 255 * ((float)((w*w*w - 2*h) % 255)/255);
            sprintf(pixel, "%d %d %d", r, g, b);
            if(w != WIDTH-1){
                strcat(pixel, " ");
            }
            write(fd, pixel, strlen(pixel));
        }
        write(fd, "\n", strlen("\n"));
    }
    close(fd);
    return 0;
}