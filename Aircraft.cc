#include "Aircraft.h"


Aircraft::Aircraft(const string type, const string reg){

  Aircraft::type = type;
  registration = reg;
  flightHours = 0;
  //cout<<arr<<endl;
  //

}

Aircraft::~Aircraft(){

  //cout<<"aircraft destructor called"<<endl;

}

void Aircraft::install(Part* p,Date& d){

  p->install(d);
  arr.add(p);

}

void Aircraft::takeFlight(int hours){

    flightHours += hours;

    for(int i =0; i < arr.getSize(); i++){
        arr[i]->addFlightHours(hours);
    }


}

void Aircraft::inspectionReport(Date& d, Array<Part*>* array){

    for(int i =0; i < arr.getSize(); i++){
      if(arr[i]->inspection(d))array->add(arr[i]);

    }

}

std::ostream& operator<<(std::ostream& cout, Aircraft* a){


      cout<<"Type: " <<a->getType()<<endl;
      cout<<"Registration: "<<a->getRegistration()<<endl;
      //cout<<"Flight hours: "<<a->getFlightHours()<<endl;

      // Array<Part*> p;
      // Date d;
      // a->inspectionReport(d,&p);
      //
      // cout<<endl<<"Parts: "<<endl<<p<<endl;

    return cout;
}
