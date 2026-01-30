SELECT * FROM employees;
SELECT * FROM departments;
SELECT * FROM projects;
SELECT * FROM works_on;

SELECT first_name, last_name, salary
FROM employees;

UPDATE departments
SET dept_name = 'Human Resources'
WHERE dept_id = 1;

DELETE FROM employees
WHERE first_name = 'Alex' AND last_name = 'Miller';

ALTER TABLE employees
ADD COLUMN phone_number VARCHAR(15) UNIQUE;

UPDATE projects
SET budget = 35000.00
WHERE project_name = 'Mobile App';

ALTER TABLE works_on
ADD CONSTRAINT hours_worked_check CHECK (hours_worked > 0);

UPDATE employees
SET salary = 
CASE
	WHEN dept_id = 2 THEN salary*1.1
	ELSE salary*1.05
END;

ALTER TABLE departments
ADD COLUMN manager_id INTEGER
REFERENCES employees(emp_id);

ALTER TABLE departments
DROP COLUMN manager_id;

SELECT * FROM employees
WHERE salary > 65000;

SELECT * FROM employees
WHERE hire_date > '2022-01-01';

SELECT * FROM employees
WHERE email ILIKE '%@technova.com';

SELECT * FROM employees
ORDER BY salary DESC;

SELECT * FROM employees
ORDER BY SALARY DESC
LIMIT 2;

SELECT SUM(budget)
FROM projects;

SELECT AVG(salary)
FROM employees;

SELECT dept_id AS "department id",
COUNT(emp_id) AS "number of employees"
FROM employees
GROUP BY dept_id;

SELECT first_name FROM employees
WHERE salary = (
SELECT MAX(salary) FROM employees
);

SELECT dept_id AS "department ID",
SUM(salary) AS "Salary Payout"
FROM employees
GROUP BY dept_id;

SELECT CONCAT(e.first_name,' ',e.last_name) AS "employee Name",
(d.dept_name) AS "department Name"
FROM employees e
INNER JOIN departments d
ON e.dept_id = d.dept_id;

SELECT (d.dept_name) AS "Department Name",
CONCAT(e.first_name, ' ', e.last_name) AS "Employee Name"
FROM departments d
LEFT JOIN employees e
ON d.dept_id = e.dept_id;

SELECT (p.project_name) AS "Project Name",
SUM(w.hours_worked) AS "Hours Worked"
FROM projects p
INNER JOIN works_on w
ON p.project_id = w.project_id
GROUP BY p.project_id;

SELECT CONCAT(e.first_name, ' ', e.last_name) AS "Employee Name",
p.project_name AS "Project Name",
w.hours_worked AS "Hours Worked"
FROM employees e
JOIN works_on w ON e.emp_id = w.emp_id
JOIN projects p ON w.project_id = p.project_id;


