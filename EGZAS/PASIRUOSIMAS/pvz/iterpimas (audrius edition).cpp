#include<iostream>
#include<fstream>
using namespace std;

void sort(int A[], int n){
    bool sorted = false, flag = false;
    while (!sorted)
    {
        flag = false;
        for(int i = 1; i < n; i ++){
            if(A[i] < A[i-1]){
                int temp1 = A[i];
                // int temp2 = B[i];
                A[i] = A[i-1];
                A[i-1] = temp1;
                flag = true;
            }
        }
        if(!flag)
            sorted = true;
    }
}

void insert(int A[], int &size, int index, int value){
    for(int i = size; i >= index; i--){
        A[i+1] = A[i]; 
    }
    A[index+1] = value;
    size++;
}

//jei sk teigiamas, iterpti x
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n, x, SK[100], TEMPARR[100];
    fd >> n >> x;
    for(int i = 0; i < n; i++){
        fd >> SK[i];
    }
    // for(int i = 0; i < n; i++){
    //     TEMPARR[i] = SK[i];
    // }
    for(int i = 0; i < n; i++)
        cout << SK[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++){
        if(SK[i] > 0){
            insert(SK, n, i, x);
            i++;
        }
    }    
    sort(SK, n);
    for(int i = 0; i < n; i++)
        cout << SK[i] << " ";
    fd.close();
    fr.close();
}