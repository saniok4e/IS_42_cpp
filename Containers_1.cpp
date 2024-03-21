#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
using namespace std;

void disp(const vector<double>& arr) {

    for (double x : arr) {
        cout << fixed << setprecision(3) << x << " ";
    }
    cout << endl;

}

void add_element(vector<double>& arr, double& sum, double& avg) {

    sum = accumulate(arr.begin(), arr.end(), 0.0);
    avg = sum / arr.size();
    arr.push_back(sum);
    arr.push_back(avg);

}

void rabotaSVektorom(vector<double>& arr, int n, double& avg) {

    int flag = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            flag++;
            if (flag == 3) {
                arr[i] = avg;
                flag = 0;
            }
        }
    }

}

int menu(vector<double>& arr, int n, double& sum, double& avg) {

    int choice;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1:
            double elem;
            cin >> elem;
            arr.push_back(elem);
            cout << "+: " << arr.size() << endl;
            disp(arr);
            add_element(arr, sum, avg);
            disp(arr);
            rabotaSVektorom(arr, n, avg);
            disp(arr);
            break;
        case 2:
            if (!arr.empty()) {
                arr.pop_back();
                cout << "-: " << arr.size() << endl;
                disp(arr);
                add_element(arr, sum, avg);
                disp(arr);
                rabotaSVektorom(arr, n, avg);
                disp(arr);
            }
            else {
                cout << "Массив пуст, удаление невозможно." << endl;
            }
            break;
        default:
            cout << "Неверный выбор действия. Попробуйте еще раз." << endl;
        }
    }

}

void main() {

    setlocale(LC_ALL, "Russian");
    double  sum = 0;
    double avg = 0;
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl << n << endl;

    disp(arr);
    add_element(arr, sum, avg);
    disp(arr);
    rabotaSVektorom(arr, n, avg);
    disp(arr);
    menu(arr, n, sum, avg);

}