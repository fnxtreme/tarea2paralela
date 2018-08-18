#include <iostream>
#include <fstream>
#include <sstream>
#include <mpi.h>

// NOMBRE: MARIO URBINA

using namespace std;
int main(int argc,char* arg[]){
  ifstream infile("UTEM.csv");
  string l;
  MPI_Status status;
  int p,t,co=0,N=0,n,cont=1,c[39];
  for(int i=0;i<40;i++)
  {
    c[i]=0;
  }
  string a[39];
  a[0]="1 Ingeniería En Gestión Turistica";
  a[1]="21042 Ingeniería En Prevención De Riesgos Y Medio Ambiente";
  a[2]="21080 Ingeniería En Química";
  a[3]="21076 Ingenieria Civil Industria";
  a[4]="21031 Ingeniería En Geomensura";
  a[5]="21074 Ingenieria Civil En Obras Civiles";
  a[6]="21012 Contador Publico Y Auditor (diurno)";
  a[7]="21081 Ingeniería En Comercio Internacional";
  a[8]="21075 Ingenieria Civil Electrónica";
  a[9]="21046 Bachillerato En Ciencias De La Ingeniería";
  a[10]="21045 Ingeniería Industrial";
  a[11]="21043 Trabajo Social";
  a[12]="21037 Ingeniería En Mecánica";
  a[13]="21002 Bibliotecología Y Documentación";
  a[14]="21024 Diseño En Comunicacion Visual";
  a[15]="21087 Ingeniería Civil En Prev De Riesgos Y Medio Ambiente";
  a[16]="21048 Ingeniería Comercial";
  a[17]="21039 Ingeniería En Industria Alimentaria";
  a[18]="21030 Ingeniería En Informática";
  a[19]="21032 Ingeniería En Construcción";
  a[20]="21036 Ingeniería En Electrónica";
  a[21]="21041 Ingeniería Civil En Computación Menc Informática";
  a[22]="21023 Diseño Industrial";
  a[23]="21073 Ingenieria En Biotecnología";
  a[24]="21047 Arquitectura";
  a[25]="21083 Química Industrial";
  a[26]="21044 Ingeniería Civil Industrial Con Mención Sistemas De Gestión";
  a[27]="21096 Ingeniería Civil En Mecánica";
  a[28]="21071 Dibujante Proyectista";
  a[29]="21025 Ingeniería En Transporte Y Transito";
  a[30]="21015 Ingeniería En Administración Agroindustrial";
  a[31]="21004 Cartografía";
  a[32]="21088 Cartografía Y Geomática";
  a[33]="Contador Publico Y Auditor (vespertino)";
  a[34]="Magister En Trabajo Social Con Especialización En Competencias Para La Accion Socioeducativa";
  a[35]="Ingeniería Civil Industrial";
  a[36]="Magister En Tecnologia Nuclear";
  a[37]="8091 Magister En Politicas Publicas Y Seguridad Ciudadana";
  a[38]="Magister En Quimica Menciòn Tecnològica De Los Materiales";
  a[39]="OTROS";
  string v;
  string d[13786];
  MPI::Init();
    p=MPI::COMM_WORLD.Get_rank();
    t=MPI::COMM_WORLD.Get_size();
    int P[t-1];
    if(== 0)
	{
      while(getline(infile,l))
	  {
        stringstream stream(l);
        while(getline(stream,v,','))
		{
          co++;
          if(co== 2)
		  {
            d[N]=v;
            N++;
            co=-1;
          }
        }
      }
      for(int X=1;X<13787;X++)
	  {
        n= 39;
        if (d[X]=="1 Ingeniería En Gestión Turistica")
		{
			n=0;
		}
        if (d[X]=="21042 Ingeniería En Prevención De Riesgos Y Medio Ambiente")
		{
			n=1;
		}
        if (d[X]=="21080 Ingeniería En Química")
		{
			n=2;
		}
        if (d[X]=="21076 Ingenieria Civil Industria")
		{
			n=3
		}
        if (d[X]=="21031 Ingeniería En Geomensura")
		{
			n=4;
		}
        if (d[X]=="21074 Ingenieria Civil En Obras Civiles")
		{
			n=5;
		}
        if (d[X]=="21012 Contador Publico Y Auditor (diurno)")
		{
			n=6;
		}
        if (d[X]=="21081 Ingeniería En Comercio Internacional")
		{
			n=7;
		}
        if (d[X]=="21075 Ingenieria Civil Electrónica")
		{
			n=8;
		}
        if (d[X]=="21046 Bachillerato En Ciencias De La Ingeniería")
		{
			n=9;
		}
        if (d[X]=="21045 Ingeniería Industrial")
		{
			n=10;
		}
        if (d[X]=="21043 Trabajo Social")
		{
			n=11;
		}
        if (d[X]=="21037 Ingeniería En Mecánica")
		{
			n=12;
		}
        if (d[X]=="21002 Bibliotecología Y Documentación")
		{
			n=13;
		}
        if (d[X]=="21024 Diseño En Comunicacion Visual")
		{
			n=14;
		}
        if (d[X]=="21087 Ingeniería Civil En Prev De Riesgos Y Medio Ambiente")
		{
			n=15;
		}
        if (d[X]=="21048 Ingeniería Comercial")
		{
			n=16;
		}
        if (d[X]=="21039 Ingeniería En Industria Alimentaria")
		{
			n=17;
		}
        if (d[X]=="21030 Ingeniería En Informática")
		{
			n=18;
		}
        if (d[X]=="21032 Ingeniería En Construcción")
		{
			n=19;
		}
        if (d[X]=="21036 Ingeniería En Electrónica")
		{
			n=20;
		}
        if (d[X]=="21041 Ingeniería Civil En Computación Menc Informática")
		{
			n=21;
		}
        if (d[X]=="21023 Diseño Industrial")
		{
			n=22;
		}
        if (d[X]=="21073 Ingenieria En Biotecnología")
		{
			n=23;
		}
        if (d[X]=="21047 Arquitectura")
		{
			n=24;
		}
        if (d[X]=="21083 Química Industrial")
		{
			n=25;
		}
        if (d[X]=="21044 Ingeniería Civil Industrial Con Mención Sistemas De Gestión")
		{n=26;
		}
        if (d[X]=="21096 Ingeniería Civil En Mecánica")
		{
			n=27;
		}
        if (d[X]=="21071 Dibujante Proyectista")
		{
			n=28;
		}
        if (d[X]=="21025 Ingeniería En Transporte Y Transito")
		{
			n=29;
		}
        if (d[X]=="21015 Ingeniería En Administración Agroindustrial")
		{
			n=30;
		}
        if (d[X]=="21004 Cartografía")
		{
			n=31;
		}
        if (d[X]=="21088 Cartografía Y Geomática")
		{
			n=32;
		}
        if (d[X]=="Contador Publico Y Auditor (vespertino)")
		{
			n=33;
		}
        if (d[X]=="Magister En Trabajo Social Con Especialización En Competencias Para La Accion Socioeducativa")
		{
			n=34;
		}
        if (d[X]=="Ingeniería Civil Industrial")
		{
			n=35;
		}
        if (d[X]=="Magister En Tecnologia Nuclear")
		{
			n=36;
		}
        if (d[X]=="8091 Magister En Politicas Publicas Y Seguridad Ciudadana")
		{
			n=37;
		}
        if (d[X]=="Magister En Quimica Menciòn Tecnològica De Los Materiales")
		{
			n=38;
		}
        if (cont==t)
		{
          cont= 1;
        }
        MPI_Send(&n,1,MPI_INT,cont,0,MPI_COMM_WORLD);
        cont++;
      }
    }
    else if(p!= 0){
      MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      c[n]++;
      P[p]++;      
    }
    for(int i=0;i<40;i++)
	{
      cout<<"carrera: "<<a[i]<<",cantidad : "<<c[i]<<endl;
    }
    for(int i=1;i<t;i++)
	{
      cout<<"procesador"<<i<<"cuenta : "<<P[i]<<endl;
    }
  MPI_Finalize();
}
