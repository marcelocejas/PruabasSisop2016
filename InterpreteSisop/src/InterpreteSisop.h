/*
 * InterpreteSisop.h
 *
 *  Created on: 24/4/2016
 *      Author: utnso
 */

#ifndef INTERPRETESISOP_H_
#define INTERPRETESISOP_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parser/parser.h>

#define MAXLINESIZE 100

	t_puntero definirVariable(t_nombre_variable variable);
	t_puntero obtenerPosicionVariable(t_nombre_variable variable);
	t_valor_variable dereferenciar(t_puntero puntero);
	void asignar(t_puntero puntero, t_valor_variable variable);
	void imprimir(t_valor_variable valor);
	void imprimirTexto(char* texto);

#endif /* INTERPRETESISOP_H_ */
