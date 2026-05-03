# Write your MySQL query statement below
select 
    id,
    movie,
    description,
    rating
from Cinema
where
    mod(id , 2) and description not like 'boring'
order by rating desc;