//Name: Liam Loeffel bals
//Program Name: Adding List Based Integers
//Description: This program takes an input file with two numbers on each line and adds them using lists

// Lab 04: Adding List-Based Integers
#include "list.h"
#include <iostream>
#include <string>

int main() {
	int digit;                 //stores the single number to be put in the list index
	int sum;                   //stores the sum of the two things stored at the same index
	int carry = 0;             //will be 1 or 0 depending on if the last sum was over 10

	while (true) {
		LinkedList<int> firstNumber;      //stores the first number read
		LinkedList<int> secondNumber;     //stores the second number read
		LinkedList<int> finalNumber;      //stores the final sum
		
		//Source: Chat GPT
		//this breaks the loop when its done reading
		std::string line;
		if (!std::getline(std::cin, line)) {
			break;
		}
		//end: Chat GPT

		bool isFirstNumber = true;    // decides whether or not the number should be stored in firstNumber or Second Number

		for (char digitAsChar : line) {        // goes thru each line
			if (digitAsChar == ' ') {      // skips the space and makes isFirstNumber false
				isFirstNumber = false;
				continue;
			}

			digit = digitAsChar - '0'; //converts the char to int
			if (digit >= 0 && digit <= 9) { //checks to make sure the number is an actual int
				if (isFirstNumber) { //are we on the first number
					firstNumber.appendNode(digit);
				} else {
					secondNumber.appendNode(digit);
				}
			}
		}

		//find the smaller array
		int smallerSize;   //stores the smaller arrays size
		int largerSize;    //stores the larger arrays size
		LinkedList<int> largerList;  //stores the larger array
		LinkedList<int> smallerList; //stores the smaller array

		if(firstNumber.nodeCount() >= secondNumber.nodeCount()){ //decides which one is bigger
			//stores the two sizes
			smallerSize = secondNumber.nodeCount(); 
			largerSize = firstNumber.nodeCount();
			
			int countTwo = 0; //stores a secondary iterator
			for(int i = 0; i < largerSize; i++){
				largerList.appendNode(firstNumber.getValue(i)); //make the larger list
				//filling the whole array other than the end with 0s
				if((i+1) > (largerSize-smallerSize)){ 
					smallerList.appendNode(secondNumber.getValue(countTwo));
					countTwo++;
				}else{
					smallerList.appendNode(0);
				}
			}
			
		}else{ //does the same thing as the above code but for the other list as the larger list
			smallerSize = firstNumber.nodeCount();
			largerSize = secondNumber.nodeCount();
			int count = 0;
			for(int i = 0; i < largerSize; i++){
				largerList.appendNode(secondNumber.getValue(i));
				if((i+1) > (largerSize-smallerSize)){
					smallerList.appendNode(firstNumber.getValue(count));
					count++;
				}else{
					smallerList.appendNode(0);
				}
			}
		}
		//this code exists cuz I was too lazy to go in the above code and fix it so the lists were backwards
		LinkedList<int> large; 
		LinkedList<int> small;
		//makes the lists backwards
		for (int i = largerSize - 1; i >= 0; i--){
			large.appendNode(largerList.getValue(i));
			small.appendNode(smallerList.getValue(i));
		}


		carry = 0; //reset the carry
		
		//adds everything except a last carry if there is one
		for(int i = 0; i < largerSize; i++){
			sum = (small.getValue(i)+large.getValue(i)+carry+10)%10;
			carry = (small.getValue(i)+large.getValue(i)+carry)/10;
			finalNumber.appendNode(sum);
		}
		//adds the last carry
		if (carry == 1){
			finalNumber.appendNode(1);
		}
		

		//prints the final answer
		for(int i = finalNumber.nodeCount() - 1; i >= 0; i--){
			std::cout << finalNumber.getValue(i);
		}
		std::cout << std::endl;

	}
	return 0;
}
