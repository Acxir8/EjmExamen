#include <stdio.h>
#define Calif 2000 
int main()
{
	int NumCal, PosCal = 0, CueCal = 0, NumPasada, contador, NumComp, copia, encontro = 0, posicion = 0, Elerepetidos=0, NumCali, NumCalN;
	double Cal[Calif][2], copia2;
	scanf_s("%i", &NumCal); //pedir numero de calificaciones 
	//Guardar todos los datos
	NumCali = NumCal;
	NumCalN = NumCal;
	for (PosCal = 0; PosCal < NumCal; PosCal++) //repite hasta el numero de calificaciones 
	{   
		
		for (CueCal = 0; CueCal < 2; CueCal++)//repite 2 veces, para el numero de cuenta y la calificacións
		{
			scanf_s("%lf", &Cal[PosCal][CueCal]); //Guardar numero de cuenta y calificación
		}	
	}
	//Ordenar los datos
	if (NumCal == 1) {
		printf("%i\n", NumCal);
	    printf("%i %f\n", (int)Cal[0][0], Cal[0][1]);
		return 0;
      }
	else {
		for (NumPasada = 0; NumPasada < NumCalN; NumPasada++)
		{
			for (NumComp = 0; NumComp < NumCal - 1; NumComp++)
			{
				CueCal = 0;
				if (Cal[NumComp][CueCal] > Cal[NumComp + 1][CueCal])
				{
					copia = (int)Cal[NumComp + 1][CueCal];
					copia2 = Cal[NumComp + 1][CueCal + 1];
					Cal[NumComp + 1][CueCal] = Cal[NumComp][CueCal];
					Cal[NumComp + 1][CueCal + 1] = Cal[NumComp][CueCal + 1];
					Cal[NumComp][CueCal] = copia;
					Cal[NumComp][CueCal + 1] = copia2;
				}
			}
			//encontrar los repetidos
			for (contador = 0; contador < NumCal; contador++)
			{
				if (Cal[contador][CueCal] == Cal[contador + 1][CueCal])
				{
					if (Cal[contador][CueCal + 1] < Cal[contador + 1][CueCal + 1])
						Cal[contador][CueCal + 1] = Cal[contador + 1][CueCal + 1];//verificamos cual calificacion es mayor y reemplazamos
					encontro = 1; // validamos que encontro una numcuenta repetida
					posicion = contador; //guardamos al posición en la que encontro el numcuenta repetido
					Elerepetidos += 1;
					break;
				}
			}
			if (encontro == 1)
			{
				//inicia el ciclo que recorrerá los números de cuenta desde la posición en la que los encontro
				//borrando así el repetido 
				for (contador = posicion; contador < NumCal; contador++)
				{
					if (Cal[contador][CueCal] == Cal[contador + 1][CueCal])
					{
						if (Cal[contador][CueCal + 1] < Cal[contador + 1][CueCal + 1])
						{
							Cal[contador][CueCal + 1] = Cal[contador + 1][CueCal + 1];
							Cal[contador][CueCal] = Cal[contador + 1][CueCal];
						}
						else {
							Cal[contador][CueCal] = Cal[contador + 1][CueCal];
							Cal[contador + 1][CueCal + 1] = Cal[contador + 2][CueCal + 1];
						}
					}
					else {
						Cal[contador][CueCal] = Cal[contador + 1][CueCal];
						Cal[contador][CueCal + 1] = Cal[contador + 1][CueCal + 1];
					}
				}
				NumCal--;
				encontro = 0;
			}
		}
		int Numtotal = NumCali - Elerepetidos;
		printf("%i\n", Numtotal);
		for (PosCal = 0; PosCal < Numtotal; PosCal++) printf("%i %f\n", (int)Cal[PosCal][0], Cal[PosCal][1]);
	}
	
	return 0;
}

