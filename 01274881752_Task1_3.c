#include <stdio.h>

int task_id = 0;
char task_description[100][100];
int task_completed[100];

void add_task()
{
    printf("Enter task description: ");
    fflush(stdin);
    fgets(task_description[task_id], 100, stdin);

    task_completed[task_id] = 0;

    printf("Task added successfully!\n");
    task_id++;
}

void view_tasks()
{
    printf("Current tasks:\n");
    for (int i = 0; i < task_id; i++)
    {
        printf("Task ID: %d\nDescription: %sStatus: %s\n", i + 1, task_description[i], task_completed[i] ? "Completed" : "Incomplete");
    }
}

void view_completed_tasks()
{
    printf("Completed tasks:\n");
    for (int i = 0; i < task_id; i++)
    {
        if (task_completed[i])
        {
            printf("Task ID: %d\nDescription: %s\n", i + 1, task_description[i]);
        }
    }
}

void view_incomplete_tasks()
{
    printf("Incomplete tasks:\n");
    for (int i = 0; i < task_id; i++)

        if (!task_completed[i])
        {
            printf("Task ID: %d\nDescription: %s\n", i + 1, task_description[i]);
        }
}

void mark_task_as_completed()
{
    printf("Enter task ID to mark as completed: ");
    int task_id_to_mark;
    scanf("%d", &task_id_to_mark);

    if (task_id_to_mark > 0 && task_id_to_mark <= task_id)
    {
        if (task_completed[task_id_to_mark - 1])
        {
            printf("Task is already completed!\n");
        }
        else
        {
            task_completed[task_id_to_mark - 1] = 1;
            printf("Task marked as completed successfully!\n");
        }

    }
    else
    {
        printf("Task ID does not exist!\n");
    }
}

void remove_task()
{
    printf("Enter task ID to remove: ");
    int task_id_to_remove;
    scanf("%d", &task_id_to_remove);

    if (task_id_to_remove > 0 && task_id_to_remove <= task_id)
    {
        for (int i = task_id_to_remove - 1; i < task_id - 1; i++)
        {
            strcpy(task_description[i], task_description[i + 1]);
            task_completed[i] = task_completed[i + 1];
        }
        task_id--;
        printf("Task removed successfully!\n");
    }
    else
    {
        printf("Task ID does not exist!\n");
    }
}

void show_table()
{
    printf("| Task ID | Description | Status |\n");
    printf("|---------|-------------|--------|\n");

    for (int i = 0; i < task_id; i++)
    {
        printf("| %7d | %-11s | %7s |\n", i + 1, task_description[i], task_completed[i] ? "Completed" : "Incomplete");
    }
}

int main()
{
    printf("Minions Task Manager\n");

    while (1)
    {
        printf("1. Add Task\n2. View All Tasks\n3. View Completed Tasks\n4. View Incomplete Tasks\n5. Mark Task as Completed\n6. Remove Task\n7. Show Table\n8. Exit\nSelect an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_task();
            break;
        case 2:
            view_tasks();
            break;
        case 3:
            view_completed_tasks();
            break;
        case 4:
            view_incomplete_tasks();
            break;
        case 5:
            mark_task_as_completed();
            break;
        case 6:
            remove_task();
            break;
        case 7:
            show_table();
            break;
        case 8:
            printf("Exiting Minions Task Manager. Have a great day!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
