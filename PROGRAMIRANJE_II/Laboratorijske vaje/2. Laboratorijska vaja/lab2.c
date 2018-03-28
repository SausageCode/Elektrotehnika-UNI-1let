#include <stdio.h>
//definiramo nov tip spremenljivke - vektor, ki vsebuje dve komponenti
struct vektor{
	int x;
	int y;
};
//naredimo "prototipe" funkcij, da program ve, da obstajajo, saj se nahajajo po main() funkciji, za lepošto preglednost te
void konjugiranje(struct vektor a, struct vektor b);
void sestevanje(struct vektor a, struct vektor b);
void odstevanje(struct vektor a, struct vektor b);
void mnozenje(struct vektor a, struct vektor b);
void deljenje(struct vektor a, struct vektor b);

int main(){
//definiramo spremenljivke, stevilo izbire ter oba vektorja
	int izbira;
	struct vektor z;
	struct vektor w;
//vprasamo uporabnika, kaj zeli narediti
	printf("Izberi funkcijo: 1 - konjugiranje, 2 - sestevanje, 3 - odstevanje, 4 - mnozenje, 5 - deljenje\t");
	scanf("\n %d", &izbira);
//glede na odlocitev, se izvrsi eden od sledecih primerov
	switch(izbira){
		case 1://konjugiranje
			konjugiranje(z,w);
			break;
		case 2://sestevanje
			sestevanje(z,w);
			break;
		case 3://odstevanje
			odstevanje(z,w);
			break;
		case 4://mnozenje
			mnozenje(z,w);
			break;
		case 5://deljenje
			deljenje(z,w);
			break;
		default:
			printf("NEVELJAVEN VNOS!\n");
	}
//ne gled na to, kaj se je izvedlo, je tega konec, zato vprasamo, ce zeli ponovno pognati program na meni(restart funkcije) ali konca program
	printf("\nŽelite ponovno nazaj na meni ali koncam program? (1 - MENI, 0 - KONEC)\t");
	scanf(" %d", &izbira);
	if(izbira == 1){main();}
	return 0;
}
//funkcije, ki se klicejo v switch stavku glede na izbiro uporabnika
void konjugiranje(struct vektor a, struct vektor b){
	printf("Vnesi stevilo za konjugiranje v obliki a+bi\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Konjugirano stevilo je:\t%d%+di\n", a.x, a.y*(-1));
}
void sestevanje(struct vektor a, struct vektor b){
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Vsota stevil z in w je:\t%d%+di", a.x+b.x, a.y+b.y);
}
void odstevanje(struct vektor a, struct vektor b){
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %d+%di", &b.x, &b.y);
	printf("Razlika stevil z in w je:\t%d.y%+di", a.x-b.x, a.y-b.y);
}
void mnozenje(struct vektor a, struct vektor b){
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %d+%di", &b.x, &b.y);
	printf("Produkt stevil z in w je:\t%d%+di", a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}
void deljenje(struct vektor a, struct vektor b){
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %d+%di", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %d+%di", &b.x, &b.y);
	if((b.x*b.x+b.y*b.y) != 0){
		printf("Kvocient stevil z in w je:\t%.2f%+.2fi \n",(float)(a.x*b.x+a.y*b.y)/(b.x*b.x+b.y*b.y),(float)(a.y*b.x-a.x*b.y)/(b.x*b.x+b.y*b.y));
	}
	else{
		printf("Deljenje z nic NI dovoljeno!");
	}
}