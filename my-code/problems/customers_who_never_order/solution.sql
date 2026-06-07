# Write your MySQL query statement below
select
    cus.name as Customers
from Customers cus
left join Orders o on cus.id = o.customerId
group by cus.id
having count(o.customerId) = 0;