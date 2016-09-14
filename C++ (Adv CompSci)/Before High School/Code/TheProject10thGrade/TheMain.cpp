#include <iostream>
#include <chrono>

  using namespace std;

int main() {
    for (int i = 0; i <= 90; i = i + 30){
        auto store = chrono::duration_values<chrono::nanoseconds>::zero();

        for (int j = 0; j < 10; j++){
            auto startTime = chrono::high_resolution_clock::now();
            int counter = 0;
            int value;
            long fib;
            value = i;

            long array[value + 1];
            while (counter <= value){
                if (value >= 0 && counter == 0){
                    array[0] = 0;
                }
                if (value >= 1 && counter == 1){
                    array[1] = 1;
                }
                if (value >= 2 && counter >= 2){
                    array[counter] = array[counter - 1] + array[counter - 2];
                }

                counter = counter + 1;
            }
            fib = array[value];
            auto endTime = chrono::high_resolution_clock::now();


            store = store + (endTime - startTime);
        }
        cout << chrono::duration_cast<chrono::nanoseconds>(store / 10).count() << "\n";
    }



}



