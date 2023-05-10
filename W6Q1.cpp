#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class Register {
    public:
    Register() {}
    Register(char s) {
    n = s - '0';
    Convert(n);
}
friend ostream& operator <<(ostream& out, Register reg) {
    out << "01";
    for (int i = 0; i < 3; i++) {
    out << reg.bin[i];
}
return out;
}
private:
    int n;
    int bin[3];
    void Convert(int n) {
    for (int i = 0; i < 3; i++) {
    bin[2-i] = (n >> i) & 1;
}
}
};

class RType {
public:
  RType() {}
  RType(string code) { f = code; }
  void newrd(char s) { rd = Register(s); }
  void newrs(char s) { rs = Register(s); }
  void newrt(char s) { rt = Register(s); }
friend ostream& operator<<(ostream& out, RType ins) {
    out << "000000" << ins.rs << ins.rt << ins.rd << "00000";
    if(ins.f == "add") out << "100000";
    else if(ins.f == "sub") out << "100010";
    else if(ins.f == "or") out << "100101";
    else if(ins.f == "and") out << "100100";
    return out;
}
private:
  Register rd, rs, rt;
  string f;
};

class IType {
public:
  IType() {}
  void input(int num) { Convert(num); }
  void newrs(char s) { rs = Register(s); }
  void newrt(char s) { rt = Register(s); }
friend ostream& operator<<(ostream& out, IType ins) {
    out << "001000" << ins.rs << ins.rt;
    for (int i = 0; i < 16; i++) {
    out << ins.bin[i];
}
return out;
}
private:
  Register rs, rt;
  string f;
  int bin[16];
  void Convert(int n) {
  for (int i = 0; i < 16; i++) {
  bin[15-i] = (n >> i) & 1;
}
}
};

int main() {
string com;
    while(cin >> com) {
    if(com == "add" || com == "sub" || com == "or" || com == "and") {
    RType Rcom = RType(com);
for (int i = 0; i < 3; i++) {
string regis;
cin >> regis;
      switch (i) {
      case 0: Rcom.newrd(regis[2]); break;
      case 1: Rcom.newrs(regis[2]); break;
      case 2: Rcom.newrt(regis[2]); break;
      default: break;
}
}
cout << Rcom << endl;
}
  else if(com == "addi") {
  IType Icom = IType();
for (int i = 0; i < 2; i++) {
string regis;
cin >> regis;
  switch (i) {
  case 0: Icom.newrt(regis[2]); break;
  case 1: Icom.newrs(regis[2]); break;
  default: break;
}
}
int im;
    cin >> im;
    Icom.input(im);
    cout << Icom << endl;
}
}
return 0;
}