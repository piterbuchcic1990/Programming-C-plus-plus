#include <iostream>

using namespace std;

int main()
{
    using std::ios_base;

    float price1=20.4;
    float price2=1.9+8.0/9.0;
    cout.setf(ios_base::showpoint);

    cout<<"\"futrzaki \" kosztuja "<<price1<<" zl\n";
        cout<<"\" smoki \" kosztuja "<<price2<<" zl\n";
        cout.precision(2);
           cout<<"\"futrzaki \" kosztuja "<<price1<<" zl\n";
        cout<<"\" smoki \" kosztuja "<<price2<<" zl\n";

    cout << "Hello world!" << endl;
    return 0;
}
