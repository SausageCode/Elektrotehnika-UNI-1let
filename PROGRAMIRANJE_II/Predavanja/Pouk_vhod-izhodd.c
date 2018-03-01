#include <stdio.h>

int main(){
    int a;
    int b;

    printf("Vprisi prvo vrednost");
    scanf("%d", &a);
    printf("Vpisi drugo vrednos");
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a+b);

    return 0;
}