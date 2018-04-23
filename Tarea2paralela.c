#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int contar (char* nom){
  FILE *entrada;
  int ch, lineas;

  if ((entrada = fopen(nom, "r")) == NULL){
     perror(nom);
     return EXIT_FAILURE;
  }
  lineas = 0;
  while ((ch = fgetc(entrada)) != EOF){
     if (ch == '\n')
        lineas++;
  }

  fclose(entrada);
  printf("NUMERO DE LINEAS: %d\n", lineas - 1);

  return EXIT_SUCCESS;
}

int main(int argc, char** argv){

  int tamano, procesador;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &tamano); //obtenemos el tamano
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //captura el rank
  
  contar("utem.csv");
  return 0;

  MPI_Finalize();
}
