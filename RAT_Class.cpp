//
//  RAT.cpp
//  Classes_RAT_Class
//
//  Created by Errol Roberts on 5/11/19.
//  Copyright © 2019 Errol Roberts. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class rat{
    
private:
    int n;
    int d;
    int m;
    bool status;
    
public:
    rat(){
        n=0;
        d=1;
        m=0;
        status = false;
    }
    
    rat(int i, int j){
        n=i;
        d=j;
    }
    
    // conversion constructor
    rat(int i){
        n=i;
        d=1;
    }
    
    //accessor functions (usually called get() and set(...) )
    int getN(){ return n;}
    int getD(){ return d;}
    
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    
    //arithmetic operators
    rat operator+(rat r){
        rat t;
        t.n = n*r.d + d*r.n;
        t.d = d*r.d;
        reduce(t);
        return t;
    }
    
    rat operator-(rat r){
        rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        reduce(t);
        
        return t;
    }
    
    rat operator/(rat r){
        rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        reduce(t);
        
        return t;
    }
    
    rat operator*(rat r){
        rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        reduce(t);
        
        return t;
    }
    
    void reduce(rat& t){
        int divisor = gcd(t.n, t.d);
        t.n /= divisor;
        t.d /= divisor;
        if(t.d < 0 || t.n < 0){
            t.status = true;
        }
        
    }
    //overloaded i/o operators
    friend ostream& operator<<(ostream& os, rat r);
    friend istream& operator>>(istream& is, rat& r);

    int gcd(int n, int d){
        return d == 0 ? n : gcd(d, n%d);
    }
    
    
    
}; //end Rat

ostream& operator<<(ostream& os, rat r){
    if(r.n >= r.d){
        r.m = r.n / r.d;
        r.n = r.n % r.d;
    }
    if(r.m == 0 && r.n == 0){
        os << 0;
    }
    
    else if(r.m > 0){
        if(r.status == true) os << "-";
        os << abs(r.m) << " ";
        if(r.n <= 0) os << " ";
        else os << abs(r.n) << "/" << abs(r.d);
    }
    else{
        if(r.status == true) os << "-";
        os << abs(r.n) << "/" << abs(r.d);
    }
    
    return os;
}

istream& operator>>(istream& is, rat& r){
    is >> r.status >> r.m >> r.n >> r.d;
    return is;
}

int main() {
    rat r1(5, 2), r2(3, 2);
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2;
    r2 = r1 * r2;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    
    return 0;
}
