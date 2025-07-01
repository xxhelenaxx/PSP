//Единечно повржана листа
//[.]----->[A|.]----->[B|.]----->[C|NULL]

//jazol-->   [info|link]---->
#include <iostream>
using namespace std;

struct jazol{ //struktura za jazol jazol1[info][link]--->jazol2[info][link]--->jazol3[info][0]
   int info;    // del od jazolot za podatoko(elementot)
   jazol *link; //del od jazolot koj pokazhuva kon sledniot jazol
};
struct Lista{
  jazol*head; //prviot jazol
  void init(){ //inicijalizacija
      head=NULL; //prazna lista 
  }
  void dodadiPrv(int prv){ //dodavanje na prviot element
      jazol *pom=new jazol; //se kreira nov jazol so operatorot new za dinamichko alociranje
      pom->info=prv; //se skladira vrednosta vo noviot jazol
      pom->link=head; //pokazhuvachot da pokazhuva kon segashniot prv jazol
      head=pom; //noviot jazol se deklarira kako prv jazol
  }
  void dodadiPosleden(int posleden){//dodavanje na element na kraj od listata
      jazol *pom=new jazol;//se kreira nov jazol
      jazol *dvizhenje=head; //pridvizhuvanjeto se zakachuva na prviot jazol(da pochne od tamu)
      pom->info=posleden; //vrednosta se skladira vo noviot jazol
      if (head==NULL)//ako listata e prazna
      head=pom; //noviot element se deklarira kako prv element
      else{
          while (dvizhenje->link!=NULL)//dodeka pridvizhuvanjeto ne stigne do posledniot jazol(dali ima sleden element?)
            dvizhenje=dvizhenje->link; //ako ima sleden se pridvizhuvame kon nego
          dvizhenje->link=pom; //koga kje stigneme na krajot, tuka go postavuvame noviot jazol
          pom->link=NULL;//ova znachi deka  e posleden jazol, pa linkot mora da pokazhuva kon 0(nema na krajot vrska bidjekji nema nareden jazol)
      }
  }
  void pechatiLista(){
      for (jazol*pom=head; pom!=NULL; pom=pom->link){ 
          cout<<pom->info<<'\t';
          cout<<endl;
      }
  }
  void brishiPosleden(){
      if(head!=NULL){ //dali listata e prazna
          if (head->link==NULL){ //dali ima samo eden element
            
            delete head; //go brisheme
            head==NULL; 
          }
          else{ //ako ima povekje od eden element
              jazol *pom=head, *brishi; //kreirame dva pokazhuvachi(edniot kje se pridvizhuva do predposlednioot, a dr kje pokazhuva kon posledniot element)
              while(pom->link->link!=NULL) //se dvizhime se do jazolot koj pokazhuva do posledniot jazol
                  pom=pom->link;//tuka kje oznachime da pokazhuva prviot pokazhuvach
              brishi = pom->link;//oznachuvame deka vtoriot  pokazhuvach kje stane posledniot pokazhuvach
              pom->link = NULL;//ja brisheme vrskta so posledniot jazol
              delete brishi;//go brisheme posledniot element
          }
          
      }
  }
  void brishiPrv(){
      if (head!=NULL){ //ako listata ne e prazna
          if (head->link==NULL){ //ako postoi samo eden element
              delete head;//go brisheme
              head=NULL;
          }
          else {//dokolku ima povekje elementi
          jazol*pom=head;//pomoshnik pokazhuvach koj pokazhuva na prviot jazol
          head=head->link;//prviot element go pridvizhuvame da pokazhuva kon naredniot(vtoriot)
          delete pom;//go brisheme prviot element
      }
      }
  }
  void brishiLista(){
      while (head!=0) //dodeka se isprazni listata
      brishiPosleden(); //brishi go posledniot element
  }
  int lenght(){
      int n=0; //se kreira brojach koj kje broe klk elementi ima
      jazol*pom=head; //pokazhuvach koj go sodrzhi prviot el
      while(pom!=NULL){ //dodeka ne stigne pokazhuvachot do krajot na nizata
          pom=pom->link; //se premestuva kon sledniot elemet
          n++; //se zgolemuva vrednosta na brojachot
      } return n; //se vrakja brojachot
  }
  void insert(jazol*j, int data){
      jazol *pom=new jazol;//se kreira nov jazol
      pom->info=data; //se vmetnuva vmetnatata data od korisnikot vo jazolot
      pom->link=j->link; //sе postavuva linkot na noviot jazol
      j->link=pom; 
  }
  void delete_after(jazol*j){
      if(j->link==NULL) //Ako e posleden vneseniot jazol
      return; //izlezi od funk
      jazol *tmp=j->link; //dokolku ne e posleden se kreira temporary promenliva koja ja skladira datata na ovoj jazol
      j->link=tmp->link; //se povrzuva so sledbenikot
      delete tmp;//se brishe sledniot jazol
  }
};
/******************************************************************************
EDINECHNO POVRZHANA KRUZHNA LISTA

 -->[infoA|link]----->[infoB|link]----->[infoC|link] -->
 --------------------------------
 
*******************************************************************************/
struct jazol {
int info;
jazol* link;
};
struct kruznaLista{
    jazol *head; //prviot jazol
    jazol *end; //posledniot jazol
    int n; //broj na elementi vo nizata
    void init(){ //inicijaliziranje na listata
        head=end=NULL; //definirame deka e prazna
        n=0;
    }
    void dodadiPrv(int prv){
        jazol*pom=new jazol;//se kreira nov jazol
        pom->info=prv;//se stava vrednosta od korisnikot vo noviot jazol
        if(head==NULL){ //ako nizata nema elementi
            pom->link=pom;//linkot se stava da pokazhuva kon samiot element bidejkji e edinstven
            end=head=pom;//toj jazuva stanuva i prv i posleden jazol
        }
        else{//inaku
            pom->link=head;//jazolot pokazhuva kon prviot element
            head=pom;//noviot jazol stanuva prv
            end->link=head;//krajniot link se stava da pokazhuva kon noviot prv jazol
        } n++; //se zgolemuva br na elementi
    }
    void dodadiPosleden (int p){
        jazol*pom=new jazol;//se kreira nov jazol
        pom->info=prv;//se stava datata od korisnikot vo noviot jazol
        if(head==NULL){ //ako nizata nema elementi
            pom->link=pom;//linkot se stava da pokazhuva kon samiot element bidejkji e edinstven
            end=head=pom;//-||-
        }else{
            pom->link=end;
            end=pom;
            pom->link=head;
        }n++;
        
    }
    void brishiPosleden(){
        if(head->link==head){ //Ako listata se sostoi od eden element
            delete head; //izbrishi go
            head=end=NULL;
        }
        if(head!=NULL){//inaku
            jazol*pom=head;//nov pokazhuvach kon pochetokot
            while(pom->link!=end) //dodeka ne stigne da pokazhuva do posledniot jazol
            pom=pom->link;//da se pridvizhuva
            pom->link=head;//koga kje stigne do pretposledniot da go nasochi da pokazhuva kon prviot
            delete end;//da go izbrishe krajot
            end=pom;//da go stavi pretposledniot element kako kraen
        }n--; //se namaluva brojot na elementi
    }
    void brishiPrv(){
        if(head->link==head){ //Ako listata se sostoi od eden element
            delete head; //izbrishi go
            head=end=NULL;
        } if(head!=NULL){//inaku
            end->link=head->link;//krajniot element da pokazhuva kon elementot posle prviot
            delete head;//prviot da se izbrishe
            head=end->link;//prviot e onoj jazol kon koj pokazhuva posledniot element
        }n--;//se namaluva br na elementi
    }
    void brishiLista(){
        while(head!=NULL)
        brishiPosleden();
    }
};

