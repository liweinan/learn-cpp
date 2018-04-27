#include <iostream>

#include <iostream>
#include <cmath>
#include <cstdlib>

#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root

unsigned char RD(int, int);

unsigned char GR(int, int);

unsigned char BL(int, int);

void pixel_write(int, int);

FILE *fp;

int main() {
    fp = fopen("MathPic.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
    for (int j = 0; j < DIM; j++)
        for (int i = 0; i < DIM; i++)
            pixel_write(i, j);
    fclose(fp);
    return 0;
}

void pixel_write(int i, int j) {
    static unsigned char color[3];
    color[0] = RD(i, j) & 255;
    color[1] = GR(i, j) & 255;
    color[2] = BL(i, j) & 255;
    fwrite(color, 1, 3, fp);
}

// 实现放在下面：

unsigned char RD(int i,int j){
    static double k;k+=rand()/1./RAND_MAX;int l=k;l%=512;return l>255?511-l:l;
}

unsigned char GR(int i,int j){
    static double k;k+=rand()/1./RAND_MAX;int l=k;l%=512;return l>255?511-l:l;
}

unsigned char BL(int i,int j){
    static double k;k+=rand()/1./RAND_MAX;int l=k;l%=512;return l>255?511-l:l;
}