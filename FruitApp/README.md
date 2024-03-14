# Fruit Inventory Management System

This project is developed as part of the Object-Oriented Programming. It aims to assist Klaus, the manager of a fruit store, in managing his inventory efficiently. The system allows users to add, delete, and search for fruits based on various criteria through a console-based user interface.

## Features

### Functional Requirements
1. Store attributes: Name, Origin, Expiry Date, Quantity, and Price for each fruit.
2. Ability to add or delete fruits. If an existing fruit is added, only its quantity is updated.
3. List all available fruits containing a specific string (sorted by name).
4. Display fruits with low quantities (user-defined threshold).
5. Sort fruits by expiry date.

### Additional Requirements
- Console-based user interface for user interaction.
- Initial sample data of at least 10 fruits.
- No persistent storage required.

## Architecture
The application follows a modular architecture with namespaces for domain, repository, controller, and UI. It utilizes smart pointers where necessary and adheres to English naming conventions for clarity.

### UML Class Diagram
