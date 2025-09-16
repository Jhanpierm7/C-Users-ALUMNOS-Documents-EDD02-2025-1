#include <stdio.h>

// definición de tipos
typedef struct {
    int codigo;
    double nota;
} estudiante;

// prototipos
double maxNotaRec(const estudiante arr[], int n, int index);
double sumaNotaRec(const estudiante arr[], int n, int index);
void imprimirEstudiantes(const estudiante arr[], int n);

int main() {
    estudiante arr[] = {
        {2024101, 4.5},
        {2024102, 3.2},
        {2024103, 4.8},
        {2024104, 2.9},
        {2024105, 3.7}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Lista de Estudiantes ===\n");
    imprimirEstudiantes(arr, n);

    // 1) Nota máxima
    double maxNota = maxNotaRec(arr, n, 0);
    printf("\nLa nota maxima del curso es: %.2f\n", maxNota);

    // 2) Promedio
    double suma = sumaNotaRec(arr, n, 0);
    double promedio = suma / n;
    printf("El promedio del curso es: %.2f\n", promedio);

    return 0;
}

// funciones recursivas
double maxNotaRec(const estudiante arr[], int n, int index) {
    if (index == n - 1) {
        return arr[index].nota; // caso base
    }
    double maxResto = maxNotaRec(arr, n, index + 1);
    return (arr[index].nota > maxResto) ? arr[index].nota : maxResto;
}

double sumaNotaRec(const estudiante arr[], int n, int index) {
    if (index == n) {
        return 0.0; // caso base
    }
    return arr[index].nota + sumaNotaRec(arr, n, index + 1);
}

// función auxiliar para mostrar lista
void imprimirEstudiantes(const estudiante arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Codigo: %d  |  Nota: %.2f\n", arr[i].codigo, arr[i].nota);
    }
}