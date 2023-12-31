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
    