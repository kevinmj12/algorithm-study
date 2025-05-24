#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> vecPlus, vecMinus;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0) {
			vecPlus.push_back(a);
		}
		else {
			vecMinus.push_back(a);
		}
	}


	sort(vecPlus.begin(), vecPlus.end(), greater<>());
	sort(vecMinus.begin(), vecMinus.end());


	int answer = 0;

	for (int i = 0; i < vecPlus.size(); i++) {
		if (i + 1 < vecPlus.size()) {
			if (vecPlus[i] * vecPlus[i + 1] > vecPlus[i] + vecPlus[i + 1]) {
				answer += vecPlus[i] * vecPlus[i + 1];
				i++;
			}
			else {
				answer += vecPlus[i];
			}
		}
		else {
			answer += vecPlus[i];
		}
	}
	for (int i = 0; i < vecMinus.size(); i++) {
		if (i + 1 < vecMinus.size()) {
			if (vecMinus[i] * vecMinus[i + 1] > vecMinus[i] + vecMinus[i + 1]) {
				answer += vecMinus[i] * vecMinus[i + 1];
				i++;
			}
			else {
				answer += vecMinus[i];
			}
		}
		else {
			answer += vecMinus[i];
		}
	}

	cout << answer;
}