# Lim Data Structures
Basic data structures for the C programming language.

## About

These are the basic data structures implementation for the C programming language, mainly for learning purposes.
Right now it contains three structs:

### 1) Flow

A dynamic array like the C++ std::vector, which uses an inital internal buffer of predefined size (default is 100 elements).
If its capacity exceeds the predefined stack size or if the user requests greater size at creation, the buffer is reallocated into 
a heap allocated new array using calloc() and safe transfer of the old stack buffer to the new one in the heap.

Why that? You will ask.

The main purpose of this implementation is that, in most cases, I find myself not needing much space for items in C++ vector, but I use it anyway
because you never know how much space you will need. So I wanted a solution that provides stack allocated buffer for quick memory access, with the possibility
of transferring to heap memory in case of buffer filling, which case is rare. And because C++ vector is stored in heap memory by default, I ended up creating
my own basic vector, for learning purposes. I used the name Flow because I find it beautiful, and because it manifests the dynamic nature of this linear
data strusture.

### 2) List

A doubly linked list with an obvious name this time, providing the basic operations for linked lists.

### 3) Stack

A simple stack struct with operations like push, pop, and get.

## Usage

This implementation aims to be pure, without using macros (for now). The drawback is that the structs use the void* internal type, which means that you have to be careful
with casting the void pointer to your desired type.

For example:

```
Flow intVector = createFlow(20); // Initial capacity as argument

int newInt = 14;

appendInFlow(&intVector, &newInt);

int secondNum = *((int*) atFlowIndex(&intVector, 0); // You have to cast to int pointer and then dereference it. 

```

To make things easier, in each header file in the beginning I added a typedef instruction defining the word
<b>Type</b> with void* as default. So, if you need for example to create a FloatFlow or a FloatList, just change this typedef to float. Then you only have to rename the
struct and its functions, which is easy by using find and replace in your editor, e.g. renaming Flow to CharFlow.

### More data structures will come in the future!
