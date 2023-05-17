#include <bits/stdc++.h>

using namespace std;

map<string, int> my;

int main(){
    int i, d, x, day;
    int tc, sub;
    string s;

    cin >> tc;

	  for(i=1; i<=tc; i++){
        cin >> sub;
        while(sub--){
            cin>> s>> day;
            my[s] = day;
        }
        cin >> d;
        cin >> s;
        printf("Case %d: ", i);
        if(my[s] <= d && my[s] != 0){

            printf("Yesss\n");
        }
        else if(my[s] <= d+5 && my[s] != 0){
            printf("Late\n");
        }
        else{
            printf("Do your own homework!\n");
        }
        my.clear();
	}

	return 0;
}