#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool comp(Job a, Job b)
{
    return (a.profit>b.profit);
}

void Job_Scheduling(int n, Job jb[])
{
    cout<<"The sequence of jobs according to max profits is: "<<endl;
    sort(jb,jb+n,comp);// sorting the jobs according to descending order of profits
    int slot[n];//to check if the slot is free
    int seq[n];// to give the resulting sequence

    //Initialize all the slots to be free before the algo begins
    for (int i=0;i<n;i++)
    {
        slot[i]=false;
    }


    //Iterate through the given jobs 
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,jb[i].deadline)-1;j>=0;j--)
        {
            //we find the free slots from the end
            if(slot[j]==false)
            {
                seq[j]=i; // Adding job to the result
                slot[j]=true;
                break;
            }
        }
    }

    //print the result
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        cout<<jb[seq[i]].id<<endl;
    }

} 

int main()
{
    int choice;
    int m;
    bool loop=true;
    cout<<"Enter the size of the job array= "<<endl;
    cin>>m;
    Job j[m];
    while(loop)
    {
    cout<<"---MENU----"<<endl;
    cout<<"1. Enter values"<<endl;
    cout<<"2. Display the Jobs"<<endl;
    cout<<"3. Sequence"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice= "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter the jobs= "<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<"Enter the Job ID= "<<endl;
                cin>>j[i].id;
                cout<<"Enter the Job deadline= "<<endl;
                cin>>j[i].deadline;
                cout<<"Enter the Job profit ="<<endl;
                cin>>j[i].profit;
            }
        }
        break;
        case 2:
        cout<<"The Jobs are: "<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<j[i].id<<"\t"<<j[i].deadline<<"\t"<<j[i].profit<<endl;
        }
        break;

        case 3:
        Job_Scheduling(m,j);
        break;
        
        case 4:
        cout<<"Code exit... "<<endl;
        loop=false;
        break;
    }

    }
    
}

