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

  

  Alphabet& operator>>(int shift) {

    if (islower(ch)) {

      ch = (ch - 'a' + shift) % 26 + 'a';

    } else if (isupper(ch)) {

      ch = (ch - 'A' + shift) % 26 + 'A';

    }

    return *this;

  }

  Alphabet& operator<<(int shift) {

    if (islower(ch)) {

      ch = (ch - 'a' - shift + 26) % 26 + 'a';

    } else if (isupper(ch)) {

      ch = (ch - 'A' - shift + 26) % 26 + 'A';

    }

    return *this;

  }

};