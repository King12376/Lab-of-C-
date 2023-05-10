#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to calculate determinant of a matrix
int Determinant(vector<vector<int>> mat)
{
    if (mat.size() == 1) {
        return mat[0][0];
    } else {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++) {
            // Create submatrix by removing the first row and ith column
            vector<vector<int>> submat;
            for (int j = 1; j < mat.size(); j++) {
                vector<int> row;
                for (int k = 0; k < mat.size(); k++) {
                    if (k != i) {
                        row.push_back(mat[j][k]);
                    }
                }
                submat.push_back(row);
            }
            // Calculate determinant of submatrix and add to sum
            sum += pow(-1, i) * mat[0][i] * Determinant(submat);
        }
        return sum;
    }
}

// Function to calculate cofactor of a matrix element
int Cofactor(vector<vector<int>> mat, int x, int y)
{
    // Create submatrix by removing the xth row and yth column
    vector<vector<int>> submat;
    for (int i = 0; i < mat.size(); i++) {
        if (i != x) {
            vector<int> row;
            for (int j = 0; j < mat.size(); j++) {
                if (j != y) {
                    row.push_back(mat[i][j]);
                }
            }
            submat.push_back(row);
        }
    }
    // Calculate determinant of submatrix as cofactor
    return Determinant(submat);
}

// Function to convert matrix to fractions
string ConvertToFraction(vector<vector<int>> admat, int determinant)
{
    string result = "";
    for (int i = 0; i < admat.size(); i++) {
        for (int j = 0; j < admat.size(); j++) {
            int d = determinant;
            // Reduce fraction to simplest terms
            for (int k = 2; k <= abs(admat[i][j]) && k <= abs(d); k++) {
                if (admat[i][j] % k == 0 && d % k == 0) {
                    admat[i][j] /= k;
                    d /= k;
                    k--;
                }
            }
            // Convert to string and add to result
            if (admat[i][j] != 0) {
                if (admat[i][j] < 0 ^ d < 0) {
                    result += "-";
                }
                if (abs(d) > 1) {
                    result += to_string(abs(admat[i][j])) + "/" + to_string(abs(d));
                } else {
                    result += to_string(abs(admat[i][j]));
                }
            } else {
                result += to_string(abs(admat[i][j]));
            }
            result += " ";
        }
        if (i < admat.size()-1) {
            result += '\n';
        }
    }
    return result;
}

// Function to transpose a matrix
vector<vector<int>> Transpose(vector<vector<int>> mat)
{
    vector<vector<int>> tmat;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
          row.push_back(mat[j][i]);
          }

 	  tmat.push_back(row);

 	}

return tmat;
}


string Adjoint(vector<vector<int>> mat) {
    vector<vector<int>> admat; int d = Determinant(mat);
      for (int i = 0; i < mat.size(); i++) {
      vector<int> row;
      for(int j = 0; j < mat.size(); j++)
 	{

int a = pow(-1, i + j) * Cofactor(mat, i, j);
 	row.push_back(a);
 	}
 	admat.push_back(row);
	}
 	admat = Transpose(admat);

return ConvertToFraction(admat, d);

}

int main()  {

vector<vector<int>> mat, tmat; int m, n;
cin >> m >> n; if(m < 0 || n < 0) {
return 0;
}

for (int i = 0; i < m; i++) {

vector<int> row;

for (int j = 0; j < n; j++) {
    int a;
    cin >> a;
    row.push_back(a);
}

 	mat.push_back(row);

 	}
tmat = Transpose(mat);
 
for (int i = 0; i < tmat.size(); i++)   {
    for (int j = 0; j < tmat[i].size(); j++) {
    cout << tmat[i][j] << " ";
	}
    cout << '\n';
 	}


if(m != n)  {
    cout << '\n' << "Cannot produce an inverse matrix."; return 0;
 	}

    if(Determinant(mat) == 0) {
    cout << '\n' << "Cannot produce an inverse matrix."; return 0;
 	}

    cout << '\n' << Adjoint(mat);

return 0;

}
