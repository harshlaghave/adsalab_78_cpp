/*
Problem Statement:Implement a problem of minimum work to be done per day to CO2 
finish given tasks within D days problem.   
Statement: Given an array task [] of size N denoting amount of work to 
be done for each task, the problem is to find the minimum amount of 
work to be done on each day so that all the tasks can be completed in 
at most D days. 
Note: On one day work can be done for only one task.

*/


#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<int>& task, int D, int X) {
    int totalDays = 0;
    for (int t : task)
        totalDays += (t + X - 1) / X;  // ceil division
    return totalDays <= D;
}

int minWorkPerDay(vector<int>& task, int D) {
    int low = 1;
    int high = *max_element(task.begin(), task.end());
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canFinish(task, D, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> task = {3, 2, 4};
    int D = 1;
    cout << "Minimum work per day = " << minWorkPerDay(task, D);
    return 0;
}
