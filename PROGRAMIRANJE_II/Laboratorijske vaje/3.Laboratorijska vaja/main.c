#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"
#include <math.h>
#include <time.h>
#define DIM 1000 // veliost stranice

struct kompleks{
        double x;
        double y;
};

struct kompleks sestevanje(struct kompleks a, struct kompleks b);
struct kompleks mnozenje(struct kompleks a, struct kompleks b);
int dolociBarvo(struct kompleks u, struct kompleks c);
unsigned char slika[DIM][DIM];

int main() {

	srand(time(NULL));
	struct kompleks z;
	struct kompleks c;
	int x, y;
	//spodnji odsek generira random koncnico za ime izvozene slike, da se slike med seboj ne prerisujejo, ce se delajo z istim imenom
	char ime[15] = "fraktal_  .bmp";
	ime[8] = rand()%100;
	printf("%c\n", ime[8]);
	//enako bi lahko random nastavke za generiranje slike naredili z random izbiro iz seznama razlicnih znanih nastavkov za lepe vzorce
	c.x = -0.6;//preset
	c.y = 0.43;

	for (x = 0, z.x = -1.7; x < DIM; x++, z.x += 3.4/(DIM-1)){
		for (y = 0, z.y = -1.7; y < DIM; y++, z.y += 3.4/(DIM-1)){
			slika[x][y] = dolociBarvo(z, c);
		}
	}

	shraniBMP(slika, DIM, DIM, ime);

	return 0;
}


struct kompleks sestevanje(struct kompleks a, struct kompleks b){
	struct kompleks r;
	r.x = a.x+b.x;
	r.y = a.y+b.y;
	return r;
    }

struct kompleks mnozenje(struct kompleks a, struct kompleks b){
	struct kompleks r;
	r.x = a.x*b.x-a.y*b.y;
	r.y = a.x*b.y+a.y*b.x;
	return r;
    }

int dolociBarvo(struct kompleks u, struct kompleks c){//u je nas z, ampak je lokalna spremenljivka, tako da ne vpliva na z
	int barva;
	double vel;//dolzina vektorja u(z)
	for(barva=0; barva<255; barva++){
		u = sestevanje(mnozenje(u,u), c);
		vel = sqrt(u.x*u.x+u.y*u.y);
		if(vel > 2) break;//ce nam pobegne radij vektorja cez 2, koncaj
	}
	return 255-barva;
}
