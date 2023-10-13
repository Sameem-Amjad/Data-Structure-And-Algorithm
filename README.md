## Introduction
C++ stands as a versatile programming language known for creating high-performance applications. It was crafted by Bjarne Stroustrup as an extension of the venerable C language, bestowing developers with fine-grained control over system resources and memory management. This language's object-oriented nature imparts a clear structural approach to programming, promoting code reusability, and consequently reducing development costs.

## Why Choose C++?
C++ earns its stripes as a middle-level language, affording the capability to tackle low-level tasks like drivers and kernels, while also excelling in the creation of high-level applications such as games, graphical user interfaces, and desktop software. Notably, the syntax and code structure of both C and C++ are analogous. Key reasons to embrace C++ include its portability, platform-independence, user-friendly nature, impressive speed, and rich library support.

## Linked Lists
Linked lists, like arrays, serve as linear data structures, but they distinguish themselves by storing elements at non-contiguous locations, connecting these elements through pointers. Their allure becomes evident when overcoming the limitations of fixed-size arrays and offering more straightforward insertion and deletion operations.

### Why Choose Linked Lists?
While arrays excel at storing linear data of uniform types, they come with constraints: fixed sizes and costly element insertions. Linked lists step in to overcome these limitations, offering dynamic size adjustments and more convenient insertions and deletions. They come in three common flavors:

- Singly Linked List
- Doubly Linked List
- Circular Linked List

Before diving into these types, let's get acquainted with some essential terms:

- Node: Every element within a linked list is referred to as a node, encapsulating data and a pointer to the next node, maintaining the list's structure.
- Head: The initial node in the linked list, known as the head, marks the starting point of the entire list.
- Tail: The final node in the linked list, the tail, serves as the list's endpoint.
- Link: Each link in a linked list stores an element.
- Next: Each link within the list connects to the subsequent link through a reference labeled 'Next.'

### Singly Linked List
A singly linked list moves in a single direction, from the head to the tail, allowing traversal in one direction only.

### Declaring a Singly Linked List
In C++, a singly linked list is declared using the following structure:

```cpp
struct SinglyLinkedList {
    int data;
    SinglyLinkedList* next;
};
```

## Doubly Linked List
Doubly linked lists extend the capabilities of singly linked lists by enabling navigation in both forward and backward directions.

### Declaring a Doubly Linked List
In C++, you declare a doubly linked list as follows:

```cpp
struct DoublyLinkedList {
    int data;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;
};
```

## Circular Linked List
Circular linked lists create a loop, with no null endpoints. They can be either singly or doubly linked.

### Declaring a Circular Linked List
In C++, a circular linked list is declared as follows:

```cpp
struct CircularLinkedList {
    int data;
    CircularLinkedList* next;
};
```

## Stack
A stack is a linear data structure that adheres to the Last In, First Out (LIFO) principle. This means that the last item added to the stack is the first to be removed. It serves as an abstract data type, frequently used in various programming languages. The analogy to a real-world stack, where operations are performed at one end only, helps to conceptualize its behavior.

### How Stacks Work
Abstracted with a predefined capacity, a stack allows for adding and removing elements in a particular order. Each added element is placed atop the stack, and only the top element can be removed.

### Basic Stack Operations
Stacks support fundamental operations:

- Push: Adding an element to the top of the stack.
- Pop: Removing the top element from the stack.
- IsEmpty: Checking if the stack is empty.
- IsFull: Verifying if the stack is at maximum capacity.
- Peek: Retrieving the value of the top element without removing it.

### Declaring a Stack
In C++, you declare a stack using the following structure:

```cpp
struct Stack {
    int top = -1;
    int size;
    int* arr;
};
```

## Queue
A queue, a linear data structure, follows the First In, First Out (FIFO) principle. In this scenario, the first item added is the first to be removed. It functions as an abstract data type, widely employed in programming languages. The analogy of a queue, where the first person in line is the first to be served, illustrates the essence of a queue.

### How Queues Work
A queue operates with two pointers: FRONT and REAR. FRONT tracks the first element, while REAR tracks the last. Initially set to -1, these values change as elements are enqueued or dequeued.

### Basic Queue Operations
Queues support essential operations:

- Enqueue: Adding an element to the end of the queue.
- Dequeue: Removing an element from the front of the queue.
- IsEmpty: Checking if the queue is empty.
- IsFull: Verifying if the queue is at maximum capacity.
- Peek: Retrieving the value of the front element without removing it.

