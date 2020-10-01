#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector <int> roll(std::vector <int>&finalResult) {
    srand(std::time(0));
    std::vector <int> result (5);

    
    for (int i = 0; i < result.size(); i++) {
        char keep;
       result.at(i) = (1 + rand() % 6);
       std::cout << "Die " << (i + 1) << " = " << result.at(i) << std::endl;
       std::cout << "Type 'H' if you want to keep it or any other letter if you want to roll again\n";
       std::cin >> keep;
       keep = toupper(keep);
       if (keep != 'H') {
           i = (i - 1);
       }
    }
    return result;
}

void six(std::vector <int>& finalResult) {
    int howMany = 0;
    for (int i = 0; i < finalResult.size(); i++) {
        if (finalResult.at(i) == 6) {
            howMany = (howMany + 1);
        }
    }

    std::cout << "There are " << howMany << " dice with 6 among the dice you rolled.\n";
}

void pairs(std::vector <int>& finalResult) {
    int count = 0;
    for (int i = 0; i < finalResult.size(); i++) {
        for (int j = 0; j < finalResult.size(); j++) {
            if (j != i) {
                if (finalResult.at(j) == finalResult.at(i)) {
                    count = (count + 1);
                }
            }
        
        }
    }
    count = (count / 2);
    std::cout << "There are " << count << " pairs among the dice you rolled.\n";

}

int main()
{
    std::cout << "Welcom to the dice rolling game!\n";
    std::vector <int> finalResult(5);
    finalResult = roll(finalResult);
    six(finalResult);
    pairs(finalResult);
    

    return 0;
}

