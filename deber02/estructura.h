#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H


typedef struct materia{
	char nameMateria[20];
	int creditos;
	int paralelo;
} materia;

typedef struct estudiante{
	char nameEstudiante[20];
	int nivel;
	char carrera[20];
	int num_materias;
	materia materias [3];
}estudiante;

typedef struct profesor{
	char nameProfesor[20];
	char carrera[20];
	int num_materias;
	materia materias[7];
}profesor;


#endif
