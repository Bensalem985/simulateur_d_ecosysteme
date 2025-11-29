#include <windows.h> // Pour SetConsoleOutputCP
#include "Core/GameEngine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {

    // 🌐 Configuration de la console pour UTF-8
    SetConsoleOutputCP(65001);

    // 🎲 Initialisation de l'aléatoire
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::cout << "🎮 Demarrage du Simulateur d'Ecosysteme" << std::endl;
    std::cout << "=======================================" << std::endl;
    
    // 🏗 Création du moteur de jeu
    Ecosystem::Core::GameEngine engine("Simulateur d'Ecosystème Intelligent", 1200.0f, 800.0f);
    
    // ⚙️ Initialisation
    if (!engine.Initialize()) {
        std::cerr << "Erreur: Impossible d'initialiser le moteur de jeu" << std::endl;
        return -1;
    }
    
    std::cout << "Moteur initialisé avec succès" << std::endl;
    std::cout << "Lancement de la simulation..." << std::endl;
    std::cout << "=== CONTRÔLES ===" << std::endl;
    std::cout << "ESPACE: Pause/Reprise" << std::endl;
    std::cout << "R: Reset simulation" << std::endl;
    std::cout << "F: Ajouter nourriture" << std::endl;
    std::cout << "FLÊCHES: Vitesse simulation" << std::endl;
    std::cout << "ECHAP: Quitter" << std::endl;
    
    // 🎮 Boucle principale
    engine.Run();
    
    // 🛑 Arrêt propre
    engine.Shutdown();
    
    // 👋 Attente avant fermeture
    std::cout << "Simulation terminée. Appuyez sur entrée pour fermer..." << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
}