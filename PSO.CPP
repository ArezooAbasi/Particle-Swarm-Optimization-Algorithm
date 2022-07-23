#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
const double pi = 3.141592653589793238463;
double ** war;
int sizeofwar = 21;
//+10;



int main(){
	double r1 = 0;
	double r2 = 0;
	double result = 0;
	double gbest = -100;
	double pbest = 0;
	int gbesti = 0;
	int gbestj = 0;
	int pbesti = 0;
	int pbestj = 0;

	srand(time(NULL));
	int pb1 = rand() % 21;
	int pb2 = rand() % 21;
	int xk1 = rand() % 21;
	int xk2 = rand() % 21;
	int rannd1 = 1;
	int rannd2 = 1;


	int c1 = 1;
	int c2 = 1;
	//	double war[21][21];

	war = new double*[sizeofwar];
	for (int i = 0; i <= sizeofwar; i++) {
		war[i] = new double[sizeofwar];
		for (int j = 0; j <= sizeofwar; j++) {
			war[i][j] = 0;
		}
	}

	for (double x = -10; x <= 10; x++){
		for (double y = -10; y <= 10; y++){
			r1 = sin(x)*sin(y);
			r2 = exp(abs(100 - sqrt(pow(x, 2) + pow(y, 2)) / pi));
			result = (-0.0001)* pow(((abs(r1*r2) + 1)), 0.1);
			//	cout << "result  is " << result << endl;
			int h1 = x + 10;
			int h2 = y + 10;
			war[h1][h2] = result;
			cout << war[h1][h2] << endl;
		}
	}

	// find gbest
	for (int i = 0; i < sizeofwar; i++) {
		for (int j = 0; j < sizeofwar; j++) {
			if (war[i][j] > gbest){
				gbest = war[i][j];
				gbesti = i; // tabdil mishe az -10 ta 10
				gbestj = j;
	//			cout << "gbest is" << gbest << endl;
	//			cout << "gbesti is" << gbesti << endl;
	//			cout << "gbestj is" << gbestj << endl;
			}
		}
	}
	//-------------------------------------------------------------------
	//fing pbest
	pbest = war[pb1][pb2];
	pbesti = pb1;
	pbestj = pb2;
//	cout << "pbest is" << pbest << endl;
//	cout << "pbesti is" << pbesti << endl;
//	cout << "pbestj is" << pbestj << endl;
	int co = 1;
	int ggxk1 = 0;
	int ggxk2 = 0;
	int ppxk1 = 0;
	int ppxk2 = 0;
	int ress1 = 0;
	int ress2 = 0;
	int vv1 = 1;
	int vv2 = 1;
	int ww1 = 5;
	int ww2 = -5;

	while (co != 0){

		//ghesmate cognitive
		if ((pbesti >= xk1) && (pbestj >= xk2) && (gbesti >= xk1) && (gbestj >= xk2)){
			ppxk1 = pbesti - xk1;
			ppxk2 = pbestj - xk2;
			ggxk1 = gbesti - xk1;
			ggxk2 = gbestj - xk2;

			ppxk1 = ppxk1 * rannd1 * c1;
			ppxk2 = ppxk2 * rannd2 * c1;
			ggxk1 = ggxk1 * rannd1 * c2;
			ggxk2 = ggxk2 * rannd2 * c2;

		//	cout << "ppxk1 va ppxk2	" << ppxk1 << ppxk2 << endl;
		//	cout << "ggxk1 va ggxk2	" << ggxk1 << ggxk2 << endl;
		}
		else{
			vv1 = vv1 * ww1;
			vv1 = vv2 * ww2;

			if (((xk1 + vv1) < 22) && ((xk1 + vv1) >= 0) && ((xk2 + vv2) < 22) && ((xk2 + vv2) >= 0)){
				xk1 = xk1 + vv1;
				xk2 = xk2 + vv1;
			}
			else{
				xk1 = rand() % 21;
				xk2 = rand() % 21;
			}
		}

		ress1 = ggxk1 + ppxk1;
		ress2 = ggxk2 + ppxk2;

	//	cout << "ress1 and ress2 " << ress1 << ress2 << endl;

		xk1 = ress1;
		xk2 = ress2;


		int bb = 10;
		if ((war[gbesti][gbestj] > war[xk1][xk2]) && (bb != 0)){
		//	cout << "Yes" << endl;
			cout << "gbesti nahaee	" << gbesti - 10 << endl;
			cout << "gbestj nahaee	" << gbestj - 10 << endl;
			cout << "meghdare nahaee gbest " << war[gbesti][gbestj] << endl;
			cout << "pbesti nahaee	" << pbesti - 10 << endl;
			cout << "pbestj nahaee	" << pbestj - 10 << endl;
			cout << "meghdare nahaee pbest " << war[pbesti][pbestj] << endl;

			cout << "meghdari ke dar nahayat residim  " << war[xk1][xk2] << endl;
			cout << "xi nahaee	" << xk1 - 10 << endl;
			cout << "yj nahaee	" << xk2 - 10 << endl;


			exit(1);
		}
		else{

			vv1 = vv1 * ww1;
			vv1 = vv2 * ww2;

			if (((xk1 + vv1) < 22) && ((xk1 + vv1) >= 0) && ((xk2 + vv2) < 22) && ((xk2 + vv2) >= 0)){
				xk1 = xk1 + vv1;
				xk2 = xk2 + vv1;
			}
			else{
				xk1 = rand() % 21;
				xk2 = rand() % 21;
			}
		}

	}



	return 0;
}
