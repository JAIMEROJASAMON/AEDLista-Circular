/*Rodrigo Mayett Guzman
es el programa principal de la lista */
#include "Lista.h"


int main()
{
	Lista l = Lista();//crea una lista vacia 
	l.AddInicio(4);
	l.AddFinal(27);
	l.AddInicio(5);
	l.AddFinal(10);
	l.AddRef(666,5);
	l.AddInicio(6);
	l.AddInicio(7);	
	l.AddFinal(555);
	l.RemoveInicio();
	l.RemoveFinal();
	l.BuscarElemento(666);
	l.RemoveRef(27);
	//l.VaciarLista();
	l.Show();	
	return 0;
}