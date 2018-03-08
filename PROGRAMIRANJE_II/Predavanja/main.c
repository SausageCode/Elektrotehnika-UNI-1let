#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dogodek(float verjetnost); //prototip funkcije
int dogodek(float verjetnost){
    if((float)rand() / RAND_MAX <= verjetnost){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {

    /*int a;
    float b;
    printf("Vnesi stevilo a:");
    scanf("%d", &a);
    printf("Vnesi drugo stevilo b:");
    scanf("%f", &b);
    printf("%d + %f = %d\n", a, b, a+b);*/

    /*int x = 7;
    x = x/8.0 *8; //ce zapisemo prvo osmico kot 8, potem bi bil x ne-celostevilski. Zato vrne program 0. Ce spremenimo v 8.0, potem ga uposteva kot realno stevilo.
    printf("%d", x);
    */

//    int x, stevec = 0;
//    srand(time(NULL));
//    for(x=0; x < 100000;x++){
//        stevec += dogodek(0.5);
//    }
//    printf("%d", stevec);

    unsigned long i;
    float pBolan = 0.005; //verjetnost da ubije
    float pPozitBolan = 0.99; //resnično bolan verjetnost
    float pPozitZdrav = 0.01;//verjetnost da pokaze da je bolan, ceprav je zdrav
    unsigned long pozit = 0;
    unsigned long pozitBolan = 0;

    srand(time(NULL));
    for(i = 0; i<100000;i++){
        if(dogodek(pBolan)){//vemo da je bolan
            if(dogodek(pPozitBolan)){//testiramo kako dobro izmerimo, ali je bolan
                pozitBolan++;//dodamo ga med bolane in pozitivno testirane
                pozit++;
            }
        }
        else{//testiramo zdravega
            if(dogodek(pPozitZdrav)){//tu se znajde zdrav in pozitivno testiran
                pozit++;
            }
        }
    }
    printf("%f", (float)pozitBolan/pozit); // dobimo rezultat koliko je bolanih na vse pozitivne, vidimo da 2/3 je v bistvu zdravih





    return 0;
}