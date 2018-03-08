#include <stdio.h>

int main(){
    float x, x0, x1;
    float dx = 0.0000001;
    float integral = 0;
    printf("vnesi spodno mejo");
    scanf("%f",&x0);
    printf("Vnesi zgornjo mejo");
    scanf("%f",&x1);

    for(x=x0; x<x1;x+=dx){
        integral += dx*(2*x*x-5*x);
    }

    printf("Integral znasa: %f\n", integral);

    return 0;
}