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
    // Sélectionner la base de données
     conn->setSchema("todo");

     // Créer une requête d'insertion
     string description = "Acheter des courses";
     bool completed = false;
     string query = "INSERT INTO tasks (description, completed) VALUES (?, ?)";

     // Créer un PreparedStatement
     unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));

     // Lier les paramètres
     pstmt->setString(1, description);
     pstmt->setBoolean(2, completed);

     // Exécuter la requête d'insertion
     pstmt->executeUpdate();

     // Confirmer l'insertion
     cout << "Tache inseree avec succes." << endl;

    
     /*
     // Créer une requête de mise à jour (UPDATE)
     int taskId = 9; // ID de la tâche que vous voulez mettre à jour
     bool completed = true; // Mettre à jour le statut à 'true' (terminé)
     string query = "UPDATE tasks SET completed = ? WHERE id = ?";

     // Créer un PreparedStatement pour exécuter la requête UPDATE
     unique_ptr<PreparedStatement> pstmt(conn->prepareStatement(query));

     // Lier les paramètres à la requête
     pstmt->setBoolean(1, completed); // Lier la valeur 'completed' à la première position (?)
     pstmt->setInt(2, taskId);         // Lier l'ID de la tâche à la deuxième position (?)

     // Exécuter la requête de mise à jour
     int rowsAffected = pstmt->executeUpdate(); // Nombre de lignes affectées par la mise à jour

     // Afficher un message de confirmation
     if (rowsAffected > 0) {
         cout << "Tache mise a jour avec succes." << endl;
     }
     else {
         cout << "Aucune tache trouvée avec cet ID ou mise a jour non effectuee." << endl;
     }
     */

    /* // Sélectionner la base de données
    conn->setSchema("todo");

    // Créer une requête DELETE
    int taskId = 1; // ID de la tâche à supprimer
    string query = "DELETE FROM tasks WHERE id = ?";

    // Créer un PreparedStatement pour exécuter la requête DELETE
    unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(query));

    // Lier les paramètres à la requête
    pstmt->setInt(1, taskId); // Lier l'ID de la tâche à la position (?)

    // Exécuter la requête de suppression
    int rowsAffected = pstmt->executeUpdate(); // Nombre de lignes supprimées

    // Afficher un message de confirmation
    if (rowsAffected > 0) {
        cout << "Tache supprimee avec succes." << endl;
    }
    else {
        cout << "Aucune tache trouvee avec cet ID ou mise a jour non effectuee." << endl;
    }
    */
}