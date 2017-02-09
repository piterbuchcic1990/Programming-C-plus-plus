#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Customer{
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive=processtime=0;}
    void seter(long when);
    long when()const{return arrive;}
    int ptime()const {return processtime;}

};
typedef Customer Item;

class Quene{
private:
    struct Node{Item item; struct Node *next;};
    enum{Q_SIZE=10};
    Node *fronte;
    Node *rear;
    int items;
    const int qsize;
    Quene(const Quene &q) : qsize(0){}
    Quene & operator=(const Quene &q){return *this;}
public:
    Quene(int qs=Q_SIZE);
    ~Quene();
    bool isempty()const;
    bool isfull()const;
    int quenecount()const;
    bool enque(const Item &item);
    bool dequene(Item &item);



};
const int MIN_PER_HR = 60;
bool newcustomer(double x);
int main()
{
srand(std::time(0));

cout << "Studium przypadku: bankomat Banku Stu Kas\n";
    cout << "Podaj maksymalną długość kolejki: ";
    int qs;
    cin >> qs;
  Quene line1(qs); // w kolejce może stanąć do qs klientów
  Quene line2(qs);
bool flag1=true;
bool flag2=true;

    cout << "Podaj symulowany czas (w godzinach): ";
    int hours;                 // liczba godzin symulacji
    cin >> hours;
long cyclelimit = MIN_PER_HR * hours;       // liczba cykli


    cout << "Podaj średnią liczbę klientów na godzinę: ";
    double perhour;            // średnia liczba nowych klientów na godzinę
    cin >> perhour;

 double min_per_cust;       // średni odstęp czasowy pomiędzy klientami
    min_per_cust = MIN_PER_HR / perhour;

 Item temp1;                 // dane nowego klienta
 Item temp2;
    long turnaways = 0;        // liczba klientów odesłanych z kolejki
    long customers = 0;        // liczba klientów przyjętych do kolejki
    long served = 0;           // liczba klientów obsłużonych w symulacji
    long sum_line = 0;         // łączna liczba oczekujących
    int wait_time = 0;         // czas do zwolnienia bankomatu
    long line_wait = 0;        // łączny czas oczekiwania


  for (int cycle = 0; cycle < cyclelimit; cycle++)
    {

        if (newcustomer(min_per_cust))  // mamy nowego chętnego
        {





          if (line1.isfull())
          {
              flag1=false;

          }

          if(line2.isfull())
          {
              flag2=false;

          }
          if(!flag1&&!flag2)
          {
              turnaways++;
          }

            if(flag1)
            {
                customers++;
                temp1.seter(cycle);        // czas przybycia = nr cyklu
                line1.enque(temp1);     // dołączenie klienta do kolejki
            }
            if(flag2)
            {
                customers++;
                temp2.seter(cycle);        // czas przybycia = nr cyklu
                line2.enque(temp2);


            }
            flag1=true;
            flag2=true;





        }
        if (wait_time <= 0 && (!line1.isempty()||!line2.isempty()))
        {
            if(!line1.isempty())
            {
            line1.dequene(temp1);        // następny do obsłużenia
            wait_time = temp1.ptime();   // czas obsługi = wait_time
            line_wait += cycle - temp1.when();
            served++;
            }
            if(!line2.isempty())
            {

            line2.dequene(temp2);        // następny do obsłużenia
            wait_time = temp2.ptime();   // czas obsługi = wait_time
            line_wait += cycle - temp2.when();
            served++;
            }

        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line1.quenecount()+line2.quenecount();
    }


if (customers > 0)
    {
        cout << " liczba klientów przyjętych: " << customers << endl;
        cout << "liczba klientów obsłużonych: " << served << endl;
        cout << " liczba klientów odesłanych: " << turnaways << endl;
        cout << "    średnia długość kolejki: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
            cout << (double) sum_line / cyclelimit << endl;
        cout << "    średni czas oczekiwania: "
            << (double) line_wait / served << " minut\n";
    }
    else
        cout << "Brak klientów!\n";

    cout << "Gotowe!\n";














    return 0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
void Customer::seter(long when)
{

    processtime=rand()%3+1;
    arrive=when;
}

Quene::Quene(int qs) : qsize(qs)
{
    fronte=rear=nullptr;
    items=0;


}




    Quene::~Quene()
    {
        Node *temp;
        while(fronte!=nullptr)
        {
            temp=fronte;
            fronte=fronte->next;
            delete temp;
        }

    }
    bool Quene::isempty()const
    {
        return items==0;

    }
    bool Quene::isfull()const
    {
        return items==qsize;

    }
    int Quene::quenecount()const
    {

        return items;
    }
    bool Quene::enque(const Item &item)
    {
        if(isfull())
            return false;
        Node *add=new Node;
        add->item=item;
        add->next=nullptr;
        items++;
        if(fronte==nullptr)
            fronte=add;
        else
            rear->next=add;
        rear=add;

        return true;

    }
    bool Quene::dequene(Item &item)
    {
        if (fronte==nullptr)
            return false;
        item=fronte->item;
        items--;
        Node *temp=fronte;
        fronte=fronte->next;
        delete temp;
        if(items==0)
            rear=nullptr;
        return true;

    }
