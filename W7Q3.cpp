class PokerCard

{

public:

    PokerCard(std::string s, int f)

    {

        suit = s;

        face = f;

    }

    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)

    {

        out<<"["<<p.face<<" of "<<p.suit<<"]";

        return out;

    }


    bool operator>(PokerCard &b)

    {

      if (face == b.face)

    {

        if (suit == "spade" && b.suit != "spade")

        {

            return true;

        }

        else if (suit == "heart" && b.suit != "spade" && b.suit != "heart")

        {

            return true;

        }

        else if (suit == "diamond" && b.suit == "club")

        {

            return true;

        }

        else

        {

            return false;

        }

    }

    else

    {

        if (face == 1)

        {

            return true;

        }

        else if (b.face == 1)

        {

            return false;

        }

        else

        {

            return face > b.face;

        }

    }

    }

    bool operator<(PokerCard &b)

    {

      return !(operator>(b)) && !(operator==(b));

    }

    bool operator==(PokerCard &b)

    {

      return face == b.face && suit == b.suit;

    }

private:

    std::string suit;

    int face;

};