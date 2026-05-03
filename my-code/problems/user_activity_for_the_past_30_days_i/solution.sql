# Write your MySQL query statement below
select 
    activity_date day,
    count(distinct user_id) active_users
from Activity
where activity_date between DATE_SUB('2019-07-27' , interval 29 day) and DATE('2019-07-27')
group by activity_date;

