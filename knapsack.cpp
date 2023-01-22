#include <iostream>
using namespace std;

int p[100];
int w[100];

void GreedyKnapsack(int m, int n){
    float x[n];

    for(int i = 0; i < n; i++){
        x[i] = 0.0;
    }

    int U = m, i = 0;

    for(i = 0; i < n; i++){
        if(w[i] > U){
            break;
        }
        x[i] = 1.0;
        U = U - w[i];
    }

    if(i <= n){
        x[i] = U / (float) w[i];
    }

    for(int i = 0; i < n; i++){
        cout << "ITEM" << i+1 << ": " << x[i] << endl;
    }
    cout << endl;

    float total_profit = 0.0;
    for(int i = 0; i < n; i++){
        total_profit += p[i] * x[i];
    }

    cout << "Total Profit: " << total_profit << endl;
}

int main(){
    int n, m;

    cout << "Enter values for n and m: ";
    cin >> n >> m;

    cout << "Enter price: ";
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    cout << "Enter weight: ";
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    GreedyKnapsack(m, n);

}
