#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Posibles {
  vector <bool> _b;
public:
  Posibles(): _b(9,true){}
  bool activo(int v) const {return _b[v-1];}
  void elimina(int v){_b[v-1]=false;}
  int num_activos() const {return count(_b.begin(), _b.end(), true);}
  int val() const{
    vector<bool>::const_iterator it = find(_b.begin(), _b.end(), true);
    return 1 + (it - _b.begin());
  }
  string str(int ancho) const;
};

string Posibles::str(int ancho) const{
  string s(ancho, ' ');
  int i, j=0;
  for(i=1;i<=9;i++){
    if (activo(i)){
      s[++j] = ('0' + i);
    }
  }
  return s;
}

class Sudoku {
  vector <Posibles> _celdas;
  static vector < vector<int> > _grupos, _grupos_de, _vecinos;
public:
  Sudoku(string s);
  static void inicializa();

  Posibles posibles(int k) const {return _celdas[k];}
  bool resuelto() const;
  bool asigna(int k, int val);
  bool elimina(int k, int val);
  void escribe(ostream& o) const;
  int menos_posibilidades() const;
};

bool Sudoku::resuelto() const {
  int k;
  for (k=0;k<_celdas.size();k++){
    if (_celdas[k].num_activos() != 1){
      return false;
    }
  }
  return true;
}

bool Sudoku::elimina(int k, int val){
  int kp, x, n=0, k2, i;
  if (!_celdas[k].activo(val)){
    return true;
  }
  _celdas[k].elimina(val);
  const int N = _celdas[k].num_activos();
  if (N == 0){
    return false;
  } else if (N == 1){
    const int v2 = _celdas[k].val();
    for (i=0;i<_vecinos[k].size();i++){
      if (!elimina(_vecinos[k][i],v2)){ return false;}
    }
  }
  for (x=0;x<3;x++){
    const int g = _grupos_de[k][x];
    for (i=0;i<9;i++){
      const int kp = _grupos[g][i];
      if(_celdas[kp].activo(val)){
        n++;
        k2 = kp;
      }
    }
    if (n==0){
      return false;
    } else if (n==1){
      if(!asigna(k2,val)){ return false;}
    }
  }
  return true;
}

bool Sudoku::asigna(int k, int val){
  int i;
  for(i=1;i<=9;i++){
    if(i != val){
      if(!elimina(k,i)){return false;}
    }
  }
  return true;
}

void Sudoku::escribe(ostream& o) const{
  int i,j,k, ancho = 2;
  for (k=0;k<_celdas.size();k++){
    ancho = max(ancho, 1+ _celdas[k].num_activos());
  }
  string sep(3*ancho, '-');
  for(i=0;i<9;i++){
    if(i==3 || i==6){ cout << sep << "+-" << sep << "+-" << sep << endl;}
    for(j=0;j<9;j++){
      const int k = i*9 + j;
      if(j==3 || j==6){ cout << "| ";}
      cout << _celdas[k].str(ancho);
    }
    cout << endl;
  }
}

vector< vector<int> > Sudoku::_grupos(27), Sudoku::_grupos_de(81), Sudoku::_vecinos(81);

Sudoku::Sudoku(string s) : _celdas(81) {
  int i,k=0;
  for(i=0;i<s.size();i++){
    if(s[i]>='1' && s[i] <= '9'){
        if (!asigna(k, s[i]-'0')){
          cout << "ERROR SUDOKU INICIAL" << endl;
        }
        k++;
    }else if(s[i]=='0' || s[i]=='.'){k++;}
  }
  assert(k==81);
}

void Sudoku::inicializa(){
  int i,j,k,x;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      const int k = i*9+j;
      const int g[3] = {i, 9+j, 18+((i/3)*3) + (j/3)};
      for(x=0;x<3;x++){
        _grupos[g[x]].push_back(k);
        _grupos_de[k].push_back(g[x]);
      }
    }
  }
  for (k=0;k<81;k++){
    for (x=0;x<3;x++){
      const int g = _grupos_de[k][x];
      for(i=0;i<9;i++){
        const int k2 = _grupos[g][i];
        if (k2 != k){
          _vecinos[k].push_back(k2);
        }
      }
    }
  }
}

int Sudoku::menos_posibilidades() const {
  int k, kmin = -1, min;
  for (k=0;k<_celdas.size();k++){
    const int np = _celdas[k].num_activos();
    if (np>1 && (kmin == -1 || np < min)){
      min = np;
      kmin = k;
    }
  }
  return kmin;
}
//NULL
Sudoku* soluciona(Sudoku* S){
  int i;
  if (S == NULL || S->resuelto()){
    return S;
  }
  const int k = S->menos_posibilidades();
  const Posibles p = S->posibles(k);
  for (i=1;i<=9;i++){
    if (p.activo(i)){
      Sudoku *S1 = new Sudoku(*S);
      if (S1->asigna(k, i)){
        Sudoku *S2 = soluciona(S1);
        if ((S2 != NULL) && (S2 != S1)){
          delete S1;
          return S2;
        }
      }
      delete S1;
    }
  }
  return NULL;
}
int main(){
  Sudoku::inicializa();
  //RESUELVE SUDOKU FACIL
  string s, linea;
 // while(getline(cin, linea)) s+= linea;
  Sudoku S(".4...71..53..9..7...7.6.94.4.6.8.751.1....69..53.1...296..3..1.37..51...1..2.9367");
  S.escribe(cout);
  //CODIGO FUNCIONANDO PERO NO TERMINA EL SUDOKU
  //Sudoku S("4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
  //Sudoku *S = soluciona(new Sudoku("4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......"));
  //S->escribe(cout);
}
