#include <iostream>
#include <vector>
#include <cmath>

const int N = 4;

double det(std::vector <std::vector <double> > arr) {
  if(arr.size() == 2) return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];

  double sum = 0;

  for(int i = 0; i < arr.size(); i++) {
    std::vector <std::vector <double> > temp;
    for(int j = 0; j < arr.size(); j++) {
      if(i == j) continue;
      std::vector <double> row;
      for(int k = 1; k < arr.size(); k++) {
        row.push_back(arr[j][k]);
      }
      temp.push_back(row);
    }
    sum += pow(-1.0, 2 + i) * arr[i][0] * det(temp);
  }

  return sum;
}

int main() {
  std::vector <std::vector <double> > arr { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }};
  std::cout << det(arr);
}
