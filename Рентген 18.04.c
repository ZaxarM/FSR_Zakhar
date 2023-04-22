#include "lodepng.h"
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define e_r 10
#define e_g 10
#define e_b 10
#define e_a 10

char* loadPng(const char* filename, int* width, int* height) {
  unsigned char* image = NULL;
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

int is_close(int r1, int g1, int b1, int a1, int r2, int g2, int b2, int a2) {
    if (fabs(r1-r2) < e_r
        &&  fabs(g1 - g2) < e_g
        &&  fabs(b1 - b2) < e_b
        &&  fabs(a1 - a2) < e_a)
        return 1;
    else return 0;
    }

int is_black(int r, int g, int b) {
      int gray=(r+g+b)/3;
      if ( gray < 128 ) {
        return 1;
      } else
        return 0;
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
                    image[x+i]+=G[2-i][2-j];
}
struct Graph {
    struct Graph*next;
    int v; // number of vertices of G;
} typedef Graph;

Graph* init_graph(int v) {
    Graph* pG=(Graph*)malloc(sizeof(Graph));
    if (pG==NULL)
        printf("Memory error");
    else{
        pG->v=v;
        pG->next=NULL;
    }
    return pG;
}
void add_edge(int i,int j,int x,int y,int w,int h,Graph*coh_ar[w*h]) {
    int n=i*w+j;
    int m=x*w+y;
    Graph*tmp_el;
    tmp_el=init_graph(m);
    tmp_el->next=coh_ar[n];
    coh_ar[n]=tmp_el;
    return;
}
void set_pixel(int x, char* image){
   image[4*x+0]=255;
   image[4*x+1]=0;
   image[4*x+2]=0;
   image[4*x+3]=0;
   return;
}

void DFS (int V,Graph*coh_ar[V],int col[V],int vert,char* image,int width){
    if (col[vert]){
        printf("visited");
        return;
    }
    col[vert]=-1;
    int i;
    Graph*tmp;
    while(tmp!=NULL)
        if(!col[tmp->v])
            DFS(V,coh_ar,col,tmp->v,image,width);
    col[vert]=1;
    set_pixel(i,image);
    return;
}
int main() {
    char *filename = "skull.png";
    int w, h, i;
    char *picture = loadPng(filename, &w, &h);
    if (picture == NULL){
        printf("I can not read the picture from the file %s. Error.\n", filename);
        return -1;
    }
    precrocess_image_gauss(picture,w,h);
    Graph*coh_ar[w*h];
    for (int i = 1; i < w-1; i++){
        for (int j = 1; j < h-1; j++){
            int r, g, b, a;
            int r1, g1, b1, a1;
            get_pixel(i, j, &r, &g, &b, &a, picture, w);
            get_pixel(i-1, j, &r1, &g1, &b1, &a1, picture, w);
            if (is_close(r,  g,  b,  a, r1, g1, b1, a1  )) {
                        add_edge(i,j,i-1,j,w,h,coh_ar);
                         }
            get_pixel(i+1, j, &r1, &g1, &b1, &a1, picture, w);
            if (is_close(r,  g,  b,  a, r1, g1, b1, a1  )) {
                        add_edge(i,j,i+1,j,w,h,coh_ar);
                         }
            get_pixel(i, j-1, &r1, &g1, &b1, &a1, picture, w);
            if (is_close(r,  g,  b,  a, r1, g1, b1, a1 )) {
                        add_edge(i,j,i,j-1,w,h,coh_ar);
            }
            get_pixel(i, j+1, &r1, &g1, &b1, &a1, picture, w);
            if (is_close(r,  g,  b,  a, r1, g1, b1, a1  )) {
                        add_edge(i,j,i,j+1,w,h,coh_ar);
            }

        }
    }
    int col[w*h];
    for (i=0;i<w*h;i++)
        col[i]=0;
    for (i=0;i<w*h;i++)
        if (col[i]==0)
            DFS(w*h,coh_ar,col,i,picture,w);
    char * new_image = "scull-modified.png";
    writePng(new_image, picture, w, h);
    return 0;
}
