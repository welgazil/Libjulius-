

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Librairie qui fournit une fonction de chiffrement par décalage
// les caractères  vont aussi changer de casse 

char * chiffrer(const char * str, int decalage){

	int i = 0;

	

	char * BUFFER = malloc(sizeof(char) * (strlen(str)+1));

	strcpy(BUFFER,str);



	while (BUFFER[i] != '\0') {

		

		if (BUFFER[i] >= 'A' && BUFFER[i] <= 'Z') {

			char c = BUFFER[i] - 'A';
			c += decalage;
			c = c % 26;
			BUFFER[i] = c + 'A';
			BUFFER[i] = tolower(BUFFER[i]);

		}

		else if (BUFFER[i] >= 'a' && BUFFER[i] <= 'z') {

			char c = BUFFER[i] - 'a';
			c += decalage;
			c = c % 26;
			BUFFER[i] = c + 'a';
			BUFFER[i] = toupper(BUFFER[i]);
		}

	i++;

	}
	
	return(BUFFER);

}


