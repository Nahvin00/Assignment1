#include <iostream>
#include <fstream>

using namespace std;
int total(char);
double average(int,int);
int main()
{
    int total_Q1=0,total_Q2=0,total_Q3=0,total_Q4=0,total_Q5=0;
    double avg_Q1=0,avg_Q2=0,avg_Q3=0,avg_Q4=0,avg_Q5=0,ins_avg;
    ofstream outputFile("studentMarks.txt",ios::out);
    if(!outputFile){
        cerr << "File could not be opened \n";
        exit(1);
    }
    int res;
    cout<<"Getting started with Evaluation process."<<endl<<endl
        <<"Enter number of respondent: ";
    cin>>res;
    int ins[res], cour[res];
    char Q1[res], Q2[res], Q3[res], Q4[res], Q5[res];
    cout<<"Enter Instructor number followed by course code, and answer for five questions: "<<endl;
    for(int i=0;i<res;i++){
        cout<<"Data set: "<<(i+1)<<endl;
        cin>>ins[i]>>cour[i]>>Q1[i]>>Q2[i]>>Q3[i]>>Q4[i]>>Q5[i];
        while((Q1[i]!='A'||'E'||'G'||'U'||'P') && (Q2[i]!='A'||'E'||'G'||'U'||'P') && (Q3[i]!='A'||'E'||'G'||'U'||'P') && (Q4[i]!='A'||'E'||'G'||'U'||'P') && (Q5[i]!='A'||'E'||'G'||'U'||'P')){
           cout<<"Invalid Characters! Only  re-enter either 'A', 'E', 'G', 'U', or 'p' for five questions: "<<endl;
           cin>>Q1[i]>>Q2[i]>>Q3[i]>>Q4[i]>>Q5[i];
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
        outputFile<<ins[i]<<"   "<<cour[i]<<" "<<Q1[i]<<" "<<Q2[i]<<" "<<Q3[i]<<" "<<Q4[i]<<" "<<Q5[i]<<endl;
        
        total_Q1+=total(Q1[i]);
        total_Q2+=total(Q2[i]);
        total_Q3+=total(Q3[i]);
        total_Q4+=total(Q4[i]);
        total_Q5+=total(Q5[i]);
        }
    avg_Q1=average(total_Q1,res); 
    avg_Q2=average(total_Q2,res);
    avg_Q3=average(total_Q3,res);
    avg_Q4=average(total_Q4,res);
    avg_Q5=average(total_Q5,res);
    ins_avg=(0.15*avg_Q1)+(0.23*avg_Q2)+(0.08*avg_Q3)+(0.32*avg_Q4)+(0.22*avg_Q5);
    
    
    
return 0;
}
    
int total(char x){
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

double average(int x, int y){
    int z=x/y;
    return z;
    
}    
