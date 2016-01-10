#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;



void Hamiltonian(const double  p1, const double  p2, double& H,
                 const double q1,  const double q2);

void symEuler(double& p1,double& p2, 
              double& q1, double& q2, const double dt);

int main(){
    ofstream out("solution");
    
  double p1, p2, q1, q2;

  const double tEnd = 20*M_PI;
  double dt = 0.05;
  double t = 0;
  const int N  = (tEnd-t)/dt;
  const double ecc=0.6;
  double H;

  q1= 1-ecc; q2=0;
  p1= 0; p2= sqrt((1+ecc)/(1-ecc));
  
  Hamiltonian(p1, p2, H, q1, q2);
  
  out << t << "\t" << p1<< "\t" << p2 << "\t" << q1<< "\t" << q2 <<"\t" << H <<endl;
  
  for(int i=0; i<N; i++){
    t += dt;
    symEuler(p1, p2, q1, q2, dt);
    
    Hamiltonian(p1, p2, H, q1, q2);
    
    out << t << "\t" << p1<< "\t" << p2 << "\t" << q1<< "\t" << q2 <<"\t" << H <<endl;
    
  }
  
  out.close();


  return 0;
}



void symEuler(double& p1,double& p2, 
              double& q1, double& q2, const double dt){
    
    p1-=dt*pow(pow(q1,2)+pow(q2,2),-3.0/2)*q1;
    p2-=dt*pow(pow(q1,2)+pow(q2,2),-3.0/2)*q2;
   
    
    q1+=dt*p1;
    q2+=dt*p2;
}


void Hamiltonian(const double  p1, const double  p2, double& H,
                 const double q1,  const double q2){
    
	H=0.5*(pow(p1,2)+pow(p2,2))-1/(sqrt(pow(q1,2)+pow(q2,2)));

}