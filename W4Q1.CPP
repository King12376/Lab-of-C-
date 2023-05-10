#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
public:
    void scan() {
        int n;
        cin >> n;
        data.resize(n);
        for (int i = 0; i < n; i++) {
            data[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }
    }
    void print() {
        if (data.empty()) {
            cout << "No element in matrix can be printed." << endl;
            return;
        }
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void rotate_right() {
        if (data.empty()) {
            cout << "No element in matrix can be rotated." << endl;
            return;
        }
        int n = data.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = data[n - j - 1][i];
            }
        }
        data = temp;
    }
    void rotate_left() {
        if (data.empty()) {
            cout << "No element in matrix can be rotated." << endl;
            return;
        }
        int n = data.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = data[j][n - i - 1];
            }
        }
        data = temp;
    }
};

int main() {
    Matrix mat;
    string instruction;
    while (cin >> instruction) {
        if (instruction == "scan") {
            mat.scan();
        } else if (instruction == "print") {
            mat.print();
        } else if (instruction == "rotate") {
            string direction;
            cin >> direction;
            if (direction == "right") {
                mat.rotate_right();
            } else if (direction == "left") {
                mat.rotate_left();
            } else {
                cout << "unknown" << endl;
            }
        } else if (instruction == "stop") {
            return 0;
        } else {
            cout << "unknown" << endl;
        }
    }
    return 0;
}
