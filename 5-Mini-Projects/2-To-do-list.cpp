/*
Create a console application that allows the user to create a to-do list.

The program should allow the user to add, remove, and view tasks on the list. 
Each task should have a name and a due date associated with it. Use a vector container to store the tasks.
*/

#include <iostream>
#include <vector>

struct Task
{
    std::string name;
    std::string due_date;
};
//create vector cotainer for tasks
std::vector<Task> tasks;

//Add Task
void add_task()
{
    Task task;
    std::cout << "Enter task name: ";
    std::cin >> task.name;
    std::cout << "Enter task due date: ";
    std::cin >> task.due_date;
    tasks.push_back(task);
}
//Remove Task
void remove_task()
{
    int task_index;
    std::cout << "Enter task index: ";
    std::cin >> task_index;

    tasks.erase(tasks.begin() + task_index);
}

//View Task
void view_task()
{
    std::cout << "To-do-list: " << std::endl;
    for(int i = 0; i < tasks.size(); i++)
    {
        std::cout << i << "." << tasks[i].name << " " << tasks[i].due_date << std::endl;
    }
}

int main() {
  int choice;

  do {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add task" << std::endl;
    std::cout << "2. Remove task" << std::endl;
    std::cout << "3. View to-do list" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        addTask();
        break;
      case 2:
        removeTask();
        break;
      case 3:
        viewTaskList();
        break;
      case 4:
        exit(0);
        break;
      default:
        std::cout << "Invalid choice." << std::endl;
    }
  } while (choice != 4);

  return 0;
}
