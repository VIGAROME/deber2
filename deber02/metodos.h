

#ifndef METODOS_H
#define METODOS_H
#include "estructura.h"
#include <stdio.h>


profesor crearProfesor();
estudiante crearEStudiante();
void registrarMateriaEst(materia *m);
void registrarMateriaProf(materia *m);
void mostrarDatosEstudiante(estudiante e);
void mostrarDatosProfesor(profesor p);
void eliminarMateriaProf( profesor *p, int numMateria);
void eliminarMateriaEst( estudiante *e, int numMateria);
void cambiarNivel( estudiante *e);
void modificarDatosESt(estudiante);
#endif 
