#include <bits/stdc++.h>
#define double long double
using namespace std;
double w[1010][1010] = {0,};
double A[1010][1010] = {0,};
double R[1010][1010] = {0,};
int Ans[1010][1010] = {0,};
//double T = 0.1; //소수점 16자리까지
double newT = 10000;
//double T = 0.005;
int n = 0;
int bp() {
   for(int i = 0; i<n; i++) {
      for(int j = 0; j<n; j++) {
         A[i][j] = R[i][j] = 0;
      }
   }
   int convergecount = 0;
   int iter = 0;
   while(1) {
      iter++;
      for(int k = 0; k<n; k++) {
         double max1 = 0, max2 = 0; int id = 0;
         if(R[k][0]+w[k][0]/2>R[k][1]+w[k][1]/2) {
            max1 = R[k][0]+w[k][0]/2;
            max2 = R[k][1]+w[k][1]/2;
            id = 0;
         }
         else {
            max2 = R[k][1]+w[k][1]/2;
            max1 = R[k][0]+w[k][0]/2;
            id = 1;
         }
         for(int b = 0; b<n; b++) {
            if(max1<R[k][b]+w[k][b]/2) {
               max2 = max1;
               max1 = R[k][b]+w[k][b]/2;
               id = b;
            }
            else if(max2<R[k][b]+w[k][b]/2){
               max2 = R[k][b]+w[k][b]/2;
            }
         }
         double sum1 = 0, sum2 = 0;
         for(int b = 0; b<n; b++) {
            sum1 += exp((R[k][b]+w[k][b]/2-max1)*newT);
            if(b!=id) sum2 += exp((R[k][b]+w[k][b]/2-max2)*newT);
         }
         for(int a = 0; a<n; a++) {
            if(id==a) A[k][a] = w[k][a]/2-max2-log(sum2)/newT;
            else A[k][a] = w[k][a]/2-max1-log(sum1-exp((R[k][a]+w[k][a]/2-max1)*newT))/newT;
         }
      }
      for(int a = 0; a<n; a++) {
         double max1 = 0, max2 = 0; int id = 0;
         if(A[0][a]+w[0][a]/2>A[1][a]+w[1][a]/2) {
            max1 = A[0][a]+w[0][a]/2;
            max2 = A[1][a]+w[1][a]/2;
            id = 0;
         }
         else {
            max2 = A[1][a]+w[1][a]/2;
            max1 = A[0][a]+w[0][a]/2;
            id = 1;
         }
         for(int j = 0; j<n; j++) {
            if(max1<A[j][a]+w[j][a]/2) {
               max2 = max1;
               max1 = A[j][a]+w[j][a]/2;
               id = j;
            }
            else if(max2<A[j][a]+w[j][a]/2){
               max2 = A[j][a]+w[j][a]/2;
            }
         }
         double sum1 = 0, sum2 = 0;
         for(int j = 0; j<n; j++) {
            sum1 += exp((A[j][a]+w[j][a]/2-max1)*newT);
            if(j!=id) sum2 += exp((A[j][a]+w[j][a]/2-max2)*newT);
         }
         for(int k = 0; k<n; k++) {
            if(id==k) R[k][a] = w[k][a]/2-max2-log(sum2)/newT;
            else R[k][a] = w[k][a]/2-max1-log(sum1-exp((A[k][a]+w[k][a]/2-max1)*newT))/newT;
         }
      }
      bool doesconverge = true;
      for(int k = 0; k<n; k++) {
         for(int a = 0; a<n; a++) {
            if(R[k][a]+A[k][a]>0) {
               if(Ans[k][a]!=1) doesconverge=false;
               Ans[k][a] = 1;
            }
            else {
               if(Ans[k][a]!=0) doesconverge=false;
               Ans[k][a] = 0;
            }
         }
      }
      if(doesconverge) {
         convergecount++;
      }
      else {
         convergecount = 0;
      }
      if(convergecount==10) {
         break;
      }
   }
//   int cnt = 0;
//   for(int k = 0; k<n; k++) {
//      printf("%2d: ", k+1);
//      for(int a = 0; a<n; a++) {
//         cout << fixed << setprecision(3) << R[k][a]+A[k][a] << ' ';
//         if(R[k][a]+A[k][a]>0) {
//            cnt++;
//            Ans[k][a] = 1;
//         }
//         else {
//            Ans[k][a] = 0;
//         }
//      }
//      printf("\n");
//   }
//   printf("\n");
   return iter;
}

int main() {
    clock_t st = clock();
    ofstream outFile("convergenceresult_200.txt");
    for(int tc = 1; tc <= 100; tc ++) {
        string s = "ising_tc_200_";
        int t = tc;
        string s2="";
        while(t) {
            s2 = (char)('0'+t%10) + s2;
            t /= 10;
        }
        s += s2;
        s += ".txt";
        cout << s << '\n';
        ifstream myFile(s);
        myFile >> n;
        for(int i = 0;i <n;i++) {
            for(int j = 0; j <n;j++) {
                myFile >> w[i][j];
            }
        }
        myFile.close();
        outFile << "Start " << tc << '\n';
        for(int i= 1000; i <= 100000; i += 1000) {
            newT= i;
            int c = bp();
            outFile << c << '\n';
            if(i%10000==0) {
                cout << (int)((double)i/1000)<<'%' << '\n';
                cout << c << '\n';
            }

        }
    }
   clock_t en = clock();
   outFile << st << ' ' << en << '\n';
   outFile << en - st << "ms\n";
   cout << en - st << "ms\n";
   outFile.close();
}