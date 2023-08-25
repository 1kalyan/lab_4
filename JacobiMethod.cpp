#include<iostream>
#include<iomanip>
#include<math.h>
/* In this example we are solving
  7x+2y-z = 8
2x-8y-z = -17
-x-y+5z=12

*/
#define f1(x,y,z)  (8-2*y+z)/7
#define f2(x,y,z)  (17+2*x-z)/8
#define f3(x,y,z)  (12+x+y)/5

using namespace std;

int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int step=1;

 /* Setting precision and writing floating point values in fixed-point notation. */
 cout<< setprecision(6)<< fixed;

 /* Input */
 /* Reading tolerable error */
 cout<<"Enter tolerable error: ";
 cin>>e;

 cout<< endl<<"Iteration\tx\t\ty\t\tz"<< endl;
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  cout<<setw(6)<< step<<setw(6)<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;

  /*absolutue value of floating point Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  step++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);

 cout<<"\nSolution: x = "<<round(x1)<<", y = "<< round(y1)<<" and z = "<<round(z1);
 return 0;
}

