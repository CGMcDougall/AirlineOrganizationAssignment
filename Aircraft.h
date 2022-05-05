#ifndef AIRC_H
#define AIRC_H

#include <string>
#include "Array.h"
#include "Part.h"
#include <iostream>

using namespace std;

class Aircraft{

  friend ostream& operator<<(ostream&,Aircraft*);

  public:
    Aircraft(const string, const string);
    ~Aircraft();

    inline string& getRegistration() {return registration;}
    inline string& getType() {return type;}
    inline int getFlightHours() {return flightHours; }

    void install(Part*,Date&);

    void takeFlight(int);

    void inspectionReport(Date& d, Array<Part*>* array);


  protected:
    string type;
    string registration;
    int flightHours;
    Array<Part*> arr;

};


#endif
