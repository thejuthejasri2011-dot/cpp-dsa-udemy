#include <iostream>

using namespace std;

class Cookie {
    private:
    string color;

    public:
    Cookie(string color) {
        this->color = color;
    }
    string getcolor () {
        return color;
    }
    void setcolor (string color) {
        this->color = color;
    }
};

int main() {
    Cookie* cookieOne = new Cookie("green");
    Cookie* cookieTwo = new Cookie("blue");

    cookieOne->setcolor("pink");

    cout << "C1: " << cookieOne->getcolor() << endl;
    cout << "C2: " << cookieTwo->getcolor() << endl;

}