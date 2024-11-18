#include "header.h";
int main()
{

    // Instantiate Driver
    Driver* driver = mariadb::get_driver_instance();

    // Configure Connection
    SQLString url("jdbc:mariadb://localhost:3306/hotel");
    Properties properties({ {"user", "jean"}, {"password", "123"} });

    // Establish Connection
    unique_ptr<Connection> conn(driver->connect(url, properties));

    connexion(conn);

    vector<Chambres> chambres(10);

    //getMenu(chambres);

    /*
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