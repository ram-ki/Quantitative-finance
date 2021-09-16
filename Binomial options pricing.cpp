#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // input - option contract
    double S0=100;
    double u=0.50;
    double r=0.10;
    double K=100;
    double N=5;
    double d = 1 / u;
    double p = (1 + r - d) / (u - d);
    double q = 1 - p;
    
    // main execution - creating a binomial tree
    vector<double> temp(N+1,0.0);
    vector<vector<double>> stock(N+1,vector<double> (N+1,0.0));
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            stock[j][i]=S0*(pow(u,(i - j))*pow(d,j));
        }
    }

    // execution - calculating payoff at each discrete time
    vector<vector<double>> option(N+1,vector<double> (N+1,0.0));
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            double a=stock[j][i]-K;
            option[j][i]=max(0.0, a);
        }
    }

    // execution - discounting at each disrete time along with probabilty
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<=i; j++){
            option[j][i]=((p*option[j][i+1])+(q*option[j+1][i+1]))/(1+r);
        }
    }

    // printing options contract price
    double ans=int(option[0][0]*100);
    cout << option[0][0] << endl;
   
   return 0;
}
