class Gate
{
    public :
        Gate *input[2] ;
        virtual bool output() = 0 ;
  		void setValue(Gate *, int) ;
        void setValue(bool, int) ;
} ;

class TRUE : public Gate
{
    public :
        virtual bool output() { return 1 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

class FALSE : public Gate
{
    public :
        virtual bool output() { return 0 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

TRUE t ;
FALSE f ;

void Gate::setValue(bool val, int pin)
{
    if(val) this -> input[pin] = &t ;
    else this -> input[pin] = &f ;
}

void Gate::setValue(Gate *gate, int pin) { this -> input[pin] = gate ; }

class NOT : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) ; }
        void setValue(bool val, int pin = 0)
        {
        	if(val) this -> input[0] = &t ;
            else this -> input[0] = &f ;
        }
        void setValue(Gate* gate, int pin = 0) { this -> input[0] = gate ; }
} ;

class NAND : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) || !(this -> input[1] -> output()) ; }
} ;

class NOR : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) && !(this -> input[1] -> output()) ; }
} ;

class AND : public Gate
{
    public :
        AND() : Gate() {}
        virtual bool output() { 
            NAND nand;
            NOT not_gate;
            not_gate.setValue(&nand, 0);
            nand.setValue(this->input[0], 0);
            nand.setValue(this->input[1], 1);
            return not_gate.output();
        }
} ;

class OR : public Gate
{
    public :
        OR() : Gate() {}
        virtual bool output() {
            NOR nor;
            NOT not_gate;
            not_gate.setValue(&nor, 0);
            nor.setValue(this->input[0], 0);
            nor.setValue(this->input[1], 1);
            return not_gate.output();
        }
} ;

class XOR : public Gate
{
    public :
        XOR() : Gate() {}
        virtual bool output() {
            AND and1, and2;
            NOT not1, not2;
            not1.setValue(this->input[0], 0);
            not2.setValue(this->input[1], 0);
            and1.setValue(this->input[0], 0);
            and1.setValue(&not2, 1);
            and2.setValue(&not1, 0);
            and2.setValue(this->input[1], 1);
            OR or_gate;
            or_gate.setValue(&and1, 0);
            or_gate.setValue(&and2, 1);
            return or_gate.output();
        }
} ;