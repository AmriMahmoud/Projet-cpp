class DonneeInexistanteException : public exception {
    string message;
    string collection;
    string identifiant;

public:
    DonneeInexistanteException(const string& msg, const string& coll, const string& id)
        : message(msg), collection(coll), identifiant(id) {
        message = "Donnee inexistante dans '" + collection + "' avec identifiant '" +
                  identifiant + "': " + msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    string getCollection() const {
        return collection;
    }

    string getIdentifiant() const {
        return identifiant;
    }
};
