#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Give inputs - bond prices, coupon rate, maturity for each bond
   int bondprices[]={98,97,96};
   double coupons[]={5,5,5};
   int mat[]={1,2,3};

   // main function execution
   int m=sizeof(bondprices)/sizeof(bondprices[0]);
   int n=mat[m-1];

   // array r[n] includes the interest rates for each year till maximum maturity
   double r[n];
   r[0]=-log(bondprices[0]/(100.0+coupons[0]));
   for(int i=1; i<n; i++){
       double a=bondprices[i];
       double c=coupons[i];
       if(i+1==mat[i]){
           for(int j=0; j<i; j++){
               double k=exp(-r[j]*(j+1));
               a-=(c*k);
           }
           r[i]=-(log(a/(100.0+c)))/(i+1);
       }
       // interpolation for gaps in maturity of bonds
       else{
           r[i]=(((r[i-1]-r[i-2])/(mat[i-1]-mat[i-2]))*(mat[i]-mat[i-2]))+r[i-2];
       }
   }
   // printing answer - bootstrapped interest rate for the final year
   double ans=int(r[n-1]*1000.0)/1000.0;
   cout << ans << endl;
   return 0;
}
