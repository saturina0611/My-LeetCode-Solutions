# Write your MySQL query statement below
select
    a.player_id,
    a.event_date first_login
from Activity a
where (
    select min(a2.event_date)
    from Activity a2
    where a.player_id = a2.player_id
) = a.event_date;