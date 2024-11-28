#include <iostream>
using namespace std;

class Laptop {
public:
    int ram;
    string* producatoril;
    string brand;
    float pret;
    static int TVA;
    const int anFabricatie;

    Laptop() : anFabricatie(2024), ram(8) {
        this->brand = "Dell";
        this->pret = 3000;
        this->producatoril = NULL;
    }


    Laptop(int ram, string brand, float pret, int anFabricatie) : anFabricatie(anFabricatie) {
        this->ram = ram;
        this->brand = brand;
        this->pret = pret;
        this->producatoril = new string[this->ram];
        for (int i = 0; i < this->ram; i++) {
            this->producatoril[i] = "Intel";
        }
    }


    Laptop(const Laptop& l) : anFabricatie(l.anFabricatie) {
        this->ram = l.ram;
        this->brand = l.brand;
        this->pret = l.pret;
         this->producatoril = new string[l.ram];
            for (int i = 0; i < l.ram; i++) {
                 this->producatoril[i] = l.producatoril[i];
                }
            }

    ~Laptop() {
        if (this->producatoril) {
            delete[] this->producatoril;
        }
    }
    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }
  
};

int Laptop::TVA = 19;

class Incarcator {
public:
    int putere;
    string* compatibilitati;
    string brand;
    float pret;
    static int TVA;
    const int anFabricatie;


    Incarcator() : anFabricatie(2024), putere(20) {
        this->brand = "Generic";
        this->pret = 250;
        this->compatibilitati = NULL;
    }

    Incarcator(int putere, string brand, float pret, int anFabricatie) : anFabricatie(anFabricatie) {
        this->putere = putere;
        this->brand = brand;
        this->pret = pret;
        this->compatibilitati = new string[this->putere];
        for (int i = 0; i < this->putere; i++) {
            this->compatibilitati[i] = "Universal";
        }
    }


    Incarcator(const Incarcator& i) : anFabricatie(i.anFabricatie) {
        this->putere = i.putere;
        this->brand = i.brand;
        this->pret = i.pret;
        this->compatibilitati = new string[i.putere];
            for (int j = 0; j < i.putere; j++) {
                this->compatibilitati[j] = i.compatibilitati[j];
            }
    }

    ~Incarcator() {
        if (this->compatibilitati != NULL) {
            delete[] this->compatibilitati;
        }
    }
    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }
};
int Incarcator::TVA = 19;

class Casti {
public:
    string brand;
    string tip;
    bool wireless;
    float pret;
    string* compatibilitatic;
    int numarcompatibilitatic;
    static int TVA;
    const int anFabricatie;

    Casti() : anFabricatie(2024), numarcompatibilitatic(0) {
        this->brand = "Generic";
        this->tip = "Over-Ear";
        this->wireless = false;
        this->pret = 100;
        this->compatibilitatic = NULL;
    }


    Casti(string brand, string tip, bool wireless, float pret, int anFabricatie, int numarcompatibilitatic, string* compatibilitatic)
        : anFabricatie(anFabricatie) {
        this->brand = brand;
        this->tip = tip;
        this->wireless = wireless;
        this->pret = pret;
        this->numarcompatibilitatic = numarcompatibilitatic;
            this->compatibilitatic = new string[numarcompatibilitatic];
            for (int i = 0; i < numarcompatibilitatic; i++) {
                this->compatibilitatic[i] = compatibilitatic[i];
            }
        }
   
    Casti(const Casti& c) : anFabricatie(c.anFabricatie) {
        this->brand = c.brand;
        this->tip = c.tip;
        this->wireless = c.wireless;
        this->pret = c.pret;
        this->numarcompatibilitatic = c.numarcompatibilitatic;
            this->compatibilitatic = new string[c.numarcompatibilitatic];
            for (int i = 0; i < c.numarcompatibilitatic; i++) {
                this->compatibilitatic[i] = c.compatibilitatic[i];
            }
    }

    ~Casti() {
        if (this->compatibilitatic != NULL) {
            delete[] this->compatibilitatic;
        }
    }

    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }
};
int Casti::TVA = 19;

int main() {
    Laptop laptop1;
    Laptop laptop2(16, "Apple", 8000, 2023);
    Laptop laptop3 = laptop2;

    cout << "Laptop 1 Pret cu TVA: " << Laptop::calculeazaPretCuTVA(laptop1.pret) << endl;

    Incarcator incarcator1;
    Incarcator incarcator2(65, "Samsung", 200, 2023);
    Incarcator incarcator3 = incarcator2;

    cout << "Incarcator 1 Pret cu TVA: " << Incarcator::calculeazaPretCuTVA(incarcator1.pret) << endl;

    string compatibilitati[] = { "Laptop", "Telefon" };
    Casti casti1;
    Casti casti2("Sony", "In-Ear", true, 300, 2023, 2, compatibilitati);
    Casti casti3 = casti2;

    cout << "Casti 1 Pret cu TVA: " << Casti::calculeazaPretCuTVA(casti1.pret) << endl;

    return 0;
}
