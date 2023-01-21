#include <iostream>

#include "renderer.hpp"

int main() {
    renderer r(400, 90);
    r.render();
    r.top_left_corner.print();
    std::cout << "Hello World!" << std::endl;
    return 0;
}
