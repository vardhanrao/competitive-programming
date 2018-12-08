#include <fstream>

using namespace std;

constexpr const unsigned long mod = 1000000007;

unsigned long power(unsigned short a, unsigned short b) {
    if(b == 0)
        return 1ul;
    if(b == 1)
        return static_cast<unsigned long>(a);
    unsigned long hpower = power(a, b >> 1);
    return (hpower * ((hpower * (b % 2 == 1 ? a : 1)) % mod)) % mod;
}

int main() {

    unsigned int T;
    unsigned short a, b;
    fstream fin("../input.txt"), fout("../output.txt", ios::out);

    fin >> T;

    while(T--)
        fin >> a >> b, fout << power(a, b) << endl;

    fin.close(), fout.close();

    return 0;
}