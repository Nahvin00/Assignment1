
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
bool test(char,char,char,char,char);
double total(char);
double average(double,double);
void display(int,int,int,double,double,double,double,double,double);
int main()
{
    double total_Q1=0,total_Q2=0,total_Q3=0,total_Q4=0,total_Q5=0;
    double avg_Q1=0,avg_Q2=0,avg_Q3=0,avg_Q4=0,avg_Q5=0,ins_avg;
    ofstream outputFile("DataOutput.txt",ios::out);
    if(!outputFile){
        cerr << "File could not be opened \n";
        exit(1);
    }
    int res;
    double size=0;
    cout<<"Getting started with Evaluation process."<<endl<<endl
        <<"Enter number of respondent: ";
    cin>>res;
    int ins[res], cour[res];
    char Q1[res], Q2[res], Q3[res], Q4[res], Q5[res];
    cout<<"Enter Instructor number followed by course code, and answer for five questions: "<<endl;
    for(int i=0;i<res;i++){
        cout<<"Data set: "<<(i+1)<<endl;
        cin>>ins[i]>>cour[i]>>Q1[i]>>Q2[i]>>Q3[i]>>Q4[i]>>Q5[i];
        while(test(Q1[i],Q2[i],Q3[i],Q4[i],Q5[i])!=true){
           cout<<"Invalid Characters! Only  re-enter either 'A', 'E', 'G', 'U', or 'p' for five questions: "<<endl;
           cin>>Q1[i]>>Q2[i]>>Q3[i]>>Q4[i]>>Q5[i];
           test(Q1[i],Q2[i],Q3[i],Q4[i],Q5[i]);
        }
        if(i>0){
            while(ins[i]!=ins[i-1]){
                cout<<"Instructor Number doesn't match!"<<endl<<"Please re-enter the Instructor Number: "<<endl;
                cin>>ins[i];
            }
            while(cour[i]!=cour[i-1]){
                cout<<"Course Code doesn't match!"<<endl<<"Please re-enter the Course Code: "<<endl;
                cin>>cour[i];
            }
        }
        outputFile<<ins[i]<<"    "<<cour[i]<<"  "<<Q1[i]<<" "<<Q2[i]<<" "<<Q3[i]<<" "<<Q4[i]<<" "<<Q5[i]<<endl;
        
        total_Q1+=total(Q1[i]);
        total_Q2+=total(Q2[i]);
        total_Q3+=total(Q3[i]);
        total_Q4+=total(Q4[i]);
        total_Q5+=total(Q5[i]);
        size++;
        }
    avg_Q1=average(total_Q1,size); 
    avg_Q2=average(total_Q2,size);
    avg_Q3=average(total_Q3,size);
    avg_Q4=average(total_Q4,size);
    avg_Q5=average(total_Q5,size);
    ins_avg=(0.15*avg_Q1)+(0.23*avg_Q2)+(0.08*avg_Q3)+(0.32*avg_Q4)+(0.22*avg_Q5);
    display(ins[0],cour[0],res,avg_Q1,avg_Q2,avg_Q3,avg_Q4,avg_Q5,ins_avg);
    
    
    
return 0;
}
bool test(char a,char b,char c,char d,char e){
    bool x;
    if((a=='A'||a=='E'||a=='G'||a=='U'||a=='P')&&(b=='A'||b=='E'||b=='G'||b=='U'||b=='P')&&(c=='A'||c=='E'||c=='G'||c=='U'||c=='P')&&(d=='A'||d=='E'||d=='G'||d=='U'||d=='P')&&(e=='A'||e=='E'||e=='G'||e=='U'||e=='P')){
        x=true;
        
    }
    else{
        x=false;
    }
    return x;
}
    
double total(char x){
    int z;
        switch (x){
            case 'E':
                z=4;
                break;
            case 'G':
                z=3;
                break;
            case 'A':
                z=2;
                break;
            case 'P':
                z=1;
                break;
            case 'U':
                z=0;
                break;
        }
    return z;
}

double average(double x, double y){
    double z=x/y;
    return z;
}

void display (int a, int b, int c, double d, double e, double f, double g, double h, double i) {
  std::cout << std::fixed << std::setprecision(2) <<endl<<endl
        << "COURSE/INSTRUCTOR EVALUATION SUMMARY" << endl << endl << endl
        <<"INSTRUCTOR NUMBER: " << a << endl 
        <<"COURSE NUMBER: " << b << endl
        <<"NUMBER OF PARTICIPANTS: " << c << endl 
        <<"AVERAGES:" << endl 
        <<"QUESTION 1\t" << d << endl 
        <<"QUESTION 2\t" << e << endl 
        <<"QUESTION 3\t" << f << endl 
        <<"QUESTION 4\t" << g << endl 
        <<"QUESTION 5\t" << h << endl 
        <<"INSTRUCTOR AVERAGE: " << i << endl <<endl << endl 
        <<"END OF PROGRAM.";
    
}
