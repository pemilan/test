#include <iostream>
using namespace std;
class Vektor
{
  private:
     int Rozmer;
     int *Slozky;
  public:
     Vektor();
     Vektor(int rozmer);
     Vektor(const Vektor& druhy);
     ~Vektor();
     void pricti(const Vektor druhyVektor);
     void pricti(const int *ptr);
     int dejRozmer() const;
     int dejPrvek(int index) const;
     void nastavPrvek(int index, int hodnota);
     int *daj_ptr() const;
};

Vektor::Vektor():Rozmer(0),Slozky(NULL)
{  cout << "constructor 0" << endl;
}


Vektor::Vektor(const Vektor& druhy):Rozmer(druhy.dejRozmer()),Slozky(new int[this->Rozmer])
{
   cout << "constructor druhy" << endl;	

   for(register int p = 0; p<this->Rozmer; p++)
   {
      Slozky[p] = druhy.dejPrvek(p);
   }
}


Vektor::Vektor(int rozmer):Rozmer(rozmer),Slozky(new int[rozmer])
{ cout << "constructor rozmer" << endl;}

Vektor::~Vektor()
{
 cout << "destruktor" << endl;
  delete[] Slozky;
}

inline int Vektor::dejRozmer() const
{
   return Rozmer;
}

inline int Vektor::dejPrvek(int index) const
{
   return ((Rozmer > index) && (index >=0))? Slozky[index] : 0;
}

inline int *Vektor::daj_ptr() const
{
	return Slozky;
}


void Vektor::pricti(const Vektor druhyVektor)
{
   if (this->Rozmer != druhyVektor.dejRozmer())
   {
      return ;
   }
   for(register int p = 0; p<this->Rozmer; p++)
   {
      this->Slozky[p] += druhyVektor.dejPrvek(p);
   }
}


void Vektor::pricti(const int *ptr)
{
   for(register int p = 0; p<this->Rozmer; p++)
   {
      this->Slozky[p] += ptr[p];
   }
}


void Vektor::nastavPrvek(int index, int hodnota)
{
   if ((Rozmer > index) && (index >=0))
   {
      Slozky[index] = hodnota;
   }
}

int main(void)
{
   Vektor v1(4),v2(4);
   int p;
   for(p = 0; p<4; p++)
   {
      v1.nastavPrvek(p,p);
      v2.nastavPrvek(p,2*p+10);
   }
   v1.pricti(v2);
   
   v1.pricti(v2.daj_ptr());   
   v2.nastavPrvek(2,0); /* BUM!!!!!*/
   cout << "v2 prvky: ";
   for(p=0; p<4; p++)
      cout << v2.dejPrvek(p) << '\t';
   
   cout << "Vysledek: ";
   for(p=0; p<4; p++)
      cout << v1.dejPrvek(p) << '\t';
   cout << endl;
   return 0;
}
//local zmena 1 2D
//remote zmena 1
