# Electric Scooter Management System

This project is developed as part of the Object-Oriented Programming course at Babeș-Bolyai University, Cluj Napoca. It is designed to manage the fleet of electric scooters for a rental service. The system allows both managers and customers to interact with the application through a console-based user interface.

## Features (Labor 5)

### Functional Requirements
1. Two user roles: Manager and Customer.
2. Manager can add, delete, or edit scooters.
3. Search for scooters by location.
4. Filter scooter list by age or mileage.
5. View all scooters sorted by age.
6. Customers can reserve or use scooters.

### Additional Requirements
- Initial sample data for 10 or more scooters.
- Layered architecture with namespaces for domain, repository, controller, and UI.
- Smart-pointer implementation for repository and controller references.
- Exception handling for invalid inputs.
- Code written in English with meaningful naming conventions.
- Unit tests for repository and controller.

## Features (Labor 6)

### Functional Requirements
1. Customers can reserve one or more scooters.
2. Customers can view their reserved scooters.
3. Program prompts for selection of storage mode: volatile or persistent.

### Additional Requirements
- Repository polymorphism: Abstract repository class with In-Memory and CSV File repository subclasses.
- Adaptation of existing In-Memory repository as a subclass of CRUD repository.
- Implementation of CSV File repository to store data persistently.
- Avoidance of unnecessary object copying.
- Consistent separation of responsibilities between layers.
- Main program in Main.cpp and tests in test.cpp.

## Compilation and Execution
To compile the program using the GNU Compiler, use the following command:
