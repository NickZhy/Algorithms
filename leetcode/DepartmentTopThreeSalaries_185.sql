# Write your MySQL query statement below
select Department.Name as 'Department', Employee.Name as 'Employee', Salary 
from Employee
join Department on Employee.DepartmentId = Department.Id
where (select count(distinct e.Salary)
       from Employee as e
       where e.DepartmentId = Employee.DepartmentId and
       e.Salary >= Employee.Salary) <= 3
order by DepartmentId, Salary desc
