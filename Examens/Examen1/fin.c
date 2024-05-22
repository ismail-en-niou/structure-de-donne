/*(3 pts) On considère la file suivante :

F -> 13 -> 7 -> 9 -> 12 -> 44 -> 67 -> 88 -> 25 -> NULL


Où F est un pointeur sur le début de file et Q est un pointeur sur la fin de file.
On considère avoir déjà programmé les fonctions suivantes :
- enfiler(x) qui sert à ajouter l’élément x à la file.
- defiler() qui sert à supprimer un élément de la file.


Soit la partie du code suivante :
enfiler(5) ;
a = defiler() ;
b = defiler() ;
enfiler(a+b) ;
a = defiler() ;
b = defiler() ;
enfiler(b-a) ;
Après exécution du code précédent, comment sera la file ? Donner les valeurs sur la figure
suivante :

44 -> 67 -> 88 -> 5 -> 20 -> 3
*/