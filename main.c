#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLIBROS 100
#define MAXCADENA 100

//colores

#define COLOR_VERDE "\x1b[32m"
#define COLOR_ROJO "\x1b[31m"
#define COLOR_RESET "\x1b[0m"
int main()
{
    int cantidadLibros;
   char *tabulacion[] = {"TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK", "GANANCIA"};
   char titulos[MAXLIBROS][MAXCADENA];
   char autor[MAXLIBROS][MAXCADENA];
   char genero[MAXLIBROS][MAXCADENA];
   char ISBN[MAXLIBROS][MAXCADENA];
   double precio[MAXLIBROS];
   int stock[MAXLIBROS];
   double ganancias[MAXLIBROS];
   char isbnBuscado[MAXCADENA];
    int encontrado = 0;
   int i;
   int j;
   char opcion;

   printf("INGRESE LA CANTIDAD DE LIBROS A REGISTRAR (MAX %d): ", MAXLIBROS);
   scanf("%d", &cantidadLibros);
   getchar();

printf("\n--------------INGRESO DE DATOS---------------\n");

    for(i=0; i < cantidadLibros; i++){
            printf("INGRESE EL TITULO DEL LIBRO NUMERO %d: ", i + 1);
            fgets(titulos[i], MAXCADENA, stdin);
            titulos[i][strcspn(titulos[i], "\n")] = '\0';
        } printf("\n");

    for(i = 0; i < cantidadLibros; i++){
        printf("INGRESE EL AUTOR DEL LIBRO NUMERO %d: ", i + 1);
        fgets(autor[i], MAXCADENA, stdin);
        autor[i][strcspn(autor[i], "\n")] = '\0';

    } printf("\n");


    for(i=0; i < cantidadLibros; i++){
            printf("INGRESE EL GENERO DEL LIBRO NUMERO %d: ", i + 1);
            fgets(genero[i], MAXCADENA, stdin);
            genero[i][strcspn(genero[i], "\n")] = '\0';
        } printf("\n");


    for(i=0; i < cantidadLibros; i++){
    do{
        printf("INGRESE EL ISBN DEL LIBRO NUMERO %d (10 caracteres): ", i + 1);
            scanf("%10s", ISBN[i]);
        if(strlen(ISBN[i]) != 10){
           printf("ISBN INVALIDO. DEBE TENER EXACTAMENTE 10 CARACTERES\n") ;
       }
     } while (strlen(ISBN[i]) != 10);
    }printf("\n");

    for(i = 0; i< cantidadLibros; i++){
        do{
        printf("INGRESE EL PRECIO DEL LIBRO NUMERO %d:\n", i + 1);
            scanf("%lf", &precio[i]);
        if(precio[i] < 0){
            printf("POR FAVOR INTRODUZCA UN PRECIO VALIDO\n");
        }
    } while (precio[i] < 0);
} printf("\n");

    for(i = 0; i < cantidadLibros; i++){
        printf("INGRESE EL STOCK DEL LIBRO NUMERO %d:\n", i + 1);
        scanf("%d", &stock[i]);
    }printf("\n");


//calculo de las ganancias

    for(i = 0; i < cantidadLibros; i++){
        ganancias[i] = precio[i] * stock[i];
    }

//SALIDA 

    printf("\n------------TABLA---------------\n");

    for (i = 0; i < 7; i++) {
    printf("%-20s|", tabulacion[i]);
    }printf("\n");


    for (i = 0; i < cantidadLibros; i++) {

    char tituloMay[MAXCADENA], autorMay[MAXCADENA], generoMay[MAXCADENA], isbnMay[MAXCADENA];
    for (int j = 0; j < MAXCADENA; j++) {
        tituloMay[j]  = toupper(titulos[i][j]);
        autorMay[j]   = toupper(autor[i][j]);
        generoMay[j]  = toupper(genero[i][j]);
        isbnMay[j]    = toupper(ISBN[i][j]);
    }

    tituloMay[MAXCADENA-1] = '\0';
    autorMay[MAXCADENA-1] = '\0';
    generoMay[MAXCADENA-1] = '\0';
    isbnMay[MAXCADENA-1] = '\0';

    printf("%-20s|", tituloMay);
    printf("%-20s|", autorMay);
    printf("%-20s|", generoMay);
    printf("%-20s|", isbnMay);
    printf("%-20.2lf|", precio[i]);
    printf("%-20d|", stock[i]);

    if (ganancias[i] < 0) {
        printf("%s%-20.2lf%s|", COLOR_ROJO, ganancias[i], COLOR_RESET);
    } else {
        printf("%s%-20.2lf%s|", COLOR_VERDE, ganancias[i], COLOR_RESET);
    }
    printf("\n");
}

    printf("\n---------------FILTRADO--------------\n");
do{
    printf("\nIngrese el ISBN a buscar: ");
    getchar();
    fgets(isbnBuscado, MAXCADENA, stdin);
    isbnBuscado[strcspn(isbnBuscado, "\n")] = '\0';

for (i = 0; i < cantidadLibros; i++) {
    if (strcmp(isbnBuscado, ISBN[i]) == 0) {
        printf("\nResultado: %s | %s | %s | %s |  %.2lf | STOCK: %d\n",
            titulos[i], autor[i], genero[i], ISBN[i], precio[i], stock[i]);
        encontrado = 1;
        break; 
    }
}
if (!encontrado) {
    printf("\nNo se encontró ningún registro con ese ISBN.\n");
}

     printf("\n¿Desea buscar otro libro? (s/n): ");
     scanf(" %c", &opcion);
 } while (opcion == 's' || opcion == 'S');
    return 0;
}



