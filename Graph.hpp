/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */

#pragma once

#include <vector>
#include <ostream>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> matrix;

    public:
        void loadGraph(const std::vector<std::vector<int>>& input);
        std::string printGraph() const;
        const std::vector<std::vector<int>>& getMatrix() const;

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-() const; // Unary minus
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator*(int scalar) const;
        Graph operator*(const Graph& other) const;
        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);
        Graph operator/(int scalar) const;

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;

        // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement

        // Multiplication by a scalar
        friend Graph operator*(int scalar, const Graph& g);

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
    };

} // namespace ariel
