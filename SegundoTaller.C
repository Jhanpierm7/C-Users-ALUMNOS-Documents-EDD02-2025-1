#include <stdio.h>

// Prototipos
void llenarArray(int arr[], int n);
void mostrarArray(int arr[], int n);
void selectionSortAsc(int arr[], int n);
void insertionSortDesc(int arr[], int n);

int main() {
    int arr[10], opcion;
    int n = 10;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Llenar arreglo\n");
        printf("2. Mostrar arreglo\n");
        printf("3. Ordenar con Selection Sort (Ascendente)\n");
        printf("4. Ordenar con Insertion Sort (Descendente)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                llenarArray(arr, n);
                break;
            case 2:
                mostrarArray(arr, n);
                break;
            case 3:
                selectionSortAsc(arr, n);
                break;
            case 4:
                insertionSortDesc(arr, n);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while(opcion != 5);

    return 0;
}

// Llenar arreglo (validando positivos)
void llenarArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese el valor %d (entero positivo): ", i + 1);
            scanf("%d", &arr[i]);
            if (arr[i] <= 0) {
                printf("El numero debe ser positivo. Intente de nuevo.\n");
            }
        } while (arr[i] <= 0);
    }
}

// Mostrar arreglo
void mostrarArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Selecionamos Sort Ascendente
void selectionSortAsc(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambio
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        printf("Paso %d: ", i + 1);
        mostrarArray(arr, n);
    }
    printf("Arreglo final ordenado Ascendente: ");
    mostrarArray(arr, n);
}

// Insertamos el Sort Descendente 
void insertionSortDesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i]; // Elemento a insertar
        int j = i - 1;
        // Desplazar hacia la derecha los elementos menores que 'clave'
        while (j >= 0 && arr[j] < clave) {  // <-- solo cambie el signo
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;

        printf("Paso %d: ", i);
        mostrarArray(arr, n);
    }
    printf("Arreglo final ordenado Descendente: ");
    mostrarArray(arr, n);
}
