#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Trupmena {
    int sveikoji;
    int skaitiklis;
    int vardiklis;
};

int rastiDBD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void suprastintiTrupmena(Trupmena &t) {
    long long bendrasSkaitiklis = (long long)t.sveikoji * t.vardiklis + t.skaitiklis;
    
    if (bendrasSkaitiklis == 0) {
        t.sveikoji = 0;
        t.skaitiklis = 0;
        t.vardiklis = 1;
        return;
    }
    
    int dbd = rastiDBD(bendrasSkaitiklis, t.vardiklis);
    bendrasSkaitiklis /= dbd;
    t.vardiklis /= dbd;
    
    t.sveikoji = bendrasSkaitiklis / t.vardiklis;
    t.skaitiklis = abs(bendrasSkaitiklis % t.vardiklis);
    
    if (t.sveikoji == 0 && bendrasSkaitiklis < 0) {
        t.skaitiklis = -t.skaitiklis;
    }
}

void skaiciuotiSumaIrSkirtuma(Trupmena t1, Trupmena t2, Trupmena &suma, Trupmena &skirtumas) {
    long long skait1 = (long long)t1.sveikoji * t1.vardiklis + t1.skaitiklis;
    long long skait2 = (long long)t2.sveikoji * t2.vardiklis + t2.skaitiklis;
    
    long long bendrasVardiklis = (long long)t1.vardiklis * t2.vardiklis;
    
    suma.sveikoji = 0;
    suma.skaitiklis = skait1 * t2.vardiklis + skait2 * t1.vardiklis;
    suma.vardiklis = bendrasVardiklis;
    suprastintiTrupmena(suma);
    
    skirtumas.sveikoji = 0;
    skirtumas.skaitiklis = skait1 * t2.vardiklis - skait2 * t1.vardiklis;
    skirtumas.vardiklis = bendrasVardiklis;
    suprastintiTrupmena(skirtumas);
}

void isvestiTrupmena(ofstream &fr, Trupmena t) {
    bool yraNeigiama = (t.sveikoji < 0) || (t.sveikoji == 0 && t.skaitiklis < 0);
    
    int rodomasSveikas = abs(t.sveikoji);
    int rodomasSkaitiklis = abs(t.skaitiklis);
    
    if (rodomasSkaitiklis == 0) {
        if (yraNeigiama) fr << setw(6) << -rodomasSveikas;
        else fr << setw(6) << rodomasSveikas;
    } 
    else if (rodomasSveikas == 0) {
        if (yraNeigiama) fr << setw(3) << "-" << rodomasSkaitiklis << "/" << left << setw(2) << t.vardiklis << right;
        else fr << setw(4) << rodomasSkaitiklis << "/" << left << setw(2) << t.vardiklis << right;
    } 
    else {
        if (yraNeigiama) fr << setw(2) << -rodomasSveikas << setw(2) << rodomasSkaitiklis << "/" << left << setw(2) << t.vardiklis << right;
        else fr << setw(3) << rodomasSveikas << setw(1) << rodomasSkaitiklis << "/" << left << setw(2) << t.vardiklis << right;
    }
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");
    
    int n;
    fd >> n;
    
    
    fr << "      T1             T2            Suma          Skirtumas\n";

    
    for (int i = 0; i < n; i++) {
        Trupmena t1, t2, suma, skirtumas;
        
        fd >> t1.sveikoji >> t1.skaitiklis >> t1.vardiklis;
        fd >> t2.sveikoji >> t2.skaitiklis >> t2.vardiklis;
        
        skaiciuotiSumaIrSkirtuma(t1, t2, suma, skirtumas);
        
        fr << " ";
        isvestiTrupmena(fr, t1);
        fr << "     ";
        isvestiTrupmena(fr, t2);
        fr << "     ";
        isvestiTrupmena(fr, suma);
        fr << "     ";
        isvestiTrupmena(fr, skirtumas);
        fr << "\n";
    }
    
    
    
    fd.close();
    fr.close();
    
    return 0;
}
