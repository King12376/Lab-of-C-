class Alphabet {

private:

  char ch;

public:

  // use ch to set the alphabet.

  Alphabet(int ch) {

    this->ch = ch;

  }

  

  friend ostream& operator<<(ostream& os, const Alphabet& a) {

        os << a.ch;

        return os;

    }

    friend char operator+(int shift, const Alphabet& a) {

        return a.ch + shift;

    }

};