#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

struct Task {
    int id;
    string title;
    string description;
    bool isDone;
    int priority;
};

class TaskManager {
private:
    Task tasks[MAX_TASKS];
    int taskCount;

    void insertSorted(Task t);

public:
    TaskManager() {
        taskCount = 0;
    }

    void addTask();

    void viewTasks();

    void deleteTask();

    void markDone();

    void editTask();
};

void TaskManager :: insertSorted(Task t) {
        int i=taskCount - 1;
        for(i; i > 0 && tasks[i].priority > t.priority ; i--)
        tasks[i + 1] = tasks[i];
        
        tasks[i + 1] = t;
        taskCount++;
    }

 void TaskManager ::addTask() {
     if ( taskCount == MAX_TASKS ){
         cout<<"sory the tasks is full";
         return;
     }
    
    Task t;
    
    cout<<"inter the numebr of the task: ";
    cin>>t.id;
    cin.ignore(); 
    cout<<"inter the title of the task: ";
    cin.ignore(); 
    getline(cin, t.title);
    cout<<"inter the descripe of the task: ";
    cin.ignore();
    getline(cin, t.description);

    cout<<"inter the priority of the task: ";
    cin>>t.priority;
    
    t.isDone=false;
    
    insertSorted(t);
    
    }
    
 void TaskManager :: viewTasks() {
       
    }

void TaskManager :: deleteTask() {
        
    }

void TaskManager :: markDone() {
        
    }

void TaskManager :: editTask() {
        
    }

int main() {
    TaskManager manager;
    int choice;

    do {
        cout << "\n📋 list of tasks:\n";
        cout << "1. add a Task\n";
        //cout << "2. view a Tasks\n";
        //cout << "3. edit a Task\n";
        //cout << "4. delete a Task\n";
        //cout << "5. Mark a task as complete\n";
        cout << "0. exit\n";
        cin >> choice;

        switch (choice) {
            case 1: manager.addTask(); break;
            //case 2: manager.viewTasks(); break;
            //case 3: manager.editTask(); break;
            //case 4: manager.deleteTask(); break;
            //case 5: manager.markDone(); break;
            case 0: cout << "thank you\n"; break;
            default: cout << "sory Wrong entry.\n";
        }

    } while (choice != 0);

    return 0;
}
