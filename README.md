# Algorithms & Data Structures (ADS1)

**ADS1** is a comprehensive educational library written in C++, implementing a wide range of classic data structures and sorting algorithms. The project is designed to demonstrate the inner workings of various dictionaries, trees, priority queues, and heaps.

The application relies on a simple, interactive demonstration interface in the `main.cpp` file, where you can easily switch between use cases (e.g., testing an AVL tree or Heap Sort) using configuration flags.

## 🚀 Implemented Algorithms & Structures

The project is divided into three main modules:

### 1. Sorting Algorithms (`sorting`)
* **For Arrays:** Selection Sort, Insertion Sort, Bubble Sort, Mix Sort, Comb Sort, Heap Sort, Quick Sort (two versions), Merge Sort, Shell Sort, Count Sort.
* **For Linked Lists:** Merge Sort, Bucket Sort.

### 2. Dictionaries (`dictionaries`)
* **Array-based:** Unordered Array and Ordered Array (with binary and interpolative search).
* **Trees:** BST, AVL, Splay Tree, RST Tree, SBB Tree (2-3-4). *(Note: The B-Tree implementation is currently a work in progress and may not function fully. BB Tree, Trie, and Patricia are planned but not yet implemented).*
* **Hash Tables:** Simple Hash, Chain Hash, Open Hash, Double Hash.

### 3. Priority Queues (`priority_queues`)
* **List-based:** Unordered List and Ordered List.
* **Heaps & Trees:** Traditional Heap, Beap, Leftist Heap, Skew Heap, Binomial Tree. *(Note: Binomial Queue is currently a work in progress).*

## 📂 Project Structure

The project is organized in a clean, modular way:

```text
.
├── CMakeLists.txt              # Build configuration file
├── README.md                   # Project documentation
├── main.cpp                    # Entry point and usage examples
├── dictionaries/               # Dictionary classes and implementations
│   ├── array.cpp / .h
│   ├── avl.cpp / .h
│   ├── bst.cpp / .h
│   └── ... (hash, sbb_tree, splay_tree, rst, etc.)
├── priority_queues/            # Priority queue classes and implementations
│   ├── heap.cpp / .h
│   ├── beap.cpp / .h
│   ├── list.cpp / .h
│   └── ... (leftist_skew_heap, binomial_tree, etc.)
└── sorting/                    # Sorting algorithm implementations
    ├── sort_arrays.cpp / .h
    └── sort_lists.cpp / .h
```

## 🛠️ Build Instructions

This project requires a compiler that supports the **C++20** standard and **CMake** (minimum version 3.29).

1. **Clone the repository:**
```bash
git clone <your-repo-url> ads1
cd ads1
```

2. **Prepare the build directory and compile:**
An out-of-source build is recommended.
```bash
mkdir build
cd build
cmake ..
make
```

## 💻 Usage

To test specific algorithms or data structures, run the generated binary:

```bash
./ads1
```

### Configuring Examples in `main.cpp`
You can manage which module is executed by editing the `ProgramType type` variable inside the `main()` function in `main.cpp`. You can choose one of the following variants:

* `SORTING_ARRAYS` - Demonstrates array sorting (uses `MERGE_SORT` by default).
* `SORTING_LISTS` - Demonstrates linked list sorting (uses `MERGE_LIST` by default).
* `DICTIONARIES` - Demonstrates dictionary operations (e.g., on `SBB_TREE`).
* `PRIORITY_QUEUES` - Demonstrates priority queues (defaults to `ORDERED_LIST`).

Example of changing the behavior:
```cpp
// inside main.cpp
ProgramType type = DICTIONARIES; // Change to your desired module

// Then, in the corresponding 'case', you can change the algorithm, for example:
dictionaries_usage(A, n, AVL_TREE); // Instead of SBB_TREE
```
After modifying the parameters in `main.cpp`, simply rebuild the project by running `make` in the `build` directory.

## ⚙️ Technical Details

* **Language:** C++20.
* **Time Complexity:** The project serves as a great tool for analyzing time complexity. For example, console outputs highlight the differences between inserting into an unordered list (O(1)) versus an ordered list (O(n)).
* **Extensibility:** The class-based architecture (utilizing inheritance or composition) within specific folders makes it easy to write and plug in your own modules without disrupting the existing codebase.

* ---

**Author:** Krzysztof Wójtowicz
**Course:** Algorithms and Data Structures 1 (Algorytmy i struktury danych 1) @ MiNI WUT
