#include <iostream>
#include <initializer_list>
using namespace std;
double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> & ril);
int main()
{
    cout << "Lista 1.: suma = " << sum({2,3,4})
        <<", �rednia = " << average({2,3,4}) << '\n';

    std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "Lista 2.: suma = " << sum(dl)
        <<", �rednia = " << average(dl) << '\n';

    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "Lista 3.: suma = " << sum(dl)
        <<", �rednia = " << average(dl) << '\n';
    return 0;
}

double sum(std::initializer_list<double> il)
{
    double tot = 0;
    for (auto p = il.begin(); p !=il.end(); p++)
        tot += *p;
    return tot;
}
double average(const std::initializer_list<double> & ril)
{
    double tot = 0;
    int n = ril.size();
    double ave = 0.0;
    if (n > 0)
    {
        for (auto p = ril.begin(); p !=ril.end(); p++)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}
