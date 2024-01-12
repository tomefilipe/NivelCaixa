#include <Firebase_ESP_Client.h>

class Tank
{
public:
    Tank(std::string tankId, int pin, int size);
    void read();
    bool setFirebaseSettings(FirebaseData *fbdo, FirebaseAuth *auth, FirebaseConfig *config, std::string projectId);
    void calibrate();
    bool setFirestoreLevel();
    bool updateFirebase();
    bool updateHistory();

private:
    std::string tankId;
    int pin;
    int size;
    int level;
    bool leaking;
    int calibration;

    std::string _PROJECT_ID;
    FirebaseData *_fbdo;
    FirebaseAuth *_auth;
    FirebaseConfig *_config;
};