### Declaring a Queue
In C++, you declare a queue using the following structure:

```cpp
struct Queue {
    int front = -1;
    int rear = -1;
    int size = 10;
    int* arr;
};
```

## Trees
Trees, non-linear hierarchical data structures, consist of nodes connected by edges. They have a central node, structural nodes, and sub-nodes interconnected by edges. Trees possess unique characteristics:

- A single root node without a parent.
- Each node has one parent but can have multiple children.
- Every node connects to its children through edges.

### Basic Tree Terminology
To better understand tree data structures, it's crucial to grasp key terms:

- Parent Node: The ancestor of a node is known as its parent.
- Child Node: The immediate successor of a node is its child.
- Root Node: The topmost node without a parent.
- Degree of a Node: The number of sub-trees attached to a node.
- Leaf Node or External Node: A node without any children.
- Ancestor of a Node: Nodes on the path from the root to a specific node.
- Descendant: Successor nodes on the path from a leaf node to a given node.
- Sibling: Children of the same parent.
- Height of a Node: The number of edges on the longest path from a node to a leaf.
- Internal Node: A node with at least one child.
- Neighbour of a Node: Parent or child nodes of a node.
- Subtree: A node along with its descendants.

### Types of Trees
Trees are categorized based on the number of children a node can have:

**1. General Tree:**
In a general tree, nodes can have any number of children. No restrictions are imposed on the number of children a node may have.

**2. Binary Tree:**
A binary tree allows each node to have at most two children, typically referred to as the left child and the right child. Binary trees come in various flavors:

- Full Binary Tree: Every node has either 0 or 2

 children.
- Perfect Binary Tree: All interior nodes have two children, and all leaves have the same depth.
- Balanced Tree: The height difference between left and right subtrees at any node is at most 1.
- Binary Search Tree: Nodes follow a binary search property, with left child values being less than the parent and right child values being greater.

### Declaring a Tree
In C++, a tree node is declared with the following structure:

```cpp
struct Tree {
    int data;
    Tree* leftChild;
    Tree* rightChild;
};
```

## Graphs
Graphs in data structures are versatile, non-linear data structures comprised of nodes or vertices and connecting edges. They address real-world problems represented as network structures, such as telephone networks, circuit networks, and social networks. Important graph terms include:

- Vertex: Each node in the graph is a vertex.
- Edge: Edges represent connections between vertices.
- Adjacency: Two nodes are adjacent if they are connected by an edge.
- Path: A path signifies a sequence of edges between two vertices.

### Representations of Graphs
Graphs are represented in two primary forms:

**1. Adjacency List:**
In this representation, nodes are indexed in a one-dimensional array, with edges stored as lists.

**2. Adjacency Matrix:**
In this representation, nodes are indexed in a two-dimensional array, with non-zero values indicating the presence of an edge.

Graph traversal is the process of searching for nodes within a graph. Two common methods are:

- **Depth-First Search (DFS):** It explores deeply, descending as far as possible along a branch before backtracking. DFS is implemented using a stack or recursion.
- **Breadth-First Search (BFS):** It explores broadly, visiting all neighbors before moving to their children. BFS employs a queue for implementation.

## Sorting Algorithms
Sorting algorithms are essential for arranging data in a specific order. They play a pivotal role in managing and retrieving information efficiently. Sorting algorithms vary in terms of time and space complexity.

### Complexity of Sorting Algorithms
The efficiency of sorting algorithms hinges on their time and space complexity.

**1. Time Complexity:**
Time complexity measures the algorithm's execution time concerning the input size. It's typically expressed using Big-O notation (O), Omega notation (Ω), and Theta notation (Θ).

**2. Space Complexity:**
Space complexity quantifies the total memory usage during an algorithm's execution, encompassing both auxiliary memory and input space.

### Types of Sorting Algorithms:
Here are some common sorting algorithms:

### 1. Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order. It's not suitable for large datasets due to its high average and worst-case time complexity.

#### Complexity of Bubble Sort:
- Time Complexity: O(N^2)
- Space Complexity: O(1)

### 2. Selection Sort
Selection Sort works by repeatedly finding the minimum element and moving it to the beginning of the array. It's not efficient for large datasets.

#### Complexity of Selection Sort:
- Time Complexity: O(N^2)
- Space Complexity: O(1)

### 3. Insertion Sort
Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It's efficient for small datasets.

#### Complexity of Insertion Sort:
- Time Complexity: O(N^2)
- Space Complexity: O(1)

