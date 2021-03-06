// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits>

typedef struct Student {
	int id;
	char *f_name;
	char *l_name;
	int n_assignments;
	double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
	Student student;
	double average = 0.0;
	
	// Sequence of user input -> store in fields of `student`
	student.id = promptInt("Please enter the student's id number: ", 0, 999999999); 
	
	student.f_name = (char*)malloc(128 * sizeof(char)); 
	std::cout << "Please enter the student's first name: "; 
	std::cin.get(student.f_name, 128, '\n'); 
	std::cin.clear(); 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	
	student.l_name = (char*)malloc(128 * sizeof(char)); 
	std::cout << "Please enter the student's last name: "; 
	std::cin.get(student.l_name, 128, '\n'); 
	std::cin.clear(); 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	
	student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, 134217728); 
	
	std::cout << std::endl; 
	
	student.grades = (double*)malloc(student.n_assignments * sizeof(double)); 
	for(int i = 0; i < student.n_assignments; i++) {
		student.grades[i] = promptDouble("Please enter grade for assignment "+std::to_string(i)+": ", 0, 1000); 
	}
	
	std::cout << std::endl; 
	
	// Call `CalculateStudentAverage(???, ???)`
	calculateStudentAverage(&student, &average); 
	
	// Output `average`
	std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << std::to_string(student.id) << "]" << std::endl; 
	std::cout.precision(1); 
	std::cout << "\tAverage grade: " << std::fixed << average << std::endl; 
	
	return 0;
}

/*
	message: text to output as the prompt
	min: minimum value to accept as a valid int
	max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
	// Code to prompt user for an int
	
	int result = 0; 
	bool valid = false; 
	std::string user_input; 
	
	while(!valid)
	{
		valid = true; 
		std::cout << message; 
		std::cin >> user_input; 
		
		for (int i = 0; i < user_input.length(); i++) {
			if(!isdigit(user_input[i])) {
				std::cout << "Sorry, I cannot understand your answer" << std::endl; 
				valid = false; 
				break; 
			}
		}
		
		if(valid) {
			result = stoi(user_input); 
		}
		
		if(result < min || max < result) {
			std::cout << "Sorry, I cannot understand your answer" << std::endl; 
			valid = false; 
		}
		
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	}
	
	return result; 
}

/*
	message: text to output as the prompt
	min: minimum value to accept as a valid double
	max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
	// Code to prompt user for a double
	
	double result = 0.0; 
	bool valid = false; 
	std::string user_input; 
	
	while(!valid)
	{
		valid = true; 
		std::cout << message; 
		std::cin >> user_input; 
		
		for (int i = 0; i < user_input.length(); i++) {
			if(!isdigit(user_input[i]) && !('.' == user_input[i])) {
				std::cout << "Sorry, I cannot understand your answer" << std::endl; 
				valid = false; 
				break; 
			}
		}
		
		if(valid) {
			result = stod(user_input); 
			
			if(result < min || max < result) {
				std::cout << "Sorry, I cannot understand your answer" << std::endl; 
				valid = false; 
			}
		}
		
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	}
	
	return result; 
}

/*
	object: pointer to anything - your choice! (but choose something that will be helpful)
			pointer to the relevant Student struct. 
			
	avg: pointer to a double (can store a value here)
		 pointer to a double meant to contain the average. 
*/
void calculateStudentAverage(void *object, double *avg)
{
	// Code to calculate and store average grade
	Student* student = (Student*)object; 
	
	double sum = 0.0; 
	
	for(int i = 0; i < student->n_assignments; i++) { 
		sum += student->grades[i]; 
	}
	
	*avg = (sum / student->n_assignments); 
}
