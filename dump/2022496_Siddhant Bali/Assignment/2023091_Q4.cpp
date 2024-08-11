#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;


int partition(vector<int> &task_IDs, int start, int end)
{
    int pivot = task_IDs[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (task_IDs[j] <= pivot)
        {
            i++;
            swap(task_IDs[i], task_IDs[j]);
        }
    }
    swap(task_IDs[i + 1], task_IDs[end]);
    return i + 1;
}

void quicksort(vector<int> &task_IDs, int start, int end)
{
    if (start < end)
    {
        int q = partition(task_IDs, start, end);
        quicksort(task_IDs, start, q - 1);
        quicksort(task_IDs, q + 1, end);
    }
}

class Task_Scheduler {
    vector<int> ID;
    int remaining_Tasks, index_To_Remove;
    public:
    Task_Scheduler(vector<int> pivot) {quicksort(pivot, 0, pivot.size()-1); ID = pivot; srand(time(0)); remaining_Tasks = pivot.size();}
    void Select_Yuji_Itadori() {
        int random = rand() % 2;
        remaining_Tasks--;
        index_To_Remove = random ? 0 : ID.size()-1;
        cout << "ID: " << ID[index_To_Remove] << endl;
    }
    void Select_Megumi_Fushigoro() {
        int index_To_Remove = rand() % ID.size();
        remaining_Tasks--;
        cout << "K = " << index_To_Remove+1 << endl;
        cout << "ID: " << ID[index_To_Remove] << endl;
    }
    void Select_Nobara_Kugisaki() {
        remaining_Tasks--;
        index_To_Remove = (remaining_Tasks+1)/2;
        cout << "ID: " << ID[index_To_Remove] << endl;
    }
    void remove() {ID.erase(ID.begin() + index_To_Remove);}
    int size() {return ID.size();}
    void print_IDs() {for (int i: ID) cout << i << " "; cout << endl;}
};


int main()
{
    vector<int> ID;
    cout << "Enter IDs followed by an {Enter} (-1 to exit)" << endl;
    while (true) {
        int y; cin >> y;
        if (y != -1) ID.push_back(y);
        else break;
    }
    Task_Scheduler Task_Scheduler(ID);
    cout << "Enter queries (-1 to exit)" << endl;
    while (true) {
        int y; cout << "Enter query: "; cin >> y;
        if (y == 1) {Task_Scheduler.Select_Yuji_Itadori(); Task_Scheduler.remove();}
        if (y == 2) {Task_Scheduler.Select_Megumi_Fushigoro(); Task_Scheduler.remove();}
        if (y == 3) {Task_Scheduler.Select_Nobara_Kugisaki(); Task_Scheduler.remove();}
        if (!Task_Scheduler.size()) {cout << "No more tasks left."; break;}
        if (y == -1) break;
        // Task_Scheduler.print_IDs();
    }
    return 0;
}