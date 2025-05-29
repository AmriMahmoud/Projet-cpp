#include "part1/Client.h"
#include "part1/Table.h"
#include "part1/Reservation.h"
#include "part1/Service.h"
#include "part1/Employe.h"
#include "part1/ChefCuisinier.h"
#include "part1/OperationInvalideException.h"
#include "part2/Menu.h"
#include "part2/Entree.h"
#include "part2/PlatPrincipal.h"
#include "part2/Dessert.h"
#include "part2/BoissonAlcoolisee.h"
#include "part2/BoissonNonAlcoolisee.h"
#include "part3/Stock.h"
#include "part3/LotProduction.h"
#include "part3/SauceMaison.h"
#include "part3/DessertFrais.h"
#include "part3/PreparationMaison.h"
#include "part3/PieceViande.h"
#include "part3/FichierException.h"
#include"template.h"
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

void afficherMenuPrincipal() {
    cout << "\n---- Menu Principal ----\n";
    cout << "1. Gerer les reservations\n";
    cout << "2. Gerer le menu\n";
    cout << "3. Gerer le stock\n";
    cout << "4. Tester les fonctionnalites\n";
    cout << "5. Quitter\n";
    cout << "Choix: ";
}

void gererReservations(Service& service, vector<Table>& tables, vector<shared_ptr<Client>>& clients) {
    int choix;
    do {
        cout << "\n---- Gestion des Reservations ----\n";
        cout << "1. Faire une reservation\n";
        cout << "2. Afficher les reservations\n";
        cout << "3. Modifier une reservation\n";
        cout << "4. Supprimer une reservation\n";
        cout << "5. Retour au menu principal\n";
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                auto client = make_shared<Client>();
                cout << "Entrez les informations du client:\n";
                cin >> *client;
                clients.push_back(client);
                cout << "Tables disponibles:\n";
                for (size_t i = 0; i < tables.size(); i++) {
                    if (tables[i].estDisponible()) {
                        cout << i << ". " << tables[i] << endl;
                    }
                }
                int tableIndex;
                unsigned int nbPersonnes;
                cout << "Choisissez une table (numero de la liste): ";
                cin >> tableIndex;
                cout << "Nombre de personnes: ";
                cin >> nbPersonnes;

                if (tableIndex >= 0 && static_cast<size_t>(tableIndex) < tables.size() && tables[tableIndex].estDisponible()) {
                    auto res = make_shared<Reservation>(clients.back().get(), &tables[tableIndex], nbPersonnes);
                    res->confirmer();
                    service.ajouterReservation(res);
                } else {
                    cout << "Table invalide ou deja occupee!\n";
                }
                break;
            }
            case 2: {
                if (service.getNombreReservations() == 0) {
                    cout << "Aucune reservation.\n";
                } else {
                    cout << service;
                }
                break;
            }
            case 3: {
                int index;
                if (service.getNombreReservations() == 0) {
                    cout << "Aucune reservation a modifier.\n";
                    break;
                } else {
                    cout << service;
                }
                cout << "Entrez l'index de la reservation a modifier (0-"<< service.getNombreReservations() - 1 << "): ";
                cin >> index;
                if (index >= 0 && static_cast<size_t>(index) < service.getNombreReservations()) {
                    unsigned int nbPersonnes;
                    service.modifierReservation(index, nbPersonnes);
                } else {
                    cout << "Index invalide.\n";
                }
                break;
            }
            case 4: {
                int index;
                if (service.getNombreReservations() == 0) {
                    cout << "Aucune reservation a supprimer." << endl;
                    break;
                } else {
                    cout << service;
                }
                cout << "Entrez l'index de la reservation a supprimer (0-"
                << service.getNombreReservations() - 1 << "): ";
                cin >> index;
                if (index >= 0 && static_cast<size_t>(index) < service.getNombreReservations()) {
                    service.supprimerReservation(index);
                } else {
                    cout << "Index invalide.\n";
                }
                break;
            }
            case 5:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Option invalide.\n";
        }
    } while (choix != 5);
}
void gererMenu(Menu& menu) {
    int choix;
    do {
        cout << "\n---- Gestion du Menu ----\n";
        cout << "1. Ajouter un item au menu\n";
        cout << "2. Afficher le menu\n";
        cout << "3. Modifier un item\n";
        cout << "4. Supprimer un item\n";
        cout << "5. Retour au menu principal\n";
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                string type, nom, description;
                cout << "Type d'item (entree/plat/dessert/boisson): ";
                cin >> type;
                if (type == "entree") {
                    auto entree = make_unique<Entree>();
                    cout << "Entrez les details de l'entree:\n";
                    cin >> *entree;
                    menu.ajouterItem(move(entree));
                } else if (type == "plat") {
                    auto plat = make_unique<PlatPrincipal>();
                    cout << "Entrez les details du plat principal:\n";
                    cin >> *plat;
                    menu.ajouterItem(move(plat));
                } else if (type == "dessert") {
                    auto dessert = make_unique<Dessert>();
                    cout << "Entrez les details du dessert:\n";
                    cin >> *dessert;
                    menu.ajouterItem(move(dessert));
                } else if (type == "boisson") {
                    string alcoolisee;
                    cout << "Alcoolisee ? (oui/non): ";
                    cin >> alcoolisee;
                    if (alcoolisee == "oui") {
                        auto boisson = make_unique<BoissonAlcoolisee>();
                        cout << "Entrez les details de la boisson alcoolisee:\n";
                        cin >> *boisson;
                        menu.ajouterItem(move(boisson));
                    } else {
                        auto boisson = make_unique<BoissonNonAlcoolisee>();
                        cout << "Entrez les details de la boisson non alcoolisee:\n";
                        cin >> *boisson;
                        menu.ajouterItem(move(boisson));
                    }
                } else {
                    cout << "Type d'item invalide.\n";
                }
                break;
            }
            case 2:
                cout << menu << endl;
                break;
            case 3: {
                cout << "Liste des items du menu:\n";
                cout << menu << endl;
                int index;
                cout << "Entrez l'index de l'item a modifier: ";
                cin >> index;
                if (index >= 0 && index < menu.getItems().size()) {
                    string nom, description;
                    double prix;

                    cout << "Nouveau nom: ";
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Nouvelle description: ";
                    getline(cin, description);
                    cout << "Nouveau prix: ";
                    cin >> prix;
                    menu.modifierItem(index, nom, description, prix);
                    cout << "Item modifie.\n";
                } else {
                    cout << "Index invalide.\n";
                }
                break;
            }
            case 4: {
                cout << "Liste des items du menu:\n";
                cout << menu << endl;
                int index;
                cout << "Entrez l'index de l'item a supprimer: ";
                cin >> index;
                menu.supprimerItem(index);
                break;
            }
            case 5:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Option invalide.\n";
        }
    } while (choix != 5);
}
void gererStock(Stock& stock) {
    int choix;
    do {
        cout << "\n---- Gestion du Stock ----\n";
        cout << "1. Ajouter un produit\n";
        cout << "2. Ajouter un lot\n";
        cout << "3. Verifier disponibilite\n";
        cout << "4. Faire l'inventaire\n";
        cout << "5. Definir seuil d'alerte\n";
        cout << "6. Sauvegarder/Charger produit\n";
        cout << "7. Retour au menu principal\n";
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                string typeProduit;
                cout << "Type de produit (sauce/dessert/viande): ";
                cin >> typeProduit;

                if (typeProduit == "sauce") {
                    auto sauce = new SauceMaison();
                    cout << "Entrez les details de la sauce:\n";
                    cin >> *sauce;
                    stock.ajouterProduit(sauce);
                    cout << "Sauce ajoutee au stock.\n";
                } else if (typeProduit == "dessert") {
                    auto dessert = new DessertFrais();
                    cout << "Entrez les details du dessert:\n";
                    cin >> *dessert;
                    stock.ajouterProduit(dessert);
                    cout << "Dessert ajoute au stock.\n";
                } else if (typeProduit == "viande") {
                    auto viande = new PieceViande();
                    cout << "Entrez les details de la piece de viande:\n";
                    cin >> *viande;
                    stock.ajouterProduit(viande);
                    cout << "Piece de viande ajoutee au stock.\n";
                } else {
                    cout << "Type de produit invalide.\n";
                }
                break;
            }
            case 2: {
                auto lot = new LotProduction();
                cout << "Entrez les details du lot:\n";
                cin >> *lot;
                stock.ajouterLot(lot);
                cout << "Lot ajoute au stock.\n";
                break;
            }
            case 3: {
                string nom;
                int quantite;
                cout << "Nom du produit: ";
                cin >> nom;
                cout << "Quantite a verifier: ";
                cin >> quantite;
                bool disponible = stock.verifierDisponibilite(nullptr, quantite); 
                cout << "Disponibilite: " << (disponible ? "Oui" : "Non") << endl;
                break;
            }
            case 4: {
                cout << stock << endl;
                break;
            }
            case 5: {
                string nomProduit;
                int seuil;
                cout << "Nom du produit: ";
                cin.ignore();
                getline(cin, nomProduit);
                cout << "Seuil d'alerte: ";
                cin >> seuil;
                stock.definirSeuilAlerte(nomProduit, seuil);
                cout << "Seuil d'alerte defini pour " << nomProduit << ".\n";
                break;
            }
            case 6: {
                int sousCHoix;
                cout << "\n1. Sauvegarder une preparation\n";
                cout << "2. Charger une preparation\n";
                cout << "Choix: ";
                cin >> sousCHoix;

                if (sousCHoix == 1) {
                    auto prep = new PreparationMaison("Tarte aux pommes", 12.50, "France", 45, "Moyenne");
                    string nomFichier;
                    cout << "Nom du fichier: ";
                    cin.ignore();
                    getline(cin, nomFichier);
                    prep->sauvegarderDansFichier(nomFichier);
                    cout << "Preparation sauvegardee dans " << nomFichier << ".\n";
                    delete prep;
                } else if (sousCHoix == 2) {
                    string nomFichier;
                    cout << "Nom du fichier: ";
                    cin.ignore();
                    getline(cin, nomFichier);
                    auto prep = PreparationMaison::chargerDeFichier(nomFichier);
                    if (prep) {
                        cout << "Preparation chargee: " << *prep << endl;
                        delete prep;
                    } else {
                        cout << "Erreur lors du chargement du fichier.\n";
                    }
                } else {
                    cout << "Option invalide.\n";
                }
                break;
            }
            case 7:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Option invalide.\n";
        }
    } while (choix != 7);
}
void testerFonctionnalites() {
    cout << "\n==== Test des Fonctionnalites ====\n";
    // 1. Operateur + et - dans PreparationMaison
    cout << "\n-- 1. Operateurs + et - dans PreparationMaison --\n";
    PreparationMaison prep("Tarte aux pommes", 12.50, "France", 45, "Moyenne");
    cout << "Preparation initiale : " << prep << endl;

    PreparationMaison prepPlus = prep + 15;
    cout << "Apres +15 minutes : " << prepPlus << endl;

    PreparationMaison prepMinus = prep - 10;
    cout << "Apres -10 minutes : " << prepMinus << endl;

    // 2. Operateur d'affectation dans Stock
    cout << "\n-- 2. Operateur d'affectation dans Stock --\n";
    Stock stock1;
    stock1.ajouterProduit(new PreparationMaison("Tarte aux pommes", 12.50, "France", 45, "Moyenne"));
    stock1.ajouterLot(new LotProduction("2023-05-01", 10, "LOT123"));

    Stock stock2;
    stock2 = stock1;

    cout << "Stock original :\n" << stock1 << endl;
    cout << "Stock copie :\n" << stock2 << endl;

    // 3. Utilisation de std::map dans Stock
    cout << "\n-- 3. Seuils avec std::map --\n";
    stock1.definirSeuilAlerte("Tarte aux pommes", 5);
    stock1.definirSeuilAlerte("Mousse au chocolat", 3);

    cout << "Seuil pour Tarte aux pommes : " << stock1.getSeuilAlerte("Tarte aux pommes") << endl;
    cout << "Seuil pour Mousse au chocolat : " << stock1.getSeuilAlerte("Mousse au chocolat") << endl;
    cout << "Seuil pour Produit inconnu : " << stock1.getSeuilAlerte("Produit inconnu") << endl;

    // 4. Operations sur les fichiers avec fstream
    cout << "\n-- 4. Sauvegarde et Chargement de Fichiers --\n";
    PreparationMaison prepFile("Mousse au chocolat", 8.50, "Belgium", 30, "Easy");

    try {
        prepFile.sauvegarderDansFichier("c:/fichiers/mousse.txt");
        cout << "Preparation sauvegardee dans : c:/fichiers/mousse.txt\n";

        PreparationMaison* loadedPrep = nullptr;
        try {
            loadedPrep = PreparationMaison::chargerDeFichier("mousse.txt");
            cout << "Charge depuis le chemin par defaut : " << *loadedPrep << endl;
            delete loadedPrep;
        } catch (const FichierException& e) {
            cout << "Erreur de chargement : " << e.what() << "\nEssai avec le chemin complet...\n";
            loadedPrep = PreparationMaison::chargerDeFichier("c:/fichiers/mousse.txt");
            cout << "Charge : " << *loadedPrep << endl;
            delete loadedPrep;
        }
    } catch (const FichierException& e) {
        cout << "Erreur de fichier : " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Erreur inattendue : " << e.what() << endl;
    }

    // 5. Chargement d'un fichier inexistant
    cout << "\n-- 5. Chargement d'un fichier inexistant --\n";
    try {
        PreparationMaison* p = PreparationMaison::chargerDeFichier("c:/fichiers/inexistant.txt");
        cout << "Charge avec succes : " << *p << endl;
        delete p;
    } catch (const FichierException& e) {
        cout << "Exception attrapee : " << e.what() << endl;
        cout << "  Operation : " << e.getOperation() << " | Fichier : " << e.getFichier() << endl;
    }

    // 6. Tests des operateurs de Dessert
    cout << "\n-- 6. Operateurs de Dessert --\n";
    Dessert d1("Tiramisu", 5.5, "Dessert italien au cafe", 15, 300);
    cout << "Dessert initial :\n" << d1 << endl;

    Dessert d2 = d1 + 100;
    cout << "\nApres +100 calories :\n" << d2 << endl;

    Dessert d3 = d2 - 250;
    cout << "\nApres -250 calories :\n" << d3 << endl;

    string dessertFile = "c:/fichiers/dessert_test.txt";
    d3.sauvegarderDansFichier(dessertFile);
    cout << "\nDessert sauvegarde dans : " << dessertFile << endl;

    Dessert d5 = Dessert::chargerDeFichier(dessertFile);
    cout << "\nDessert charge depuis le fichier :\n" << d5 << endl;

    // 7. Tests du Menu : copie, modification, exception
    cout << "\n-- 7. Tests du Menu --\n";
    Menu menu1;
    menu1.ajouterCategorie("Entree", 6.0);
    menu1.ajouterCategorie("Plat principal", 14.5);
    menu1.ajouterItem(make_unique<Plat>("Soupe", 5.0, "Soupe de legumes"));
    menu1.ajouterItem(make_unique<Plat>("Steak", 15.0, "Steak et frites"));

    cout << "\n--- Menu 1 ---\n";
    menu1.afficherMenu();
    menu1.afficherCategoriesPrix();

    Menu menu2;
    menu2 = menu1;


    cout << "\n--- Menu 2 (copie) ---\n";
    menu2.afficherMenu();
    menu2.afficherCategoriesPrix();

    menu1.supprimer(0);
    menu1.ajouterCategorie("Dessert", 4.0);

    cout << "\n--- Menu 1 (modifie) ---\n";
    menu1.afficherMenu();
    menu1.afficherCategoriesPrix();

    cout << "\n--- Menu 2 (devrait etre inchange) ---\n";
    menu2.afficherMenu();
    menu2.afficherCategoriesPrix();

    try {
        double prixEntree = menu1.getPrixMoyenCategorie("Entree");
        cout << "Prix moyen pour Entree : " << prixEntree << " TND" << endl;

        double prixSoupe = menu1.getPrixMoyenCategorie("Soupe");
        cout << "Prix moyen pour Soupe : " << prixSoupe << " TND" << endl;

    } catch (const DonneeInexistanteException& e) {
        cerr << "Exception attrapee : " << e.what() << endl;
        cerr << "  Collection : " << e.getCollection()
             << " | Identifiant : " << e.getIdentifiant() << endl;
    }

    // 8. Ajustements de salaire des employes
    cout << "\n-- 8. Operations sur les salaires des employes --\n";
    Employe emp("Dupont", "Jean", "0601020304", 1, 2000.0);
    cout << "Salaire initial : " << emp.getSalaire() << " TND" << endl;

    Employe empBonus = emp + 500.0;
    cout << "Apres bonus (+500) : " << empBonus.getSalaire() << " TND" << endl;

    try {
        Employe empReduc = emp - 800.0;
        cout << "Apres reduction (-800) : " << empReduc.getSalaire() << " TND" << endl;
    } catch (const OperationInvalideException& ex) {
        cerr << "Exception attrapee : " << ex.what() << endl;
        cerr << "  Operation : " << ex.getOperation() << " | Valeur : " << ex.getValeur() << endl;
    }

    try {
        Employe empNegative = emp - 2500.0;
        cout << "Apres reduction excessive : " << empNegative.getSalaire() << " TND" << endl;
    } catch (const OperationInvalideException& ex) {
        cerr << "Exception attrapee : " << ex.what() << endl;
        cerr << "  Operation : " << ex.getOperation() << " | Valeur : " << ex.getValeur() << endl;
    }

    // 9. Sauvegarde/chargement de ChefCuisinier
    cout << "\n-- 9. Sauvegarde/Chargement de Chef --\n";
    ChefCuisinier chef("Martin", "Sophie", "0611223344", 2, 3000.0, "Cuisine francaise");
    cout << "[Avant sauvegarde] :\n" << chef << endl;

    string chefFile = "c:/fichiers/chef_test.txt";
    chef.sauvegarderDansFichier(chefFile);

    ChefCuisinier chefLoaded = ChefCuisinier::chargerDeFichier(chefFile);
    cout << "\n[Apres chargement] :\n" << chefLoaded << endl;

    // 10. Operations sur les reservations et services
    cout << "\n-- 10. Reservations et Service --\n";
    Client client1("John", "Doe", "123-456-7890");
    Client client2("Jane", "Smith", "098-765-4321");

    Table table1(1), table2(2), table3(3);

    auto res1 = make_shared<Reservation>(&client1, &table1, 4);
    auto res2 = make_shared<Reservation>(&client2, &table2, 2);
    auto res3 = make_shared<Reservation>(&client1, &table3, 6);

    Service service1;
    service1.ajouterReservation(res1);
    service1.ajouterReservation(res2);
    service1.ajouterReservation(res3);

    cout << "Service 1 (avant modifications) :\n";
    cout << service1;

    service1.modifierReservation(1, 5);
    cout << "\nService 1 (apres modification) :\n";
    cout << service1;

    Service service2 = service1;
    cout << "\nService 2 (apres affectation) :\n";
    cout << service2;

    service1.getReservations().front()->annuler();
    cout << "\nService 1 (apres annulation) :\n";
    cout << service1;

    service1.supprimerReservation(0);
    cout << "\nService 1 (apres suppression) :\n";
    cout << service1;

    service1.terminerService();
    cout << "\nService 1 (apres terminaison) :\n";
    cout << service1;

    // 11. Template
    cout << "\n-- 11. Template --\n";

    Tableau<Plat> menuPlat;

    menuPlat.ajouterLigne({Plat("Soupe de legumes", 5.50), Plat("Salade", 7.00)});
    menuPlat.ajouterLigne({Plat("Steak", 15.00), Plat("Poulet roti", 12.50)});

    cout << "Tableau Plat :\n";
    menuPlat.afficherTableau();

    menuPlat.ajouterItem(0, 2, Plat("Tarte", 6.00));
    cout << "\nTableau Plat (apres ajout d'un nouvel element) :\n";
    menuPlat.afficherTableau();

    Tableau<Dessert> menuDessert;

    menuDessert.ajouterLigne({Dessert("Tiramisu", 4.50), Dessert("Creme brulee", 5.00)});
    menuDessert.ajouterLigne({Dessert("Mousse au chocolat", 4.00), Dessert("Glace", 3.50)});

    cout << "\nTableau Dessert :\n";
    menuDessert.afficherTableau();
}



int main() {
    vector<Table> tables;
    Service service;
    Menu menu;
    Stock stock;
    vector<shared_ptr<Client>> clients;

    int tailles[] = {2, 4, 6, 8, 10};
    for (int i = 1; i <= 20; i++) {
        tables.emplace_back(i, tailles[i % 5]);
    }


    int choix;
    do {
        afficherMenuPrincipal();
        cin >> choix;

        switch (choix) {
            case 1:
                gererReservations(service, tables, clients);
                break;
            case 2:
                gererMenu(menu);
                break;
            case 3:
                gererStock(stock);
                break;
            case 4:
                testerFonctionnalites();
                break;
            case 5:
                cout << "Au revoir!\n";
                break;
            default:
                cout << "Option invalide.\n";
        }
    } while (choix != 5);

    return 0;
}
