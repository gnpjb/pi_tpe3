es crucial para el funcionamiento del programa
que se cambie todos los ";;" por "; ;"

tambien debe nombrarse el archivo de datos de
datos de aeropuerto como "aeropuerto.csv"
y el de vuelos como "vuelos.csv"

el programa compila con

gcc -Wall -pedantic -std=c99 -g cargarAeropuertos.c cargarNextVuelo.c main.c process_queries.c query1ADT.c query2ADT.c query3ADT.c query4ADT.c TAD.c -o nombre_archivo_salida.o
