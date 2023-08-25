#include<iostream>
#define N 10

using namespace std;

int main(){
    double a[N][N],b[N],ratio;
    int i,j,k,n;
	
	 cout<<"Enter number of unknowns: ";
	 cin>>n;
    cout<<"Enter the agumented matrix\n";
    for(i =1; i<=n;i++){
        for(j=1;j<=n+1;j++){
			
            cout<<"a["<<i<<"]"<< "["<<j<<"]= ";
        cin>>a[i][j];
        }
    }
    //Guass Elimination
    for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(int k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
     /*Back Substitution Method */
	 b[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  b[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		b[i] = b[i] - a[i][j]*b[j];
		  }
		  b[i] = b[i]/a[i][i];
	 }

	 /* Displaying Solution */
	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"X["<< i<<"] = "<< b[i]<< endl;
	 }

    return 0;
}