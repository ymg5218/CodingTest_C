// 11664

#include <iostream>
#include <cmath>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

struct vector {
	double x;
	double y;
	double z;
};

double getLength(vector X) {
	return sqrt(X.x * X.x + X.y * X.y + X.z * X.z);
}

double getDistance(vector X, vector Y) {
	double x = Y.x - X.x;
	double y = Y.y - X.y;
	double z = Y.z - X.z;
	vector temp = { x, y, z };
	return getLength(temp);
}

double getDot(vector X, vector Y) {
	return X.x * Y.x + X.y * Y.y + X.z * Y.z;
}

double solution(vector A, vector B, vector C) {
	vector line = { B.x - A.x, B.y - A.y, B.z - A.z };
	double lengthOfLine = getLength(line);

	if (lengthOfLine == 0)
		return getDistance(A, C);

	double projection = getDot({ C.x - A.x, C.y - A.y, C.z - A.z }, { B.x - A.x, B.y - A.y, B.z - A.z }) / lengthOfLine;

	if (projection <= 0) return getDistance(A, C);
	else if (projection >= lengthOfLine) return getDistance(B, C);
	else {
		vector projectionVector = {
			A.x + line.x * projection / lengthOfLine,
			A.y + line.y * projection / lengthOfLine,
			A.z + line.z * projection / lengthOfLine
		};
		
		return getDistance(projectionVector, C);
	}
}

int main() {
	FASTIO;
	vector A, B, C;
	cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
	cout << fixed;
	cout.precision(7);
	cout << solution(A, B, C) << endl;
}