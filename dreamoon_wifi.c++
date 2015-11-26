#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//http://stackoverflow.com/questions/15301885/calculate-value-of-n-choose-k
long long nk(long long n, long long k) {
    if (k == 0) return 1;
    return (n * nk(n - 1, k - 1)) / k;
}

int main()
{
    double prob;
    int sdist = 0;
    int rdist = 0;
    int qflip = 0;
    string sstr;
    string rstr;
    cin >> sstr;
    cin >> rstr;

    for (char c: sstr) {
        sdist += (c == '+') ? 1 : -1;
        //cerr << "achr: \"" << c << "\"" << endl;
    }

    for (char c: rstr) {
        if (c == '+') {
            ++rdist;
        } else if (c == '-') {
            --rdist;
        } else {
            ++qflip;
        }
        //cerr << "pchr: \"" << c << "\"" << endl;
    }
    //cerr << sdist << endl;
    //cerr << rdist << endl;
    //cerr << qflip << endl;

    rdist -= sdist;
    rdist = (rdist >=0) ? rdist : -rdist;

    if (qflip < rdist || ((qflip-rdist) & 1)) {
        prob = 0.00;
    } else {
        int nflip = rdist + (qflip-rdist)/2;
        //cerr << "rdist: " << rdist << endl;
        //cerr << "nflip: " << nflip << endl;
        //cerr << "qflip: " << qflip << endl;
        //cerr << "nk(nf,qf)=" << (double)nk(qflip, nflip) << endl;
        prob = (double)nk(qflip, nflip)/(double)(1<<qflip);
    }

    cout << setprecision(12) << fixed << prob << endl;
}

