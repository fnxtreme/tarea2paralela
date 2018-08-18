#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

// NOMBRE:MARIO URBINA

using namespace std;

int main(int argc, char** argv)
{
  int i,j,z=9,m[z-1][z-1];
  for(i=0;i<z;i++)
  {
    for(j=0;j<z;j++)
	{
      m[i][j]=0;
    }
  }
  string a,b,c1,c2,c3,c4;
  cout<<"Ingresar la secuencia"<<endl;
  cin>>a;
  stringstream stream(a);
  while (getline(stream,b,'"'))
  {
    if(b!="")
	{
      c1=c1+b;
    }
  }
  stringstream s(c1);
  while (getline(s,b,'['))
  {
    if (b!="")
	{
      c2=c2+b;
    }
  }  
  stringstream r(c2);
  while (getline(r,b,']'))
  {
    if(b!="")
	{
      c3=c3+b;
    }
  }
  stringstream t(c3);
  while (getline(t,b,';'))
  {
    if(b!="")
	{
      c4=c4+b;      
    }
  }
  int l=c4.size();
  char n[l-1];
  strcpy(n,c4.c_str());
  int cont= 0;
  int x,y;
  for(i=0;i<l;i++)
  {    
    if(cont==0)
	{
      x=n[i]-48;
      cont++;
    }
    if(cont==1)
	{
      y=n[i]-48;
      cont++;
    }
    if(cont==2)
	{
      cont= 0;
      m[x][y]=n[i]-48;
    }
  } 
  for(i=0;i<z;i++)
  {
    for(j=0;j<z;j++)
	{
      cout<<m[i][j];
    }
    cout<<endl;
  }
}
