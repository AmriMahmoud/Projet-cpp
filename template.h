template <typename T>
class Tableau {
private:
    vector<vector<T>> data;

public:
    void ajouterLigne(const vector<T>& ligne) {
        data.push_back(ligne);
    }

    void ajouterItem(size_t ligne, size_t colonne, const T& item) {
        if (ligne < data.size()) {
            if (colonne < data[ligne].size()) {
                data[ligne][colonne] = item;
            } else {
                // Expand the row if needed
                data[ligne].resize(colonne + 1);
                data[ligne][colonne] = item;
            }
        } else {
            // Expand the matrix if ligne is out of range
            data.resize(ligne + 1);
            data[ligne].resize(colonne + 1);
            data[ligne][colonne] = item;
        }
    }

    void afficherTableau() const {
        for (const auto& ligne : data) {
            for (const auto& item : ligne) {
                cout << item << " | ";
            }
            cout << endl;
        }
    }
};
