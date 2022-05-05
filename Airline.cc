#include "Airline.h"


Airline::Airline(const string& n){
  name = n;

}

Airline::~Airline(){

  //cout<<"destructor called"<<endl;

  //delete partArr[0];
  //delete aircraftArr[0];

  for(int a = aircraftArr.getSize()-1; a >= 0; --a){
    //cout<<a<<endl;
    delete aircraftArr[a];
  }

  for(int i = 0; i < partArr.getSize(); i++){
    //cout<<partArr[i]->getName()<<endl;
    //cout<<"here "<<i<<endl;
    delete partArr[i];
  }

  // for(int i = partArr.getSize()-1; i >= 0; i--){
  //
  //   //cout<<i<<endl;
  //
  //   if(partArr[i] == NULL){
  //     cout<<i<<" does not exist"<<endl;
  //     continue;
  //   }
  //   delete partArr[i];
  // }

}
Part* Airline::getParts(const string& name){

  for(int i =0; i < partArr.getSize(); i++){
      if(partArr[i]->getName().compare(name) == 0)return partArr[i];
  }

  cout<<"No such part exists"<<endl;
  return NULL;

}

Aircraft* Airline::getAircraft(const string& type){

  for(int i=0; i < aircraftArr.getSize(); i++){
      if(aircraftArr[i]->getRegistration().compare(type) == 0)return aircraftArr[i];
  }

  cout<<"No such aircraft exists"<<endl;
  return NULL;

}


void Airline::addAircraft(const string& type, const string& reg){

  if(!aircraftArr.isFull())aircraftArr.add(new Aircraft(type,reg));

}

void Airline::addPart(const string& part, int fh, int it){

    if(!partArr.isFull()){
        //cout<<partArr.isFull()<<endl;

        if(it != 0 && fh != 0)partArr.add(new FHIT_Part(part,fh,it));
        else if(it != 0)partArr.add(new IT_Part(part,it));
        else partArr.add(new FH_Part(part,fh));
  }

}

void Airline::takeFlight(const string reg, int hours){

    Aircraft* e = getAircraft(reg);
    if(e == NULL){
      return;
    }

    e->takeFlight(hours);

}

void Airline::printParts(){
    cout<<"All parts: "<<endl;
    for(int i =0; i < partArr.getSize(); i++){
        cout<<partArr[i]<<endl;
    }
}

void Airline::printAircraft(){

    cout<<"All aircraft: "<<endl;
    for(int i =0; i < aircraftArr.getSize(); i++){
        cout<<aircraftArr[i]<<endl;
    }
}

void Airline::inspectionReport(const string& reg, Date& d){

    Aircraft *a = getAircraft(reg);
    if(a == NULL){
      return;
    }

    Array<Part*> replace;
    a->inspectionReport(d,&replace);

    cout<<"Aircraft: "<<reg<<" should replace following parts: "<<endl;
    for(int i = replace.getSize()-1; i >= 0; i--){
        cout<<replace[i]<<endl;
        //delete replace[i];
    }

}

bool Airline::install(string reg, string n, Date& d){

  Aircraft *a = getAircraft(reg);
  Part *p = getParts(n);

  if(a == NULL || p == NULL)return false;

  a->install(p,d);
  return true;
}
