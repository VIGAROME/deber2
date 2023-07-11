

#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



estudiante crearEStudiante(){
	estudiante e;
	int num_mat=0;
	printf("------------Registro de Estudiante-----------\n");
	printf("Nombre: ");
	scanf("%s", e.nameEstudiante);
	printf("Nivel: ");
	scanf("%d", &e.nivel);
	printf("Carrera: ");
	scanf("%s", e.carrera);
	while(num_mat<3 || num_mat>7){
		printf("Ingrese el numero de materias que el estudiante %s va a dar (recuerde que es de 3 a 7): ", e.nameEstudiante);
		scanf("%d", &num_mat);
	}
	e.num_materias=num_mat;
	for(int i =0; i<num_mat;i++){
		materia m;
		registrarMateriaEst( &m);
		e.materias[i]= m;
	}
	return e;
}

profesor crearProfesor(){
	profesor p;
	int num_mat=0;
	printf("------------Registro de profesor-----------\n");
	printf("Nombre: ");
	scanf("%s", p.nameProfesor);
	printf("Carrera: ");
	scanf("%s", p.carrera);
	while(num_mat<2 || num_mat>3){
		printf("Ingrese el numero de materias que el profesor %s va a dar (recuerde que es de 2 a 3): ",p.nameProfesor);
		scanf("%d", &num_mat);
	}
	p.num_materias=num_mat;
	for(int i =0; i<num_mat;i++){
		materia m;
		registrarMateriaProf( &m);
		p.materias[i]= m;
		
	}
	return p;
}




 void registrarMateriaEst(materia *m){
	printf("-----------Registro de materia------------\n");
	printf("Nombre: ");
	scanf("%s", m->nameMateria);
	printf("Cuantos creditos tiene la materia %s: ",m->nameMateria);
	scanf("%d",&m->creditos);
	
}

void registrarMateriaProf(materia *m){
	printf("-----------Registro de materia------------\n");
	printf("Nombre: ");
	scanf("%s", m->nameMateria);
	printf("De que papalelo es la materia %s: ",m->nameMateria);
	scanf("%d",&m->paralelo);
}


void mostrarDatosEstudiante(estudiante e){
	printf("\n------------------\n");
	printf("El estudiante %s esta en el nivel %d de la carrera %s.\nY tiene las siguientes materias registradas\n", e.nameEstudiante, e.nivel, e.carrera);
	for ( int i=0; i<e.num_materias;i++){
		printf("%d: %s -> tiene %d creditos\n", (i+1), e.materias[i].nameMateria, e.materias[i].creditos);
	}
	
	
	
	
}	
	
void mostrarDatosProfesor(profesor p){
	printf("\n------------------\n");
	printf("El profesor %s de la carrera %s.\nTiene las siguientes materias registradas\n", p.nameProfesor, p.carrera);
	for ( int i=0; i<p.num_materias;i++){
		printf("%d: %s -> esta en el paralelo %d \n",(i+1),  p.materias[i].nameMateria, p.materias[i].paralelo);
	}
}


void eliminarMateriaProf( profesor *p, int numMateria){
	
	while(numMateria<=0 || numMateria> p-> num_materias){
		printf("Ingrese el numero de materia: ");
		scanf("%d",&numMateria);
	}
	for(int i = (numMateria-1); i<p->num_materias;i++){
		printf("%s",p->materias[i].nameMateria);
		p->materias[i]=p->materias[i++];
	}
	p->num_materias-=1;
	


}

void eliminarMateriaEst( estudiante *e, int numMateria){
	
	while(numMateria<=0 || numMateria> e-> num_materias){
		printf("Ingrese el numero de materia: ");
		scanf("%d",&numMateria);
	}
	for(int i= numMateria-1; i<e->num_materias-1; i++){
		e->materias[i]=e->materias[i++];
	}
	e->num_materias=e->num_materias-1;


}

void cambiarNivel( estudiante *e){
	int level;
	level = e-> nivel;
	e-> nivel = level+1;
	printf("El estudiante %s estaba en el nivel %d, ahora esta en el nivel %d" , e->nameEstudiante,level,e->nivel);
	
}

