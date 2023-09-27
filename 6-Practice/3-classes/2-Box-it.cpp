/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .

The default constructor of the class should initialize , , and  to .

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.

The copy constructor BoxBox ) should set  and  to 's  and , respectively.

Apart from the above, the class should have  functions:

int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box
Overload the operator  for the class Box. Box   Box  if:

 < 
 <  and ==
 <  and == and ==
Overload operator  for the class Box().
If  is an object of class Box:

 should print ,  and  on a single line separated by spaces.

For example,

Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength();	// Should return 2
b2.getBreadth(); // Should return 3
b2.getheight();	// Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2);	// Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.
Constraints


Two boxes being compared using the  operator will not have all three dimensions equal.
*/
class Box {
 private:
  int length;
  int breadth;
  int height;

 public:
  // Default constructor.
  Box() : length(0), breadth(0), height(0) {}

  // Parameterized constructor.
  Box(int length, int breadth, int height)
      : length(length), breadth(breadth), height(height) {}

  // Copy constructor.
  Box(const Box& other)
      : length(other.length), breadth(other.breadth), height(other.height) {}

  // Getters.
  int getLength() const { return length; }
  int getBreadth() const { return breadth; }
  int getHeight() const { return height; }

  // Calculates the volume of the box.
  long long CalculateVolume() const {
    return (long long)length * breadth * height;
  }

  // Operator overload for < operator.
  bool operator<(const Box& other) const {
    return (length < other.length) ||
           (breadth < other.breadth && length == other.length) ||
           (height < other.height && breadth == other.breadth &&
            length == other.length);
  }

  // Friend function overload for << operator.
  friend ostream& operator<<(ostream& out, const Box& box) {
    out << box.length << " " << box.breadth << " " << box.height;
    return out;
  }
};
