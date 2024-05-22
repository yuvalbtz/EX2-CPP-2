/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */

#include "Graph.hpp"
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace ariel {

    // Load the graph with the provided matrix
    void Graph::loadGraph(const std::vector<std::vector<int>>& input) {
        matrix = input;
    }

   // Print the graph as a string in the desired pattern
    std::string Graph::printGraph() const {
        std::stringstream ss;
        for (const auto& row : matrix) {
            ss << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                ss << row[i];
                if (i < row.size() - 1) {
                    ss << ", ";
                }
            }
            ss << "]";
            if (&row != &matrix.back()) {
                ss << "\n";
            }
        }
        return ss.str();
    }

    // Get the adjacency matrix of the graph
    const std::vector<std::vector<int>>& Graph::getMatrix() const {
        return matrix;
    }

    // Addition operator
    Graph Graph::operator+(const Graph& other) const {
        if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
            throw std::invalid_argument("Graphs must be of the same dimensions");
        }
        Graph result;
        result.matrix = matrix;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                result.matrix[i][j] += other.matrix[i][j];
            }
        }
        return result;
    }

    // Addition assignment operator
    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    // Unary minus operator (negation)
    Graph Graph::operator-() const {
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& val : row) {
                val = -val;
            }
        }
        return result;
    }

    // Subtraction operator
    Graph Graph::operator-(const Graph& other) const {
        return *this + (-other);
    }

    // Subtraction assignment operator
    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    // Multiplication by a scalar operator
    Graph Graph::operator*(int scalar) const {
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& val : row) {
                val *= scalar;
            }
        }
        return result;
    }

   Graph Graph::operator*(const Graph& other) const {
    if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
        throw std::invalid_argument("Graphs must be of the same dimensions");
    }
    Graph result;
    result.matrix = matrix;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result.matrix[i][j] *= other.matrix[i][j];
        }
    }
    return result;
}

    // Multiplication assignment operator (scalar)
    Graph& Graph::operator*=(int scalar) {
        *this = *this * scalar;
        return *this;
    }

    // Division assignment operator (scalar)
    Graph& Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        for (auto& row : matrix) {
            for (auto& val : row) {
                val /= scalar;
            }
        }
        return *this;
    }

    // Division by a scalar operator
    Graph Graph::operator/(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& val : row) {
                val /= scalar;
            }
        }
        return result;
    }

    // Equality operator
    bool Graph::operator==(const Graph& other) const {
        return matrix == other.matrix;
    }

    // Inequality operator
    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator>(const Graph& other) const {
        if (*this == other) {
            return false;
        }

        // Compare based on edge count
        int thisEdges = 0;
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                thisEdges += element;
            }
        }

        int otherEdges = 0;
        for (const auto& row : other.matrix) {
            for (const auto& element : row) {
                otherEdges += element;
            }
        }

        if (thisEdges != otherEdges) {
            return thisEdges > otherEdges;
        }

        // If edge counts are equal, compare based on matrix size
        return matrix.size() > other.matrix.size();
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    bool Graph::operator<(const Graph& other) const {
        return other > *this;
    }

    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }

    // Prefix increment operator
    Graph& Graph::operator++() {
        for (auto& row : matrix) {
            for (auto& val : row) {
                ++val;
            }
        }
        return *this;
    }

    // Postfix increment operator
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement operator
    Graph& Graph::operator--() {
        for (auto& row : matrix) {
            for (auto& val : row) {
                --val;
            }
        }
        return *this;
    }

    // Postfix decrement operator
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    // Friend function: multiplication by a scalar (scalar * graph)
    Graph operator*(int scalar, const Graph& g) {
        return g * scalar;
    }

    // Friend function: output operator
    std::ostream& operator<<(std::ostream& os, const Graph& g) {
        os << g.printGraph();
        return os;
    }
}