/******************************************************************************

DVOJNO POVRZHANI LISTI!!!

jazol-->   <---[prev|info|next]--->

[HEAD]--->[0|infoA|next]<----->[prev|infoB|next]<--->[prev|infoC|0]<----[TAIL]

*******************************************************************************/
//definiranje(kod)
#include <stdio.h>
using namespace std;

struct jazol{ //kreirame struktura(tip na podatok narechen jazol koj vo sebe sodrzhi informacii)
    int info; //-->ova e delot vo jazolot koj go sodrzhi podatokot
    jazol *next, *prev; //kreirame dva podjazli koi gi sodrzhat vrskite(links) za pokazhuvanje kon dr jazol vo listata
};
struct Lista{ 
    jazol*head, *tail; //gi kreirame dvata jazli koi se pochetok i kraj na nizata
    void init(){
        head=tail=NULL; //so ovaa funkcija ja inicijalizirame listata
    }
    void dodadiPrv (int prv){//f-ja za dodavanje na prviot el
        jazol *pok=new jazol;//kreirame nov pokazhuvach kon jazol
        pok->info=prv;//vo delot info od noviot jazol go vmetnuvame podatokot od korisnikot
        pok->next=head;//pokazhuvachot koj pokazhuva na sledbenikot da pokazhuva kon head
        pok->prev=NULL; //pokazhuvachot kon prethodnikot da pokazhuva kon NULL
        if(head==NULL)//dokolku nema elementi
        tail=pok;//posledniot jazol da pokazhuva kon nego
        else
            head->prev=pok;//inaku prethodnikot na prviot jazol se postavuva da pokazhuva kon nego
        head=pok;//pochetokot da pokazhuva kon noviot jazol
    }
    void dodadiPosleden(int posleden){
        jazol*pok=new jazol; //nov pokazhuvach kon jazol
        pok->info=posleden; //se skladira vrednosta vo delot info
        pok->next=NULL; //pokazhuvachot sledbenik da pokazhuva kon NULL
        pok->prev=tail; //pokazhuvachot prethodnik se postavuva na krajot
        if (head==NULL)//ako listata e edinstven
            head=pok; //pok na prviot jazol da pokazhuva kon nego
        else
            tail->next=pok; //inaku pok sledbenik na posledniot jazol se postavuva da pokazuva kon noviot jazol
        tail=pok; //krajot da pokazhuva kon noviot jazol
        }
    void izbrishiPrv(){
        if (head!=NULL){ //ako listata ne e prazna
            if(head->next==NULL){ //ako ima samo eden element
                delete head; //izbrishi go
                head=tail=NULL;//inicijaliziraj prazna lista
            }
            else {
                jazol*pok=head;
                head=head->next;//pochetokot da pokazhuva kon sledbenikot(odnosno pochetok da stane sledbenikot)
                head->prev=NULL; //prethodnikot na noviot ppochetok da bide NULL
                delete pok; //izbrishi go pochetokot koj go skladiravme vo pok
            }
        }
    }
    void izbrishiPosleden(){
        if(head!=NULL){
            if (head->next==NULL){
                delete head;
                head=tail=NULL;
            }
            else{
                jazol*pok=tail; //pok da pokazhuva kon krajot na nizata
                tail=tail->prev;//noviot kraj da stane prethodnikot na krajot(pretposledniot element)
                tail->next=NULL; //sledbenikot da bide NULL
                delete pok;//izbrishi go krajot koj go skladiravme vo pok
            }
        }
    }
};
/******************************************************************************

DVOJNO POVRZHANI KRUZHNI LISTI

isto kako edinechnite kruzhni listi, samo so dvojni vrski i bez kraj(jamka)

  [HEAD]--->][prev|infoA|next]<--->[prev|infoB|next]<----->[prev|infoC|next]<-----[TAIL]
            isto i infoA i infoC se povrzani 
*******************************************************************************/
#include <stdio.h>
using namespace std;
 struct jazol{
     //isto kako kaj dvojni povrzhani listi
 };
 struct Lista{
     jazol*head, *tail;
     void init(){
         //isto kako kaj dvojna Lista
         head=tail=NULL;
     }
     void ins_first(int x){
         jazol *p=new jazol;
         p->info=x;
         if (head == NULL) {//ako listata e prazna
         tail = head = p; //el e i prv i posleden
         p->prev = p->next = p;//dvete vrski se povrzani so samiot el bidejkji e edinstven
    }
        else {
        p->next = head;//ako ne e edinstven el da bide prv jazol na koj shto kje pokazhuva pochetokot
        p->prev = tail;//i krajot da pokazhuva kon nego bidejkji e kruzhna lista i prviot i posl el se povrzani
        tail->next = p;//istoto
        head->prev = p_ptr;
        head = p_ptr;
        }
    }
         
     
 };

