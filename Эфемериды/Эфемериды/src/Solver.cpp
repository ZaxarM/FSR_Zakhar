#include "Solver.h"
#include "Except.h"
#include "Parcer.h"
#include <iostream>
#include <cmath>
using namespace std;
Solver::Solver(Parcer* p) : parcer(p) {}

Solution Solver::solve() {
    Solution solution;
        double date[DATA_SIZE][DATE_COLUMNS], positionX[DATA_SIZE], positionY[DATA_SIZE], positionZ[DATA_SIZE], velocityX[DATA_SIZE], velocityY[DATA_SIZE], velocityZ[DATA_SIZE];
        string info[9];

        try {
            if (parcer->parse(info, date, positionX, positionY, positionZ, velocityX, velocityY, velocityZ)) {
                double y,m,d,h,mi,s;
                cout<<"The beginning of research:"<<endl;
                cout<<"Year: "<<date[0][0]<<"  "<<"Month: "<<date[0][1]<<"  "<<"Date: "<<date[0][2]<<"  "<<"Hour: "<<date[0][3]<<"  "<<"Minute: "<<date[0][4]<<"  "<<"Second: "<<date[0][5]<<"  "<<endl;
                cout<<"The end of research:"<<endl;
                cout<<"Year: "<<date[DATA_SIZE-1][0]<<"  "<<"Month: "<<date[DATA_SIZE-1][1]<<"  "<<"Date: "<<date[DATA_SIZE-1][2]<<"  "<<"Hour: "<<date[DATA_SIZE-1][3]<<"  "<<"Minute: "<<date[DATA_SIZE-1][4]<<"  "<<"Second: "<<date[DATA_SIZE-1][5]<<"  "<<endl;
                cout<<"Enter the time of the research"<<endl;
                cout<<"Year: ";
                cin>>y;
                cout<<"Month: ";
                cin>>m;
                cout<<"Date: ";
                cin>>d;
                cout<<"Hour: ";
                cin>>h;
                cout<<"Minute: ";
                cin>>mi;
                cout<<"Second: ";
                cin>>s;
                double t=time(date,y,m,d,h,mi,s);
                solution.velX = calculateAverage(velocityX,t);
                solution.velY = calculateAverage(velocityY,t);
                solution.velZ = calculateAverage(velocityZ,t);
                solution.posX = calculateAverage(positionX,t);
                solution.posY = calculateAverage(positionY,t);
                solution.posZ = calculateAverage(positionZ,t);
                solution.velocity = sqrt((solution.velX)*(solution.velX)+(solution.velY)*(solution.velY)+(solution.velZ)*(solution.velZ));
                for(int i = 0; i < 9;i++){
                    solution.inf[i] = info[i];
                }

            } else {
                throw Except(PARSE_ERROR, "Error parsing file");
            }
        } catch (const Except& e) {
            cerr << "Error: " << e.get_err() << " -- ";
            e.print();
            // Обработка ошибок по необходимости
        }
    return solution;
}

    // string* arr(string info[]){
    //     string inf[15];
    //     for(int i = 0; i < 15;i++){
    //         inf[i] = info[i];
    //     }
    //     return inf;
    // }
    double Solver::time(double (*date)[6],double y,double m,double d,double h,double mi,double s){
        double startTime=date[0][0]*365*24*60*60+date[0][1]*30*24*60*60+date[0][2]*24*60*60+date[0][3]*60*60+date[0][4]*60+date[0][5];
        double endTime=date[DATA_SIZE-1][0]*365*24*60*60+date[DATA_SIZE-1][1]*30*24*60*60+date[DATA_SIZE-1][2]*24*60*60+date[DATA_SIZE-1][3]*60*60+date[DATA_SIZE-1][4]*60+date[DATA_SIZE-1][5];
        double partTime=endTime-startTime;
        double totalTime=y*365*24*60*60+m*30*24*60*60+d*24*60*60+h*60*60+mi*60+s;
        return (totalTime-startTime)/partTime;
    }

    double Solver::Lagrange_interpolation(const double vel[],double t[],int n,double time){
        double L, l;
        int i, j;
        L = 0;
        for (i = 0; i < n; ++i)
        {
            l = 1;
            for (j=0;j<n;j++)
                if (i != j)
                    l *= (time - t[j]) / (t[i] - t[j]);
            L += vel[i] * l;
        }
        return L;
    }

    double Solver::calculateAverage(const double A[],double T) {
        double res;
        int i,n=10;
        double t[n];
        for (i=0;i<n;i++)
            t[i]=1.0/DATA_SIZE*i;
        res=Lagrange_interpolation(A,t,n,T);
        return res;
    }
