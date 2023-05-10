#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int Result(string f, int* bits) {
     int res = 1;
for (int i = 2; i < f.size(); i++) { int tmp = 0;
if (f[i] >= 'A' && f[i] <= 'Z') {

 	tmp = bits[f[i] - 'A']; int j;
for (j = 1; f[i + j] == '\''; j++) tmp = !tmp;

 	res = res && tmp;

 	i += j - 1;

 	}

if (f[i] == '+') {

if (res == 1) 
break;

 	res = 1;

 	}

 	}

return res;

}
 
int main() {

int m, n; cin >> n;
 	m = pow(2, n); string f; cin.ignore();
 	getline(cin, f);

for (int i = 2; i < f.size(); i++) if (f[i] - 'A' >= n) {
cout << "ERROR";

return 0;

 	}

string bars = "++";

 	bars.insert(1, 2 * n + 5, '-'); cout << bars << '\n' << "| ";
for (int i = 0; i < n; i++) cout << (char)('A' + i) << " "; cout << "| F |\n" << bars << '\n';
for (int i = 0; i < m; i++) { int bits[n];
cout << "| ";

for (int j = 0; j < n; j++) {

 	bits[j] = (i >> (n - j - 1)) & 1; cout << bits[j] << " ";
 	}

cout << "| " << Result(f, bits) << " |\n";
 
 	}

cout << bars; return 0;
}
