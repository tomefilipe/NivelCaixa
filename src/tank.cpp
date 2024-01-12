#include "tank.hpp"
#include "utils.cpp"

Tank::Tank(std::string tankId, int pin, int size)
{
    this->tankId = tankId;
    this->pin = pin;
    this->size = size;
    this->level = 0;
    this->leaking = false;

    // Chamar função de calibração
    // Chamar função de leitura
};

void Tank::calibrate(){
    // Calibrar sensor
};

bool Tank::setFirebaseSettings(FirebaseData *fbdo, FirebaseAuth *auth, FirebaseConfig *config, std::string projectId)
{
    _fbdo = fbdo;
    _auth = auth;
    _config = config;
    _PROJECT_ID = projectId;
};

void Tank::read(){
    // Ler sensor
};

bool Tank::updateFirebase()
{
    FirebaseJson content;
    content.set("fields/currentLevel/doubleValue", level);
    content.set("fields/leaking/booleanValue", leaking);
    content.set("fields/updatedAt/timestampValue", timeToTimestamp(time(nullptr)));

    std::string path = "Tanks/" + tankId;

    while (!Firebase.ready())
        ;

    if (Firebase.Firestore.patchDocument(_fbdo, _PROJECT_ID, "", path, content.raw(), "currentLevel,leaking,updatedAt"))
    {
        return true;
    }
    else
    {
        Serial.printf(_fbdo->errorReason().c_str());
        return false;
    };
};

bool Tank::updateHistory()
{
    FirebaseJson content;
    content.set("fields/level/doubleValue", level);
    content.set("fields/leaking/booleanValue", leaking);
    content.set("fields/time/timestampValue", timeToTimestamp(time(nullptr)));

    std::string path = "Tanks/" + tankId + "/History";

    while (!Firebase.ready())
        ;

    if (Firebase.Firestore.createDocument(_fbdo, _PROJECT_ID, "", path, content.raw()))
    {
        return true;
    }
    else
    {
        Serial.printf(_fbdo->errorReason().c_str());
        return false;
    };
};