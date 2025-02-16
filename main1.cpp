#include <iostream>
#include <limits>
#include <iomanip>

#if !defined(EXO)
#define EXO 1
#endif

#if EXO == 1
int main() {
    int tab[10] = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Taille totale du tableau : " << sizeof(tab) << " octet(s)\n";
    std::cout << "Taille d'un élément : " << sizeof(tab[0]) << " octet(s)\n";
    std::cout << "Nombre d'éléments : " << sizeof(tab)/sizeof(tab[0]) << "\n";
    return 0;
}

#elif EXO == 2
int main() {
    const int PETITE_PIECE = 250;
    const int GRANDE_PIECE = 350;
    const double TAXE = 0.06;
    const int JOURS = 30;

    int petites, grandes;
    std::cout << "Number of small rooms: ";
    std::cin >> petites;
    std::cout << "Number of large rooms: ";
    std::cin >> grandes;

    int cout = petites * PETITE_PIECE + grandes * GRANDE_PIECE;
    double tax = cout * TAXE;
    double total = cout + tax;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Estimate for carpet cleaning service\n";
    std::cout << "Number of small rooms: " << petites << "\n";
    std::cout << "Number of large rooms: " << grandes << "\n";
    std::cout << "Price per small room: " << PETITE_PIECE << "dh\n";
    std::cout << "Price per large room: " << GRANDE_PIECE << "dh\n";
    std::cout << "Cost : " << cout << "dh\n";
    std::cout << "Tax: " << tax << "dh\n";
    std::cout << "=============================\n";
    std::cout << "Total estimate: " << total << "dh\n";
    std::cout << "This estimate is valid for " << JOURS << " days\n";
    return 0;
}

#elif EXO == 3
constexpr int factorielle(int n) {
    return n <= 1 ? 1 : n * factorielle(n - 1);
}

int main() {
    constexpr int resultat = factorielle(5);
    static_assert(factorielle(5) == 120, "Erreur factorielle");
    std::cout << "Factorielle de 5 : " << resultat << "\n";
    return 0;
}

#elif EXO == 4
int value = 100;

int main() {
    int value = 50;
    std::cout << "Valeur locale : " << value << "\n";
    std::cout << "Valeur globale : " << ::value << "\n";
    return 0;
}

#elif EXO == 5
const int MOIS = 12;
constexpr double RAYON = 7.0;
#define PI 3.14159

int main() {
    // MOIS = 13; // Erreur si décommenté
    double aire = PI * RAYON * RAYON;
    std::cout << "Nombre de mois dans une année : " << MOIS << "\n";
    std::cout << "Rayon du cercle : " << RAYON << "\n";
    std::cout << "Aire du cercle : " << aire << "\n";
    return 0;
}

#elif EXO == 6
int safeMultiply(int a, int b) {
    if (a > 0 && b > 0) {
        if (a > std::numeric_limits<int>::max() / b) {
            std::cerr << "Erreur: Overflow!\n";
            return -1;
        }
    } else if (a < 0 && b < 0) {
        if (a < std::numeric_limits<int>::max() / b) {
            std::cerr << "Erreur: Overflow!\n";
            return -1;
        }
    } else if (a > 0 && b < 0) {
        if (b < std::numeric_limits<int>::min() / a) {
            std::cerr << "Erreur: Overflow!\n";
            return -1;
        }
    } else if (a < 0 && b > 0) {
        if (a < std::numeric_limits<int>::min() / b) {
            std::cerr << "Erreur: Overflow!\n";
            return -1;
        }
    }
    return a * b;
}

int main() {
    int a = 30000, b = 1000;
    int result = safeMultiply(a, b);
    if (result != -1) std::cout << "Resultat: " << result << "\n";

    a = 300000, b = 10000;
    result = safeMultiply(a, b);
    if (result != -1) std::cout << "Resultat: " << result << "\n";
    return 0;
}

#else
int main() {
    std::cout << "Exercice non défini!\n";
    return 0;
}
#endif