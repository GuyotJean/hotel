#include <mariadb/conncpp.hpp>
#include <iostream>

using namespace std;
using namespace sql;


int main()
{
    // Instantiate Driver
    Driver* driver = mariadb::get_driver_instance();

    // Configure Connection
    SQLString url("jdbc:mariadb://localhost:3306/todo");
    Properties properties({ {"user", "jean"}, {"password", "123"} });

    // Establish Connection
    unique_ptr<Connection> conn(driver->connect(url, properties));

    // Create a new Statement
    unique_ptr<Statement> stmnt(conn->createStatement());

    // Execute query
    ResultSet* res = stmnt->executeQuery("select * from tasks");

    // Loop through and print results
    while (res->next()) {
        cout << "id = " << res->getInt(1);
        cout << ", description = " << res->getString(2);
        cout << ", completed = " << res->getBoolean(3) << "\n";

    }


    // S�lectionner la base de donn�es
     conn->setSchema("todo");

     // Cr�er une requ�te d'insertion
     string description = "Acheter des courses";
     bool completed = false;
     string query = "INSERT INTO tasks (description, completed) VALUES (?, ?)";

     // Cr�er un PreparedStatement
     unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));

     // Lier les param�tres
     pstmt->setString(1, description);
     pstmt->setBoolean(2, completed);

     // Ex�cuter la requ�te d'insertion
     pstmt->executeUpdate();

     // Confirmer l'insertion
     cout << "Tache inseree avec succes." << endl;

     /*

     // Cr�er une requ�te de mise � jour (UPDATE)
     int taskId = 9; // ID de la t�che que vous voulez mettre � jour
     bool completed = true; // Mettre � jour le statut � 'true' (termin�)
     string query = "UPDATE tasks SET completed = ? WHERE id = ?";

     // Cr�er un PreparedStatement pour ex�cuter la requ�te UPDATE
     unique_ptr<PreparedStatement> pstmt(conn->prepareStatement(query));

     // Lier les param�tres � la requ�te
     pstmt->setBoolean(1, completed); // Lier la valeur 'completed' � la premi�re position (?)
     pstmt->setInt(2, taskId);         // Lier l'ID de la t�che � la deuxi�me position (?)

     // Ex�cuter la requ�te de mise � jour
     int rowsAffected = pstmt->executeUpdate(); // Nombre de lignes affect�es par la mise � jour

     // Afficher un message de confirmation
     if (rowsAffected > 0) {
         cout << "Tache mise a jour avec succes." << endl;
     }
     else {
         cout << "Aucune tache trouv�e avec cet ID ou mise a jour non effectuee." << endl;
     }
     */

    /* // S�lectionner la base de donn�es
    conn->setSchema("todo");

    // Cr�er une requ�te DELETE
    int taskId = 1; // ID de la t�che � supprimer
    string query = "DELETE FROM tasks WHERE id = ?";

    // Cr�er un PreparedStatement pour ex�cuter la requ�te DELETE
    unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));

    // Lier les param�tres � la requ�te
    pstmt->setInt(1, taskId); // Lier l'ID de la t�che � la position (?)

    // Ex�cuter la requ�te de suppression
    int rowsAffected = pstmt->executeUpdate(); // Nombre de lignes supprim�es

    // Afficher un message de confirmation
    if (rowsAffected > 0) {
        cout << "Tache supprimee avec succes." << endl;
    }
    else {
        cout << "Aucune tache trouvee avec cet ID ou mise a jour non effectuee." << endl;
    }
    */
}




























/*
struct Chambres {
    string nom;
    string prenom;
    int numero;
    bool reserv;
    bool occupy;
};

void getMenu(struct vector <Chambres> chambres);
void doReserv(struct vector <Chambres> chambres);
void undoReserv(struct vector <Chambres> chambres);
void confirmReserv(struct vector <Chambres> chambres, int a);
void ModifyReserv(struct vector <Chambres> chambres);
void occup(struct vector <Chambres> chambres);
void out(struct vector <Chambres> chambres);
void leaveMenu(struct vector <Chambres> chambres);
void getData(vector <Chambres> &chambres);

int main()
{
    struct vector <Chambres> chambres(10);
    getData(chambres);

    getMenu(chambres);
}



void getMenu(struct vector <Chambres> chambres) {
    int nav;
    cout << "Faire une reservation : [1]" << endl;
    cout << "Annuler la reservation : [2]" << endl;
    cout << "Confirmer la reservation : [3]" << endl;
    cout << "Modifier nom, nom de famille, chambre : [4]" << endl;
    cout << "Occuper la chambre : [5]" << endl;
    cout << "Sortir de la chambre : [6]" << endl;
    cout << "Quitter le menu : [7]" << endl;
    cin >> nav;

    switch (nav)
    {
    case 1:
        doReserv(chambres);
        break;
    case 2:
        undoReserv(chambres);
        break;
    case 3:
        confirmReserv(chambres,-1);
        break;
    case 4:
        ModifyReserv(chambres);
        break;
    case 5:
        occup(chambres);
        break;
    case 6:
        out(chambres);
        break;
    case 7:
        leaveMenu(chambres);
        break;
    }
}


void doReserv(struct vector <Chambres> chambres) {
    int choose = 0;
    cout << "############################################## Faire une reservation : " << endl;
    cout << "Les chambres disponible sont : " << endl;
    for (int i = 0; i < chambres.size(); i++) {
        if (chambres[i].occupy == false) {
            cout << "[" << chambres[i].numero << "] -----> Taper : " << i + 1 << endl;
        }
    }
    cin >> choose;
    choose -= 1;
    cout << "Vous allez reserver la chambre : " << chambres[choose].numero << endl;

    cout << "Veuillez entrer votre nom : ";
    cin >> chambres[choose].nom;
    cout << "Veuillez entrer votre prenom : ";
    cin >> chambres[choose].prenom;
    confirmReserv(chambres, choose);

}
void undoReserv(struct vector <Chambres> chambres) {
    cout << "Annuler la reservation";
}
void confirmReserv(struct vector <Chambres> chambres,int n) {
    string reponse;
    if (n > -1) {
        cout << "Recapitulation :\n Reservation pour " << chambres[n].prenom << "  " << chambres[n].nom << " \n Etes vous sur ?" << "\nYes / No" << endl;
        cin >> reponse;
        if (reponse == "Yes") {
            doReserv(chambres);
        }
        else if (reponse == "No") {
            //IL faut vider le tableau
            doReserv(chambres);
        }
    }
}
void ModifyReserv(struct vector <Chambres> chambres) {
    cout << "Modifier la reservation : ";
}
void occup(struct vector <Chambres> chambres) {
    cout << "Occuper la chambre : ";
}
void out(struct vector <Chambres> chambres) {
    cout << "Quitter la chambre : ";
}
void leaveMenu(struct vector <Chambres> chambres) {
    cout << "Vous etes sorti(e).";
}

void getData(struct vector <Chambres> &chambres) {
    for (int i = 0; i < chambres.size(); i++) {
        chambres[i].numero = 101 + i;
        chambres[i].occupy = false;
    }
}
*/