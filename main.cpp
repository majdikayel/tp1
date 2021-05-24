#include <iostream>

#include "cout.hpp"
#include "eau.hpp"
#include "location.hpp"
#include "electricite.hpp"


int main()
{

    Cout *les_couts[250];

    float somme = 0;

    int nbr_couts{};
    Cout *cout = nullptr;
    int choix;

    do
    {
        std::cout << "===========MENU ============" << std::endl;
        std::cout << "1. Ajouter un coût de location avec ses informations" << std::endl;
        std::cout << "2. Ajouter un coût en électricité avec ses informations" << std::endl;
        std::cout << "3. Ajouter un coût pour la consommation d'eau avec ses informations" << std::endl;
        std::cout << "4. Afficher un compte-rendu de la machine avec les coûts entrés et les coûts totaux d'utilisation pour une période déterminée" << std::endl;
        std::cout << "0. Quitter le programme " << std::endl;
        std::cout << "entrez votre choix" << std::endl;
        std::cin >> choix;

        switch (choix){

        case 1:

            cout = new Location();

            std::cout << "Entrez le nom du location " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez l'espace du location en m² " << std::endl;
            static_cast<Location *>(cout)->set_espace(std::cin);

            std::cout << "Entrez le coût en sous pour la location " << std::endl;
            static_cast<Location *>(cout)->set_cout_location(std::cin);

            break;

        case 2:

            cout = new Electricite();

            std::cout << "Entrez le nom du cout d'electricité " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez le voltage de la machine " << std::endl;
            static_cast<Electricite *>(cout)->set_voltage(std::cin);

            std::cout << "Entrez l'ampérage de la machine " << std::endl;
            static_cast<Electricite *>(cout)->set_amperage(std::cin);

            std::cout << "Entrez un coût en sous de l'électricité " << std::endl;
            static_cast<Electricite *>(cout)->set_cout_electric(std::cin);

            break;

        case 3:

            cout = new Eau();

            std::cout << "Entrez le nom du cout en eau " << std::endl;
            cout->set_nom(std::cin);

            std::cout << "Entrez le débit " << std::endl;
            static_cast<Eau *>(cout)->set_debit(std::cin);

            std::cout << "Entrez le coût de l'eau en sous " << std::endl;
            static_cast<Eau *>(cout)->set_cout_eau(std::cin);

            break;

        case 4:

            int periode;
            std::cout << "Entrez la période " << std::endl;
            std::cin >> periode;

            for (int i = 0; i < nbr_couts; i++)
            {
                std::cout << les_couts[i]->getnom() << " : " << les_couts[i]->calculerCout() * periode << " $" << std::endl;
                somme += les_couts[i]->calculerCout() * periode;
            }

            std::cout << "========================" << std::endl;
            std::cout << "Cout total = " << somme << " $ "
                      << " pour " << periode << " jours " << std::endl;
            break;

        case 0:
            std::cout << "Fin de programme " << std::endl;
            break;

        default:
            std::cout << "Choix invalide" << std::endl;
            break;
        }

        if (cout != nullptr) { 
            if (nbr_couts <= 250){ 
                les_couts[nbr_couts++] = cout;
            }
            else { 
                std::cout << "Vous avez atteint la capacité maximale !" << std::endl;
            }
        }

    } while (choix != 0);

    for (int i = 0; i < nbr_couts; i++)
    {
        delete les_couts[i];
    }
}