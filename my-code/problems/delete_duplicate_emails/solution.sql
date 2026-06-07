# Write your MySQL query statement below
delete p
from Person p
inner join Person p2 
    on p.id > p2.id
    and p.email = p2.email