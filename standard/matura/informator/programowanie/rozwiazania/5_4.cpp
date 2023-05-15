#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <map>
using namespace std;

int main() {

	const int N = 10;
	int A[N] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	for(int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				int x = A[j];
				A[j] = A[i];
				A[i] = x;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << A[i] << " ";

	return 0;
}