#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    cout << "First, enter the number of test cases. " << endl;
    cout << "Then, for each test case, enter the number of equations. " << endl;
    cout << "Then, for each equation, enter the number of coefficients. " << endl;
    cout << "Then, for each coefficient, enter the value. " << endl;
    cout << "The program will output YES if the solution exists, and NO if it does not." << endl;
    cout << "If the solution exists, the program will output the solution." << endl;
    cout << "Please note that the number of coefficients in an equation must be at least 1 more than the number of equations in the test case. " << endl;

    int t;
    cin >> t;

    while (t--) {
        int no_eqn;
        cin >> no_eqn;

        vector<vector<double>> matrix;
        bool solvable = true;

        for (int i = 0; i < no_eqn; i++) {
            int no_coeff;
            cin >> no_coeff;

            if (no_coeff < no_eqn + 1) {
                solvable = false;
                break;
            }

            vector<double> eqn;
            for (int j = 0; j < no_coeff; j++) {
                double coeff;
                cin >> coeff;
                eqn.push_back(coeff);
            }
            matrix.push_back(eqn);

            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][i] == 0) {
                    int p = -1;
                    for (int k = i + 1; k < matrix.size(); k++) {
                        if (matrix[k][i] != 0) {
                            p = k;
                            break;
                        }
                    }
                    if (p == -1) {
                        solvable = false;
                        break; 
                    }
                    swap(matrix[i], matrix[p]);
                }

                double d = matrix[i][i];
                for (int j = i; j <= matrix[i].size(); j++) {
                    matrix[i][j] /= d;
                }

                for (int j = 0; j < matrix.size(); j++) {
                    if (j != i) {
                        double f = matrix[j][i];
                        for (int k = i; k <= matrix[j].size(); k++) {
                            matrix[j][k] -= f * matrix[i][k];
                        }
                    }
                }
            }
        }

        if (!solvable || matrix.back()[matrix.back().size() - 2] == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < matrix.size(); i++) {
                cout << fixed << setprecision(2) << matrix[i].back() << " ";
            }
            cout << endl;
        }
    }

    return 0;
}