#include <iostream>
#include <vector>

extern "C" {
    //int adder(int, int);
    int looper(int[]);
}

struct Guy{
    char *name;
    char *job;
    int family[5];

    Guy(){
        name = nullptr;
        job = nullptr;
        for (int i = 0; i < 5; i++){
            family[i] = 9;
        }
    }
    ~Guy() {
        free(name);
        free(job);
    }
}

int main(){
    int numbers[5];
    for (int i = 0; i < 5; i++){
        numbers[i] = 
    }
    int a = looper(numbers);
    std::cout << a << std::endl;
    return 0;
}
    