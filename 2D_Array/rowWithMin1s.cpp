#include <iostream>
#include <vector>

using namespace std;
// ? min number of 1s means maximum number of zeros row find
int minRow(int n, int m, vector<vector<int>> A) {
        int max=0;
        int index=0; 
        for(int i=0;i<n; i++){
            int count=0;
            for(int j=0; j<m; j++){
                if(A[i][j] == 0){
                    count++;
                }
            }
            if(count>max){
                max = count;
                index = i;
            }
        }
        return index+1; // zero base indexing
    }

int main() {
    // Example usage:
    vector<vector<int>> A = {{1, 0, 0, 1},
                             {0, 0, 1, 0},
                             {0, 1, 0, 0},
                             {0, 0, 0, 1}};
    int n = 4; // Number of rows
    int m = 4; // Number of columns

    int result = minRow(n, m, A);
    if (result != -1) {
        cout << "Row with the minimum number of 0s is: " << result << endl;
    } else {
        cout << "Matrix is empty or all rows have the same number of zeros." << endl;
    }

    return 0;
}
