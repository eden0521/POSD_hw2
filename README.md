# Pattern Oriented Software Design
#### Fall, 2018

#### Homework 2

# Purpose of the homework:
  Using different ways to pass compare function
  1. lambda function
  2. function
  3. object

  See [C++ Reference std::sort](http://www.cplusplus.com/reference/algorithm/sort/ "std::Sort")
# Requirements:
 1. Create `shape.h`. with following interface below.

        class Shape {
        ...
            virtual double area() const = 0;
            virtual double perimeter() const = 0;
        ...
        }
 2. `Circle`, `Triangle`, `Rectangle` should inherit `Shape`.

 3. Implement `compactness()` method for each class.

        Compactness Formula : P^2 / A

        P = Perimeter ; A = Area
        Note:If Area = 0.Throw an exception string "Division by zero".


 4. Create `sort.h`. with following interface below:

    **Note: Each class constructor below are the skeleton. You should finish implementation by yourself.**

        class Sort{
            public:
              Sort(std::vector<Shape*>* v): _v(v){}

              // The argument ** Accept comparison ** can accept lambda, function, and object
              void sortArea(** Accept comparison **)

              void sortPerimeter(** Accept comparison **)

              void sortCompactness(** Accept comparison **)

            private:
              std::vector<Shape*>* _v;
        };

        //You should implement area ascending and descending lamda function as parameter for Sort::sortArea()

        //You should use those functions as parameter for Sort::sortPerimeter()
        bool perimeterDescendingComparison(Shape *a, Shape *b);

        bool perimeterAscendingComparison(Shape *a, Shape *b);

        //You should use those objects as parameter for Sort::sortCompactness()
        class CompactnessAscendingComparison{
        };

        class CompactnessDescendingComparison{
        };

 5. Modify `Triangle` constuctor, If the vertex can not construct a triangle. Throw an exception string  "Not a triangle".

 6. Create `ut_main.cpp`, `ut_sort.cpp`.<br>
 The `ut_main.cpp` should include `ut_sort.cpp` and  `ut_shape.cpp`.<br>
 Write the sortunit  test in `ut_sort.cpp`.<br>
 Modify ut_shape.cpp `TEST(triangle, isTriangle)` assertion.<br>
 Change assertion to assert exception string which is equal to "Not a triangle".

 7. Write the corresponding makefile to generate executable file which named **`hw2`**.
