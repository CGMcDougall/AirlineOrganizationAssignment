#include "Part.h"



Part::Part(const string s){

  name = s;
  flightHours = 0;

}

Part::Part(Part& p){
  name = p.name;
  installationDate = p.installationDate;
  flightHours = p.flightHours;
}

Part::~Part(){
  //do nothing
}

void Part::addFlightHours(int i){

  flightHours += i;

}

void Part::install(Date& d){

  installationDate = d;

}

bool Part::inspection(Date& d){
  return false;
}

void Part::print(ostream& out) const{
  out<<"Part: " <<name<<endl;
  out<<"Flight hours: "<<flightHours<<endl;
  Date d = installationDate;
  out<<"Installation date: "<<d;

}


ostream& operator<<(ostream& cout, Part* p){
      p->print(cout);
      return cout;
}



FH_Part::FH_Part(string n, int hrs)
  :Part(n){

  fh_inspect = hrs;
}

FH_Part::FH_Part(FH_Part& p) : Part(p){

  fh_inspect = p.fh_inspect;

}


bool FH_Part::inspection(Date& d){

  if(flightHours >= fh_inspect)return true;
  return false;

}

void FH_Part::print(ostream& out)const{

    Part::print(out);
    out<<"Inspect every: "<<fh_inspect<<" flight hours"<<endl;

}


IT_Part::IT_Part(const string n, int hrs)
  : Part(n){

  it_inspect = hrs;

}

IT_Part::IT_Part(IT_Part& p) : Part(p){
  it_inspect = p.it_inspect;
}

bool IT_Part::inspection(Date& d){

  if(d.toDays() >= (installationDate.toDays() + it_inspect))return true;
  return false;

}

void IT_Part::print(ostream& out) const{

  Part::print(out);
  out<<"Inspect every: "<<it_inspect<<" days"<<endl;

}

FHIT_Part::FHIT_Part(const string n, int it, int fh)
  : IT_Part(n,it), FH_Part(n,fh), Part(n){

}

FHIT_Part::FHIT_Part(FHIT_Part& p)
  : IT_Part(p), FH_Part(p), Part(p){

  }


bool FHIT_Part::inspection(Date& d){

  if(IT_Part::inspection(d) && FH_Part::inspection(d))return true;
  return false;

}

void FHIT_Part::print(ostream& out)const{

  FH_Part::print(out);
  out<<"Inspect every: "<<it_inspect<<" days"<<endl;

}
