#include "lodepng.h"
#include <stdio.h>
#define e_r
#define e_g
#define e_b


char* loadPng(const char* filename, int* width, int* height) {

  unsigned char* image = NULL;
  unsigned int width, height;

  int error = lodepng_decode32_file(&image, width, height, filename);
  if(error)
  {
    printf("error %u: %s\n", error, lodepng_error_text(error));
  }

  return (image);
}



void writePng(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
  unsigned char* png;
  int pngsize;

  int error = lodepng_encode32(&png, &pngsize, image, width, height);
  if(!error) {
    lodepng_save_file(png, pngsize, filename);
  }
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));
  free(png);
}

void get_pixel(int x, int y, int *r, int *g, int *b, int *a, char* image, int width )
{
   *r =  image[4 * width * y + 4 * x + 0];
   *g =  image[4 * width * y + 4 * x + 1];
   *b =  image[4 * width * y + 4 * x + 2];
   *a =  image[4 * width * y + 4 * x + 3];
   return;
}

void set_pixel(int x, int y,int r, int g, int b, int a, char* image, int width){
    image [4*width*y+4*x+0]=r;
    image [4*width*y+4*x+1]=g;
    image [4*width*y+4*x+2]=b;
    image [4*width*y+4*x+3]=a;
}

bool is_black(int r,g,b){
    int gray=(r+g+b)/3;
    if (gray<128)
        return true;
    else
        return false;
}

void precrocess_image_gauss(char* image, int width, int height){
    int x,y,i,j;
    double G[3][3];
    G[0][0]=0.0924;
    G[0][1]=0.1192;
    G[0][2]=0.0924;
    G[1][0]=0.1192;
    G[1][1]=0.1538;
    G[1][2]=0.1192;
    G[2][0]=0.0924;
    G[2][1]=0.1192;
    G[2][2]=0.0924;
    for (x=1;x<width-1;x++)
        for (y=1;y<height-1;y++)
            for (i=-1;i<=1;i++)
                for (j=-1;j<=1;j++)
                    image[x+i][x+j]+=G[2-i][2-j];
}

void add_edge(int w, int h,int x1,int y1,int x2,int y2,mat[h*w][h*w]){
    mat[x1*w+y1][x2*w+y2]=1;
    mat[x2*w+y2][x1*w+y1]=1;
    return 0;
}

bool is_close (int r1,int r2,int g1,int g2,int b1,int b2){
    return fabs(r1-r2)<e_r && fabs(g1-g2)<e_g && fabs(b1-b2)<e_b
}

int main() {
    char * filename="";
    int w,h;
    scanf("%d",&w);
    scanf("%d",&h);
    char *picture = loadPng("", &w, &h);
    int i,j,k,f,r,g,b,a,r1,r2,g1,g2,b1,b2,a1,a2;
    int mat[w*h][w*h];
    for (i=0;i<w*h;i++){
        for (int j=0;j<w*h;j++){
          mat[i][j]=0;
    for (i=0;i<w;i++)
        for (j=0;j<h;j++){
            get_pixel(i,j,&r,&g,&b,&a,picture,w);
            if (is_black(r,g,b))
                set_pixel(i,j,0,0,0,0,picture,w);
            else
                set_pixel(i,j,255,255,255,0,picture,w);
        }
    precrocess_image_gauss(picture,w,h);
    for (i=0;i<w;i++)
        for (j=0;j<h;j++){
            get_pixel(i,j,&r1,&g1,&b1,&a1,picture,w);
            for(k=0;i<w;r++)
                for(f=0;f<h;f++){
                    get_pixel(k,r,&r2,&g2,&b2,&a2,picture,w);
                    if (i!=k)&&(j!=f)
                        if (is_close(r1,r2,g1,g2,b1,b2))
                            add_edge(w,h,i,j,k,f,mat);
                }
        }
    return 0;
}

    // get filename with picture
        // use library for it!

    // read file and convert it to 2D array
        // function get_pixel is simple

    // analyze 2D array
        // use graph connectivity algorithm for connectivity areas

    // convert 2D array to file and write it
        // use library for it!
