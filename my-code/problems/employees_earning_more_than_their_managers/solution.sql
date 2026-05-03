# Write your MySQL query statement below
select 
    a.name as Employee
from Employee a
inner join Employee b on a.managerId = b.id and a.salary > b.salary;