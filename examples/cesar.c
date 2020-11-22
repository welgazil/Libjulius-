
#include <stdio.h>

#include <libjulius.h>

#define STR "AbCd"

// cesar réalise un chiffrement d'une chaîne décrite dans une constante
// symbolique STR. On utilise la fonction chiffrer de la librairie libjulius


int main()

{

	printf(" La chaîne qui va être cryptée est %s avec le décalage %d \n", STR, 10);
	char * res = chiffrer(STR,10);
	printf("Texte chiffré : %s \n",res);
	return 0;
}

