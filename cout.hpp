#ifndef __COUT_HPP__
#define __COUT_HPP__

#include <iostream>
#include <string>

class Cout  {
  protected:
    std::string nom;
   
  public:
    Cout();
    Cout(std::string le_nom);
   
    void set_nom(std::string);
    void set_nom(std::istream&);

     const std::string& getnom();
   
    virtual ~Cout() = default ;

    virtual double calculerCout() = 0 ;
};

#endif