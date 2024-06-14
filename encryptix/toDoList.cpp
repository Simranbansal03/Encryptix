#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task> &tasks)
{
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); // To ignore any newline characters left in the input buffer
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks in the list." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description << " ["
             << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void markTaskAsCompleted(vector<Task> &tasks)
{
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
    }
    else
    {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    }
}

void removeTask(vector<Task> &tasks)
{
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
    }
    else
    {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    }
}

int main()
{
    vector<Task> tasks;
    int choice;

    do
    {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskAsCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
