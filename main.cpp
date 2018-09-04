#include <fstream>
#include <sstream>
#include <cstring>
 #include <stdio.h>
#include <stdlib.h>

// Nombre: Mario Urbina

using namespace std;
 int main(int argc, char** argv)
{
  int a=9,m[a-1][a-1];
  void m(int a[][8])
  {
  int i,j;
  for (i=0;i<a;i++)
  {
    for(j=0;j<a;j++)
    {
      m[i][j]=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      a[i][j]=0;
    }
  }
  }
}
  // como secuencia para la prueba se rellena con estos numeros [0,1,7][5,3,2][8,3,9]
  string b,c,c1,c2,c3,c4;
  cout<<"ingresar secuencia"<<endl;
  cin>>b;
  stringstream stream(b);
  while(getline(stream,c,'"'))
  {
    if (c!="")
    {
      c1=c1+c;
    }
  }
void mostrar1(int a[][8])
{
  int i,j;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      cout<<a[i][j];
    }
    cout<<endl;
  }
} 
  stringstream ini(c1);
  while(getline(ini,c,'['))
  {
    if(c!="")
    {
      c2=c2+c;
    }
  }
void mostrar2(int b[],int H)
{
  int i;
  for(i=0;i<H;i++)
  {
    cout<<b[i];
  }
}
  stringstream fn(c2);
  while(getline(fn,c,']'))
  {
    if(c!="")
    {
      c3=c3+c;
    }
  cout<<endl;
}
void agregar(int a[][8],int F[],int C[],int c[],int X)
{
  int i;
  for(i=0;i<X;i++)
  {
    a[F[i]][C[i]]=c[i];
  }
  stringstream casi(c3);
  while(getline(casi,c,';'))
  {
    if(c!="")
    {
      c4=c4+c;
}
int main(int argc,char**argv)
{
  int sud[8][8];
  m(sud);
  int X,i,Y=0,largo=strlen(argv[1]),cant=largo/7,zz=(3*cant)-1,num[zz];
  char arreglo[largo-1];
  strcpy(arreglo,argv[1]);
  for(i=0;i<largo;i++)
  {
    if(arreglo[i]>47&&arreglo[i]<58)
    {
      int X=arreglo[i]-48;
      num[Y]=X;
      Y++;
    }
  }
  int largo=c4.size();
  char numeros[largo-1];
  strcpy(numeros,c4.c_str());
  int contador=0,X,Y;
  for(i=0;i<largo;i++)
  {
    if(contador==0)
    {
      X=numeros[i]-48;
      contador++;
    }
    if(contador==1)
    {
      Y=numeros[i]-48;
      contador++;
    }
    if(contador==2)
    {
      contador=0;
      m[X][Y]=numeros[i]-48;
    }
  int filas[cant-1],columna[cant-1],valor[cant-1],F=0,C=0,c=0;
  for(i=0;i<=zz;i=i+3){
    filas[F]=num[i];
    F++;
  }
  for(i=0;i<a;i++)
  {
    for(j=0;j<a;j++)
    {
      cout<<m[i][j];
    }
    cout<<endl;
  for(i=1;i<=zz;i=i+3)
  {
    columna[C]=num[i];
    C++;
  }
  for(i=2;i<=zz;i=i+3)
  {
    valor[c]=num[i];
    c++;
  }
  agregar(sud,filas,columna,valor,cant);
  mostrar1(sud);
}
