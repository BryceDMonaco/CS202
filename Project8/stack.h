#include <iostream>

using namespace std;

class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack&);
                ~Stack();
                Stack& operator=(const Stack&);
                bool push(char); //Inserts
                bool pop(char&); //Removes
                bool empty() const; //Checks if empty
                bool full() const; //Checks if full
                bool clear(); //clears data
		bool operator==(const Stack&) const;
                friend ostream& operator<<(ostream&, const Stack&);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                char* data;
};

