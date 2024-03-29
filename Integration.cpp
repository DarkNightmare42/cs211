#include <iostream>
using namespace std;

typedef double (*FUNC)(double);
//written by some dude named rohit, lol.
// Note: x represents the horizontal position of the rectangle, f(x) is the height, and increment is the width.
// I am using the midpoint of each subinterval as the height of each rectangle to get a more accurate estimate.
// This is why I initialize x to a + increment/2.  To use the left endpoint, initialize x to a.
double integrate(FUNC f, double a, double b) {
   double sum = 0, increment = .0001;
   for (double x = a + increment/2; x < b; x += increment) // For each rectangle,
      sum += f(x) * increment;                             // calculate the area and add it to the sum
   return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
   return 0;
}
