
#include <iostream>
using namespace std;

struct Noeud {
    int valeur;
    Noeud* gauche;
    Noeud* droite;
};

struct File {
    Noeud* T[100];
    int debut;
    int fin;
};

void Initialiser(File &F) {
    F.debut = 0;
    F.fin = -1;
}

bool FileVide(File F) {
    return F.debut > F.fin;
}

void Enfiler(File &F, Noeud* p) {
    F.fin++;
    F.T[F.fin] = p;
}

Noeud* Defiler(File &F) {
    Noeud* p = F.T[F.debut];
    F.debut++;
    return p;
}

Noeud* CreerNoeud(int x) {
    Noeud* p = new Noeud;
    p->valeur = x;
    p->gauche = NULL;
    p->droite = NULL;
    return p;
}

Noeud* RemplirArbre() {
    int n, x;

    cout << "Donner le nombre de noeuds : ";
    cin >> n;

    if (n <= 0)
        return NULL;

    cout << "Donner la valeur de la racine : ";
    cin >> x;

    Noeud* racine = CreerNoeud(x);

    File F;
    Initialiser(F);
    Enfiler(F, racine);

    int compteur = 1;

    while (compteur < n) {
        Noeud* p = Defiler(F);

        cout << "Fils gauche de " << p->valeur
             << " (1 si tu veux le creer, 0 sinon) : ";

        int choix;
        cin >> choix;

        if (choix == 1 && compteur < n) {
            cout << "Valeur du fils gauche : ";
            cin >> x;

            p->gauche = CreerNoeud(x);
            Enfiler(F, p->gauche);
            compteur++;
        }

        if (compteur < n) {
            cout << "Fils droit de " << p->valeur
                 << " (1 si tu veux le creer, 0 sinon) : ";
            cin >> choix;

            if (choix == 1) {
                cout << "Valeur du fils droit : ";
                cin >> x;

                p->droite = CreerNoeud(x);
                Enfiler(F, p->droite);
                compteur++;
            }
        }
    }

    return racine;
}

void AffichageLargeur(Noeud* racine) {
    if (racine == NULL)
        return;

    File F;
    Initialiser(F);
    Enfiler(F, racine);

    while (!FileVide(F)) {
        Noeud* p = Defiler(F);

        cout << p->valeur << " ";

        if (p->gauche != NULL)
            Enfiler(F, p->gauche);

        if (p->droite != NULL)
            Enfiler(F, p->droite);
    }
}

int main() {
    Noeud* A = RemplirArbre();

    cout << "Affichage par largeur : ";
    AffichageLargeur(A);

    return 0;
}
