#include<iostream>
#include<fstream>
using namespace std;
struct diena{
	int pirmadienis;
	int antradienis;
	int treciadienis;
	
	
};
int main() {
int n,valandusk=0,virs=0,zemiau=0,totalval=0,totalvirs=0,totalzemiau=0;
diena A[50];
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n;
for(int i =0;i<n;i++){
	valandusk=0;
	virs=0;
	zemiau=0;
	fd>>A[i].pirmadienis>>A[i].antradienis>>A[i].treciadienis;
		if(A[i].pirmadienis>5) virs++;
	else if (A[i].pirmadienis<5) zemiau++;
	valandusk+=A[i].pirmadienis;
		if(A[i].antradienis>6) virs++;
	else if (A[i].antradienis<6) zemiau++;
	valandusk+=A[i].antradienis;
		if(A[i].treciadienis>4) virs++;
	else if (A[i].treciadienis<4) zemiau++;
	valandusk+=A[i].treciadienis;
	fr<<valandusk<<" "<<virs<<" "<<zemiau<<endl;
	totalval+=valandusk;
	totalvirs+=virs;
	totalzemiau+=zemiau;
}
fr<<totalval<<" "<<totalvirs<<" "<<totalzemiau;
fd.close();
fr.close();

return 0;
}

