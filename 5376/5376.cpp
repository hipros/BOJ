#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll EXPONENTIATION(int n) { return pow(10, n); }
void SWAP(pair<ll, ll>& p) {
    ll &a = p.first, &b = p.second;
    a = a^b;
    b = a^b;
    a = a^b;
}
ll GCD(ll a, ll b)
{
    while(b) {
        ll t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main ()
{
    int T;
    cin>>T;
    while(T--) {
        int posDot, posBracket;
        string D, I, R;
        ll numerator, denominator;             //분자, 분모
        ll gcd;
        cin>>D;
        posDot = (int)D.find('.');
        I = D.substr(0, posDot);
        R = D.substr(posDot, D.length());
        R = R.substr(1, R.length());

        posBracket = (int)R.find('(');
        if(posBracket == string::npos) {                      //비순환 소수
            int dlength = R.length();
            numerator = atoi(R.c_str());
            denominator = EXPONENTIATION(dlength);
            numerator += atoi(I.c_str()) * EXPONENTIATION(dlength);
        }
        else {                                               //순환 소수
            ll circulDec, nonCirculDec, numerator_;        // 순환부, 비순환부, 정수+비순환부
            int circulDecLen = R.length() - posBracket - 2, nonCirculDecLen = posBracket;

            nonCirculDec = atoi(R.substr(0, nonCirculDecLen).c_str());
            circulDec = atoi(R.substr(posBracket+1, posBracket+1+circulDecLen).c_str());

            denominator = EXPONENTIATION(circulDecLen)-1;          //make 99..
            denominator *= EXPONENTIATION(nonCirculDecLen);        //make 99.. to 99..00..

            numerator_ = atoi(I.c_str()) * EXPONENTIATION(nonCirculDecLen) + nonCirculDec;
            numerator = numerator_ * EXPONENTIATION(circulDecLen) + circulDec;
            numerator -= numerator_;
        }


        pair<ll, ll> p(denominator, numerator);
        if(denominator < numerator) SWAP(p);
        gcd = GCD(p.first, p.second);

        cout<<numerator/gcd<<'/'<<denominator/gcd<<'\n';
    }
    return 0;
}