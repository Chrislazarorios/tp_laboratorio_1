#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define ARRAY_SIZE 1000

typedef struct
{
    int id;
    int isEmpty;
    //
    char name[51];
    char lastName[51];
    float salary;
    int sector;
}Employee;

int initEmployees(Employee* list, int len);
int findEmptyEmployee(Employee* list, int len, int *position);
int findEmployeeById(Employee* list, int len,int id, int *position);
int addEmployee(Employee* list, int len, int* contadorID);
int removeEmployee(Employee* list, int len);
int modifyEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len);
int promedioEmployees(Employee* list, int len);
int printEmployees(Employee* list, int len);
int informesEmployee(Employee list[], int len);





#endif // employee_H_INCLUDED
