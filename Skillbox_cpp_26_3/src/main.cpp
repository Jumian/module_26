#include <iostream>
#include "Window.h"

int main() {
    Window window;
    window.init();
    window.control();
    std::cout << "End.." << std::endl;
}
