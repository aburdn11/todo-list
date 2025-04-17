#include <iostream>
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
    static const int MAX_TASKS = 100; 
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
     if (taskCount == 0) {
         cout << "There is no task to show" << endl;
         return;
     }

     for (int i = 0; i < taskCount; i++) {
         cout << "ID: " << tasks[i].id << (tasks[i].isDone ? " is Done " : "is Not done ")
             << "\n" << tasks[i].title << "Priority" << tasks[i].priority
             << "\n" << tasks[i].description << endl;
     }
    }

void TaskManager :: deleteTask() {
    int id;
    cout << "Enter Task ID to remove : " << endl;
    cin >> id;

    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (tasks[i].id == id) {
            for (int j = i; j < taskCount - 1; ++j)
            {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            found = true;
            cout << "Task removed successfully" << endl;
            break;
        }
    }

    if (!found)
        cout << "Task not found" << endl;
    }

void TaskManager :: markDone() {
         int id;
        cout << "Enter the task number to mark it as complete";
        cin >> id;

        for (int i = 0; i < taskCount; ++i) {
            if (tasks[i].id == id) {
                tasks[i].isDone = true;
                cout << "Task completed";
                return;
            }
        }

        cout << "Task not Found";

    }

void TaskManager :: editTask() {
        
        int id;
        cout <<"Enter Task ID to edit";
        cin >> id;
        cin.ignore();

        for (int i = 0; i < taskCount; ++i) {
            if (tasks[i].id == id) {
                Task updated;
                cout << "New title  ";
                getline(cin, updated.title);
                cout << "New Description";
                getline(cin, updated.description);
                cout << "New priority ";
                cin >> updated.priority;

                updated.id = tasks[i].id;
                updated.isDone = tasks[i].isDone;

            for (int j = i; j < taskCount - 1; ++j)
                tasks[j] = tasks[j + 1];
            taskCount--;

            insertSorted(updated);
            cout << "Task updated successfully.\n";
            return;
            }
        }

        cout << "Task not found.\n";
    }

int main() {
    TaskManager manager;
    int choice;
     
    do {
        cout << "\n List of tasks:\n";
        cout << "1. add a Task\n";
        cout << "2. view a Tasks\n";
        cout << "3. edit a Task\n";
        cout << "4. delete a Task\n";
        cout << "5. Mark a task as complete\n";
        cout << "0. exit\n";
        cin >> choice;

        switch (choice) {
            case 1: manager.addTask(); break;
            case 2: manager.viewTasks(); break;
            case 3: manager.editTask(); break;
            case 4: manager.deleteTask(); break;
            case 5: manager.markDone(); break;
            case 0: cout << "thank you\n"; break;
            default: cout << "sory Wrong entry.\n";
        }

    } while (choice != 0);

    return 0;
}
