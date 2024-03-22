#pragma once
#include <iostream>
#include <cstdarg>
#include <cstring>
using namespace std;
class Sort
{
private:
    int* list;// add data members
    int lung;
public:
    Sort(int length, int imin, int imax)
    {
        list = new int[length];
        lung = length;
        for (int i = 0; i < length; i++)
        {
            list[i] = (rand() % (imax - imin + 1)) + imin;
        }
    }
    Sort(int length, int v[])
    {
        list = new int[length];
        lung = length;
        for (int i = 0; i < length; i++)
        {
            list[i] = v[i];
        }
    }
    Sort()
    {
        int count;
        cin >> count;
        lung = count;
        list = new int[count];
        for (int i = 0; i < count; i++)
            cin >> list[i];
    }
    Sort(int count, ...)
    {
        lung = count;
        va_list arg;
        va_start(arg, count);
        list = new int[count];
        for (int i = 0; i < count; i++)
            list[i] = va_arg(arg, int);
        va_end(arg);
    }
    Sort(char* r)
    {
        lung = 0;
        for (int i = 0; i < strlen(r); i++)
        {
            if (r[i] == ',')
            {
                lung++;
            }
         }
        lung++;
        list = new int[lung];
        int count = 0;
        int temp = 0;
        for (int i=0;i<strlen(r);i++)
        {
            if (r[i] == ',')
            {
                list[count] = temp;
                count++;
                temp = 0;
            }
            else
            {
                int var = int(r[i]) - 48;
                temp = temp * 10 + var;
            }
        }
        list[count] = temp; 
    }
    ~Sort()
    {
        delete list;
    }
    // add constuctors
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};