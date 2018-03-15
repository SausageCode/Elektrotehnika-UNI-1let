#include <stdio.h>
/*Napiši program, ki sešteje, odšteje, zmnoži ali delji dve kompleksni števili oblike z = a+bi in w = c+di, ki sta podana s strani uporabnika v obliki z = a+bi
*/

int main(){

	int a=0;
	int b=0;
	int c=0;
	int d=0;
	char operator;

	printf("Vnesi prvo kompleksno stevilo v obliki a+bi	");
	scanf("\n%d %d", &a, &b);
	printf("Vnesi drugo kompleksno stevilo v obliki a+bi	");
	scanf("\n%d %d", &c, &d);
	printf("Stevili sta z = %d%+di ter w = %d%+di.\n", a, b, c, d);
	printf("Vnesi aritmeticni operator:	");
	scanf("\n %c",&operator);

	switch(operator){
		case '+':
			printf("Vsota stevil z in w je: %d%+di", a+c, b+d);
			break;
		case '-':
			printf("Razlika stevil z in w je: %d%+di", a-c, b-d);
			break;
		case '*':
			printf("Produkt stevil z in w je: %d%+di", a*c-b*d, a*d+b*c);
			break;
		case '/':
			if((c*c+d*d) == 0){printf("Deljenje ni dovoljeno! Ponovno pozenem program.");main();}
			printf("Kvocient stevil z in w je: %.2f%+.2fi \n", (float)(a*c+b*d)/(c*c+d*d),(float)(b*c-a*d)/(c*c+d*d));
			break;
		case ',': // za testerat, da vse naenkrat spise, vpisi vejico za operator
			printf("Vsota stevil z in w je: %d%+di \n", a+c, b+d);
			printf("Razlika stevil z in w je: %d%+di\n", a-c, b-d);
			printf("Produkt stevil z in w je: %d%+di\n", a*c-b*d, a*d+b*c);
			if((c*c+d*d) == 0){printf("Deljenje ni dovoljeno!");}
			printf("Kvocient stevil z in w je: %.2f%+.2fi", (float)(a*c+b*d)/(c*c+d*d),(float)(b*c-a*d)/(c*c+d*d));
			break;
		default:
			printf("Neveljaven vnos!");
			main();
	}
	return 0;
}