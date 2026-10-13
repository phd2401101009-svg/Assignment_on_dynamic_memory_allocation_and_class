# C++ Dynamic Memory & Class Practice Assignments

This repository contains C++ implementations and automated verification for two core OOP and memory management assignments.

---

## Question 1: Dynamic Array Allocation and Resizing

### Problem Statement
Write a C++ program to dynamically create an array of type `Person` (where a `Person` has characteristics: `name`, `age`, `height`, `gender`, and `gpa`) to store the data of 500 persons. Subsequently, resize this array dynamically to hold data for 600 persons. Navigate the resized array to find and print the average age, height, and GPA for all 600 persons.

### Expected Functionality
1. Dynamically allocate memory for an array of 500 `Person` structures/objects.
2. Populate initial 500 records.
3. Dynamically reallocate memory to expand the array capacity from 500 to 600 elements while preserving original data.
4. Populate the remaining 100 records.
5. Traverse the entire 600-element array to calculate and output:
   - Average Age
   - Average Height
   - Average GPA

---

## Question 2: Person Class Initialization and Updates

### Problem Statement
Write a C++ program to create a class named `Person` with characteristics: `name`, `age`, `height`, `gender`, and `gpa`. 
- Include member functions to initialize the object data.
- Include an `update` member function to modify the `age`, `height`, and `gpa` of an existing `Person` object.
- Provide display methods to verify data before and after modification.

### Expected Functionality
1. Encapsulate person attributes inside a `Person` class.
2. Use constructor or explicit `init()` method to set initial attribute values.
3. Use an `update()` method to modify `age`, `height`, and `gpa`.
4. Output initial and updated object states.

---

## Test Examples

### Question 1 Examples

#### Test Example 1.1 (Standard Small Dataset - Scaled Concept Validation)
* **Input Dataset Overview**: 600 records with uniform values across all entries.
  - 600 entries: Age = `20`, Height = `170.0`, GPA = `3.5`
* **Expected Output**:
  ```text
  Average Age: 20.00
  Average Height: 170.00
  Average GPA: 3.50
