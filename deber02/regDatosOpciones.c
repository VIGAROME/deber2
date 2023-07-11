
#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void modificacionesEst(estudiante *e);
void modificacionesProf(profesor *p);

int main (int argc, char *argv[]){
		int cantPersonas=atoi(argv[1]);

		//verificar el numero de personas
		
		while(cantPersonas < 2){
			printf("Ingrese la cantidad de personas a registar \n RECUERDE QUE DEBE SER MAYOR A 2!!!!");
			scanf("%d", &cantPersonas);
		}
		int opt;
		while ((opt = getopt(argc, argv, "pea")) != -1) {
		
		   switch(opt){
			case 'p':{
			     printf("Has ingresado a la opción profesores: %c\n", opt);
			     profesor *profesores =malloc(cantPersonas*sizeof(profesor));
			     for( int i=0; i<cantPersonas ;i++){
			     	profesor p = crearProfesor();
			     	mostrarDatosProfesor(p);
			     	
			     	modificacionesProf( &p);
			     	mostrarDatosProfesor(p);
			     	
			     	profesores[i]=p;
			     }
			     free(profesores);
			     break;		
			}
			
			case 'e':{
			     printf("Has ingresado a la opción estudiante: %c\n", opt);
			     estudiante *estudiantes =malloc(cantPersonas*sizeof(estudiante));
			     for( int i=0; i<cantPersonas ;i++){
			     	estudiante e = crearEStudiante();
			     	mostrarDatosEstudiante(e);
			     	
			     	modificacionesEst(&e);
			     	mostrarDatosEstudiante(e);
			     	
			     	estudiantes[i]=e;
			     }
			     free(estudiantes);
			     break;
			}
		
			case 'a':{
			     printf("Has ingresado a la opción ambas: %c\n", opt);
			     profesor *p =malloc(sizeof(profesor));
			     *p = crearProfesor();
			     mostrarDatosProfesor( *p);
			     
			     modificacionesProf( p);
			     mostrarDatosProfesor( *p);
			     
			     cantPersonas-=1;
			     estudiante *estudiantes =malloc(cantPersonas*sizeof(estudiante));
			     for( int i=0; i<cantPersonas ;i++){
			     	estudiante e=crearEStudiante();
			     	mostrarDatosEstudiante(e);
			     	
			     	modificacionesEst(&e);
			     	mostrarDatosEstudiante(e);
			     	
			     	estudiantes[i]=e;
			     }
			     free(estudiantes);
			     free(p);
			}
			case '?': {
      			     printf("Opción no reconocida: %c\n", optopt);
      			     break;
    			}
		   }
		}
		return 0;	
}


void modificacionesEst(estudiante *e){
//modificar est

char respuesta=' ';
while (respuesta==' '){
	char temp;
	printf("Desea modificar datos del estudiante? ('y' || 'n')\n");
	scanf("%c",&temp);
	if(temp=='y' || temp=='n'){
		respuesta = temp;
	}
}
if (respuesta =='y'){
	int opc=-1;
	
	while(opc==-1){
		int temp;
		printf("-----------Opciones------------\n");
		printf("1: Cambiar nivel\n");
		printf("2: Eliminar matera\n");
		printf("3: salir\n");
		scanf("%d", &temp);
		if (temp==1 || temp==2 || temp==3){
			opc=temp;
		}else{
			printf("Opcion incorrecta\n");
		}
		
	
	}
	switch(opc){
		case 1:{
			cambiarNivel( e);
			break;
		}
		case 2:{
			eliminarMateriaEst( e, -1);
			break;
		}
		case 3:{
			break;
		}
	}
		
}
		     	
		     	
		     	
//
}


void modificacionesProf(profesor *p){


char respuesta=' ';
while (respuesta==' '){
	char temp;
	printf("Desea modificar datos del profesor? ('y' || 'n')\n");
	scanf("%c",&temp);
	if(temp=='y' || temp=='n'){
		respuesta = temp;
	}
}
if (respuesta =='y'){
	int opc=-1;
	
	while(opc==-1){
		int temp;
		printf("-----------Opciones------------\n");
		printf("1: Eliminar matera\n");
		printf("2: salir\n");
		scanf("%d", &temp);
		if (temp==1 || temp==2 ){
			opc=temp;
		}else{
			printf("Opcion incorrecta\n");
		}
		
	
	}
	switch(opc){
		case 1:{
			eliminarMateriaProf( p,-1);
			break;
		}
		case 2:{
			break;
		}
	}
}
		     	
		     	
		     	
//

}
