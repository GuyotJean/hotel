#include "header.h"

void getData(const unique_ptr<Connection>& conn) {
    try {

        conn->setSchema("Hotel");
        // Create a new Statement
        unique_ptr<Statement> stmnt(conn->createStatement());

        // Execute query
        ResultSet* res = stmnt->executeQuery("SELECT COUNT(*) FROM Chambres");
        res->next();
        
        
        if (res->getInt(1) == 0) {
            cout << "La table est vide : " << endl;

            string query = "INSERT INTO Chambres (Numero) VALUES (?)";

            unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));

            for (int i = 0; i < 10; i++) {
                int data1 = 100 + i;

                pstmt->setInt(1, data1);

                pstmt->executeQuery();

            }

            pstmt->executeUpdate();

            cout << "Table prete." << endl;
        }

        else {
            cout << "Table deja remplie." << endl;
            this_thread::sleep_for(std::chrono::seconds(2));
            system("cls");
            AfficherDonnees(conn);
            getMenu(conn);
        }
    }
    catch(SQLException) {

    }


}

    
void AfficherDonnees(const unique_ptr<Connection>& conn) {
    // Create a new Statement
    unique_ptr<Statement> stmnt(conn->createStatement());

    // Execute query
    ResultSet* res = stmnt->executeQuery("SELECT * FROM Chambres");

    // Loop through and print results
    while (res->next()) {
        cout << "id = " << res->getInt(1);
        cout << ", Numero = " << res->getInt(2);
        cout << ", Nom = " << res->getString(3);
        cout << ", Prenom = " << res->getString(4);
        cout << ", isReserved = " << res->getString(5) << endl;

    }
}


void getMenu(const unique_ptr<Connection>& conn) {
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
        doReserv(conn);
        break;
    case 2:
        undoReserv(conn);
        break;
    case 3:
        confirmReserv(conn);
        break;
    case 4:
        ModifyReserv(conn);
        break;
    case 5:
        occup(conn);
        break;
    case 6:
        out(conn);
        break;
    case 7:
        leaveMenu(conn);
        break;
    }
}


void doReserv(const unique_ptr<Connection>& conn) {

}
void undoReserv(const unique_ptr<Connection>& conn) {
    cout << "Annuler la reservation";
}
void confirmReserv(const unique_ptr<Connection>& conn) {
}
void ModifyReserv(const unique_ptr<Connection>& conn) {
    cout << "Modifier la reservation : ";
}
void occup(const unique_ptr<Connection>& conn) {
    cout << "Occuper la chambre : ";
}
void out(const unique_ptr<Connection>& conn) {
    cout << "Quitter la chambre : ";
}
void leaveMenu(const unique_ptr<Connection>& conn) {
    cout << "Vous etes sorti(e).";
}