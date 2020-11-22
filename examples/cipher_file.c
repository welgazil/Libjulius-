
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libjulius.h>

#define TAILLE_MAX 1000

int main(int argc, char * argv[]) {

	char  chaine2[TAILLE_MAX]="";
	char * cryptee = NULL;
	int longueurChaine = 0;
	char *  s = NULL;
	int decalage;

	s = argv[1];

	//chaine2 = (char *)malloc(TAILLE_MAX);

	//cryptee = (char *)malloc(TAILLE_MAX);


	FILE * fp= NULL;

	if (argc==1) {

		fprintf(stderr,"Erreur : nom de fichier absent\n");
		return 1;

	}

	fp = fopen(argv[1],"r");

	decalage = atoi(argv[2]);


	while(fgets(chaine2,TAILLE_MAX+1,fp) != NULL ){
	


	
	printf("message initial à crypte avec un décalage de %d : %s\n",decalage,chaine2);

	cryptee = chiffrer(chaine2,decalage);

	printf("mesage cryptee : %s\n", cryptee);
	//

	}

	//printf("mesage cryptee :\n%s\n", cryptee);


	FILE * fichier2 = NULL;
	fichier2 = fopen(argv[3],"w");

	
	
	fputs(cryptee,fichier2);
	fclose(fichier2);
	

	fclose(fp);
	//  }
	 return 0;

}