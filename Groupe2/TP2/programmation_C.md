# Synthèse des approches en C

## Débogage avec GDB

1. Compiler avec informations de débogage :

```bash
$ gcc -ggdb3 erreurs.c -o erreurs
```

2. Lancer GDB :

```bash
$ gdb erreurs
```

Vous verrez l’invite `(gdb)`.

3. Exécuter le programme :

```gdb
(gdb) r
```

Le programme s'arrête en cas d'erreur. Pour voir la pile d'appels :

```gdb
(gdb) bt
```

4. Placer un point d'arrêt à la ligne 10 :

```gdb
(gdb) break erreurs.c:10
```

5. Exécuter jusqu’au point d’arrêt :

```gdb
(gdb) r
```

6. Inspecter les variables :

```gdb
(gdb) p tableau
(gdb) p tableau[0]@5
```

7. Avancer instruction par instruction :

```gdb
(gdb) n
```

8. Continuer l’exécution jusqu’au prochain point d’arrêt ou fin :

```gdb
(gdb) continue
```

9. Quitter GDB :

```gdb
(gdb) quit
```

---

## Compilation avec GCC
### Compilation avec étapes détaillées

```bash
# Préprocesseur
gcc -E aire.c -o aire.i

# Compilation
gcc -O2 -S aire.i -o aire.s

# Assemblage
gcc -c aire.s -o aire.o

# Edition de liens
gcc aire.o -lm -o aire

# Exécution
./aire
```

### Compilation multi-fichiers

```bash
# Préprocesseur
gcc -E main.c -o main.i
gcc -E volume.c -o volume.i
gcc -E surface.c -o surface.i

# Compilation avec optimisation
gcc -O3 -c main.i -o main.o
gcc -O3 -c volume.i -o volume.o
gcc -O3 -c surface.i -o surface.o

# Edition de liens
gcc main.o volume.o surface.o -lm -o sphere

# Exécution
./sphere
```

### Compilation avec affichage des alertes
gcc -Wall -Wextra -o chercher chercher.c

## Manipulation de chaîne en C
Une chaîne de caractères est esentiellement un tableau de caractères.
Il y a donc plusieurs façon d'en déclarer une.
 * char string[20];
 * char* string=malloc(20)/realloc(20)  [Ne pas oublier de free à la fin du programme !]

 ### Concaténer une chaîne de caractère
 strcat et strncat
 char * strcat( char * destination, const char * source );
 char * strncat( char * destination, const char * source, size_t size  );   

 ### Copier/Coller une chaîne de caractère
 strcpy et strncpy
 char * strcpy( char * destination, const char * source );  
 char * strncpy( char * destination, const char * source, size_t length );   

## Gestion des structures
La déclaration d’une structure (type défini par le programmeur)
consiste à lister les déclarations des champs de la structure.
struct nom_structure
{
type_champ1 nom_champ1;
type_champ2 nom_champ2;
...
type_champn nom_champn;
}; /* attention au point-virgule! */

### Déclaration d’une variable du type correspondant
struct personne p, p2;
struct trinome t;
Grâce au typedef, notation
moins lourde :
struct personne_ { ... } ;
typedef struct personne_ personne ;
personne p, p2;

## Recherche dans un fichier
### Ouverture/Fermeture du fichier
fopen / fclose

FILE * fopen( const char * filename, const char * accessMode );     
int fclose( FILE * stream );

### Récupération du contenu du fichier
fgets et fgetc

char * fgets( char * string, int maxLength, FILE * stream );  
int fgetc( FILE * stream );