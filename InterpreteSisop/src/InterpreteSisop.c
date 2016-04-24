/*
 ============================================================================
 Name        : InterpreteSisop.c
 Author      : marcelocejas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include"InterpreteSisop.h"

AnSISOP_funciones functions = { .AnSISOP_definirVariable = definirVariable,
		.AnSISOP_obtenerPosicionVariable = obtenerPosicionVariable,
		.AnSISOP_dereferenciar = dereferenciar, .AnSISOP_asignar = asignar,
		.AnSISOP_imprimir = imprimir, .AnSISOP_imprimirTexto = imprimirTexto,

};
AnSISOP_kernel kernel_functions = { };
static const int CONTENIDO_VARIABLE = 20;
static const int POSICION_MEMORIA = 0x10;

int main(int argc, char **argv) {

	char* path;
	char line[MAXLINESIZE];
	char* pos;
	FILE *mCod = NULL;

	if (argc != 2) {
		printf("Error de recepcion de parametros.");
		printf("\t%s [PATH\\UMC.config]\n", argv[0]);
		return EXIT_FAILURE;
	}

	path = argv[1];
	mCod = fopen(path, "r");
	memset(line, '\0', MAXLINESIZE);

	while (fgets(line, MAXLINESIZE, mCod)) {

		if ((pos = strchr(line, '\n')) != NULL) {
			if (strstr(line, "#!") != NULL || strstr(line, "end") != NULL) {
				printf("Se leyo un comentario.\n");
				continue;
			}
			if (strstr(line, "begin") != NULL) {
				printf("Inicio del codigo.\n");
				continue;
			}
			if (strstr(line, "begin") != NULL) {
				printf("Inicio del codigo.\n");
				continue;
			}
			strtok(line, "\n");
			printf("Ejecutando '%s'\n", line);
			analizadorLinea(strdup(line), &functions, &kernel_functions);
			printf("================\n");
		} else {
			printf("Programa finalizado.\n");
			break;
		}

		memset(line, '\0', MAXLINESIZE);
	}

	return EXIT_SUCCESS;
}

t_puntero definirVariable(t_nombre_variable variable) {
	printf("definir la variable %c\n", variable);
	return POSICION_MEMORIA;
}

t_puntero obtenerPosicionVariable(t_nombre_variable variable) {
	printf("Obtener posicion de %c\n", variable);
	return POSICION_MEMORIA;
}

t_valor_variable dereferenciar(t_puntero puntero) {
	printf("Dereferenciar %d y su valor es: %d\n", puntero, CONTENIDO_VARIABLE);
	return CONTENIDO_VARIABLE;
}

void asignar(t_puntero puntero, t_valor_variable variable) {
	printf("Asignando en %d el valor %d\n", puntero, variable);
}

void imprimir(t_valor_variable valor) {
	printf("Imprimir %d\n", valor);
}

void imprimirTexto(char* texto) {
	printf("ImprimirTexto: %s", texto);
}
