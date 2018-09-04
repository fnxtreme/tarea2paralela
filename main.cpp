#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

// Nombre: Mario Urbina

using namespace std;
// como secuencia para la prueba se rellena con estos numeros [0,1,7][5,3,2][8,3,9]
void m(int a[][8])
{
  int i,j;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      a[i][j]=0;
    }
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
void mostrar2(int b[],int d)
{
  int i;
  for(i=0;i<d;i++)
  {
    cout<<b[i];
  }
  cout<<endl;
}
void agregar(int a[][8],int p[],int q[],int s[],int X)
{
  int i;
  for(i=0;i<X;i++)
  {
    a[p[i]][q[i]]=s[i];
  }
}
void fila1(int a[][8],int p,int s)
{
  int i;
  for(i=0;i<9;i++)
  {
    if(a[p][i]==s)
    {
      cout<<"el valor se encuentra"<<s<< "en la fila: "<<p<<endl;
    }
  }
}
void columna1(int a[][8],int q,int s)
{
  int i;
  for(i=0;i<9;i++)
  {
    if(a[i][q]==s)
    {
      cout<<"el valor se encuentra"<<s<<"en la columna: "<<q<<endl;
    }
  }
}
void regi1(int a[][8],int l,int s)
{
  int i;
  if(l==1)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==2)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=3;j<6;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==3)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=6;j<9;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if (l==4)
  {
    for(int i=3;i<6;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor " <<s<< "se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==5)
  {
    for(int i=3;i<6;i++)
    {
      for(int j=3;j<6;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==6)
  {
    for(int i=3;i<6;i++)
    {
      for(int j=6;j<9;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor " <<s<< "se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==7)
  {
    for(int i=6;i<9;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor " <<s<< "se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==8)
  {
    for(int i=6;i<9;i++)
    {
      for(int j=3;j<6;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
  if(l==9)
  {
    for(int i=6;i<9;i++)
    {
      for(int j=6;j<9;j++)
      {
        if(a[i][j]==s)
        {
          cout<<"valor "<<s<<"se encuentra en la region: "<<l<<endl;
        }
      }
    }
  }
}
int main(int argc, char** argv)
{
int sud[8][8];
m(sud);
int x,i,y=0,largo=strlen(argv[1]),cant=largo/7,zz=(3*cant)-1,num[zz];
char arreglo[largo-1];
strcpy(arreglo,argv[1]);
for(i=0;i<largo;i++)
{
   if (arreglo[i]>47&&arreglo[i]<58)
   {
     int x =arreglo[i]-48;
     num[y] =x;
     y++;
   }
}
int filas[cant-1],columna[cant-1],valor[cant-1],p=0,q=0,s=0;
for(i=0;i<=zz;i=i+3)
{
   filas[p]=num[i];
   p++;
}
for(i=1;i<=zz;i=i+3)
{
   columna[q]=num[i];
   q++;
}
for(i=2;i<=zz;i=i+3)
{
   valor[s]=num[i];
   s++;
}
agregar(sud,filas,columna,valor,cant);
mostrar1(sud);
fila1(sud,0,7);
columna1(sud,3,2);
regi1(sud,1,7);
}
