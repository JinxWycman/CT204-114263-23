#include<iostream>
#include<limits>

int reverseInteger(int num){
	int reversed=0;
	 while (num !=0){
		 int digit=num %10;
		 num /=10;
		 if (reversed > (std::numeric_limits<int>::max() - digit) / 10) {
            std::cout << "Overflow occurred!" << std::endl;
            return 0;
        }
        
        if (reversed < (std::numeric_limits<int>::min() - digit) / 10) {
            std::cout << "Underflow occurred!" << std::endl;
            return 0; 
        }

        reversed = reversed * 10 + digit; 
    }

    return reversed;
}

int main() {
    int number;
    
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int reversedNumber = reverseInteger(number);
    
    if (reversedNumber != 0) {
        std::cout << "Reversed integer: " << reversedNumber << std::endl;
    }

    return 0;
}
