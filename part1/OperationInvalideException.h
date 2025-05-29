class OperationInvalideException : public exception {
    string message;
    string operation;
    double valeur;

public:
    OperationInvalideException(const string& msg, const string& op, double val)
        : message(msg), operation(op), valeur(val) {
        message = "Operation invalide '" + operation + "' avec valeur " +
                  to_string(valeur) + ": " + msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    string getOperation() const {
        return operation;
    }

    double getValeur() const {
        return valeur;
    }
};
