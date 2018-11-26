#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
using namespace std;

double DNormal(double x){
  return 1/(sqrt(2*M_PI)*(pow(exp(1),((x*x)/2))));
}

int main(){
  double x;
  double y;
  double MonteC;
  double fy;

  int xi=-2;
  int xf=2;

  double prom;

  bool flag;
  int area = 0;
  int epoc = 1000000;
  srand (time(0));
  // cout << DNormal(0.89);
  
  prom = 0;
  for(int i = 0; i < 10; i++)
  {
    area = 0;
    for(int j = 0; j < epoc; j++){
      x = ((double) xi + (double)(rand()) / (RAND_MAX/(xf-(xi)))) ;
      y = ((double) (rand()) / (RAND_MAX));
      fy = DNormal(x);
      flag = y <= fy;
      // cout << " x:"<< x << " fy:"<< fy << " y:" << y << ": ";     
      // cout<<flag;
      // printf("\n");
      if (flag) area++;
    }  
    cout << "\n" << area;
    MonteC = ((xf-xi)*(double)area/epoc);
    cout << " -> P:" << MonteC;
    prom+=MonteC;
  }
  
  cout << "\nFinal: " << (prom/10) << endl;
  return 0;
}