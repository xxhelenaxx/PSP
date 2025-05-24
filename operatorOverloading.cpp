#include <iostream>
using namespace std;
//Во овој фајл ќе разгледаме се за оператори
//Оператор е специјален симбол кој извршува операција врз еден или повеќе податоци (операнди). На пример: +, -, =, *, [], <<, >> итн. Овие се вградени во самата библиотека
//како што има overloading за функции така има и за оператори. Ние може да направиме функција со која операторот ќе може да ни врши друга функција освен основната и ќе може да управува со нашите класи
// Класа Niza која чува динамички алоцирана низа од цели броеви и нејзината должина
class Niza {
private:
    int* niza;    // покажувач кон динамички алоцирана низа
    int dolzina;  // број на елементи во низата

public:
    // Конструктор со параметри (аргументи)
    Niza(int* niza = NULL, int dolzina = 0) { 
        this->dolzina = dolzina; //this пока/увачот е покажувач кој покажува кон објектот, односно dolzina од класата атрибутот и dolzina во аргументот имаат исто име, па this покажувачот ни спесифицира дека се работи за dolzina атрибутот
        this->niza = new int[dolzina]; // алоцирање простор за niza
        for (int i = 0; i < dolzina; i++) {
            this->niza[i] = niza[i];  // копирање елементи од проследената низа
        }
    }

    // Копирачки конструктор - прави длабока копија на друг објект
    Niza(const Niza& n) {
        dolzina = n.dolzina;
        niza = new int[dolzina];
        for (int i = 0; i < dolzina; i++) {
            niza[i] = n.niza[i];
        }
    }

    // Деструктор - ослободува меморија кога објектот се уништува
    ~Niza() {
        delete[] niza;
    }

    // Оператор =   копирање со ослободување на стара меморија
    Niza& operator=(const Niza& n) { //користиме  & референца кога сакаме да работиме со оригиналот и да го менуваме, const користиме бидејќи нема никакви измени на аргументите 
        if (this != &n) { // доколку се различни објектите 
            delete[] niza; // ослободување на старата низа

            dolzina = n.dolzina; //долѓината на низата станува должината на вметнатата низа
            niza = new int[dolzina]; // алоцирање нова меморија
            for (int i = 0; i < dolzina; i++) {
                niza[i] = n.niza[i];  // копирање елементи на вметнатата низа во нашата
            }
        }
        return *this;  // враќање на референца кон тековниот објект
      //всушност што се случи овде? а(објект)=б(објект); односно сега а ја има содржината на б.
    }
    // Оператор + ги спојува две низи и враќа нов објект
    Niza operator+(const Niza& n) const { //овде немаме референца бидејќи се вража копија(се креира нова низа) 
      //пример:
      //Niza a, b;
      //Niza c = a + b; // a и b не се менуваат, c е нова сума

        Niza tmp;
        tmp.dolzina = this->dolzina + n.dolzina;  // новата должина е збир од двете низи
        tmp.niza = new int[tmp.dolzina];           // алоцирање простор за новата низа

        for (int i = 0; i < this->dolzina; i++) {
            tmp.niza[i] = this->niza[i];           // копирање на првата низа
        }
        for (int i = 0; i < n.dolzina; i++) {
            tmp.niza[this->dolzina + i] = n.niza[i]; // копирање на втората низа
        }
        return tmp;  // враќање на новиот објект (споена низа)
    }
 // Оператор += додава елемент на крајот на низата
    Niza& operator+=(int el) { //се користи референца бидејќи се работи со оригиналот и се врши измена на самиот објект
      //пример:
      //a += 5; // a се менува

        int* tmp = new int[dolzina + 1]; // нова низа со место за уште еден елемент
        for (int i = 0; i < dolzina; i++) {
            tmp[i] = niza[i]; // копирање на постоечките елементи
        }
        tmp[dolzina] = el; // додавање новиот елемент на крај
        delete[] niza;     // ослободување старата низа
        niza = tmp;        // поставување новата низа како тековна
        dolzina++;         // зголемување на должината бидејќи додадовме еден елемент
        return *this;      // враќање на референца кон тековниот објект
    }


