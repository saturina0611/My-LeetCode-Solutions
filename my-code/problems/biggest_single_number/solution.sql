# Write your MySQL query statement below
select
    max(m.num) num
from (select
        m2.num
    from MyNumbers m2
    group by m2.num
    having count(m2.num) = 1) m

;