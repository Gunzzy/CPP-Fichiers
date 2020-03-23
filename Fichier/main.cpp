#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void creerFichier()
{
    ofstream fileStream;
    fileStream.open("prenom.txt");
    fileStream << "Pipoudou" << endl;
    fileStream << "Michel" << endl;
    fileStream << "Starf" << endl;
}

bool chargeFichier(vector<string> &listeNom)
{
    ifstream fileStream("names.txt");
    string LINE;
    if (fileStream.is_open()) {
        while (getline(fileStream, LINE))listeNom.push_back(LINE);
    } else {
        return true;
    }
    return false;
}

bool chercheNom(string nom, const vector<string> &listeNoms)
{
    for(int i = 0; i < listeNoms.size(); i++) if(listeNoms[i] == nom) return true;
    return false;
}

int main()
{
    creerFichier();
    vector<string> names;
    chargeFichier(names);
    cout<< chercheNom("Pipoudou", names) << endl;
    cout<< chercheNom("David", names) << endl;

    return 0;
}
