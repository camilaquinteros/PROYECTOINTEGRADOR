#include <stdio.h>
#include <string.h>

struct empleado {
    char nombre[20];
    int horasTrabajadas;
    int horasExtra;
};

float calcularSueldo(struct empleado emp) {
    const float tarifaHora = 1.50;
    const float tarifaHoraExtra = 2.00;
    int totalHoras = emp.horasTrabajadas + emp.horasExtra;
    float sueldo = (emp.horasTrabajadas * tarifaHora) + (emp.horasExtra * tarifaHoraExtra);
    return sueldo;
}

int main() {
    FILE *archivo;
    archivo = fopen("empleados.txt", "a");  // Abre el archivo en modo "agregar" (append)

    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        return 1;
    }

    while (1) {  // Ejecutar continuamente
        struct empleado emp;

        printf("Ingrese el nombre del empleado (o 'salir' para finalizar): ");
        scanf("%s", emp.nombre);

        if (strcmp(emp.nombre, "salir") == 0) {
            break;  // Salir del bucle si se ingresa "salir"
        }

        printf("Ingrese las horas trabajadas durante el mes: ");
        scanf("%d", &emp.horasTrabajadas);
        printf("Ingrese las horas extra trabajadas: ");
        scanf("%d", &emp.horasExtra);

        float sueldo = calcularSueldo(emp);

        printf("Nombre:%s;", emp.nombre);
        printf("Horas trabajadas:%d;", emp.horasTrabajadas);
        printf("Horas extra trabajadas:%d;", emp.horasExtra);
        printf("Sueldo mensual:$%.2f;", sueldo);

        // Escribir los datos en el archivo
        fprintf(archivo, "%s;%d;%d;%.2f\n", emp.nombre, emp.horasTrabajadas, emp.horasExtra, sueldo);
    }

    fclose(archivo);  // Cerrar el archivo al finalizar
    return 0;
}
