#include <stdio.h>

int main(){
  int t,h,te;
  float c;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    scanf("%d",&h);
    scanf("%f",&c);
    scanf("%d",&te);
    if((50 < h) && (0.7 > c) && (5600 < te) ){
      printf("10\n ");
    }
    else if((50 < h) && (0.7 > c) ){
      printf("9 \n");
    }
    else if ((0.7 > c) && (5600 < te) ){
      printf("8 \n");
    }
    else if((50 < h) && (5600 < te) ){
      printf("7\n ");
    }
    else if((50<h) || (0.7>c) || (5600<te) ){
      printf("6 \n");
    }
    else{
      printf("5\n ");
    }
  }
  return 0;
}
