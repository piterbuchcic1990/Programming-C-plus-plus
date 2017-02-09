#include <iostream>
#include <cstring>

using namespace std;
class Cd{
private:
    char performers[50];
    char label[20];
    int selection;
    double playtime;
public:
    Cd(const char *s1="brak",const char *s2="brak",int n=10,double x=10.0);
    Cd(const Cd &d);
    virtual ~Cd(){}
    virtual void Report()const;
    Cd & operator=(const Cd &d);




};
class Classic: public Cd
{
private:
    char glowny[30];
    public:
      virtual void Report()const;
      Classic(const char *s1="brak",const char *s2="brak",int n=10,double x =10.0,const char *gl="brak");
      Classic(const Cd &d,const  char *gl);
      Classic (const Classic & d);
    ~Classic(){}
    Classic & operator=(const Classic &d);


};
void Bravo(const Cd & disc);
int main()
{
    Cd mafia;
    mafia.Report();
    Classic mafia2;
    mafia2.Report();
    Cd mafia3=mafia;
    Classic mafia4=mafia2;
    mafia3.Report();
    mafia4.Report();
    cout<<endl;
    Bravo(mafia4);
     cout<<endl;
    Bravo(mafia);
    Cd *pcd=&mafia;
    pcd->Report();
    pcd=&mafia2;
    pcd->Report();

    cout << "Hello world!" << endl;
    return 0;
}
 Cd::Cd(const char *s1,const  char *s2,int n,double x)
 {
strcpy(performers,s1);
strcpy(label,s2);
selection=n;
playtime=x;

 }
    Cd::Cd(const Cd &d)
    {
strcpy(performers,d.performers);
strcpy(label,d.label);
selection=d.selection;
playtime=d.playtime;

    }

     void Cd::Report()const
     {
cout<<"performers: "<<performers<<endl;
cout<<"label: "<<label<<endl;
cout<<"selection: "<<selection<<endl;
cout<<"playtime: "<<playtime<<endl;

     }
    Cd & Cd::operator=(const Cd &d)
    {
        if(this==&d)
    return *this;
strcpy(performers,d.performers);
strcpy(label,d.label);
selection=d.selection;
playtime=d.playtime;
return *this;


    }

     void Classic::Report()const
     {
         Cd::Report();
         cout<<"ulubiena: "<<glowny<<endl;

     }
     Classic::Classic(const  char *s1,const  char *s2,int n,double x ,const char *gl):Cd(s1,s2,n,x)
     {
strcpy(glowny,gl);

     }
      Classic::Classic(const Cd &d,const  char *gl):Cd(d)
      {
strcpy(glowny,gl);

      }
      Classic::Classic (const Classic & d):Cd(d)
      {

strcpy(glowny,d.glowny);
      }
         Classic & Classic::operator=(const Classic &d)
         {
        if(this==&d)
        return *this;
        Cd::operator=(d);
        strcpy(glowny,d.glowny);
        return *this;
         }
void Bravo(const Cd & disc)
{
    disc.Report();
}
