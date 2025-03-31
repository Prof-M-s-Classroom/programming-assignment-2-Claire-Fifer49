[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Claire Fifer]`  
### **Student ID:** `[131963608]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The story is loaded from an external text file (`myStory.txt`), which is parsed to construct the decision tree. The description, its own event number and the event numbers of its left and right children are stored in the data of each node. The game ends when a node has both left and right children with event values of -1.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This file facilitates the game as a whole. It first calls the method to create the tree then it starts the game.`  
- **`GameDecisionTree.h`** → `This file contains the implementations of how the tree is created and how the game is run.`  
- **`Node.h`** → `This file contains the structure of a Node, which is the container for every event's data.`  
- **`Story.h`** → `This file contains the structure of the Story class which has all the event data.`  
- **`story.txt`** → `This file contains all the raw data for events that will be loaded into the game. Each piece of data is seperated by a |. And each new line is a new event`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  They are read from the txt file and the first token is the events own number. The second token is the description of the event. The last two tokens are its children's event numbers
- How are nodes linked based on left and right event numbers?  THe nodes are linked based on left and right event numbers as those are what decides which events are an events child.
- What happens if an event has `-1` as left or right children?  Having a '-1' as a child means that it is a leaf node. It is the end of a decision route and the game ends.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  By choosing one of two options the user is choosing the left or right child.
- What happens when the player reaches a leaf node?  The game ends when a player reaches a leaf node and no further input is asked for.
- Explain the special case where multiple events lead to the same outcome.  This is the case since one node can be a child for multiple nodes. Two different nodes or events has a child pointer to the same node or event.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  It is read in line by line and then each line is split by the specified delimiter.
- How do you ensure nodes are properly linked?  You ensure everything is properly linked by using print statements to see where each node was added.
- Any challenges faced while handling file input?  Reading in the file was tricky. And traversing an unsorted list not recursively, as I had done in the past, was a little confusing at first.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> I could not figure out why my I could not open my file. I figured out it was because of its location. So I moved it to be int the debug folder, and then it started working.


---

## **7. Sample Output & Walkthrough**

In the middle of the night your car runs out of gas. You were driving through a forest so you begin to walk along the hi
ghway in hopes of finding someone to help you or cell service. No cars have past you yet, and you spot a light in the fo
rest. Choose an option:
A) You continue walking alongside the highway
B) You start into the forest
Enter your answer (A or B):a

You continue walking alongside the highway. A run-down pick-up truck rumbles up next to you. Choose an option:
A) You ask the man driving for help
B) You start into the forest
Enter your answer (A or B):b


---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N)`  
- **Searching for an event in the tree** → `O(N)`  
- **Game traversal efficiency** → `O(log(N))`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario if a user inputs an invalid input. I ensured that the loop would still run and that the user could retry their input.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
