# Write your MySQL query statement below
select
    w.id
from Weather w
where 
    (select w2.temperature
    from Weather w2
    where w2.recordDate = date_sub(w.recordDate , interval 1 day)) < w.temperature;