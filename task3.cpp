#include <iostream>
using namespace std;

class Laptop {
private:
    int ram;
    string* producatoril;
    string brand;
    float pret;
    static int TVA;
    const int anFabricatie;
public:
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

    string getBrand() {
        return this->brand;
    }

    void setBrand(string brand) {
        if (brand.length() > 2) {
            this->brand = brand;
        }
    }

    float getPret() {
        return this->pret;
    }

    void setPret(float pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }
    int getRam() { 
        return this->ram; 
    }
    void setRam(int ram) {
        if (ram > 0) {
            this->ram = ram;
        }
    }

    string* getproducatoril() {
        return this->producatoril;
    }

    string getProducator(int index) {
        if (index >= 0 && index < this->ram) {
            return this->producatoril[index];
        }
        else {
            return "NU a fost gasit.";
        }
    }

    void setRam(int ram, string* producatoril) {
        if (ram > 0) {
            this->ram = ram;
            if (this->producatoril != NULL) {
                delete[] this->producatoril;
            }
            this->producatoril = new string[ram];
            for (int i = 0; i < ram; i++) {
                this->producatoril[i] = producatoril[i];
            }
        }
    }


    static void modificaTVA(int noulTVA) {
        if (noulTVA > 0) {
            Laptop::TVA = noulTVA;
        }
    }



    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }


    void afisare() {
        cout << "Laptop Brand: " << brand << endl;
        cout << "RAM: " << ram << endl;
        cout << "Pret: " << pret <<endl;
        cout << "An Fabricatie: " << anFabricatie << endl;
        if (producatoril != NULL) {
            cout << "Producatori: ";
            for (int i = 0; i < ram; i++) {
                cout << producatoril[i] << " ";
            }
            cout << endl;
        }
    }
    friend void afiseazaLaptop(const Laptop& laptop);

};

int Laptop::TVA = 19;

class Incarcator {
private:
    int putere;
    string* compatibilitati;
    string brand;
    float pret;
    static int TVA;
    const int anFabricatie;

public:
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

    string getBrand() {
        return this->brand;
    }

    void setBrand(string brand) {
        if (brand.length() > 2) {
            this->brand = brand;
        }
    }

    float getPret() {
        return this->pret;
    }

    void setPret(float pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }

    int getPutere() { 
        return this->putere; 
    }
    void setPutere(int putere) {
        if (putere > 0) {
            this->putere = putere;
        }
    }

    string* getcompatibilitati() {
        return this->compatibilitati;
    }

    string getCompatibilitate(int index) {
        if (index >= 0 && index < this->putere) {
            return this->compatibilitati[index];
        }
        else {
            return "Nu a fost gasit.";
        }
    }

    void setcompatibilitati(int putere, string* compatibilitati) {
        if (putere > 0) {
            this->putere = putere;
            if (this->compatibilitati != NULL) {
                delete[] this->compatibilitati;
            }
            this->compatibilitati = new string[putere];
            for (int i = 0; i < putere; i++) {
                this->compatibilitati[i] = compatibilitati[i];
            }
        }
    }
    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }

    void afisare() {
        cout << "Incarcator Brand: " << brand << endl;
        cout << "Putere: " << putere << endl;
        cout << "Pret: " << pret << endl;
        cout << "An Fabricatie: " << anFabricatie << endl;
        if (compatibilitati != NULL) {
            cout << "Compatibilitati: ";
            for (int i = 0; i < putere; i++) {
                cout << compatibilitati[i] << " ";
            }
            cout << endl;
        }
    }
    friend void afiseazaIncarcator(const Incarcator& incarcator);
};
int Incarcator::TVA = 19;

class Casti {
private:
    string brand;
    string tip;
    bool wireless;
    float pret;
    string* compatibilitatic;
    int numarcompatibilitatic;
    static int TVA;
    const int anFabricatie;

public:
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

    string getBrand() {
        return this->brand;
    }

    void setBrand(string brand) {
        if (!brand.empty()) {
            this->brand = brand;
        }
    }

    string getTip() {
        return this->tip;
    }

    void setTip(string tip) {
        if (!tip.empty()) {
            this->tip = tip;
        }
    }

    bool Wireless() {
        return this->wireless;
    }

    void setWireless(bool wireless) {
        this->wireless = wireless;
    }

    float getPret() {
        return this->pret;
    }

    void setPret(float pret) {
        if (pret > 0) {
            this->pret = pret;
        }
    }

    string getCompatibilitate(int index) {
        if (index >= 0 && index < this->numarcompatibilitatic) {
            return this->compatibilitatic[index];
        }
        else {
            return "Nu a fost gasit.";
        }
    }


    static float calculeazaPretCuTVA(float pret) {
        return pret + (pret * TVA / 100.0);
    }

    void afisare() {
        cout << "Casti Brand: " << brand << endl;
        cout << "Tip: " << tip << endl;
        cout << "Wireless: " << (wireless ? "Da" : "Nu") << endl;
        cout << "Pret: " << pret << endl;
        cout << "An Fabricatie: " << anFabricatie << endl;
        if (compatibilitatic != NULL) {
            cout << "Compatibilitati: ";
            for (int i = 0; i < numarcompatibilitatic; i++) {
                cout << compatibilitatic[i] << " ";
            }
            cout << endl;
        }
    }

    friend void afiseazaCasti(const Casti& casti);
};
int Casti::TVA = 19;

int main() {
    Laptop laptop1;
    Laptop laptop2(1, "Apple", 8000, 2023);
    Laptop laptop3 = laptop2;

    laptop1.afisare();
    laptop2.afisare();
    laptop3.afisare();

    Incarcator incarcator1;
    Incarcator incarcator2(1, "Samsung", 200, 2023);
    Incarcator incarcator3 = incarcator2;

    incarcator1.afisare();
    incarcator2.afisare();
    incarcator3.afisare();

    string compatibilitati[] = { "Laptop", "Telefon" };
    Casti casti1;
    Casti casti2("Sony", "In-Ear", true, 300, 2023, 2, compatibilitati);
    Casti casti3 = casti2;

    casti1.afisare();
    casti2.afisare();
    casti3.afisare();

    return 0;
}
