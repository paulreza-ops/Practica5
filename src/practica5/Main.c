#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include <arbol.h>
#include <Nodo.h>

int *crearEntero(int);
void imprimir(void*);

int main(void)
{
    int option, corre_programa, num;
    corre_programa = 1;
	Arbol arbol = {NULL,0,NINGUNO};

    while(corre_programa)
    {       
        printf("\n\r");
        printf("\n\r [1] Insertar en Arbol");
        printf("\n\r [2] Eliminar dato en Arbol");
        printf("\n\r [3] Equilibrar el Arbol");
        printf("\n\r [4] Mostrar Arboles");
        printf("\n\r [5] Terminar programa");

        printf("\n\r Escoge opcion: ");
        scanf("%d",&option);
        clear_buffer();

        switch(option)
            {
            case 1:
					printf(" Numero a insertar: ");
					scanf("%d", &num);
					insertarArbolO(&arbol, crearEntero(num));
                    break;
            case 2:
					printf(" Ingresa el numero a eliminar: ");
            	    scanf("%d", &num);
            	    if (eliminarDatoArbol(&arbol, &num)) {
        	            printf("Dato %d eliminado\n", num);
    	            } else {
 	                   printf("El dato %d no existe en el arbol\n", num);
	                }
                    break;
            case 3:
					equilibrarArbol(&arbol);
    	            break;
            case 4:
					if (arbol.raiz == NULL) {
	                    printf("El arbol esta vacio\n");
	                } else {
    	                printf("\nEstructura del Arbol:\n");
    	                imprimirArbol(arbol, imprimir);
    	                printf("\n");
    	            }
    	            break;
            case 5:
	                liberarArbolPostordenI(arbol.raiz);
	                arbol.raiz = NULL;
	                printf("\n Memoria liberada\n");
					corre_programa = 0;
                    break;
    		}
	}
	printf("\n FIN DE PROGRAMA \n\r");
	return 0;
}

int *crearEntero(int num)
{
	int *dato = calloc(1,sizeof(int));
	*dato = num;
	return dato;
}

void imprimir(void *dato)
{
	printf("%d",*(int*)dato);
}