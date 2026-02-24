
# TaskBox – Task Manager in C

## Description

TaskBox is a command-line task manager developed in C.
It allows users to add, delete, edit, save, and load tasks from a file.

This project was created to strengthen fundamental C programming skills, particularly dynamic memory management, single and double pointer manipulation, code modularity, and robust user input handling.

## Choice of Data Structure

The main data structure used is a singly **linked list** because:

- The number of tasks is unknown in advance.
- It allows natural dynamic memory management using malloc and free.
- Insertions and deletions are simplified, without requiring global resizing.
- The pedagogical goal was to focus on explicit pointer manipulation.

In particular, removing an element (`delete_by_id`) is easier to implement than with a dynamic array, where shifting elements would be required.

## Project Architecture

The project is structured into three main parts:
```markdown
include/tasklist.h → structure declarations and function prototypes  
src/tasklist.c     → implementation of the list management functions  
src/main.c         → user interface (CLI)
```
This separation makes it possible to:
- Isolate the core logic from the user interface.
- Modify the implementation without impacting main.c.
- Follow an abstraction principle similar to that of standard C libraries.

 
## Features
```
Available Commands:
a → add a task
d → delete a task
t → toggle task status (done / not done)
p → display the task list
x → display statistics
s → save to a file
l → load from a file
h → display help
q → quit
```


## Complexity of Operations

| Function | Complexity |
| -------------- | ---------- |
| `push_back` | O(n) |
| `find_by_id` | O(n) |
| `delete_by_id` | O(n) |
| `toggleDone` | O(n) |
| `get_stats` | O(n) |
| `save_list` | O(n) |
| `load_list` | O(n) |

The complexity is linear because each operation requires traversing the list.

## Memory management
- Each task is allocated dynamically with malloc.
- Memory is explicitly released via free.
- free_listensures that no memory leaks remain.
- load_listIt cleans the list correctly in case of an allocation error.

The project is compiled correctly
`-Wall -Wextra -Wpedantic -fsanitize=address`
and does not generate any warnings.

## Compilation

**Compilation :**
`make`

**Execution:**
`make run`

**Cleaning :**
`make clean`

## Exemple of use

	Commande (a/d/t/p/x/s/l/h/q): a  
	Entrez id et done (0/1): 1 0  
	Ajouté.
      
	Commande (a/d/t/p/x/s/l/h/q): a 
	Entrez id et done (0/1): 2 1  
	Ajouté.
	  
	Commande (a/d/t/p/x/s/l/h/q): x  
	Total: 2  
	Done: 1  
	Completion: 50.00%
	  
	Commande (a/d/t/p/x/s/l/h/q): p  
	Node id=1 done=0 next = 0x6020000000f0 
	Node id=2 done=1 next = 0x0

## What I learned

- Manipulation of single and double pointers ( `Node *` vs `Node **`).
- Dynamic memory management in C.
- Memory leak prevention.
- Robust handling of user input ( `scanf` + buffer cleaning).
- Separation of interface and implementation via files `.h` and `.c`.
- Automating compilation with a Makefile.

  

## Améliorations possibles
- Use a hash table for O(1) access.
- Implement automatic task sorting.
- Add unit tests. 
- Replace `scanf` with `fgets` for more robust input parsing


