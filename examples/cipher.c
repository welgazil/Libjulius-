// programme cipher va réaliser un chiffrement en lui fournissant le texte à chiffrer 
// en premier paramètre , et le décalage en deuxième paramètre



#include <stdio.h>
#include <stdlib.h>

#include <libjulius.h>

int main(int argc, char * argv[]) {

	int i;
	int decalage;
	char *s;

	if(argc==1){

		printf("Veuillez saisir un décalage en paramètre\n" );
	}

	if(argc>1) {

		s = argv[1];

		decalage = atoi(argv[2]);

		printf(" La chaîne qui va être cryptée est %s avec le décalage %d \n", s, decalage);



		char * res = chiffrer(s,decalage);
		printf("Texte chiffré : %s \n",res);
		return 0;

	}

}
