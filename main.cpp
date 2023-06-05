#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string T[n][3];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin >> T[i][j];
        }
    }

    cout << "#" << endl;
    //1.feladat
    int ossz = 0;
    for(int i = 0; i<n; i++)
    {
        ossz = ossz + (stoi (T[i][2])-stoi(T[i][1]))+1;


    }

    cout << ossz << endl;
    cout << "#" << endl;
    //2.Feladat

    int temp[30];
     for(int i = 0; i<30; i++)
    {
        temp[i] = 0;
    }


     for(int i = 0; i<n; i++)
    {
        for(int j = stoi(T[i][1]); j<=stoi(T[i][2]); j++)
        {
            temp[j-1]++;
        }
    }
    int maximum = 0;
    int maxhely = 0;
    for(int i = 0; i<30; i++)
    {
       if(temp[i] > maximum)
       {
           maximum = temp[i];
           maxhely = i;
       }
    }
    cout << maxhely+1 << endl;
    cout << "#" << endl;
    //3.Feladat
    int maximum2 = 0;
    int maxhely2 = 0;
     for(int i = 0; i<30; i++)
    {
        temp[i] = 0;
    }

      for(int i = 0; i<n; i++)
    {
        for(int j = stoi(T[i][1]); j<=stoi(T[i][2]); j++)
        {
            temp[j-1]++;
        }
    }

    bool igen = false;
    for(int i = 1; i<30; i++)
    {
       if(temp[i] > maximum2)
       {
           maximum2 = temp[i];
           maxhely2 = i;
           cout << maxhely2+1 << " ";
           igen = true;
       }
    }

    if(!igen)
    {
        cout << "0" << endl;
    }
    cout << endl;
    cout << "#" << endl;
    //4.Feladat

    string rendszam = "";
    int max = 0;

    for(int i = 0; i<n; i++)
    {
        string seged = T[i][0];
        int dbseged = 0;
        for(int j= 0; j<n; j++)
        {
            if(seged == T[j][0])
            {
                dbseged++;
            }
        }
        if(dbseged > max)
        {
            max = dbseged;
            rendszam = seged;
        }
    }

    cout << rendszam << endl;



    cout << "#" << endl;
    //5.Feladat

    vector<string> temp2;
    temp2.push_back(T[0][0]);
    for(int i = 1; i<n; i++)
    {
        bool seged = false;
       for(int j = 0; j<temp2.size(); j++)
       {
           if(T[i][0].compare(temp2[j]) == 0 )
           {
               seged = true;
           }
       }
       if(!seged)
       {
           temp2.push_back(T[i][0]);
       }
    }

    int temp3[temp2.size()];
    for(int i = 0; i<temp2.size(); i++)
    {
        temp3[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<temp2.size(); j++)
        {
            if(T[i][0].compare(temp2[j]) == 0)
            {
                temp3[j]++;
            }
        }
    }

    maximum = 0;
    maxhely = 0;
    for(int j = 0; j<temp2.size(); j++)
    {
        if(temp3[j] > maximum)
        {
            maximum = temp3[j];
            maxhely = j;
        }
    }

    int temp4[temp2.size()];
    for(int i = 0; i<temp2.size(); i++)
    {
        temp4[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<temp2.size(); j++)
        {
            if(T[i][0].compare(temp2[j]) == 0)
            {
                temp4[j]+= (stoi(T[i][2]) - stoi(T[i][1]))+1;
            }
        }
    }

    for(int i = 0; i<temp2.size(); i++)
    {
        cout << temp2[i] << " " << temp3[i] << " " << temp4[i] << endl;
    }


    return 0;
}
