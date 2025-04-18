#include<bits/stdc++.h>
using namespace std;
class Student
{
private:
    long long  int roll;
    double p1,p2,p3,c1,c2,c3,cal_Cgpa;
public:
    void input()
    {
        long long int  roll_temp;
        double x,y,z;
        cout<<"Enter the Student id: ";
        cin>>roll;
        cout<<endl<<"Enter Course1 point and credit: ";
        cin>>p1>>c1;
        cout<<endl<<"Enter Course2 point and credit: ";
        cin>>p2>>c2;
        cout<<endl<<"Enter Course3 point and credit: ";
        cin>>p3>>c3;
        cout<<endl;
    }
    double calculateCgpa()
    {
        double cgpa;
        cgpa=(p1*c1+p2*c2+p3*c3)/(c1+c2+c3);
        cal_Cgpa=cgpa;
        return cgpa;

    }
    void output()
    {
        cout<<"CGPA of Student ID "<<roll<<" is ";
    }
    int rollCheck(Student *student,long long int roll_xy,long long int number_Student)
    {
        for(int i=0; i<number_Student; i++)
        {
            if(student[i].roll==roll_xy)
            {
                return i;

            }

        }
        return 0;
    }
   int meritPrint(Student *student,long long int roll_x,long long int numberStudent)
    {
        for(int i=0; i<numberStudent; i++)
        {
            if(student[i].roll==roll_x)
            {
                int merit=1;

                for(int j=0; j<numberStudent; j++)
                {
                        if(student[i].calculateCgpa()<student[j].calculateCgpa())
                        {
                         merit++;
                        }


                }
              //  cout<<"merit: "<<merit<<endl;
              return merit;


            }
        }
    }
};

int main()
{
    long long int n,roll;
    cout<<"Please enter the student number: ";
    cin>>n;
    cout<<endl;
    Student ob[n],ob1;
    for(int i=0; i<n; i++)
    {
        ob[i].input();

    }
    cout<<"Enter the Student Id for result: ";
    cin>>roll;
    for(int i=0; i<n; i++)
    {
        int temp;
        temp=ob1.rollCheck(&ob[i],roll,n);
        ob[temp].output();
        cout<<ob[temp].calculateCgpa()<<endl;
        cout<<"Merit position: "<<ob1.meritPrint(&ob[i],roll,n)<<endl;



        break;

    }


    return 0;
}



