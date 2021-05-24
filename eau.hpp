#ifndef __EAU_HPP__
#define __EAU_HPP__

#include <iostream>
#include <string>

#include "cout.hpp"

class Eau : public Cout {
  private:
    float debit;
    float cout_eau;
  public:
    Eau();
    Eau(std::string le_nom, float debit, float cout_eau);
    
    void set_debit(float);
    void set_cout_eau(float);

    void set_debit(std::istream&);
    void set_cout_eau(std::istream&);

    double calculerCout() override;
    
    friend std::istream& operator>>(std::istream& is, Eau* eau);
    
};

#endif