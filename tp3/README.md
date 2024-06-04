1) A- se nota que el codigo conhilos.py es un seg mas rapido que el codigo sinhilos.py. Si es predecible.

   B- si son parecidos los tiempos de ejecucion.

   c- el programa sin comentar empieza con dos hilos , uno suma y el otro resta. los dos hilos cuando entran a la zona critica utilizan una misma variable, que es acumulador, estos hilos no tienen ningún control por lo que modifican la variable por su conveniencia lo que provoca que compitan por entrar, lo que ocasiona que al final el valor en vez de ser cero, da otro valor incorrecto. Lo que pasa cuando descomentas las líneas es que un hilo entra en un bucle, antes que el otro empieze la ejecución, esto hace el problema quede mas a la vista y no se soluciona el problema.

   A-https://github.com/RodriArrue/ASO2024TPs/blob/main/tp3/2a.jpeg

   B-https://github.com/RodriArrue/ASO2024TPs/blob/main/tp3/2B.c


