#include<iostream>

#include "cout.hpp"

Cout::Cout() {}

Cout::Cout(std::string le_nom){
    this->nom = le_nom;
}
void Cout::set_nom(std::string le_nom){
    this->nom =le_nom;
}
void Cout::set_nom(std::istream& is) {
  is>>nom;
}
const std::string& Cout::getnom() {
 return nom;
}