class FichierException : public exception {
    string message;
    string nomFichier;
    string operation;

public:
    FichierException(const string& msg, const string& fichier, const string& op)
        : message(msg), nomFichier(fichier), operation(op) {
        message = "Erreur " + operation + " sur le fichier '" + nomFichier + "': " + msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    string getFichier() const {
        return nomFichier;
    }

    string getOperation() const {
        return operation;
    }
};
