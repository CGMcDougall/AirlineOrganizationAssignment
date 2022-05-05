#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include "Array.h"
#include "Part.h"
#include "Date.h"
#include "Aircraft.h"

using namespace std;

class Airline{

  public:
    Airline(const string&);
    ~Airline();

    void addAircraft(const string&, const string&);
    void addPart(const string& part, int fh_inspect, int it_inspect);

    void takeFlight(const string reg, int hours);

    void printAircraft();
    void printParts();

    void inspectionReport(const string& reg, Date&);

    bool install(string reg, string n, Date&);

  private:
    string name;
    Array<Part*> partArr;
    Array<Aircraft*> aircraftArr;


    Part* getParts(const string&);
    Aircraft* getAircraft(const string&);

};

#endif
