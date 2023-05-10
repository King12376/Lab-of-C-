class Gate  {
public :

 	Gate *input[2] ;
  virtual bool output() = 0 ; void setValue(Gate *, int) ; void setValue(bool, int) ;
} ;

class TRUE : public Gate  {
  public :
  virtual bool output() { return 1 ; } void setValue(Gate *, int) {} void setValue(bool, int) {}
} ;

class FALSE : public Gate {
  public :
  virtual bool output() { return 0 ; } void setValue(Gate *, int) {} void setValue(bool, int) {}
} ;

TRUE t ; FALSE f ;

void Gate::setValue(bool val, int pin)  {
  if(val) this -> input[pin] = &t ; else this -> input[pin] = &f ;
}

void Gate::setValue(Gate *gate, int pin) { this -> input[pin] = gate ; }

class NOT : public Gate {
  public :
  virtual bool output() { return !(this -> input[0] -> output()) ; } void setValue(bool val, int pin = 0) {
  
  if(val) this -> input[0] = &t ; else this -> input[0] = &f ;

 	}

void setValue(Gate* gate, int pin = 0) { this -> input[0] = gate ; }

} ;

class NAND : public Gate  {
  public :
  virtual bool output() { return !(this -> input[0] -> output()) || !(this -> input[1] -> output()) ; }

} ;

  class NOR : public Gate {
  public :
  virtual bool output() { return !(this -> input[0] -> output()) && !(this -> input[1] -> output()) ; }

} ;

class AND : public Gate {
  public :

 	AND() : Gate()  {

  component[0] = new NOT;
  component[1] = new NAND;

 	}

virtual bool output() {

  component[1]->input[0] = this->input[0];
  component[1]->input[1] = this->input[1];
  component[0]->input[0] = component[1];

 	return(component[0]->output());

 	}

private :

 	Gate *component[2] ;

} ;


class OR : public Gate  {

public :
  OR() : Gate() {

  component[0] = new NOT;
  component[1] = new NOR;

 	}

virtual bool output() {

  component[1]->input[0] = this->input[0];
  component[1]->input[1] = this->input[1];
 	component[0]->input[0] = component[1];

 	return(component[0]->output());

 	}

private :

 	Gate *component[2] ;

} ;


class XOR : public Gate

{

public :

 	XOR() : Gate()

 	{

  component[0] = new OR;

 	component[1] = new NAND;

 	component[2] = new AND;

 	}

virtual bool output()

{

  component[0]->input[0] = this->input[0];

 	component[0]->input[1] = this->input[1];

 	component[1]->input[0] = this->input[0];

 	component[1]->input[1] = this->input[1];

 	component[2]->input[0] = component[0];

 	component[2]->input[1] = component[1];

 	return(component[2]->output());

 	}

private :

 	Gate *component[5] ;

} ;


class Adder

{

public :

virtual void setValue(bool, int) = 0 ; virtual void setValue(Gate *, int) = 0 ; virtual Gate *sum() = 0 ;
virtual Gate *carryOut() = 0 ;

} ;



class OneBitHalfAdder : public Adder

{

public :

 	OneBitHalfAdder()

 	{

component[0] = new XOR;

 	component[1] = new AND;

 	}

virtual void setValue(bool val, int pin)

{

if(val)

 	{

 	component[0]->input[pin] = &t;

 	component[1]->input[pin] = &t;

 	}else

 	{

 	component[0]->input[pin] = &f;

 	component[1]->input[pin] = &f;

 	}

 	}

virtual void setValue(Gate *gate, int pin)

{

  component[0]->input[pin] = gate;

 	component[1]->input[pin] = gate;

 	}

virtual Gate *sum()

{

return component[0];

 	}

virtual Gate *carryOut()

{

return component[1];

 	}

private :

 	Gate *component[2] ;

} ;


class OneBitFullAdder : public Adder

{

public :

 	OneBitFullAdder()

 	{

  a[0] = new OneBitHalfAdder;//First

 	a[1] = new OneBitHalfAdder;//Second

 	carry = new OR;

 	a[1]->setValue(false, 1);

 	}

virtual void setValue(bool val, int pin)

{

if(pin == 2)

 	{

 	a[1]->setValue(val, 1);

 	}else

 	{

 	a[0]->setValue(val, pin);

 	}

 	}

virtual void setValue(Gate *gate, int pin)

{

if(pin == 2)

 	{

 	a[1]->setValue(gate, 1);

 	}else

 	{

 	a[0]->setValue(gate, pin);

 	}

 	}

virtual Gate *sum()

{

a[1]->setValue(a[0]->sum(), 0);

 	return a[1]->sum();

 	}

virtual Gate *carryOut()

{

a[1]->setValue(a[0]->sum(), 0);

 	carry->input[0] = a[0]->carryOut();

 	carry->input[1] = a[1]->carryOut();

 	return carry;

 	}

private :

 	Adder *a[2] ;

 	Gate *carry ;

} ;
