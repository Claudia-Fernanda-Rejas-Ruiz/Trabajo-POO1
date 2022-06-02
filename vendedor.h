#include <string>
using namespace std;
class Vendedor{
private:
  string usuario;
  int contraseña;
public:
  Vendedor(){
    
  }
  ~Vendedor(){
    
  }
  void setUsuario(string user){
    usuario=user;
  }
  void setcontraseña(int contraseña){
    usuario=contraseña;
  }
  string getUsuario(){
    return this->usuario;
  }
  int getContraseña(){
    return this->contraseña;
  }

};
