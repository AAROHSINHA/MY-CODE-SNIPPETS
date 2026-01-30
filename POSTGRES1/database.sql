-- Creating Tables
CREATE TABLE departments (
	dept_id SERIAL PRIMARY KEY,
	dept_name VARCHAR(50) NOT NULL UNIQUE,
	location VARCHAR(100) UNIQUE
);

ALTER TABLE departments
DROP CONSTRAINT departments_location_key;



CREATE TABLE employees (
	emp_id SERIAL PRIMARY KEY,
	first_name VARCHAR(50) NOT NULL,
	last_name VARCHAR(50) NOT NULL,
	email VARCHAR(100) UNIQUE NOT NULL,
	salary DECIMAL(10, 2) CHECK (salary > 0),
	hire_date DATE DEFAULT CURRENT_DATE,
	dept_id INTEGER NOT NULL,

	CONSTRAINT fk_dept_id
	FOREIGN KEY (dept_id)
	REFERENCES departments(dept_id)
);

CREATE TABLE projects (
	project_id SERIAL PRIMARY KEY,
	project_name VARCHAR(100) NOT NULL,
	budget DECIMAL(12, 2) 
);

CREATE TABLE works_on (
	emp_id INTEGER NOT NULL,
	project_id INTEGER NOT NULL,
	hours_worked INTEGER,

	CONSTRAINT fk_emp_id_works_on
	FOREIGN KEY (emp_id)
	REFERENCES employees(emp_id),

	CONSTRAINT fk_project_id_works_on
	FOREIGN KEY (project_id)
	REFERENCES projects(project_id)
)

SELECT * FROM departments;
SELECT * from employees;
SELECT * FROM projects;
SELECT * FROM works_on;


INSERT INTO departments
VALUES
(1, 'HR', 'New York'),
(2, 'Engineering', 'San Francisco'),
(3, 'Marketing', 'Chicago'),
(4, 'Sales', 'New York');

INSERT INTO employees
VALUES
(1, 'John', 'Doe', 'john.doe@technova.com', 60000.00, '2022-01-15', 2),
(2, 'Jane', 'Smith', 'jane.smith@technova.com', 85000.00, '2021-06-20', 2),
(3, 'Mike', 'Brown', 'mike.brown@technova.com', 50000.00, '2023-03-10', 1),
(4, 'Sarah', 'Connor', 'sarah.c@technova.com', 95000.00, '2020-11-05', 3),
(5, 'Alex', 'Miller', 'alex.m@technova.com', 45000.00, '2023-08-01', 4);

INSERT INTO projects
VALUES
(1, 'Website Redesign', 15000.0),
(2, 'Mobile App', 30000.0),
(3, 'Data Migration', 10000.0);

INSERT INTO works_on
VALUES
(1, 1, 50),
(2, 2, 120),
(2, 2, 20),
(3, 3, 15);