    // Префиксен оператор -- (одзема еден елемент од крајот на низата) (--a → прво го менува објектот, па го враќа истиот (се користи во синтакса како дел од израз).
    Niza& operator--() { //има референца дека директно го менува this
        if (dolzina != 0) {
            int* tmp = new int[dolzina - 1];  // нова низа за еден елемент помала
            for (int i = 0; i < dolzina - 1; i++) {
                tmp[i] = niza[i];             // копирање на сите освен последниот елемент
            }
            delete[] niza;                    // ослободување на старата низа
            niza = tmp;                      // поставување на новата
            dolzina--;                      // намалување на должината
        }
        return *this;                      // враќање на референца кон тековниот објект
    }
//РАЗЛИКА МЕЃУ ПОСТ И ПРЕФИКСЕН ОПЕРАТОР!!
//Niza n;
//n += 1; n += 2; n += 3; // n = [1, 2, 3]

//Niza a = --n; // префикс: n = [1, 2], a = [1, 2]
//Niza b = n--; // постфикс: n = [1], b = [1, 2]

    // Постфикс оператор -- (исто како префиксен, но враќа копија пред намалувањето)
    Niza operator--(int) { //нема референца дека креира копија од старата состојба, потоа го скратува this, кај постфикс операторите мора да има int за да ги раликува
        Niza temp(*this);  // прво прави копија на тековниот објект

        if (dolzina != 0) {
            int* nova = new int[dolzina - 1];
            for (int i = 0; i < dolzina - 1; i++) {
                nova[i] = niza[i];
            }
            delete[] niza;
            niza = nova;
            dolzina--;
        }
        return temp;  // враќа копија од состојбата пред намалувањето
    }

    // Оператор > споредува должина на низите
    bool operator>(const Niza& n) const { //const дека не прави никакви измени само проверува
        return dolzina > n.dolzina; //враќа true или 1 ако е поголемо, ако не враќа false или 0
    }

    // Оператор == проверува дали две низи се исти (исти должина и сите елементи)
    bool operator==(const Niza& n) const {
        if (dolzina != n.dolzina) return false; 
        for (int i = 0; i < dolzina; i++) {
            if (niza[i] != n.niza[i]) return false;
        }
        return true;
    }

    // Оператор [] овозможува пристап до елементите по индекс (за читање и пишување)
    int& operator[](int index) { //референца бидејќи работа со оригиналот
        if (index < 0 || index >= dolzina) exit(-1);  // безбедносна проверка за индекс, ако е помал од 0 или поголем од должината нема да врати ништо
        return niza[index]; 
      //Niza n1;
      //n1 += 5;
      //n1[0] = 10; користи неконстантната верзија – менува елемент
    }

    // Константен оператор [] за читање елементи од константен објект
    const int& operator[](int index) const {
        if (index < 0 || index >= dolzina) exit(-1);
        return niza[index];
        //const Niza n2 = n1;
        //int x = n2[0];  користи константната верзија – читање е дозволено
        // n2[0] = 100;  ГРЕШКА – не може да се менува затоа што е const
    }

    // Оператор << за печатење на низата во формат [1, 2, 3]
    friend ostream& operator<<(ostream& out, const Niza& n) { //Операторот << за cout не е член-функција на класата Niza, туку е глобална функција што треба да има пристап до приватните елементи на класата (како niza и dolzina). затоа користиме friend
        out << "[";
        for (int i = 0; i < n.dolzina; i++) {
            out << n.niza[i];
            if (i < n.dolzina - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    // Оператор >> за внесување низи од тастатура
    friend istream& operator>>(istream& in, Niza& n) { //исто и за istream in c-in cin>>
        cout << "Vnesi dolzina na nizata: ";
        in >> n.dolzina;
        delete[] n.niza;               // ослободување на старата низа
        n.niza = new int[n.dolzina];  // алоцирање нова низа

        cout << "Vnesi elementite na nizata: ";
        for (int i = 0; i < n.dolzina; i++) {
            in >> n.niza[i];
        }
        return in;
    }
};


int main() {
    Niza n1, n2;
    cin >> n1;  // внеси ја првата низа
    cin >> n2;  // внеси ја втората низа

    cout << "Niza 1: " << n1 << endl;
    cout << "Niza 2: " << n2 << endl;

    Niza n3 = n1 + n2;  // спојување на двете низи
    cout << "Spoena niza: " << n3 << endl;

    n1 += 10;  // додавање на елемент 10 во низа 1
    cout << "Niza 1 po dodavanje na 10: " << n1 << endl;

    --n2;      // отстранување на последниот елемент од низа 2 (префиксен)
    cout << "Niza 2 po otstranuvanje na posledniot element: " << n2 << endl;

    if (n1 > n2) {
        cout << "Niza 1 e pogolema od Niza 2." << endl;
    } else {
        cout << "Niza 1 e pomala ili ednakva na Niza 2." << endl;
    }

    if (n1 == n2) {
        cout << "Nizite se ednakvi." << endl;
    } else {
        cout << "Nizite ne se ednakvi." << endl;
    }

    cout << "Element na indeks 0 vo Niza 1: " << n1[0] << endl;

    return 0;
}
