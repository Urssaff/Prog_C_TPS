# Bibliothèques
* string.h
* stdio.h
* stdlib.h
* time.h
* stdlib.h

# Références
* koor.fr
* stack overflow
* https://forge.univ-lyon1.fr/sae-c/sae-c-bouanani-dias-mayrand

# Difficulté
* arriver à différencier une expression lambda d'une opération sans avoir à changer le fonctionnement du reste de l'application

# Commentaires
* Mon choix dans la création du tokenizer dans les tps précédents vient montrer ses limites avec une notation peu naturelle pour les expressions lambda (exemple: ( lambda x . ( x + 2 ) * x ) y )
* Un refactoring de l'application avant d'implémenter les lambda a facilité l'implémentation.

