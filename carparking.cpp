#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class cars
{
protected:
    char carno[20],name[20];
    unsigned long pno;
    int count=0;
    static int track;
public:
    void getdata()
    {
        cout<<"Enter name of owner  :- ";
        cin>>name;
       // cin.getline(name,20);
        cout<<"Enter phone number :- ";
        cin>>pno;
        cout<<"Enter car number :- ";
        cin>>carno;
    }
    void display()
    {
        cout<<"Name :- "<<name<<endl;
        cout<<"Phone Number :- "<<pno<<endl;
        cout<<"Car Number :- "<<carno<<endl;
    }
};
int cars::track=0;
class parking:public cars
{
protected:
    int date[3],time[3];
    char am[5];
public:
    void getdata()
        {
            cars::getdata();
            cout<<"Enter date of entry in year, month and day :- ";
            for(int i=0;i<3;i++)
            cin>>date[i];
            cout<<"Enter time of entry in hour, minute and second in 12 hour format :- ";
            for(int i=0;i<3;i++)
            cin>>time[i];
            cout<<"Enter  time is in AM or PM :- ";
            cin>>am;
            count=1;
        }
    void display()
    {
        cars::display();
        cout<<"Entry Date :- ";
         for( int i=0;i<3;i++)
         {
            cout<<date[i];
            while(i<2)
            {
                cout<<"/";
                break;
            }
         }
        cout<<endl;
        cout<<"Entry Time :- ";
        for( int i=0;i<3;i++)
        {
            cout<<time[i];
            while(i<2)
            {
                cout<<":";
                break;
            }
        }
        cout<<" "<<strupr(am);
        cout<<endl;
    }
};
class Remove:public parking
{
protected:
    int time2[3],date2[3];
    float money;
    char pm[5];
    static int k;        //used in emptyornot function
public:
    int getdata()       //input for parking
    {
        if(count==0)
        {
             parking::getdata();
            return 1;
        }
        else
            return 0;
    }

    void removegetdata()      //input for removing
    {
        cars::getdata();
    }
    void leave()
    {
        cout<<"Enter date of leaving in year, months and date :- ";
        for(int i=0;i<3;i++)
        cin>>date2[i];
        cout<<"Enter time of leaving in hour, minute and second in 12 hour format :- ";
        for(int i=0;i<3;i++)
        cin>>time2[i];
        cout<<"Enter pm or am :- ";
        cin>>pm;
    }
    void display()          //display after parking
    {
        parking::display();
    }
    void removedisplay()       //display after removing
    {
        count=0;
        cout<<"Leaving Date :- "<<date2[0]<<"/"<<date2[1]<<"/"<<date2[2]<<endl;
        cout<<"Leaving Time :- "<<time2[0]<<":"<<time2[1]<<":"<<time2[2]<<" "<<strupr(pm)<<endl;
    }
    Remove compare (Remove r[],int a)
    {
        int k=0;
        for(int i=0;i<a;i++)
        {
            if(r[i].count==1)
            {
                if((strcmp(name,r[i].name))==0 && pno==r[i].pno && (strcmp(carno,r[i].carno)==0))
                {
                    r[i].count=0;
                    r[i].leave();
                    r[i].display();
                    r[i].removedisplay();
                    r[i].calculatemoney();
                    r[i]--;
                    k=1;
                }
            }
        }
        if(k==1)
            cout<<"-----YOUR CAR HAS BEEN REMOVED------"<<endl;
        else
            cout<<"ENTER INFORMATION DID NOT MATCH"<<endl;
    }
    void calculatemoney()
    {
        int diff1,diff2,diff,z,x;
        diff1=((date2[0]-date[0])*(356*24))+((date2[1]-date[1])*(30*24))+((date2[2]-date[2])*24);
        if((strcmp((strupr(pm)),"PM"))==0)
        time2[0]+=12;
        if((strcmp((strupr(am)),"PM"))==0)
        time[0]+=12;
        diff2=(time2[0]-time[0])+((time2[1]-time[1])/60)+((time2[2]-time[2])/3600);
        diff=diff1+diff2;
        z=diff%24;
        x=diff/24;
        if(z>3)
        {
            money=x*8+3*2+(z-3)*0.05;
            cout<<"Total Money to be paid :- "<<money<<"$"<<endl;
        }
        else
        {
            money=x*8+z*3;
            cout<<"Total Money to be paid :- "<<money<<"$"<<endl;
        }
    }
    void emptyornot()
    {
        if(k>4)
            k=0;
        if(count==0)
        {
            cout<<"Parking Place "<<k<<" : "<<endl<< "\t\tEmpty"<<endl;
            k++;
            cout<<endl;
        }
       else
        {
            cout<<"Parking Place "<<k<<" :- ";
            cout<<endl<<"\t\t";
            parking::display();
            k++;
            cout<<endl;
        }
    }
    void operator ++ (int)
    {
        track=track+1;
    }
    void operator --(int)
    {
        track=track-1;
    }
    void displayk()
    {
        cout<<"No of cars : "<<track<<endl;
    }

};
int Remove ::k=0;
int main()
{
    int choice,z;
    int check;
    Remove r[5],r6;
    while(z!=1)
    {
        cout<<"-------------------CAR PARKING SYSTEM-------------------"<<endl;
        cout<<"Select Your choice"<<endl;
    cout<<"\t 1 --> Car Parking"<<endl<<"\t 2 --> Car Removing"<<endl<<"\t 3 --> Current Status of Parking"<<endl;
    cout<<endl;
    cout<<"Choice :- ";
    cin>>choice;
    system("CLS");
    int i=0;
    switch(choice)
    {
        case 1:
        {
            cout<<"\t\tCAR PARKING"<<endl;
            while(i<5)
            {
                check=r[i].getdata();
                i++;
                if(check==1)
                break;
            }
            if(check==1)
            {
                system("CLS");
                r[i-1].display();
                r[i]++;
                r[i].displayk();
                cout<<"Parked Place :- "<<i-1<<endl;
                cout<<"------YOUR CAR HAS BEEN PARKED-------"<<endl;
                cout<<endl;
                system("pause");
                system("CLS");
            }
            else if(i>4)
            {
                cout<<"PARKING IS FULL"<<endl;
                system("pause");
            }
            break;
        }
        case 2:
        {
            cout<<"\t\tCAR REMOVING"<<endl;
            r6.removegetdata();
            r6.compare(r,5);
            r[1].displayk();
            cout<<endl;
            system("pause");
            system("CLS");
            break;
        }
        case 3:
        {
            cout<<"\t\tCURRENT STATUS"<<endl;
            for(int i=0;i<5;i++)
                r[i].emptyornot();
            system("pause");
            system("CLS");
            break;
        }
        break;
    }
    }
  return 0;
}

