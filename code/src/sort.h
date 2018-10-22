#ifndef Sort_H
#define Sort_H

#include <algorithm>
#include <vector>

using namespace std;

// sort algorithm example
/*#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}*/

class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v){}

      // The argument ** Accept comparison ** can accept lambda, function, and object]
	  template <typename comparearea>
      void sortArea(comparearea sortA){ //use lambda
		  std::sort(_v->begin(), _v->end(), sortA);  
	  }

      void sortPerimeter(bool (&sortP)(Shape *a, Shape *b)){ //use function
		  std::sort(_v->begin(), _v->end(), sortP);
	  }
      
	  template<class comparecompact>
      void sortCompactness(comparecompact sortC){ //use object
		  std::sort(_v->begin(), _v->end(), sortC);
	  }

    private:
      std::vector<Shape*>* _v;
};

//You should implement area ascending and descending "lambda" function as parameter for Sort::sortArea()

//You should use those "functions" as parameter for Sort::sortPerimeter()
bool perimeterDescendingComparison(Shape *a, Shape *b) { 
	return a->perimeter() > b->perimeter();
}

bool perimeterAscendingComparison(Shape *a, Shape *b) {
	return a->perimeter() < b->perimeter(); 
}

//You should use those "objects" as parameter for Sort::sortCompactness()
class CompactnessAscendingComparison{
	public:
	  bool operator() (Shape *a, Shape *b){
		return  a->compactness() < b->compactness(); 
	  }
};

class CompactnessDescendingComparison{
	public:
	  bool operator() (Shape *a, Shape *b){
		return  a->compactness() > b->compactness(); 
	  }
};


#endif