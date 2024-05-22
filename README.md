## Makefile Explanation

This `Makefile` is designed to compile and build the C++ project, including running tests and checking for memory leaks. Below is a line-by-line explanation of each part of the `Makefile`.

### Variables

- **CXX**: The C++ compiler to use (in this case, `clang++`).
- **CXXFLAGS**: Flags for the C++ compiler, which include:
  - `-std=c++11`: Use the C++11 standard.
  - `-Werror`: Treat all warnings as errors.
  - `-Wsign-conversion`: Warn on implicit type conversions that change the sign of an integer.
- **VALGRIND_FLAGS**: Flags for Valgrind, a tool for memory debugging, which include:
  - `-v`: Verbose output.
  - `--leak-check=full`: Check for memory leaks.
  - `--show-leak-kinds=all`: Show all kinds of memory leaks.
  - `--error-exitcode=99`: Exit with code 99 on error.

### Source and Object Files

- **SOURCES**: List of all the source files in the project.
- **OBJECTS**: List of object files generated from the source files. Uses `$(subst .cpp,.o,$(SOURCES))` to replace `.cpp` with `.o`.

### Targets

- **run**: Builds and runs both `demo` and `test`. Uses `$^` to refer to all prerequisites.

    ```make
    run: demo test
        ./$^  
    ```

- **demo**: Compiles the `demo` executable. Excludes `TestCounter.o` and `Test.o`.

    ```make
    demo: Demo.o $(filter-out TestCounter.o Test.o,$(OBJECTS))
        $(CXX) $(CXXFLAGS) $^ -o demo
    ```

- **test**: Compiles the `test` executable. Excludes `Demo.o`.

    ```make
    test: TestCounter.o Test.o $(filter-out Demo.o,$(OBJECTS))
        $(CXX) $(CXXFLAGS) $^ -o test
    ```

- **tidy**: Runs `clang-tidy` with a set of checks.

    ```make
    tidy:
        clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --
    ```

- **valgrind**: Runs Valgrind on both `demo` and `test` executables to check for memory leaks.

    ```make
    valgrind: demo test
        valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
        valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
    ```

### Pattern Rules

- **%.o: %.cpp**: Compiles `.cpp` files to `.o` object files.

    ```make
    %.o: %.cpp
        $(CXX) $(CXXFLAGS) --compile $< -o $@
    ```

### Clean Up

- **clean**: Removes all object files and executables.

    ```make
    clean:
        rm -f *.o demo test 
    ```

## Graph.hpp Explanation

The `Graph.hpp` file declares a `Graph` class with various functionalities. Below is an explanation of its components.

### Namespace

- **namespace ariel**: Contains the `Graph` class to avoid naming conflicts.

### Class Declaration

- **class Graph**: Manages a graph represented by an adjacency matrix.

### Private Members

- **std::vector<std::vector<int>> matrix**: Stores the adjacency matrix of the graph.

### Public Member Functions

- **void loadGraph(const std::vector<std::vector<int>>& input)**: Loads the graph from a given adjacency matrix.
- **std::string printGraph() const**: Returns a string representation of the adjacency matrix.
- **const std::vector<std::vector<int>>& getMatrix() const**: Returns the adjacency matrix.

### Arithmetic Operators

- **Graph operator+(const Graph& other) const**: Adds two graphs.
- **Graph& operator+=(const Graph& other)**: Adds another graph to this graph.
- **Graph operator-() const**: Returns the negation of the graph.
- **Graph operator-(const Graph& other) const**: Subtracts another graph from this graph.
- **Graph& operator-=(const Graph& other)**: Subtracts another graph from this graph.
- **Graph operator*(int scalar) const**: Multiplies the graph by a scalar.
- **Graph operator*(const Graph& other) const**: Multiplies two graphs element-wise.
- **Graph& operator*=(int scalar)**: Multiplies this graph by a scalar.
- **Graph& operator/=(int scalar)**: Divides this graph by a scalar.
- **Graph operator/(int scalar) const**: Divides the graph by a scalar.

### Comparison Operators

- **bool operator==(const Graph& other) const**: Checks if two graphs are equal.
- **bool operator!=(const Graph& other) const**: Checks if two graphs are not equal.
- **bool operator>(const Graph& other) const**: Checks if this graph is greater than another graph.
- **bool operator>=(const Graph& other) const**: Checks if this graph is greater than or equal to another graph.
- **bool operator<(const Graph& other) const**: Checks if this graph is less than another graph.
- **bool operator<=(const Graph& other) const**: Checks if this graph is less than or equal to another graph.

### Increment and Decrement Operators

- **Graph& operator++()**: Prefix increment operator.
- **Graph operator++(int)**: Postfix increment operator.
- **Graph& operator--()**: Prefix decrement operator.
- **Graph operator--(int)**: Postfix decrement operator.

### Multiplication by a Scalar

- **friend Graph operator*(int scalar, const Graph& g)**: Multiplies a graph by a scalar (commutative).

### Output Operator

- **friend std::ostream& operator<<(std::ostream& os, const Graph& g)**: Outputs the graph's adjacency matrix to an output stream.