### 4. Merge Sort
Merge Sort employs a divide and conquer strategy, breaking the array into smaller sub-arrays and merging them to form the final sorted array. It offers good performance.

#### Complexity of Merge Sort:
- Time Complexity: O(N log N)
- Space Complexity: O(N)

## Searching Algorithms
Searching in data structures involves finding specific information within a collection of items. Various searching algorithms are tailored to different data structures, such as linear search and binary search.

### Types of Searching Algorithms:
Numerous searching algorithms are employed in data structures. Let's explore two common ones:

### 1. Linear Search
Linear Search iterates through all elements in the collection, checking each one for a match. It's suitable for unsorted data.

#### Complexity of Linear Search:
- Time Complexity: O(N)
- Space Complexity: O(1)

### 2. Binary Search
Binary Search is a divide-and-conquer algorithm that requires a sorted data collection. It efficiently finds a specific item by repeatedly dividing the search interval in half.

#### Complexity of Binary Search:
- Time Complexity: O(log N)
- Space Complexity: O(1)



### Data-Structure-And-Algorithm
<br/>
<div align="center">

![data-structures-algorithms2](https://github.com/Sameem-Amjad/Data-Structure-And-Algorithm/assets/92137575/687b0bee-e4f3-476d-988a-41a79a4b7edc)

</div>
<br/>
🔥 => Arrays  <br/>
🔥 => Linked Lists  <br/>
🔥 => Stacks  <br/>
🔥 => Queues  <br/>
🔥 => Trees (Binary Trees, AVL Trees, B-trees, etc.)  <br/>
🔥 => Graphs  <br/>
🔥 => Hash Tables  <br/>
🔥 => Heaps (Min-Heap, Max-Heap)  <br/>
🔥 => Hash Maps  <br/>
🔥 => Tries  <br/>
🔥 => Linked Lists (Singly, Doubly, Circular)  <br/>
🔥 => Disjoint-Set (Union-Find) Data Structure  <br/>

### Basic Algorithms:

🔥 => Searching Algorithms (Linear Search, Binary Search)  <br/>
🔥 => Sorting Algorithms (Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort)  <br/>
🔥 => Recursion and Backtracking  <br/>
🔥 => Divide and Conquer  <br/>
🔥 => Greedy Algorithms  <br/>
🔥 => Dynamic Programming  <br/>
🔥 => Graph Traversal Algorithms (BFS, DFS)  <br/>
🔥 => Graph Algorithms (Dijkstra's, Prim's, Kruskal's, etc.)  <br/>
🔥 => String Algorithms (String matching, Edit Distance, etc.)  <br/>

### Advanced Data Structures:

🔥 => Red-Black Trees  <br/>
🔥 => Suffix Trees  <br/>
🔥 => Segment Trees  <br/>
🔥 => Fenwick Trees (Binary Indexed Trees)  <br/>
🔥 => Bloom Filters  <br/>
🔥 => Skip Lists  <br/>
🔥 => Trie Variations (Radix Tree, Compressed Trie, etc.)  <br/>

### Advanced Algorithms:

🔥 => Advanced Sorting Algorithms (Heap Sort, Radix Sort, Counting Sort, etc.)  <br/>
🔥 => Matrix Multiplication (Strassen's Algorithm)  <br/>
🔥 => Convex Hull Algorithms (Graham Scan, Jarvis March)  <br/>
🔥 => Maximum Flow Algorithms (Ford-Fulkerson, Edmonds-Karp)  <br/>
🔥 => Shortest Path Algorithms (Bellman-Ford, A* Search)  <br/>
🔥 => NP-Completeness and Approximation Algorithms  <br/>
🔥 => Computational Geometry Algorithms  <br/>
🔥 => Randomized Algorithms  <br/>
🔥 => Data Structures and Algorithms Concepts:  <br/>

🔥 => Time and Space Complexity Analysis  <br/>
🔥 => Big O Notation  <br/>
🔥 => Data Structure Design and Implementation  <br/>
🔥 => Algorithm Design and Analysis  <br/>
🔥 => Asymptotic Notations (Theta, Omega)  <br/>
🔥 => Hashing and Hash Functions  <br/>
🔥 => Memory Management and Pointers  <br/>
🔥 => Cache Optimization  <br/>
🔥 => Parallel and Concurrent Algorithms  <br/>
🔥 => NP-Hard and NP-Complete Problems  <br/>
🔥 => Amortized Analysis  <br/>
🔥 => Online Algorithms  <br/>
