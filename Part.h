#ifndef PART_H
#define PART_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Part {

  friend ostream& operator<<(ostream&, Part*);

  public:
    Part(const string);
    Part(Part&);

    virtual ~Part();

    inline string getName() { return name; }
    inline int getFlightHours() { return flightHours; }
    inline Date& getDate() { return installationDate; }

    void addFlightHours(int);
    void install(Date&);

    virtual bool inspection(Date&);

    virtual void print(ostream& out) const;


  protected:
    string name;
    Date installationDate;
    int flightHours;



};


class FH_Part : virtual public Part {

  public:

    FH_Part(const string, int);
    FH_Part(FH_Part&);
    bool inspection(Date&) override;
    void print(ostream& out) const override;

  protected:
    int fh_inspect;

};


class IT_Part : virtual public Part{

  public:

    IT_Part(const string,int);
    IT_Part(IT_Part&);
    bool inspection(Date&) override;
    void print(ostream& out) const override;

  protected:
    int it_inspect;

};

class FHIT_Part : public IT_Part, public FH_Part {

  public:
    FHIT_Part(const string n, int fh, int it);
    FHIT_Part(FHIT_Part&);
    void print(ostream& out) const override;

    bool inspection(Date&) override;

};



#endif
