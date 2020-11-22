
*************** README ************************

****DESCRIPTION DE LA LIBRAIRIE LIBJULIUS *****

lib : librairies : libjulius.a libjulius.so
include : fichiers d'entêtes : libjulius.h
src : code source 
build : contiendra les exécutables produits 
examples : codes sources d'exemple
makefile

*****************************************************

- la librairie julius (en versions statique et dynamique) 
permet de fournir une fonction de chiffrement par décalage ( chiffre de César ). 
Les caractères cryptés changent aussi de casse. (fonction de le fichier libjulius.c)

- il y a aussi 3 programmes d'exemples 

1) cesar.c : qui réalise un chiffrement/déchiffrement d'une chaîne décrite dans 
une constante symbolique ( "AbCd" )

2) cipher.c : réalise un chiffrement en lui fournissant le décalage à 
appliquer en paramètre et qui fonctionne en réalisant une lecture depuis l'entrée standard

exemple : ./cesar.exe "Abcd" 10 
=> produit le chiffrement de la chaîne "Abcd" avec le décalage 10 

3) cipher_file : permet de chiffrer un fichier .txt dont le chemin est passé en paramètre. Un nouveau fichier .txt va alors être complété par le texte chiffrer. 
( ce fichier s'apelle testecriture.txt )  

************************************************************

