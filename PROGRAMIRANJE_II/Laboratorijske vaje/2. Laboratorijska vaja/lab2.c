#include <stdio.h>
//definiramo nov tip spremenljivke - vektor, ki vsebuje dve komponenti
struct vektor{
	double x;
	double y;
};
//naredimo "prototipe" funkcij, da program ve, da obstajajo, saj se nahajajo po main() funkciji, za lepošto preglednost te
struct vektor konjugiranje(struct vektor a, struct vektor b);
struct vektor sestevanje(struct vektor a, struct vektor b);
struct vektor odstevanje(struct vektor a, struct vektor b);
struct vektor mnozenje(struct vektor a, struct vektor b);
struct vektor deljenje(struct vektor a, struct vektor b);

int main(){
//definiramo spremenljivke, stevilo izbire ter oba vektorja
	int izbira;
	struct vektor z;
	struct vektor w;
	struct vektor r;
//vprasamo uporabnika, kaj zeli narediti
	printf("Izberi funkcijo: 1 - konjugiranje, 2 - sestevanje, 3 - odstevanje, 4 - mnozenje, 5 - deljenje\t");
	scanf("\n %d", &izbira);
//glede na odlocitev, se izvrsi eden od sledecih primerov
	switch(izbira){
		case 1://konjugiranje
			r = konjugiranje(z, w);
			printf("Konjugirano stevilo z je:\t\t\t%lf%+lfi\n", r.x, r.y);
			break;
		case 2://sestevanje
			r = sestevanje(z, w);
			printf("Vsota stevil z in w je:\t\t\t\t%lf%+lfi\n", r.x, r.y);
			break;
		case 3://odstevanje
			r = odstevanje(z, w);
			printf("Razlika stevil z in w je:\t\t\t\t%lf%+lfi\n", r.x, r.y);
			break;
		case 4://mnozenje
			r = mnozenje(z, w);
			printf("Produkt stevil z in w je:\t\t\t\t%lf%+lfi\n", r.x, r.y);
			break;
		case 5://deljenje
			r = deljenje(z, w);
			printf("kvocient stevil z in w je: \t\t\t %lf%+lf", r.x, r.y);
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
struct vektor konjugiranje(struct vektor a, struct vektor b){
	struct vektor r;
	printf("Vnesi stevilo za konjugiranje v obliki a+bi\t");
	scanf("\n %lf%lfi", &a.x, &a.y);
	r.x = a.x;
	r.y = a.y * (-1);
	return r;
}
struct vektor sestevanje(struct vektor a, struct vektor b){
	struct vektor r;
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %lf%lfi", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %lf%lfi", &b.x, &b.y);
	r.x = a.x+b.x;
	r.y = a.y+b.y;
	return r;
}
struct vektor odstevanje(struct vektor a, struct vektor b){
	struct vektor r;
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %lf%lfi", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %lf%lfi", &b.x, &b.y);
	r.x = a.x-b.x;
	r.y = a.y-b.y;
	return r;
}
struct vektor mnozenje(struct vektor a, struct vektor b){
	struct vektor r;
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %lf%lfi", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %lf%lfi", &b.x, &b.y);
	r.x = a.x*b.x-a.y*b.y;
	r.y = a.x*b.y+a.y*b.x;
	return r;
}
struct vektor deljenje(struct vektor a, struct vektor b){
	struct vektor r;
	printf("Vnesi prvo kompleksno stevilo z v obliki a+bi\t");
	scanf("\n %lf%lfi", &a.x, &a.y);
	printf("Vnesi drugo kompleksno stevilo w v obliki c+di\t");
	scanf("\n %lf%lfi", &b.x, &b.y);
	if((b.x*b.x+b.y*b.y) != 0){
		r.x = (a.x*b.x+a.y*b.y)/(b.x*b.x+b.y*b.y);
		r.y = (a.y*b.x-a.x*b.y)/(b.x*b.x+b.y*b.y);
	}
	else{
		printf("Deljenje z nic NI dovoljeno!");
		r.x = 10101010;
		r.y = 10101010;
	}
	return r;
}