/******************************************************************************

MAGACINI (STACKS)  bukvalno magacin za roba, chuva vo nego strukturi
                   podredena linearna struktura
                   FIRST IN LAST OUT(FILO)/LAST IN FIRST OUT(LIFO)
      ----------------------------------------------------------------
VLEZ  ------------------------------------------------>element1
      -------------------------------------->element2 element1
      ------------------------------>element3 element2 element1
      ----------------------------------------------------------------
      
      ----------------------------------------------------------------
IZLEZ <------------------------------element3 element2 element1
      <---------------------------------------element2 element1
      <------------------------------------------------element1
*******************************************************************************/
#include <iostream>
using namespace std;
 
#define STACKSIZE 10; //golemina na magacinot(maximalen broj na elementi)
struct magacin { 
     int niza [MAX]; //magacinot go smetame za niza od elementi
     int top;//vrvot na nizata odnosno posledniot element
     
     void init(); //za inicijalizacija
     bool isEmpty(); //dali magacinot e prazen
     bool isFull(); //dali e poln
     void push(int e); //dodavanje element
     int pop(); //brishenje element
     int peek(); //chitanje na element
     void print (); //print na magacinot
     
     
 };
 void magacin::init(){
     top=-1;//go stavame vrvot na -1 za incijalizacija nizata e prazna, ponatamu toj kje stane 0 neli prviot el na nizata e 0,1,2...
 }
 bool magacin::isEmpty(){
     return (top==-1); //ako vrvot e -1 togash magacinot e prazen i f-jata vrakja 1/TRUE
 }
 bool magacin::isFull(){
     return (top==STACKSIZE-1); //ako vrvot e MAX-1 togash kje bide polna i vrakja vrednost 1(MAX=5, 0,1,2,3,4 se indeksite na elementite, 4 e 5-1, posleden element)
 }
 void magacin::push (int e){ //vnesuvanje na el
     if (isFull()){
         cout<<"Poln e"<<endl; //ako nizata e polna ne mozheme da vneseme povekje od MAX el
         exit(-1);
     }
     top++;//inaku pravime prazno mesto
     niza[top]=e;//na praznoto mesto ja vmetnuvame vrednosta shto sakame da ja vneseme
 }
 int magacin::pop(){ //brishenje el
     if(isEmpty()){
         cout<<"Prazen e"<<endl; //ako e prazna error bidejkji nema sho da se izbrishe
         exit(-1);
     }
     int temp=top; //inaku se kreira promenliva koja kje ja skladira vrednosta na vrvot
     top--; //se namaluva br na elementi i vrvot stanuva prethodniot el
     return (niza[temp]); //se brishe promenlivata kade e skladiran prethodniot vrv(posleden el)
     
 }
 int magacin::peek(){//chitanje na el
     if(isEmpty()){
         cout<<"Prazen e"<<endl;//ako e prazen magacinot nema so da chita
         exit(-1);
     }
     return (niza[top]);//inaku se vrakja vrednosta na vrvot
 }
 void magacin::print(){ //pechatenje na el od magacinot
     for(int i=0; i<=top; i++){
         cout<<niza[i];
     }
 }

/******************************************************************************

REDOVI(QUEUES) isto kako i magacini samo imaat razl vlez i izlez, pochetok i kraj
LAST IN LAST OUT (LILO), FIRST IN FIRST OUT(FIFO)

REAR                                                        FRONT
--------------------------------------------------------------------
------------------------------------------------------>element1-->
------------------------------------------->element2 element1--->
VLEZ--------------------------->element3 element2 element1----> IZLEZ 
---------------------------------------------------------------------


*******************************************************************************/
#include <iostream>
using namespace std;

#define QSIZE 100

struct QUEUE {
    int niza[QSIZE];
    int front, rear;

    void init();
    bool isEmpty();
    bool isFull();
    void enqueue(int e);
    int dequeue();
    int peek();
    void print();
};

void QUEUE::init() {
    front = -1;
    rear = -1;
}

bool QUEUE::isEmpty() {
    return front == -1;
}

bool QUEUE::isFull() {
    return rear == QSIZE - 1;
}

void QUEUE::enqueue(int e) {
    if (isFull()) {
        cout << "Redot e poln!" << endl;
        exit(-1);
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    niza[rear] = e;
}

int QUEUE::dequeue() {
    if (isEmpty()) {
        cout << "Redot e prazen." << endl;
        exit(-1);
    }
    int pom = niza[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return pom;
}

int QUEUE::peek() {
    if (isEmpty()) {
        cout << "Redot e prazen." << endl;
        exit(-1);
    }
    return niza[front];
}

void QUEUE::print() {
    if (isEmpty()) {
        cout << "Redot e prazen." << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << niza[i] << " ";
    }
    cout << endl;
}
