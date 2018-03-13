#include <stdio.h>
/*Napiši program, ki sešteje, odšteje, zmnoži ali delji dve kompleksni števili oblike z = a+bi in w = c+di
*/

int main(){

	int a=4;
	int b=-5;
	int c=-5;
	int d=1;
	char operator;

	printf("Stevili sta z = %d%+di ter w = %d%+di.\n", a, b, c, d);

	printf("Vsota stevil z in w je %d%+di \n", a+c, b+d);
	printf("Razlika stevil z in w je %d%+di\n", a-c, b-d);
	printf("Produkt stevil z in w je %d%+di \n", a*c-b*d, a*d+b*c);
	printf("Kvocient stevil z in w je %.2f%+.2fi \n", (float)(a*c+b*d)/(c*c+d*d),(float)(b*c-a*d)/(c*c+d*d));

/*	Vnašanje in ibira aritmetične operacije iz strani uporabnika
	printf("Vnesi realno komponento kompleksnega števila z\n");
	scanf(" %d", &a);
	printf("Vnesi imaginarno komponento kompleksnega števila z\n");
	scanf(" %d", &b);
	printf("Vnesi realno komponento kompleksnega števila w\n");
	scanf(" %d", &c);
	printf("Vnesi imaginarno komponento kompleksnega števila w\n");
	scanf(" %d", &d);
	printf("Vnesi aritmetični operator:\n");
	scanf(" %c",&operator);

	switch(operator){
		case '+':
			printf("Vsota števil z in w je %d%+di \n", a+c, b+d);
			break;
		case '-':
			printf("Razlika števil z in w je %d%+di\n", a-c, b-d);
			break;
		case 'x':
			printf("Produkt števil z in w je %d%+di\n", a*c-b*d, a*d+b*c);
			break;
		default:
			printf("Neveljaven vnos!");
			main();
	}*/
	return 0;
}